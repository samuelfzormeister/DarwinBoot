// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libc_STDARG__
#define __libc_STDARG__


typedef __builtin_va_list va_list;

#define va_arg(va, type)  __builtin_va_arg((va), type)
#define va_copy(va1, va2) __builtin_va_copy((va1), (va2))
#define va_start(va, arg) __builtin_va_start((va), arg)
#define va_end(va)        __builtin_va_end((va))

#endif
