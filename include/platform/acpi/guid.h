// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_GUID_H__
#define __PLATFORM_ACPI_GUID_H__

#include <stdint.h>
#include <lib/types.h>

#define EFI_ACPI_20_TABLE_GUID    \
    { 0x8868e871, 0xe4f1, 0x11d3, \
        { 0xbc, 0x22, 0x00, 0x80, 0xc7, 0x3c, 0x88, 0x81 } }

#define ACPI_TABLE_GUID           \
    { 0xeb9d2d30, 0x2d88, 0x11d3, \
        { 0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }

extern guid_t gEfiAcpiV2ConfigurationTableGuid;
extern guid_t gAcpiConfigurationTableGuid;

#endif /* __PLATFORM_ACPI_GUID_H__ */
