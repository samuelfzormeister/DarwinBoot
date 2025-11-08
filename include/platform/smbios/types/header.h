// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_TABLEHEADER_H__
#define __PLATFORM_SMBIOS_TYPES_TABLEHEADER_H__

#include <stdint.h>
#include <lib/types.h>

struct {
    uint8_t type;
    uint8_t length;
    uint16_t handle;
} typedef smbios_table_header_t;

enum {
    SMBIOS_FIRMWARE_INFO = 0,
    SMBIOS_SYSTEM_INFO,
    SMBIOS_BASEBOARD_INFO,
    SMBIOS_CHASSIS_INFO,
    SMBIOS_PROCESSOR_INFO,
    SMBIOS_CACHE_INFO = 7,
    SMBIOS_SYSTEM_SLOT_INFO = 9,
    SMBIOS_PHYSICAL_MEMORY_ARRAY = 16,
    SMBIOS_MEMORY_DEVICE_INFO,
    SMBIOS_MEMORY_MAPPED_ADDRESSES = 19, /* 'Memory Array Mapped Address' */
} typedef smbios_type_t;

#endif /* __PLATFORM_SMBIOS_TYPES_TABLEHEADER_H__ */
