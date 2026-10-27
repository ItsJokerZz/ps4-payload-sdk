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
#include <signal.h>
#include <string.h>

#include <sys/resource.h>
#include <sys/wait.h>


pid_t
wait6(idtype_t idtype, id_t id, int* status, int options,
      struct __wrusage* wrusage, struct __siginfo* info) {
  struct rusage ru;
  int st = 0;
  pid_t pid;
  pid_t who;

  switch(idtype) {
  case P_ALL:
    who = -1;
    break;

  case P_PID:
    who = id;
    break;

  case P_PGID:
    who = id ? -id : 0;
    break;

  default:
    errno = EINVAL;
    return -1;
  }

  if((options & ~(WNOHANG | WUNTRACED | WCONTINUED | WNOWAIT | WEXITED | WTRAPPED)) ||
     !(options & (WEXITED | WUNTRACED | WCONTINUED | WTRAPPED))) {
    errno = EINVAL;
    return -1;
  }

  options &= WNOHANG | WUNTRACED | WCONTINUED | WNOWAIT;

  if((pid=wait4(who, &st, options, &ru)) < 0) {
    return -1;
  }

  if(status) {
    *status = st;
  }

  if(wrusage) {
    memset(wrusage, 0, sizeof(*wrusage));
    wrusage->wru_self = ru;
  }

  if(info) {
    memset(info, 0, sizeof(*info));
    if(pid > 0) {
      info->si_signo = SIGCHLD;
      info->si_pid = pid;

      if(WIFEXITED(st)) {
	info->si_code = CLD_EXITED;
	info->si_status = WEXITSTATUS(st);
      } else if(WIFSIGNALED(st)) {
	info->si_code = WCOREDUMP(st) ? CLD_DUMPED : CLD_KILLED;
	info->si_status = WTERMSIG(st);
      } else if(WIFSTOPPED(st)) {
	info->si_code = WSTOPSIG(st) == SIGTRAP ? CLD_TRAPPED : CLD_STOPPED;
	info->si_status = WSTOPSIG(st);
      } else {
	info->si_code = CLD_CONTINUED;
	info->si_status = SIGCONT;
      }
    }
  }

  return pid;
}
