// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_SYSTEMINFO_H__
#define __PLATFORM_SMBIOS_TYPES_SYSTEMINFO_H__

#include <platform/smbios/types/entry_point.h>
#include <platform/smbios/types/header.h>

enum : uint8_t {
    SMBIOS_WAKE_TYPE_OTHER = 0x1,
    SMBIOS_WAKE_TYPE_UNKNWON = 0x2,
    SMBIOS_WAKE_TYPE_APM_TIMER = 0x3,
    SMBIOS_WAKE_TYPE_MODEM_RING = 0x4,
    SMBIOS_WAKE_TYPE_LAN_REMOTE = 0x5,
    SMBIOS_WAKE_TYPE_POWER_SWITCH = 0x6,
    SMBIOS_WAKE_TYPE_PCI_PME = 0x7,
    SMBIOS_WAKE_TYPE_AC_POWER_RESTORED = 0x8,
} typedef smbios_system_wake_type_t;

struct {
    smbios_table_header_t header;
    smbios_string_t manufacturer_name;
    smbios_string_t system_product_name;
    smbios_string_t system_product_version;
    smbios_string_t system_serial_number;
    uuid_t system_uuid;
    smbios_system_wake_type_t system_wake_type;
    smbios_string_t system_sku_number;
    smbios_string_t system_family;
} PACKED typedef smbios_system_info_t;

#endif /* __PLATFORM_SMBIOS_TYPES_SYSTEMINFO_H__ */
