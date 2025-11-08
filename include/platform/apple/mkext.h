// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_MKEXT_H__
#define __PLATFORM_APPLE_MKEXT_H__

#include <platform/apple/mach.h>

/* ah mkexts. the original kext collections. */

/* do note that every field here is stored in big endian. and i mean everything. */

#define MKEXT_MAGIC     0x4D4B5854 // 'MKXT'
#define MKEXT_SIGNATURE 0x4D4F5358 // 'MOSX'

#define MKEXT_VERSION_1 0x01008000
#define MKEXT_VERSION_2 0x02002001

struct {
    uint32_t magic;
    uint32_t signature;
    uint32_t size;
    uint32_t adler32;
    uint32_t version;
    uint32_t num_kexts;
    uint32_t cpu_type;
    uint32_t cpu_sub_type;
} typedef mkext_common_header_t;

struct {
    uint32_t offset;
    uint32_t compressed_size;
    uint32_t full_size;
    uint32_t modified_time; /* <libkern/mkext.h> says to use this as a libc time_t */
} typedef mkext_file_v1_t;

struct {
    mkext_file_v1_t plist;
    mkext_file_v1_t exec;
} typedef mkext_entry_v1_t;

struct {
    mkext_common_header_t base;
    mkext_entry_v1_t kexts[];
} typedef mkext_header_v1_t;

struct {
    mkext_common_header_t base;
    uint32_t plist_offset;
    uint32_t plist_compressed_size;
    uint32_t plist_full_size;
} typedef mkext_header_v2_t;

struct {
    uint32_t compressed_size;
    uint32_t full_size;
    uint8_t data[];
} typedef mkext_file_v2_t;

#endif /* __PLATFORM_APPLE_MKEXT_H__ */
