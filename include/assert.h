// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libc_ASSERT__
#define __libc_ASSERT__

#include <panic.h>

#define static_assert(...) _Static_assert(__VA_ARGS__)

#ifndef NDEBUG

    #define assert(...)                                                                                \
        if ((__VA_ARGS__) == 0) {                                                                      \
            panic("ASSERT FAIL: %s:%d: %s %s", __FILE__, __LINE__, __PRETTY_FUNCTION__, #__VA_ARGS__); \
        }

#else

    #define assert(...) (void)0

#endif

#endif
