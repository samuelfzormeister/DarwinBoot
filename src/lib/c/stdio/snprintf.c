// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <stdio.h>

int snprintf(char *s, size_t n, const char *format, ...)
{
    va_list list;
    va_start(list, format);
    int ret = vsnprintf(s, n, format, list);
    va_end(list);
    return ret;
}
