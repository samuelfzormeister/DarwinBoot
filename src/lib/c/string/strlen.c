// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <string.h>

size_t strlen(const char *str)
{
    size_t ret = 0;
    const char *string = str;

    while (*string != 0) {
        string++;
        ret++;
    }

    return ret;
}
