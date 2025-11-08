// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libc_STDIO__
#define __libc_STDIO__

#include <stdarg.h>
#include <stddef.h>

int printf(const char *fmt, ...);
int vprintf(const char *fmt, va_list list);

#define stderr 0
#define stdin  0
#define stdout 0

#define fprintf(fd, fmt, args...) printf(fmt, ##args)

int snprintf(char *s, size_t n, const char *format, ...);
int vsnprintf(char *s, size_t n, const char *format, va_list va);

#endif
