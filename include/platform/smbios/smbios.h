// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_SMBIOS_H__
#define __PLATFORM_SMBIOS_SMBIOS_H__

#include <lib/types.h>

#define SMBIOS_TABLE_GUID         \
    { 0xeb9d2d31, 0x2d88, 0x11d3, \
        { 0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }

#define SMBIOS3_TABLE_GUID        \
    { 0xf2fd1544, 0x9794, 0x4a2c, \
        { 0x99, 0x2e, 0xe5, 0xbb, 0xcf, 0x20, 0xe3, 0x94 } }

#include <platform/smbios/types/firmware_info.h>
#include <platform/smbios/types/system_info.h>
#include <platform/smbios/types/baseboard_info.h>
#include <platform/smbios/types/chassis_info.h>
#include <platform/smbios/types/processor_info.h>

#endif /* __PLATFORM_SMBIOS_SMBIOS_H__ */
