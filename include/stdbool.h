// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libc_STDBOOL__
#define __libc_STDBOOL__

#if (__STDC_VERSION__ >= 202311)

    //
    // C23 defines a boolean type, thus we don't need to do anything.
    //

#elif (__STDC_VERSION__ >= 201710L)

    /* Use C17's boolean type. */
    typedef _Bool bool;
    #define true  1
    #define false 0

#elif !__cplusplus

    /* Otherwise just treat it like a char. */
    typedef char bool;
    #define true  1
    #define false 0

#endif

#endif
