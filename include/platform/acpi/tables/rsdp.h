// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_RSDP_H__
#define __PLATFORM_ACPI_TABLES_RSDP_H__

#include <stdint.h>

#define ACPI_RSDP_SIGNATURE "RSD PTR "

struct {
    char signature[8];
    uint8_t checksum;
    char oem_id[6];
    uint8_t revision;
    uint32_t rsdt_address;
} typedef acpi_rsdp_table_t;

struct {
    char signature[8];
    uint8_t checksum;
    char oem_id[6];
    uint8_t revision;
    uint32_t rsdt_address;
    uint32_t length;
    uint64_t xsdt_address;
    uint8_t extended_checksum;
    uint8_t reserved[3];
} typedef acpi_xsdp_table_t;

#endif /* __PLATFORM_ACPI_TABLES_RSDP_H__ */
