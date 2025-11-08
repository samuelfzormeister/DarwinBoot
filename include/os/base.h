// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __os_base__
#define __os_base__

#include <stdlib.h>

#if __cplusplus

#define OS_ENUM(_name, _type, ...) \
	        typedef enum : _type { __VA_ARGS__ } _name##_t

#else

#define OS_ENUM(_name, _type, ...) \
	        typedef _type _name##_t; enum { __VA_ARGS__ }
#endif

#endif
