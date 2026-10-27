#include "klog.h"
#include "kernel.h"
#include "rtld_sprx.h"
#include "syscall.h"


/**
 * Dependencies to standard libraries.
 **/
static char* (*strcpy)(char*, const char*) = 0;
static int (*strcmp)(const char*, const char*) = 0;

static void* (*calloc)(unsigned long, unsigned long) = 0;
static void (*free)(void*) = 0;

static int   (*sceKernelLoadStartModule)(const char*, unsigned long, const void*,
					 unsigned int, void*, int*) = 0;
static int   (*sceKernelStopUnloadModule)(int, unsigned long, const void*, unsigned int,
					  const void*, void*) = 0;
static int   (*sceSysmoduleLoadModuleInternal)(unsigned int) = 0;


/**
 * The handle of libkernel is not the same on all firmwares.
 **/
static unsigned int g_libkernel_handle = 1;


/**
 * Extend the rtld_lib_t type with auxiliary parameters needed by .sprx loader.
 * This requires -fms-extensions.
 **/
typedef struct rtld_sprx_lib {
  struct rtld_lib;

  int handle;
  int unload_on_close;
} rtld_sprx_lib_t;


/**
 * Lookup table for sceSysmoduleLoadModuleInternal().
 **/
static struct sysmodtab {
  const char* name;
  unsigned int handle;
} sysmodtab[] = {
  {"libSceAppInstUtil.sprx", 0x80000014},
  {"libSceNet.sprx", 0x8000001c},
  {"libSceHttp.sprx", 0x8000000a},
  {"libSceSsl.sprx", 0x8000000b},
  {"libSceSystemService.sprx", 0x80000010},
  {"libSceUserService.sprx", 0x80000011},
};


/**
 * Open up a new sprx object and find the handle the kernel knows it by.
 **/
static int
sprx_open(rtld_lib_t* ctx) {
  rtld_sprx_lib_t* lib = (rtld_sprx_lib_t*)ctx;
  char path[1024];
  int handle = 0;
  int unload = 0;
  int error = 0;

  // check if the lib is an alias for libkernel
  if(!strcmp(lib->soname, "libkernel.sprx") ||
     !strcmp(lib->soname, "libkernel_web.sprx") ||
     !strcmp(lib->soname, "libkernel_sys.sprx")) {
    handle = g_libkernel_handle;
  }
  // libc is always there
  else if(!strcmp(lib->soname, "libSceLibcInternal.sprx")) {
    handle = 0x2;
  }
  else {
    if(__rtld_find_file(lib->soname, path)) {
      klog_printf("%s: not found in the system library directories\n", lib->soname);
      return -1;
    }

    for(int i=0; i<sizeof(sysmodtab)/sizeof(sysmodtab[0]); i++) {
      if(!strcmp(lib->soname, sysmodtab[i].name)) {
        if((error=sceSysmoduleLoadModuleInternal(sysmodtab[i].handle))) {
          klog_printf("%s: sceSysmoduleLoadModuleInternal(0x%x) failed: 0x%x\n",
                      lib->soname, sysmodtab[i].handle, error);
          return -1;
        }
      }
    }

    if((handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, 0)) < 0) {
      klog_printf("%s: sceKernelLoadStartModule failed: 0x%x\n", lib->soname, handle);
      return -1;
    }
    unload = 1;
  }

  lib->handle          = handle;
  lib->unload_on_close = unload;

  return 0;
}


/**
 * TODO: sprx_init
 **/
static int
sprx_init(rtld_lib_t* ctx, int argc, char** argv, char** envp) {
  return 0;
}


/**
 * TODO: sprx_fini
 **/
static int
sprx_fini(rtld_lib_t* ctx) {
  return 0;
}


/**
 * Resolve the address of a symbol provided by the given sprx object.
 **/
