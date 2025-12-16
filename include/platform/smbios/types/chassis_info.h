// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_CHASSISINFO_H__
#define __PLATFORM_SMBIOS_TYPES_CHASSISINFO_H__

#include <platform/smbios/types/entry_point.h>
#include <platform/smbios/types/header.h>

typedef enum : uint8_t {
    SMBIOS_CHASSIS_LOCK_BIT = (1 << 7),

    SMBIOS_CHASSIS_TYPE_OTHER = 0x1,
    SMBIOS_CHASSIS_TYPE_UNKNOWN = 0x2,
    SMBIOS_CHASSIS_TYPE_DESKTOP = 0x3,
    SMBIOS_CHASSIS_TYPE_LOW_PROFILE_DESKTOP = 0x4,
    SMBIOS_CHASSIS_TYPE_PIZZA_BOX = 0x5,            /* pizza time */
    SMBIOS_CHASSIS_TYPE_MINI_TOWER = 0x6,
    SMBIOS_CHASSIS_TYPE_TOWER = 0x7,
    SMBIOS_CHASSIS_TYPE_PORTABLE = 0x8,
    SMBIOS_CHASSIS_TYPE_LAPTOP = 0x9,
    SMBIOS_CHASSIS_TYPE_NOTEBOOK = 0xA,
    SMBIOS_CHASSIS_TYPE_HANDHELD = 0xB,
    SMBIOS_CHASSIS_TYPE_DOCKING_STATION = 0xC,
    SMBIOS_CHASSIS_TYPE_ALL_IN_ONE = 0xD,
    SMBIOS_CHASSIS_TYPE_SUB_NOTEBOOK = 0xE,
    SMBIOS_CHASSIS_TYPE_SPACE_SAVING = 0xF,
    SMBIOS_CHASSIS_TYPE_LUNCH_BOX = 0x10,             /* omw to have a yummy silicon sandwich with thermal paste sauce */
    SMBIOS_CHASSIS_TYPE_MAIN_SERVER_CHASSIS = 0x11,
    SMBIOS_CHASSIS_TYPE_EXPANSION_CHASSIS = 0x12,
    SMBIOS_CHASSIS_TYPE_SUB_CHASSIS = 0x13,
    SMBIOS_CHASSIS_TYPE_BUS_EXPANSION_CHASSIS = 0x14,
    SMBIOS_CHASSIS_TYPE_PERIPHERAL_CHASSIS = 0x15,
    SMBIOS_CHASSIS_TYPE_RAID_CHASSIS = 0x16,
    SMBIOS_CHASSIS_TYPE_RACK_MOUNT_CHASSIS = 0x17,
    SMBIOS_CHASSIS_TYPE_SEALED_CASE_PC = 0x18,
    SMBIOS_CHASSIS_TYPE_MULTI_SYSTEM_CHASSIS = 0x19,
    SMBIOS_CHASSIS_TYPE_COMPACT_PCI = 0x1A,
    SMBIOS_CHASSIS_TYPE_ADVANCED_TCA = 0x1B,
    SMBIOS_CHASSIS_TYPE_BLADE = 0x1C,                   /* my high tech fans run darwinOS, trust me, i use remote xpc to make them change speed */
    SMBIOS_CHASSIS_TYPE_BLADE_ENCLOSURE = 0x1D,
    SMBIOS_CHASSIS_TYPE_TABLET = 0x1E,
    SMBIOS_CHASSIS_TYPE_CONVERTIBLE = 0x1F,
    SMBIOS_CHASSIS_TYPE_DETACHABLE = 0x20,
    SMBIOS_CHASSIS_TYPE_IOT_GATEWAY = 0x21,
    SMBIOS_CHASSIS_TYPE_EMBEDDED_PC= 0x22,
    SMBIOS_CHASSIS_TYPE_MINI_PC = 0x23,
    SMBIOS_CHASSIS_TYPE_STICK_PC = 0x24,                /* i feel like this was made SPECIFICALLY for the Compute Stick line. */
} smbios_chassis_type_t;

typedef enum : uint8_t {
    SMBIOS_CHASSIS_STATE_OTHER = 0x1,
    SMBIOS_CHASSIS_STATE_UNKNOWN = 0x2,
    SMBIOS_CHASSIS_STATE_SAFE = 0x3,
    SMBIOS_CHASSIS_STATE_WARNING = 0x4,
    SMBIOS_CHASSIS_STATE_CRITICAL = 0x5,
    SMBIOS_CHASSIS_STATE_NON_RECOVERABLE = 0x6,         /* must be one roughed up chassis then */
} smbios_chassis_state_t;

typedef enum : uint8_t {
    SMBIOS_CHASSIS_SECURITY_STATUS_OTHER = 0x1,
    SMBIOS_CHASSIS_SECURITY_STATUS_UNKNWON = 0x2,
    SMBIOS_CHASSIS_SECURITY_STATUS_NONE = 0x3,
    SMBIOS_CHASSIS_SECURITY_STATUS_EXTERNAL_INTERFACE_LOCKED_OUT = 0x4,
    SMBIOS_CHASSIS_SECURITY_STATUS_EXTERNAL_INTERFACE_ENABLED = 0x5,
} smbios_chassis_security_status_t;

enum {
    SMBIOS_CHASSIS_CONTAINTED_TYPE_BIT = (1 << 7),
};

typedef struct {
    uint8_t type;
    uint8_t element_min;
    uint8_t element_max;
} smios_chassis_contained_element_t;

typedef struct {
    smbios_table_header_t header;
    smbios_string_t manufacturer_name;
    smbios_chassis_type_t type;
    smbios_string_t version;
    smbios_string_t serial_number;
    smbios_string_t asset_tag_number;
    smbios_chassis_state_t boot_up_state;
    smbios_chassis_state_t power_supply_state;
    smbios_chassis_state_t thermal_state;
    smbios_chassis_security_status_t security_status;
    uint32_t vendor_field;
    uint8_t height;
    uint8_t num_power_cords;
    uint8_t num_contained_elements;
    uint8_t contained_element_size;
    smios_chassis_contained_element_t contained_elements[] __counted_by(num_contained_elements);
    // smbios_string_t sku_number;
} smbios_chassis_info_t;

#endif /* __PLATFORM_SMBIOS_TYPES_CHASSISINFO_H__ */
