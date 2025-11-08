// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <stdio.h>
#include <External/printf/printf.h>

#undef vprintf

int vprintf(const char *fmt, va_list list)
{
    return vprintf_(fmt, list);
}
