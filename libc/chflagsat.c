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
#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h>


int
chflagsat(int fd, const char* path, unsigned long flags, int atflag) {
  int err;
  int ret;
  int nfd;

  if(atflag & ~AT_SYMLINK_NOFOLLOW) {
    errno = EINVAL;
    return -1;
  }

  if(fd == AT_FDCWD) {
    return atflag ? lchflags(path, flags) : chflags(path, flags);
  }

  if(atflag) {
    errno = ENOTSUP;
    return -1;
  }

  if((nfd=openat(fd, path, O_RDONLY | O_NONBLOCK)) < 0) {
    return -1;
  }

  ret = fchflags(nfd, flags);
  err = errno;
  close(nfd);
  errno = err;

  return ret;
}
