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
 * The payload and the libraries it depends on.
 **/
static rtld_lib_t* g_payload = 0;


/**
 * Terminate the payload.
 **/
static int
payload_terminate(int status) {
  void (*_exit)(int) = 0;

  // we are running inside a hijacked process, just return
  if(!DYNLIB_DLSYM(0x2001, "_exit", &_exit)) {
    return status;
  }

  // resolve and run _exit
  if(!DYNLIB_DLSYM(0x1, "_exit", &_exit)) {
    _exit(status);
  }

  // should not happend
  __builtin_trap();

  return -1;
}


/**
 * Load the libraries the payload depends on, and link the payload.
 **/
static int
payload_link(void) {
  rtld_sandbox_t sandbox;
  int err;

  if((err=__rtld_sandbox_leave(&sandbox))) {
    __rtld_sandbox_restore(&sandbox);
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
    if((err=__rtld_lib_open(g_payload))) {
      __rtld_lib_destroy(g_payload);
      g_payload = 0;
    }
  }

  if(__rtld_sandbox_restore(&sandbox)) {
    err = -1;
  }

  return err;
}


/**
 * Initialize the payload.
 **/
static int
payload_init(void) {
  int err = 0;

  if((err=__klog_init())) {
    return err;
  }
  if((err=__kernel_init())) {
    return err;
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
 * Entry-point invoked by the ELF loader.
 **/
int
_start(void) {
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

  // initialize crt
  if((err=payload_init())) {
    return payload_terminate(err);
  }

  // get argc, argv, and envp
  if(DYNLIB_DLSYM(0x2001, "getargc", &getargc)) {
    DYNLIB_DLSYM(0x1, "getargc", &getargc);
  }
  if(DYNLIB_DLSYM(0x2001, "getargv", &getargv)) {
    DYNLIB_DLSYM(0x1, "getargv", &getargv);
  }
  if(DYNLIB_DLSYM(0x2001, "environ", &envp)) {
    DYNLIB_DLSYM(0x1, "environ", &envp);
  }
  if(getargc && getargv) {
    argc = getargc();
    argv = getargv();
  }

  // Run .init functions
  if((err=__rtld_lib_init(g_payload, argc, argv, envp))) {
    return payload_terminate(err);
  }

  // Run the payload
  err = main(argc, argv, envp);

  // Run .fini functions. The libraries are left loaded, as they always were,
  // since the process may live on after the payload returns.
  __rtld_lib_fini(g_payload);

  return payload_terminate(err);
}
