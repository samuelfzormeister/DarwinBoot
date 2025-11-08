// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_BGRT_H__
#define __PLATFORM_ACPI_TABLES_BGRT_H__

#include <platform/acpi/tables/header.h>

#define ACPI_BGRT_SIGNATURE "BGRT"

struct {
    acpi_table_header_t header;
    uint32_t version;
    uint8_t status;
    uint8_t image_type;
    uint64_t image_address;
    uint32_t image_x;
    uint32_t image_y;
} typedef acpi_bgrt_table_t;

#endif /* __PLATFORM_ACPI_TABLES_BGRT_H__ */
