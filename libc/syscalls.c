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

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <poll.h>
#include <dirent.h>
#include <sched.h>
#include <semaphore.h>
#include <mqueue.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <sys/ptrace.h>
#include <sys/ktrace.h>
#include <sys/sysctl.h>
#include <sys/event.h>
#include <sys/ucontext.h>
#include <sys/jail.h>
#include <sys/acl.h>
#include <sys/extattr.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <aio.h>
#include <sys/cpuset.h>
#include <sys/rtprio.h>
#include <sys/thr.h>
#include <sys/umtx.h>
#include <sys/module.h>
#include <sys/linker.h>
#include <sys/procctl.h>
#include <sys/mac.h>
#include <sys/loginclass.h>
#include <netinet/sctp.h>
#include <ufs/ufs/quota.h>
#include <sys/kenv.h>
#include <sys/select.h>
#include <sys/socketvar.h>
#include <sys/syscall.h>
#include <sys/param.h>
#include <sys/cpuset.h>
#include <sys/_cpuset.h>
#include <sys/rctl.h>
#include <sys/timex.h>
#include <sys/ipc.h>
#include <sys/utsname.h>
#include <sys/reboot.h>
#include <sys/_types.h>
#include <pthread_np.h>
#include <sys/random.h>
#include <sys/_umtx.h>
#include <sys/user.h>
#include <machine/sysarch.h>
#include <bsm/audit.h>
#include <sys/vmmeter.h>


