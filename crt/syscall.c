/* Copyright (C) 2024 John Törnblom

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

#include "syscall.h"


static __attribute__ ((used)) long ptr_syscall = 0;

__attribute__ ((naked)) long
__crt_syscall(long sysno, ...) {
  asm(".intel_syntax noprefix\n"
      "  mov rax, rdi\n"
      "  mov rdi, rsi\n"
      "  mov rsi, rdx\n"
      "  mov rdx, rcx\n"
      "  mov r10, r8\n"
      "  mov r8,  r9\n"
      "  mov r9,  qword ptr [rsp + 8]\n"
      "  call qword ptr [rip + ptr_syscall]\n"
      "  ret\n");
}


/**
 * Make a syscall with a syscall instruction of our own. Only used to find
 * the syscall function above, which the PS5 loader hands to the payload and
 * the PS4 loader does not.
 **/
static long
raw_syscall(long n, ...) {
  long a1 = 0, a2 = 0, a3 = 0;
  __builtin_va_list ap;
  unsigned long ret;
  char err;

  __builtin_va_start(ap, n);
  a1 = __builtin_va_arg(ap, long);
  a2 = __builtin_va_arg(ap, long);
  a3 = __builtin_va_arg(ap, long);
  __builtin_va_end(ap);

  register long r10 asm("r10") = 0;
  register long r8  asm("r8")  = 0;
  register long r9  asm("r9")  = 0;

  asm("syscall"
      : "=a"(ret), "=@ccc"(err), "+r"(r10), "+r"(r8), "+r"(r9)
      : "a"(n), "D"(a1), "S"(a2), "d"(a3)
      : "rcx", "r11", "memory");

  return err ? -ret : ret;
}


int
__crt_syscall_init(void) {
  if(raw_syscall(SYS_dynlib_dlsym, 0x1, "getpid", &ptr_syscall)) {
    raw_syscall(SYS_dynlib_dlsym, 0x2001, "getpid", &ptr_syscall);
  }

  if(!ptr_syscall) {
    return -1;
  }

  ptr_syscall += 0xa; // jump directly to the syscall instruction

  return 0;
}
