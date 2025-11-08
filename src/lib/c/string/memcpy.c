// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <string.h>

/* should i be an elitist and not have null pointer checks */

/* should i do it in 64-bit chunks instead? */
/* that would make better use of the 64-bit registers on ARM and x86_64, but what about hypothetical ARMv7 ports? */
void *memcpy(void *dest, const void *src, size_t n)
{
    uint8_t *dst = dest;
    const uint8_t *source = src;
    for (size_t i = 0; i < n; i++) {
        dst[i] = source[i];
    }
    return dst;
}
