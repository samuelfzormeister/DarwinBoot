// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_RSDT_H__
#define __PLATFORM_ACPI_TABLES_RSDT_H__

#include <platform/acpi/tables/header.h>

#define ACPI_RSDT_SIGNATURE "RSDT"

struct {
    acpi_table_header_t header;
    uint32_t tables[];
} typedef acpi_rsdt_table_t;

#endif /* __PLATFORM_ACPI_TABLES_RSDT_H__ */
