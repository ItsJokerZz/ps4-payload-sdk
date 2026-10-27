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

#include <sys/stat.h>
#include <sys/time.h>


static int
timespec2timeval(struct timeval tv[2], const struct timespec ts[2],
		 const struct stat* sb) {
  const struct timespec* old[2] = {&sb->st_atim, &sb->st_mtim};

  for(int i=0; i<2; i++) {
    if(ts[i].tv_nsec == UTIME_NOW) {
      if(gettimeofday(&tv[i], 0)) {
	return -1;
      }
    } else if(ts[i].tv_nsec == UTIME_OMIT) {
      tv[i].tv_sec = old[i]->tv_sec;
      tv[i].tv_usec = old[i]->tv_nsec / 1000;
    } else if(ts[i].tv_nsec >= 0 && ts[i].tv_nsec < 1000000000) {
      tv[i].tv_sec = ts[i].tv_sec;
      tv[i].tv_usec = ts[i].tv_nsec / 1000;
    } else {
      errno = EINVAL;
      return -1;
    }
  }

  return 0;
}


int
futimens(int fd, const struct timespec ts[2]) {
  struct timeval tv[2];
  struct stat sb;

  if(!ts) {
    return futimes(fd, 0);
  }

  if(fstat(fd, &sb) || timespec2timeval(tv, ts, &sb)) {
    return -1;
  }

  return futimes(fd, tv);
}


int
utimensat(int fd, const char* path, const struct timespec ts[2], int flag) {
  struct timeval tv[2];
  struct stat sb;

  if(flag & ~AT_SYMLINK_NOFOLLOW) {
    errno = EINVAL;
    return -1;
  }

  if(flag && fd != AT_FDCWD) {
    errno = ENOTSUP;
    return -1;
  }

  if(!ts) {
    return flag ? lutimes(path, 0) : futimesat(fd, path, 0);
  }

  if(fstatat(fd, path, &sb, flag) || timespec2timeval(tv, ts, &sb)) {
    return -1;
  }

  return flag ? lutimes(path, tv) : futimesat(fd, path, tv);
}
