// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __compiler_clang_stddef_h_
#define __compiler_clang_stddef_h_

#include <compiler/common/stddef.h>

#if defined (__PTRDIFF_TYPE__)
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#else
typedef long long int ptrdiff_t;
#endif

#if defined (__SIZE_TYPE__)
typedef __SIZE_TYPE__ size_t;
#else
typedef long long unsigned int size_t;
#endif

#if defined (__WCHAR_TYPE__)
typedef __WCHAR_TYPE__ wchar_t;
#else
typedef unsigned short wchar_t;
#endif

#if __has_builtin(__builtin_offsetof)
#define offsetof(struct, member) __builtin_offsetof(struct, member)
#else
#error "clang isn't providing __builtin_offsetof???"
#endif

#endif /* __compiler_clang_stddef_h_ */
