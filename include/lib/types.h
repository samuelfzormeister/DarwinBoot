// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_types_h_
#define __lib_types_h_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <lib/arch.h>

#define __packed __attribute__((packed))
#define PACKED   __packed

#define __db_type_must_be_of_size(type, size) _Static_assert(sizeof(type) == size, #type " is not of the correct size.")

/* Better name for this macro? */
#define STRUCT_SIZE_CHECK(type, size) __db_type_must_be_of_size(struct type, size)
#define TYPE_SIZE_CHECK(type, size)   __db_type_must_be_of_size(type, size)

#if __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif

#if TARGET_CPU_X86_64 || TARGET_CPU_ARM64
    typedef uint64_t uintn_t;
#else
    typedef uint32_t uintn_t;
#endif

#pragma mark - Non-Standard Types

/* This mirrors the definition of a GUID in UEFI, to enable compatibility across the CoreDarwinBoot layer. */
typedef struct {
    uint32_t data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t Data4[8];
} guid_t;

typedef uint8_t uuid_t[16];

#if TARGET_CPU_ADDRESS_WIDTH == 64
typedef uint64_t virtual_address_t;
typedef uint64_t physical_address_t;
#elif TARGET_CPU_ADDRESS_WIDTH == 32
typedef uint32_t virtual_address_t;
typedef uint32_t physical_address_t;
#else
#error "Unsupported CPU address size."
#endif

#pragma mark - Built-in Macros and Types

/* Quickly check for these macros */
#ifndef __has_builtin
    #define __has_builtin(x) 0
#endif

#ifndef __has_attribute
    #define __has_attribute(x) 0
#endif

#if __has_attribute(__counted_by__)
    #define __counted_by(member) __attribute__((counted_by(member)))
#else
    #define __counted_by(member)
#endif

/* If we have the builtins; define them here */

#if __has_builtin(__builtin_bswap16)
    #define bswap16(x) __builtin_bswap16(x)
#else
    #define bswap16(x) (x & 0x00FF) << 4 | (x & 0xFF00) >> 4
#endif

#if __has_builtin(__builtin_bswap32)
    #define bswap32(x) __builtin_bswap32(x)
#endif

#if __has_builtin(__builtin_bswap64)
    #define bswap64(x) __builtin_bswap64(x)
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

    #define OSSwapBigToHostInt16(x) bswap16(x)
    #define OSSwapBigToHostInt32(x) bswap32(x)
    #define OSSwapBigToHostInt64(x) bswap64(x)

    #define OSSwapHostToBigInt16(x) bswap16(x)
    #define OSSwapHostToBigInt32(x) bswap32(x)
    #define OSSwapHostToBigInt64(x) bswap64(x)

    #define OSSwapHostToLittleInt16(x) x
    #define OSSwapHostToLittleInt32(x) x
    #define OSSwapHostToLittleInt64(x) x

    #define OSSwapLittleToHostInt16(x) x
    #define OSSwapLittleToHostInt32(x) x
    #define OSSwapLittleToHostInt64(x) x

#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

    #define OSSwapBigToHostInt16(x) x
    #define OSSwapBigToHostInt32(x) x
    #define OSSwapBigToHostInt64(x) x

    #define OSSwapHostToBigInt16(x) x
    #define OSSwapHostToBigInt32(x) x
    #define OSSwapHostToBigInt64(x) x

    #define OSSwapHostToLittleInt16(x) bswap16(x)
    #define OSSwapHostToLittleInt32(x) bswap32(x)
    #define OSSwapHostToLittleInt64(x) bswap64(x)

    #define OSSwapLittleToHostInt16(x) bswap16(x)
    #define OSSwapLittleToHostInt32(x) bswap32(x)
    #define OSSwapLittleToHostInt64(x) bswap64(x)

#endif

#endif /* __lib_types_h_ */
