// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <string.h>

void *memset(void *dest, int x, size_t n)
{
    uint8_t *dst = dest;
    for (size_t i = 0; i < n; i++) {
        dst[i] = x; // what if i told you sizeof(char) < sizeof(int)
    }
    return dst;
}
