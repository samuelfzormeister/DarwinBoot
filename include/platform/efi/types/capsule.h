// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_CAPSULE_H__
#define __PLATFORM_EFI_TYPES_CAPSULE_H__

#include <platform/efi/types/address.h>
#include <platform/efi/types/guid.h>

struct {
    uint64_t length;
    union {
        efi_physical_address_t data_block;
        efi_physical_address_t continuation_pointer;
    } u;
} typedef efi_capsule_block_descriptor_t;

struct {
    efi_guid_t capsule_guid;
    uint32_t header_size;
    uint32_t flags;
    uint32_t capsule_image_size;
} typedef efi_capsule_header_t;

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET  0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET        0x00040000

#endif /* __PLATFORM_EFI_TYPES_CAPSULE_H__ */
