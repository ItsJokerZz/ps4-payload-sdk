/* Copyright (C) 2025 John Törnblom

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING. If not, see
<http://www.gnu.org/licenses/>.  */

#include "kernel.h"
#include "klog.h"
#include "patch.h"
#include "payload.h"
#include "rtld.h"
#include "rtld_dlfcn.h"
#include "rtld_payload.h"
#include "syscall.h"


/**
 * Dependencies provided by the ELF linker.
 **/
extern unsigned char __bss_start[] __attribute__((weak));
extern unsigned char __bss_end[] __attribute__((weak));


/**
 * Entry point to the main program.
 **/
extern int main(int argc, char* argv[], char *envp[]);


/**
 * The payload and the libraries it depends on, the args passed to _start
 * (the PS4 loader passes none), the exit code, and the cpu state to go back
 * to when the payload exits.
 **/
static rtld_lib_t* g_payload = 0;
static payload_args_t* payload_args = 0;
static int g_exit_code = 0;
static void* jmpbuf[32];


/**
 * Resolve a symbol with the dynlib_dlsym syscall, made with a syscall
 * instruction of our own. It is the only syscall made that way, since the
 * syscall function is found with it.
 **/
static int
payload_dlsym(int handle, const char* name, void* addr) {
  register long r10 asm("r10") = 0;
  register long r8  asm("r8")  = 0;
  register long r9  asm("r9")  = 0;
  unsigned long ret;
  char err;

  asm("syscall"
      : "=a"(ret), "=@ccc"(err), "+r"(r10), "+r"(r8), "+r"(r9)
      : "a"(SYS_sprx_dlsym), "D"((long)handle), "S"(name), "d"(addr)
      : "rcx", "r11", "memory");

  return (int)(err ? -ret : ret);
}


/**
 * Find the syscall function. The PS5 loader hands the payload sceKernelDlsym
 * to do that with, the PS4 loader hands over nothing. So look it up with a
 * syscall of our own and give the init of the syscall function an args struct
 * of its own, which nothing else sees.
 **/
static int
payload_syscall_init(void) {
  static payload_args_t args;

  if(payload_dlsym(0x1, "sceKernelDlsym", &args.sys_dynlib_dlsym)) {
    if(payload_dlsym(0x2001, "sceKernelDlsym", &args.sys_dynlib_dlsym)) {
      return -1;
    }
  }

  return __crt_syscall_init(&args);
}


/**
 * Terminate the payload.
 **/
static int
payload_terminate(int status) {
  void (*exit)(int) = 0;

  // we are running inside a hijacked process, just return
  if(!__crt_syscall(SYS_sprx_dlsym, 0x2001, "_exit", &exit)) {
    return status;
  }

  // resolve and run exit, which flushes stdio and runs the atexit handlers,
  // or _exit if libc does not have it
  if(!__crt_syscall(SYS_sprx_dlsym, 0x2, "exit", &exit) ||
     !__crt_syscall(SYS_sprx_dlsym, 0x1, "_exit", &exit)) {
    exit(status);
  }

  // should not happend
  __builtin_trap();

  return -1;
}


/**
 * The payload starts out in a sandbox that cannot see the system libraries.
 * Leave it for as long as the libraries are being loaded, and go back after.
 **/
typedef struct payload_sandbox {
  unsigned long prison;
  unsigned long rootdir;
  unsigned long jaildir;
} payload_sandbox_t;


/**
 * Go back to the sandbox the payload started in.
 **/
static int
payload_sandbox_restore(payload_sandbox_t* state) {
  int err = 0;

  if(kernel_set_proc_rootdir(-1, state->rootdir)) {
    klog_puts("kernel_set_proc_rootdir failed");
    err = -1;
  }
  if(kernel_set_proc_jaildir(-1, state->jaildir)) {
    klog_puts("kernel_set_proc_jaildir failed");
    err = -1;
  }
  if(kernel_set_ucred_prison(-1, state->prison)) {
    klog_puts("kernel_set_ucred_prison failed");
    err = -1;
  }

  return err;
}


/**
 * Leave the sandbox. When that fails, the sandbox is left as it was found.
 **/
static int
payload_sandbox_leave(payload_sandbox_t* state) {
  if(!(state->prison=kernel_get_ucred_prison(-1))) {
    klog_puts("kernel_get_ucred_prison failed");
    return -1;
  }
  if(!(state->rootdir=kernel_get_proc_rootdir(-1))) {
    klog_puts("kernel_get_proc_rootdir failed");
    return -1;
  }
  if(!(state->jaildir=kernel_get_proc_jaildir(-1))) {
    klog_puts("kernel_get_proc_jaildir failed");
    return -1;
  }

  if(kernel_set_proc_rootdir(-1, KERNEL_ADDRESS_ROOTVNODE)) {
    klog_puts("kernel_set_proc_rootdir failed");
  } else if(kernel_set_proc_jaildir(-1, KERNEL_ADDRESS_ROOTVNODE)) {
    klog_puts("kernel_set_proc_jaildir failed");
  } else if(kernel_set_ucred_prison(-1, KERNEL_ADDRESS_PRISON0)) {
    klog_puts("kernel_set_ucred_prison failed");
  } else {
    return 0;
  }

  payload_sandbox_restore(state);

  return -1;
}


