// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <string.h>

/* Ref for the return values is https://cplusplus.com/reference/cstring/memcmp/ */
int memcmp(const void *m1, const void *m2, size_t n)
{
    const uint8_t *cursor1 = m1;
    const uint8_t *cursor2 = m2;
    size_t evaluated = 0;

    /* Hm. */
    while (evaluated < n) {
        if (cursor1[evaluated] == cursor2[evaluated]) {
            evaluated++;
        } else {
            return cursor1[evaluated] - cursor2[evaluated];
        }
    }

    return 0;
}
