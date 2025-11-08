// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_MCFG_H__
#define __PLATFORM_ACPI_TABLES_MCFG_H__

#include <platform/acpi/tables/header.h>

#define ACPI_MCFG_SIGNATURE "MCFG"

struct {
    uint64_t base_address;
    uint16_t segment;
    uint8_t start_bus_number;
    uint8_t end_bus_number;
    uint32_t reserved;
} typedef acpi_mcfg_table_entry_t;

struct {
    acpi_table_header_t header;
    uint64_t reserved;
    acpi_mcfg_table_entry_t entries[]; /*  (header.size -= sizeof(acpi_table_header_t) + 8) / sizeof(ACPI_MCFG_TABLE_ENTRY) */
} typedef acpi_mcfg_table_t;

#endif /* __PLATFORM_ACPI_TABLES_MCFG_H__ */
