// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __STLIB_INTERNAL_H__
#define __STLIB_INTERNAL_H__

#include <stdlib.h>

extern void *platform_malloc(size_t size);
extern void platform_free(void *mem);

#endif /* __STLIB_INTERNAL_H__ */
