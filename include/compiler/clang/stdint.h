// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __compiler_clang_stdint_h_
#define __compiler_clang_stdint_h_

#include <compiler/common/stdint.h>

#if defined (__INT64_TYPE__)
typedef __INT64_TYPE__ int64_t;
#else
typedef long long int int64_t;
#endif

#if defined (__UINT64_TYPE__)
typedef __UINT64_TYPE__ uint64_t;
#else
typedef long long unsigned int uint64_t;
#endif

#if defined (__INTMAX_TYPE__)
typedef __INTMAX_TYPE__ intmax_t;
#else
typedef long long int intmax_t;
#endif

#if defined (__UINTMAX_TYPE__)
typedef __UINTMAX_TYPE__ uintmax_t;
#else
typedef long long unsigned int uintmax_t;
#endif

#if defined (__INTPTR_TYPE__)
typedef __INTPTR_TYPE__ intptr_t;
#else
typedef long long int intptr_t;
#endif

#if defined (__UINTPTR_TYPE__)
typedef __UINTPTR_TYPE__ uintptr_t;
#else
typedef long long unsigned int uintptr_t;
#endif

#define UINT32_C(c) c##U
#define INT64_C(c) c##LL
#define UINT64_C(c) c##ULL

#endif /* __compiler_clang_stdint_h_ */
