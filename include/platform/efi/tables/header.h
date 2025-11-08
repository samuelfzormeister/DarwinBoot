// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_HEADER_H__
#define __PLATFORM_EFI_TABLES_HEADER_H__

#include <platform/efi/types.h>

struct _efi_table_header {
    uint64_t signature;
    uint32_t revision;
    uint32_t header_size;
    uint32_t crc32;
    uint32_t reserved;
};
typedef struct _efi_table_header efi_table_header_t;

#endif /* __PLATFORM_EFI_TABLES_HEADER_H__ */
