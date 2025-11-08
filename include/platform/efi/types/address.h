// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_ADDRESS_H__
#define __PLATFORM_EFI_TYPES_ADDRESS_H__

#include <lib/types.h>

/* 128-bit? */
typedef uint64_t efi_lba_t;

typedef uintn_t efi_physical_address_t;
typedef uintn_t efi_virtual_address_t;

#endif /* __PLATFORM_EFI_TYPES_ADDRESS_H__ */
