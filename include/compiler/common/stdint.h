// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __compiler_common_stdint_h_
#define __compiler_common_stdint_h_

#if defined (__INT8_TYPE__)
typedef __INT8_TYPE__ int8_t;
#else
typedef signed char int8_t;
#endif

#if defined (__UINT8_TYPE__)
typedef __UINT8_TYPE__ uint8_t;
#else
typedef unsigned char uint8_t;
#endif

#if defined (__INT16_TYPE__)
typedef __INT16_TYPE__ int16_t;
#else
typedef signed short int16_t;
#endif

#if defined (__UINT16_TYPE__)
typedef __UINT16_TYPE__ uint16_t;
#else
typedef unsigned short uint16_t;
#endif

#if defined (__INT32_TYPE__)
typedef __INT32_TYPE__ int32_t;
#else
typedef int int32_t;
#endif

#if defined (__UINT32_TYPE__)
typedef __UINT32_TYPE__ uint32_t;
#else
typedef unsigned int uint32_t;
#endif

#endif /* __compiler_common_stdint_h_ */
