// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_HEADER_H__
#define __PLATFORM_ACPI_TABLES_HEADER_H__

#include <stdint.h>

struct {
    char signature[4];
    uint32_t length;
    uint8_t revision;
    uint8_t checksum;
    char oem_id[6];
    char oem_table_id[8];
    uint32_t oem_revision;
    uint32_t creator_id;
    uint32_t creator_revision;
} typedef acpi_table_header_t;

#endif /* __PLATFORM_ACPI_TABLES_HEADER_H__ */
