// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_MEMORYATTRIBUTESTABLE_H__
#define __PLATFORM_EFI_TABLES_MEMORYATTRIBUTESTABLE_H__

#include <platform/efi/types.h>

#define EFI_MEMORY_ATTRIBUTES_TABLE_GUID \
    { 0xdcfa911d, 0x26eb, 0x469f,        \
        { 0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20 } }

struct {
    uint32_t version;
    uint32_t num_entries;
    uint32_t descriptor_size;
    uint32_t flags;
    efi_memory_descriptor_t Descriptors[];
} typedef efi_memory_attributes_table_t;

#define EFI_MEMORY_ATTRIBUTES_FLAGS_RT_FORWARD_CONTROL_FLOW_GUARD 0x1

#endif /* __PLATFORM_EFI_TABLES_MEMORYATTRIBUTESTABLE_H__ */
