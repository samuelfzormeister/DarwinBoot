// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <string.h>

/* This is literally just memcmp's logic but const char *'d. */
/* Let me know if this ever needs changing. */

int strncmp(const char *m1, const char *m2, size_t n)
{
    const char *cursor1 = m1;
    const char *cursor2 = m2;
    size_t evaluated = 0;

    while (evaluated < n) {
        if (cursor1[evaluated] == cursor2[evaluated]) {
            evaluated++;
        } else {
            return cursor1[evaluated] - cursor2[evaluated];
        }
    }

    return 0;
}
