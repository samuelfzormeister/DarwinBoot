// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_SYSTEMTABLE_H__
#define __PLATFORM_EFI_TABLES_SYSTEMTABLE_H__

#include <platform/efi/protocols/simple_text.h>
#include <platform/efi/tables/boot_services.h>
#include <platform/efi/tables/configuration_table.h>
#include <platform/efi/tables/runtime_services.h>

#define EFI_SYSTEM_TABLE_SIGNATURE      0x5453595320494249
#define EFI_2_110_SYSTEM_TABLE_REVISION ((2 << 16) | (110))
#define EFI_2_100_SYSTEM_TABLE_REVISION ((2 << 16) | (100))
#define EFI_2_90_SYSTEM_TABLE_REVISION  ((2 << 16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION  ((2 << 16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION  ((2 << 16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION  ((2 << 16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION  ((2 << 16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION  ((2 << 16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION  ((2 << 16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION  ((2 << 16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION  ((2 << 16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION  ((2 << 16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION  ((2 << 16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION  ((1 << 16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION  ((1 << 16) | (02))
#define EFI_SPECIFICATION_VERSION       EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION       EFI_2_110_SYSTEM_TABLE_REVISION

struct _efi_system_table {
    efi_table_header_t header;
    wchar_t *firmware_vendor;
    uint32_t firmware_revision;
    efi_handle_t con_in_handle;
    efi_simple_text_input_protocol_t *con_in;
    efi_handle_t con_out_handle;
    efi_simple_text_output_protocol_t *con_out;
    efi_handle_t standard_error_handle;
    efi_simple_text_output_protocol_t *std_err;
    efi_runtime_services_t *runtime_services;
    efi_boot_services_t *boot_services;
    uint32_t num_configuration_tables;
    efi_configuration_table_t *configuration_tables;
} typedef efi_system_table_t;

#endif /* __PLATFORM_EFI_TABLES_SYSTEMTABLE_H__ */
