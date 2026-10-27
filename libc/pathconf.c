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


/**
 * A result of -1 means there is no limit for the name, it is not an error. The
 * functions never fail with EPERM, so -1 can't be an error code either.
 **/
long
pathconf(const char *path, int name) {
  long n;

  if((n=syscall(SYS_pathconf, path, name)) < -1) {
    errno = -n;
    return -1;
  }

  return n;
}


long
fpathconf(int fd, int name) {
  long n;

  if((n=syscall(SYS_fpathconf, fd, name)) < -1) {
    errno = -n;
    return -1;
  }

  return n;
}
