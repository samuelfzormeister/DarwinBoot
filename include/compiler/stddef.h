// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __compiler_stddef_h_
#define __compiler_stddef_h_

#if defined (__clang__)
#include "clang/stddef.h"
#else
#error "Unsupported compiler!"
#endif

#endif /* __compiler_stddef_h_ */
