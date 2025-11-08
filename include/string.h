// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libc_STRING__
#define __libc_STRING__

#include <stddef.h>
#include <stdlib.h>

void *memchr(const void *mem, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *dst, int x, size_t n);
int memcmp(const void *b1, const void *b2, size_t n);

int strncmp(const char *s1, const char *s2, size_t n);

size_t strlen(const char *str);

#endif
