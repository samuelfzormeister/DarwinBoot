// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_BASEBOARDINFO_H__
#define __PLATFORM_SMBIOS_TYPES_BASEBOARDINFO_H__

#include <platform/smbios/types/entry_point.h>
#include <platform/smbios/types/header.h>

typedef enum : uint8_t {
    SMBIOS_BASEBOARD_TYPE_UNKNOWN = 0x1,
    SMBIOS_BASEBOARD_TYPE_OTHER = 0x2,
    SMBIOS_BASEBOARD_TYPE_SERVER_BLADE = 0x3,
    SMBIOS_BASEBOARD_TYPE_CONNECTIVITY_SWITCH = 0x4,
    SMBIOS_BASEBOARD_TYPE_SYSTEM_MANAGEMENT_MODULE = 0x5,
    SMBIOS_BASEBOARD_TYPE_PROCESSOR_MODULE = 0x6,
    SMBIOS_BASEBOARD_TYPE_IO_MODULE = 0x7,
    SMBIOS_BASEBOARD_TYPE_MEMORY_MODULE = 0x8,
    SMBIOS_BASEBOARD_TYPE_DAUGHTERBOARD = 0x9,
    SMBIOS_BASEBOARD_TYPE_MOTHERBOARD = 0xA,
    SMBIOS_BASEBOARD_TYPE_PROCESSOR_AND_MEMORY_MODULE = 0xB,
    SMBIOS_BASEBOARD_TYPE_PROCESSOR_AND_IO_MODULE = 0xC,
    SMBIOS_BASEBOARD_TYPE_INTERCONNECT_BOARD = 0xD,
} smbios_baseboard_type_t;

enum {
    SMBIOS_BASEBOARD_FLAG_IS_HOSTING = (1 << 0),
    SMBIOS_BASEBOARD_FLAG_REQUIRES_DAUGHTERBOARD = (1 << 1),
    SMBIOS_BASEBOARD_FLAG_IS_REMOVABLE = (1 << 2),
    SMBIOS_BASEBOARD_FLAG_IS_REPLACEABLE = (1 << 3),
    SMBIOS_BASEBOARD_FLAG_IS_HOT_SWAPPABLE = (1 << 4),
};

typedef struct {
    smbios_table_header_t header;
    smbios_string_t manufacturer_name;
    smbios_string_t product;
    smbios_string_t version;
    smbios_string_t serial_number;
    smbios_string_t asset_tag;
    uint8_t feature_flags;
    smbios_string_t location_in_chassis;
    uint16_t chassis_handle;
    smbios_baseboard_type_t type;
    uint8_t num_object_handles;
    uint16_t object_handles[] __counted_by(num_object_handles);
} PACKED SMBIOSBaseboardInfo;

#endif /* __PLATFORM_SMBIOS_TYPES_BASEBOARDINFO_H__ */