/**
 * Load a library as a dependency of the payload before the ones the payload
 * asks for, since symbols are searched for in the order the libraries are
 * added.
 **/
static int
payload_preload(rtld_lib_t* payload, const char* soname) {
  rtld_lib_t* lib;

  if(!(lib=__rtld_lib_new(payload, soname))) {
    klog_printf("Unable to load %s\n", soname);
    return -1;
  }
  if(__rtld_lib_open(lib) < 0) {
    klog_printf("unable to load '%s'\n", soname);
    __rtld_lib_destroy(lib);
    return -1;
  }

  return __rtld_lib_append_dep(payload, lib);
}


/**
 * Load the libraries the payload depends on, and link the payload.
 **/
static int
payload_link(void) {
  payload_sandbox_t sandbox;
  int err;

  if((err=payload_sandbox_leave(&sandbox))) {
    return err;
  }

  if((err=__rtld_init())) {
    klog_puts("Unable to initialize rtld");
  }
  else if(!(g_payload=__rtld_payload_new(""))) {
    err = -1;
  }
  else {
    __rtld_dlfcn_setroot(g_payload);

    // symbols are looked up in libkernel first and then in libc
    if((err=payload_preload(g_payload, "libkernel.sprx")) ||
       (err=payload_preload(g_payload, "libSceLibcInternal.sprx")) ||
       (err=__rtld_lib_open(g_payload))) {
      __rtld_lib_destroy(g_payload);
      g_payload = 0;
    }
  }

  if(payload_sandbox_restore(&sandbox)) {
    err = -1;
  }

  return err;
}


/**
 * Initialize the payload.
 **/
static int
payload_init(void) {
  int *__isthreaded = 0;
  int err = 0;

  if((err=__klog_init())) {
    return err;
  }
  if((err=__kernel_init())) {
    return err;
  }

  // a payload is free to start threads, so libc has to lock its streams
  if(!__crt_syscall(SYS_sprx_dlsym, 0x2, "__isthreaded", &__isthreaded)) {
    *__isthreaded = 1;
  } else {
    klog_puts("Unable to resolve the symbol '__isthreaded'");
  }

  if((err=payload_link())) {
    return err;
  }
  if((err=__patch_init())) {
    return err;
  }

  return err;
}


/**
 * Exit the payload by transfering the flow of control back to __crt_start().
 **/
void
payload_exit(int exit_code) {
  g_exit_code = exit_code;
  __builtin_longjmp(jmpbuf, 1);
}


/**
 * Provide a convenience function for accessing the payload args.
 **/
payload_args_t*
payload_get_args(void) {
  return payload_args;
}


/**
 * Entry-point invoked by _start.
 **/
int
__crt_start(void) {
  char** (*getargv)(void) = 0;
  int (*getargc)(void) = 0;
  char** envp = 0;
  char** argv = 0;
  int argc = 0;
  int err = 0;

  // clear .bss section
  for(unsigned char* bss=__bss_start; bss<__bss_end; bss++) {
    *bss = 0;
  }

  // without a syscall function there is nothing left to do but to return
  if((err=payload_syscall_init())) {
    return err;
  }

  // initialize crt
  if((err=payload_init())) {
    return payload_terminate(err);
  }

  // get argc, argv, and envp
  if(__crt_syscall(SYS_sprx_dlsym, 0x2001, "getargc", &getargc)) {
    __crt_syscall(SYS_sprx_dlsym, 0x1, "getargc", &getargc);
  }
  if(__crt_syscall(SYS_sprx_dlsym, 0x2001, "getargv", &getargv)) {
    __crt_syscall(SYS_sprx_dlsym, 0x1, "getargv", &getargv);
  }
  if(__crt_syscall(SYS_sprx_dlsym, 0x2001, "environ", &envp)) {
    __crt_syscall(SYS_sprx_dlsym, 0x1, "environ", &envp);
  }
  if(getargc && getargv) {
    argc = getargc();
    argv = getargv();
  }

  // run the payload, payload_exit() ends up here with the exit code set
  if(!__builtin_setjmp(jmpbuf)) {
    // Run .init functions
    if((err=__rtld_lib_init(g_payload, argc, argv, envp))) {
      g_exit_code = err;
    } else {
      g_exit_code = main(argc, argv, envp);

      // Run .fini functions. The libraries are left loaded, as they always
      // were, since the process may live on after the payload returns.
      __rtld_lib_fini(g_payload);
    }
  }

  return payload_terminate(g_exit_code);
}
