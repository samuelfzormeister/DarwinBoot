// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_XSDT_H__
#define __PLATFORM_ACPI_TABLES_XSDT_H__

#include <platform/acpi/tables/header.h>

#define ACPI_XSDT_SIGNATURE "XSDT"

struct {
    acpi_table_header_t header;
    uint64_t tables[];
} typedef acpi_xsdt_table_t;

#endif
