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
posix_fallocate(int fd, off_t offset, off_t len) {
  struct stat sb;

  if(offset < 0 || len <= 0) {
    return EINVAL;
  }

  if(fstat(fd, &sb)) {
    return errno;
  }

  if(S_ISFIFO(sb.st_mode)) {
    return ESPIPE;
  }

  if(!S_ISREG(sb.st_mode)) {
    return ENODEV;
  }

  if(offset + len < offset) {
    return EFBIG;
  }

  if(sb.st_size < offset + len && ftruncate(fd, offset + len)) {
    return errno;
  }

  return 0;
}
