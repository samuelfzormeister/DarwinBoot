// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libc_ERRNO__
#define __libc_ERRNO__

typedef int errno_t;

/* These mirror XNU's <sys/errno.h> */
#define EPERM  1
#define ENOENT 2

/* Do ESRCH and EINTR really apply here? The bootloader is a single-threaded application. */

#define EIO     5
#define ENXIO   6
#define E2BIG   7
#define ENOEXEC 8
#define EBADF   9

/* Skip ECHILD */

#define EDLK   11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14

#define EBUSY  16
#define EEXIST 17

#define ENOTDIR 20
#define EISDIR  21
#define EINVAL  22

#define EFBIG  27
#define ENOSPC 28

#define EROFS  30

#define ENOTEMPTY 66

#define ESTALE 70

#define ENOSYS 78

#define EAUTH     80
#define ENEEDAUTH 81

#define EBADEXEC  85

#define EILSEQ 92

#endif
