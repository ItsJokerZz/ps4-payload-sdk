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
#include <limits.h>
#include <poll.h>
#include <signal.h>


int
ppoll(struct pollfd fds[], nfds_t nfds, const struct timespec* timeout,
      const sigset_t* newsigmask) {
  sigset_t oldmask;
  int ms = -1;
  int err;
  int ret;

  if(timeout) {
    if(timeout->tv_sec < 0 || timeout->tv_nsec < 0 ||
       timeout->tv_nsec >= 1000000000) {
      errno = EINVAL;
      return -1;
    }

    if(timeout->tv_sec > (INT_MAX - 1000) / 1000) {
      ms = INT_MAX;
    } else {
      ms = timeout->tv_sec * 1000 + (timeout->tv_nsec + 999999) / 1000000;
    }
  }

  if(newsigmask && sigprocmask(SIG_SETMASK, newsigmask, &oldmask)) {
    return -1;
  }

  ret = poll(fds, nfds, ms);
  err = errno;

  if(newsigmask) {
    sigprocmask(SIG_SETMASK, &oldmask, 0);
  }

  errno = err;

  return ret;
}