static void*
sprx_sym2addr(rtld_lib_t* ctx, const char* name) {
  rtld_sprx_lib_t* lib = (rtld_sprx_lib_t*)ctx;
  unsigned long addr = 0;

  if(lib->handle <= 0) {
    return 0;
  }

  // try with dlsym syscall first
  if(!DYNLIB_DLSYM(lib->handle, name, &addr)) {
    return (void*)addr;
  }

  // some symbols are blocked by the dlsym syscall, try resolving
  // it by peeking at the symtab in kernel space
  if((addr=kernel_dynlib_dlsym(-1, lib->handle, name))) {
    return (void*)addr;
  }

  return 0;
}


/**
 * The kernel does not hand out the layout of the object, so there is no way
 * to tell which symbol an address belongs to.
 **/
static const char*
sprx_addr2sym(rtld_lib_t* ctx, void* addr) {
  return 0;
}


/**
 * Close the given sprx object.
 **/
static int
sprx_close(rtld_lib_t* ctx) {
  rtld_sprx_lib_t* lib = (rtld_sprx_lib_t*)ctx;

  if(lib->unload_on_close) {
    lib->unload_on_close = 0;
    if(sceKernelStopUnloadModule(lib->handle, 0, 0, 0, 0, 0) &&
       __syscall(SYS_dynlib_unload, lib->handle, 0, 0, 0, 0, 0)) {
      return -1;
    }
  }

  lib->handle = -1;

  return 0;
}


/**
 * Free all memory associated the given sprx object.
 **/
static void
sprx_destroy(rtld_lib_t* ctx) {
  sprx_close(ctx);
  free(ctx);
}


rtld_lib_t*
__rtld_sprx_new(rtld_lib_t* parent, const char *soname) {
  rtld_sprx_lib_t* lib = calloc(1, sizeof(rtld_sprx_lib_t));

  lib->parent   = parent;
  lib->open     = sprx_open;
  lib->init     = sprx_init;
  lib->sym2addr = sprx_sym2addr;
  lib->addr2sym = sprx_addr2sym;
  lib->fini     = sprx_fini;
  lib->close    = sprx_close;
  lib->destroy  = sprx_destroy;
  lib->refcnt   = 0;
  lib->handle   = -1;

  strcpy(lib->soname, soname);

  return (rtld_lib_t*)lib;
}


int
__rtld_sprx_init(void) {
  unsigned int libSceSysmodule;
  long l;

  if(!DYNLIB_DLSYM(0x1, "getpid", &l)) {
    g_libkernel_handle = 0x1;
  } else if(!DYNLIB_DLSYM(0x2001, "getpid", &l)) {
    g_libkernel_handle = 0x2001;
  } else {
    klog_puts("unable to determine libkernel handle");
    return -1;
  }

  if(DYNLIB_DLSYM(g_libkernel_handle, "sceKernelLoadStartModule",
                  &sceKernelLoadStartModule)) {
    klog_puts("Unable to resolve the symbol 'sceKernelLoadStartModule'");
    return -1;
  }
  if(DYNLIB_DLSYM(g_libkernel_handle, "sceKernelStopUnloadModule",
                  &sceKernelStopUnloadModule)) {
    klog_puts("Unable to resolve the symbol 'sceKernelStopUnloadModule'");
    return -1;
  }

  if(!RTLD_DLSYM(0x2, strcpy)) {
    return -1;
  }
  if(!RTLD_DLSYM(0x2, strcmp)) {
    return -1;
  }
  if(!RTLD_DLSYM(0x2, calloc)) {
    return -1;
  }
  if(!RTLD_DLSYM(0x2, free)) {
    return -1;
  }

  if(DYNLIB_LOAD("/system/common/lib/libSceSysmodule.sprx", &libSceSysmodule)) {
    klog_puts("Unable to load the library '/system/common/lib/libSceSysmodule.sprx'");
    return -1;
  }
  if(DYNLIB_DLSYM(libSceSysmodule, "sceSysmoduleLoadModuleInternal",
                  &sceSysmoduleLoadModuleInternal)) {
    klog_puts("Unable to resolve the symbol 'sceSysmoduleLoadModuleInternal'");
    return -1;
  }

  return 0;
}
