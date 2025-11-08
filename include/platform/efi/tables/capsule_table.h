// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_CAPSULETABLE_H__
#define __PLATFORM_EFI_TABLES_CAPSULETABLE_H__

#include <platform/efi/types.h>

struct {
    uint32_t num_capsules;
    efi_capsule_header_t *capsules[] __counted_by(num_capsules);
} typedef efi_capsule_table_t;

#endif /* __PLATFORM_EFI_TABLES_CAPSULETABLE_H__ */
