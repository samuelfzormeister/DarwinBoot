// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libc_LIMITS__
#define __libc_LIMITS__

#include <compiler/limits.h>

#define CHAR_BIT __CHAR_BIT__

#define SCHAR_MIN -__SCHAR_MAX__ - 1
#define SCHAR_MAX __SCHAR_MAX__

#define UCHAR_MAX (SCHAR_MAX * 2) + 1

#define INT_MAX  __INT_MAX__
#define UINT_MAX (INT_MAX * 2) + 1

#endif
