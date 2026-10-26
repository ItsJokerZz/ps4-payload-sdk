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

#include <sys/syscall.h>


int
getresuid(uid_t *ruid, uid_t *euid, uid_t *suid) {
  int err;

  if((err=syscall(SYS_getresuid, ruid, euid, suid))) {
    errno = -err;
    return -1;
  }

  return 0;
}


int
getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) {
  int err;

  if((err=syscall(SYS_getresgid, rgid, egid, sgid))) {
    errno = -err;
    return -1;
  }

  return 0;
}


int
setresuid(uid_t ruid, uid_t euid, uid_t suid) {
  int err;

  if((err=syscall(SYS_setresuid, ruid, euid, suid))) {
    errno = -err;
    return -1;
  }

  return 0;
}


int
setresgid(gid_t rgid, gid_t egid, gid_t sgid) {
  int err;

  if((err=syscall(SYS_setresgid, rgid, egid, sgid))) {
    errno = -err;
    return -1;
  }

  return 0;
}
