// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_ENTRYPOINT_H__
#define __PLATFORM_SMBIOS_TYPES_ENTRYPOINT_H__

#include <stdint.h>

#define SMBIOS_ANCHOR_64 "_SM3_"
#define SMBIOS_ANCHOR_32 "_SM_"

typedef uint8_t smbios_string_t;

typedef struct {
    char anchor[4];
    uint8_t checksum;
    uint8_t entry_length;
    uint8_t version_major;
    uint8_t version_minor;
    uint16_t struct_max_size;
    uint8_t entry_rev;
    uint8_t formatted[5];
    uint8_t interm_anchor[5];
    uint8_t interm_checksum;
    uin16_t struct_table_length;
    uint32_t struct_table_addr;
    uint8_t bcd_rev;
} PACKED smbios_entry_point_32_t;

typedef enum {
    SMBIOS_ENTRY_REVISION_RESERVED0 = 0,
    SMBIOS_ENTRY_REVISION_SMBIOS3 = 1,
} smbios_entry_rev_t;

typedef struct {
    char anchor[5];
    uint8_t checksum;
    uint8_t entry_length;
    uint8_t version_major;
    uint8_t version_minor;
    uint8_t doc_rev;
    uint8_t entry_rev;
    uint8_t rsvd;
    uint32_t size;
    uint64_t address;
} PACKED smbios_entry_point_64_t;

typedef union {
    smbios_entry_point_32_t e32;
    smbios_entry_point_64_t e64;
} smbios_entry_point_t;

#endif /* __PLATFORM_SMBIOS_TYPES_ENTRYPOINT_H__ */
