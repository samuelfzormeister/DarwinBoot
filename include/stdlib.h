// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libc_STDLIB__
#define __libc_STDLIB__

#include <stddef.h>

#define NULL (void *)0

int atoi(const char *str);
long atol(const char *str);

void free(void *mem);

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

#endif