long
__syscall_ret(long ret) {
  if(ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}

__attribute__((naked)) pid_t
wait4(pid_t a0, int *a1, int a2, struct rusage *a3) {
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

__attribute__((naked)) int
ktrace(const char *a0, int a1, int a2, pid_t a3) {
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

__attribute__((naked)) int
setlogin(const char *a0) {
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

__attribute__((naked)) int
acct(const char *a0) {
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

__attribute__((naked)) int
reboot(int a0) {
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

__attribute__((naked)) int
revoke(const char *a0) {
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

__attribute__((naked)) int
chroot(const char *a0) {
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

__attribute__((naked)) void *
sbrk(intptr_t a0) {
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

__attribute__((naked)) int
swapon(const char *a0) {
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

__attribute__((naked)) int
adjtime(const struct timeval *a0, struct timeval *a1) {
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

__attribute__((naked)) int
nlm_syscall(int a0, int a1, int a2, char **a3) {
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

__attribute__((naked)) int
nfssvc(int a0, void *a1) {
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

__attribute__((naked)) int
lgetfh(const char *a0, fhandle_t *a1) {
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

__attribute__((naked)) int
getfh(const char *a0, fhandle_t *a1) {
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

__attribute__((naked)) int
rtprio(int a0, pid_t a1, struct rtprio *a2) {
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

__attribute__((naked)) int
semsys(int a0, ...) {
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

__attribute__((naked)) int
msgsys(int a0, ...) {
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

__attribute__((naked)) int
shmsys(int a0, ...) {
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

__attribute__((naked)) int
setfib(int a0) {
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

__attribute__((naked)) int
ntp_adjtime(struct timex *a0) {
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

__attribute__((naked)) int
undelete(const char *a0) {
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

__attribute__((naked)) int
semget(key_t a0, int a1, int a2) {
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

__attribute__((naked)) int
semop(int a0, struct sembuf *a1, size_t a2) {
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

__attribute__((naked)) int
msgget(key_t a0, int a1) {
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

__attribute__((naked)) int
msgsnd(int a0, const void *a1, size_t a2, int a3) {
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

__attribute__((naked)) int
msgrcv(int a0, void *a1, size_t a2, long a3, int a4) {
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

__attribute__((naked)) void *
shmat(int a0, const void *a1, int a2) {
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

__attribute__((naked)) int
shmdt(const void *a0) {
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

__attribute__((naked)) int
shmget(key_t a0, size_t a1, int a2) {
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

__attribute__((naked)) int
clock_getcpuclockid2(id_t a0, int a1, clockid_t *a2) {
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

__attribute__((naked)) int
ntp_gettime(struct ntptimeval *a0) {
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

__attribute__((naked)) int
fhopen(const struct fhandle *a0, int a1) {
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

__attribute__((naked)) int
fhstat(const struct fhandle *a0, struct stat *a1) {
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

__attribute__((naked)) int
modnext(int a0) {
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

__attribute__((naked)) int
modstat(int a0, struct module_stat *a1) {
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

__attribute__((naked)) int
modfnext(int a0) {
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

__attribute__((naked)) int
modfind(const char *a0) {
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

__attribute__((naked)) int
kldload(const char *a0) {
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

__attribute__((naked)) int
kldunload(int a0) {
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

__attribute__((naked)) int
kldfind(const char *a0) {
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

__attribute__((naked)) int
kldnext(int a0) {
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

__attribute__((naked)) int
kldstat(int a0, struct kld_file_stat *a1) {
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

__attribute__((naked)) int
kldfirstmod(int a0) {
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

__attribute__((naked)) int
utrace(const void *a0, size_t a1) {
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

__attribute__((naked)) int
kldsym(int a0, int a1, void *a2) {
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

__attribute__((naked)) int
jail(struct jail *a0) {
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

__attribute__((naked)) int
extattrctl(const char *a0, int a1, const char *a2, int a3, const char *a4) {
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

__attribute__((naked)) int
extattr_set_file(const char *a0, int a1, const char *a2, const void *a3, size_t a4) {
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

__attribute__((naked)) ssize_t
extattr_get_file(const char *a0, int a1, const char *a2, void *a3, size_t a4) {
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

__attribute__((naked)) int
extattr_delete_file(const char *a0, int a1, const char *a2) {
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

__attribute__((naked)) int
extattr_set_fd(int a0, int a1, const char *a2, const void *a3, size_t a4) {
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

__attribute__((naked)) ssize_t
extattr_get_fd(int a0, int a1, const char *a2, void *a3, size_t a4) {
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

__attribute__((naked)) int
extattr_delete_fd(int a0, int a1, const char *a2) {
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

__attribute__((naked)) int
mac_syscall(const char *a0, int a1, void *a2) {
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

__attribute__((naked)) int
fhstatfs(const struct fhandle *a0, struct statfs *a1) {
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

__attribute__((naked)) int
extattr_set_link(const char *a0, int a1, const char *a2, const void *a3, size_t a4) {
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

__attribute__((naked)) ssize_t
extattr_get_link(const char *a0, int a1, const char *a2, void *a3, size_t a4) {
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

__attribute__((naked)) int
extattr_delete_link(const char *a0, int a1, const char *a2) {
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

__attribute__((naked)) int
swapoff(const char *a0) {
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

__attribute__((naked)) int
thr_create(ucontext_t *a0, long *a1, int a2) {
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

__attribute__((naked)) void
thr_exit(long *a0) {
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

__attribute__((naked)) int
thr_kill(long a0, int a1) {
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

__attribute__((naked)) int
jail_attach(int a0) {
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

__attribute__((naked)) ssize_t
extattr_list_fd(int a0, int a1, void *a2, size_t a3) {
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

__attribute__((naked)) ssize_t
extattr_list_file(const char *a0, int a1, void *a2, size_t a3) {
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

__attribute__((naked)) ssize_t
extattr_list_link(const char *a0, int a1, void *a2, size_t a3) {
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

__attribute__((naked)) int
thr_suspend(const struct timespec *a0) {
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

__attribute__((naked)) int
thr_wake(long a0) {
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

__attribute__((naked)) int
kldunloadf(int a0, int a1) {
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

__attribute__((naked)) int
audit(const void *a0, int a1) {
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

__attribute__((naked)) int
auditon(int a0, void *a1, int a2) {
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

__attribute__((naked)) int
getauid(au_id_t *a0) {
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

__attribute__((naked)) int
setauid(const au_id_t *a0) {
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

__attribute__((naked)) int
getaudit(struct auditinfo *a0) {
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

__attribute__((naked)) int
setaudit(const struct auditinfo *a0) {
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

__attribute__((naked)) int
getaudit_addr(struct auditinfo_addr *a0, int a1) {
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

__attribute__((naked)) int
setaudit_addr(const struct auditinfo_addr *a0, int a1) {
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

__attribute__((naked)) int
auditctl(const char *a0) {
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

__attribute__((naked)) int
thr_new(struct thr_param *a0, int a1) {
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

__attribute__((naked)) void
abort2(const char *a0, int a1, void **a2) {
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

__attribute__((naked)) int
thr_set_name(long a0, const char *a1) {
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

__attribute__((naked)) int
sctp_peeloff(int a0, sctp_assoc_t a1) {
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

__attribute__((naked)) int
thr_kill2(pid_t a0, long a1, int a2) {
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

__attribute__((naked)) int
cpuset(cpusetid_t *a0) {
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

__attribute__((naked)) int
cpuset_setid(cpuwhich_t a0, id_t a1, cpusetid_t a2) {
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

__attribute__((naked)) int
jail_get(struct iovec *a0, unsigned int a1, int a2) {
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

__attribute__((naked)) int
jail_set(struct iovec *a0, unsigned int a1, int a2) {
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

__attribute__((naked)) int
jail_remove(int a0) {
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

__attribute__((naked)) int
msgctl(int a0, int a1, struct msqid_ds *a2) {
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

__attribute__((naked)) int
shmctl(int a0, int a1, struct shmid_ds *a2) {
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

__attribute__((naked)) long
lpathconf(const char *a0, int a1) {
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

__attribute__((naked)) int
getloginclass(char *a0, size_t a1) {
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

__attribute__((naked)) int
setloginclass(const char *a0) {
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

__attribute__((naked)) int
rctl_get_racct(const char *a0, size_t a1, char *a2, size_t a3) {
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

__attribute__((naked)) int
rctl_get_rules(const char *a0, size_t a1, char *a2, size_t a3) {
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

__attribute__((naked)) int
rctl_get_limits(const char *a0, size_t a1, char *a2, size_t a3) {
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

__attribute__((naked)) int
rctl_add_rule(const char *a0, size_t a1, char *a2, size_t a3) {
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

__attribute__((naked)) int
rctl_remove_rule(const char *a0, size_t a1, char *a2, size_t a3) {
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

pid_t
vfork(void) {
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
procctl(idtype_t a0, id_t a1, int a2, void *a3) {
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
