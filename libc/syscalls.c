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

#include <errno.h>


long
__syscall_ret(long ret) {
  if(ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}

void
wait4() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 7\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
ktrace() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 45\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
setlogin() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 50\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
acct() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 51\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
reboot() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 55\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
revoke() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 56\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
chroot() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 61\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
sbrk() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 69\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
sstk() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 70\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
vadvise() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 72\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
swapon() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 85\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
adjtime() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 140\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
nlm_syscall() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 154\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
nfssvc() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 155\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
lgetfh() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 160\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
getfh() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 161\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
rtprio() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 166\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
semsys() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 169\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
msgsys() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 170\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
shmsys() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 171\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
setfib() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 175\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
ntp_adjtime() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 176\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
undelete() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 205\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
semget() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 221\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
semop() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 222\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
msgget() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 225\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
msgsnd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 226\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
msgrcv() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 227\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
shmat() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 228\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
shmdt() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 230\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
shmget() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 231\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
ffclock_getcounter() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 241\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
ffclock_setestimate() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 242\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
ffclock_getestimate() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 243\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
clock_nanosleep() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 244\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
clock_getcpuclockid2() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 247\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
ntp_gettime() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 248\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
nstat() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 278\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
nfstat() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 279\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
nlstat() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 280\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
fhopen() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 298\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
fhstat() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 299\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
modnext() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 300\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
modstat() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 301\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
modfnext() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 302\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
modfind() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 303\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kldload() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 304\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kldunload() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 305\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kldfind() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 306\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kldnext() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 307\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kldstat() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 308\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kldfirstmod() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 309\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
utrace() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 335\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kldsym() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 337\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
jail() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 338\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
nnpfs_syscall() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 339\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_get_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 347\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_set_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 348\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_get_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 349\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_set_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 350\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_delete_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 351\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_delete_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 352\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_aclcheck_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 353\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_aclcheck_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 354\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattrctl() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 355\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_set_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 356\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_get_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 357\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_delete_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 358\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_set_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 371\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_get_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 372\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_delete_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 373\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__setugid() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 374\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_get_proc() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 384\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_set_proc() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 385\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_get_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 386\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_get_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 387\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_set_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 388\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_set_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 389\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
mac_syscall() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 394\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
fhstatfs() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 398\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_get_pid() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 409\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_get_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 410\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_set_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 411\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_set_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 412\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_get_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 413\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_delete_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 414\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__mac_execve() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 415\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
swapoff() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 424\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_get_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 425\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_set_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 426\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_delete_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 427\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__acl_aclcheck_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 428\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
thr_create() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 430\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
thr_exit() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 431\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
thr_kill() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 433\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
jail_attach() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 436\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_list_fd() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 437\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_list_file() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 438\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
extattr_list_link() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 439\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
thr_suspend() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 442\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
thr_wake() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 443\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kldunloadf() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 444\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
audit() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 445\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
auditon() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 446\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
getauid() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 447\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
setauid() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 448\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
getaudit() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 449\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
setaudit() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 450\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
getaudit_addr() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 451\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
setaudit_addr() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 452\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
auditctl() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 453\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
thr_new() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 455\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kmq_open() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 457\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kmq_setattr() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 458\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kmq_timedreceive() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 459\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kmq_timedsend() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 460\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kmq_notify() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 461\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
kmq_unlink() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 462\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
abort2() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 463\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
thr_set_name() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 464\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
sctp_peeloff() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 471\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
thr_kill2() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 481\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
cpuset() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 484\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
cpuset_setid() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 485\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
gssd_syscall() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 505\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
jail_get() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 506\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
jail_set() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 507\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
jail_remove() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 508\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
__semctl() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 510\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
freebsd7___semctl() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 220\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
msgctl() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 511\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
shmctl() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 512\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
lpathconf() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 513\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
cap_enter() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 516\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
cap_getmode() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 517\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
pdfork() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 518\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
pdkill() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 519\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
pdgetpid() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 520\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
getloginclass() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 523\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
setloginclass() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 524\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
rctl_get_racct() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 525\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
rctl_get_rules() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 526\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
rctl_get_limits() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 527\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
rctl_add_rule() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 528\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

void
rctl_remove_rule() {
  asm(".intel_syntax noprefix\n"
    "  sub rsp, 8\n"
    "  mov r9, r8\n"
    "  mov r8, rcx\n"
    "  mov rcx, rdx\n"
    "  mov rdx, rsi\n"
    "  mov rsi, rdi\n"
    "  mov edi, 529\n"
    "  xor eax, eax\n"
    "  call syscall\n"
    "  add rsp, 8\n"
    "  mov rdi, rax\n"
    "  jmp __syscall_ret\n"
    );
}

int
vfork() {
  extern int fork(void);

  return fork();
}

int
__cap_rights_get() {
  errno = ENOSYS;
  return -1;
}

int
afs3_syscall() {
  errno = ENOSYS;
  return -1;
}

int
aio_mlock() {
  errno = ENOSYS;
  return -1;
}

int
bindat() {
  errno = ENOSYS;
  return -1;
}

int
cap_fcntls_get() {
  errno = ENOSYS;
  return -1;
}

int
cap_fcntls_limit() {
  errno = ENOSYS;
  return -1;
}

int
cap_ioctls_get() {
  errno = ENOSYS;
  return -1;
}

int
cap_ioctls_limit() {
  errno = ENOSYS;
  return -1;
}

int
cap_rights_limit() {
  errno = ENOSYS;
  return -1;
}

int
connectat() {
  errno = ENOSYS;
  return -1;
}

int
numa_getaffinity() {
  errno = ENOSYS;
  return -1;
}

int
numa_setaffinity() {
  errno = ENOSYS;
  return -1;
}

int
procctl() {
  errno = ENOSYS;
  return -1;
}

int
sctp_generic_recvmsg() {
  errno = ENOSYS;
  return -1;
}

int
sctp_generic_sendmsg() {
  errno = ENOSYS;
  return -1;
}

int
sctp_generic_sendmsg_iov() {
  errno = ENOSYS;
  return -1;
}
