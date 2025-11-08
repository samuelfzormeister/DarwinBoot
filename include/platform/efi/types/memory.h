// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_MEMORY_H__
#define __PLATFORM_EFI_TYPES_MEMORY_H__

#include <stdint.h>
#include <platform/efi/types/address.h>

typedef enum {
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} efi_allocate_type_t;

typedef enum {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
} efi_memory_type_t;

struct {
    uint32_t type;
    efi_physical_address_t physical_start;
    efi_virtual_address_t virtual_start;
    uint64_t number_of_pages;
    uint64_t attribute;
} typedef efi_memory_descriptor_t;

/* Cache Attrs */
#define EFI_MEMORY_UC  (1 << 0)
#define EFI_MEMORY_WC  (1 << 1)
#define EFI_MEMORY_WT  (1 << 2)
#define EFI_MEMORY_WB  (1 << 3)
#define EFI_MEMORY_UCE (1 << 4)
/* Memory Prot. Attrs*/
#define EFI_MEMORY_WP            (1 << 12)
#define EFI_MEMORY_RP            (1 << 13)
#define EFI_MEMORY_XP            (1 << 14)
#define EFI_MEMORY_NV            (1 << 15)
#define EFI_MEMORY_MORE_RELIABLE (1 << 16)
#define EFI_MEMORY_RO            (1 << 17)
#define EFI_MEMORY_SP            (1 << 18)
#define EFI_MEMORY_CPU_CRYPTO    (1 << 19)
#define EFI_MEMORY_RUNTIME       (1 << 63)
#define EFI_MEMORY_ISA_VALID     (1 << 62)
#define EFI_MEMORY_ISA_MASK      (1 << 44) | (1 << 45) | (1 << 46) | (1 << 47) | (1 << 48) | (1 << 49) | (1 << 50) | (1 << 51) | (1 << 52) | (1 << 53) | (1 << 54) | (1 << 55) | (1 << 56) | (1 << 57) | (1 << 58) | (1 << 59)

#endif /* __PLATFORM_EFI_TYPES_MEMORY_H__ */
