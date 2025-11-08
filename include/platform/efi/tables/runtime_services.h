// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_RUNTIMESERVICES_H__
#define __PLATFORM_EFI_TABLES_RUNTIMESERVICES_H__

#include <platform/efi/tables/header.h>
#include <platform/efi/types.h>

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION  EFI_SPECIFICATION_VERSION

enum {
    EFI_VARIABLE_NON_VOLATILE = 0x00000001,
    EFI_VARIABLE_BOOTSERVICE_ACCESS = 0x00000002,
    EFI_VARIABLE_RUNTIME_ACCESS = 0x00000004,
    EFI_VARIABLE_HARDWARE_ERROR_RECORD = 0x00000008,
    EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS = 0x00000020,
    EFI_VARIABLE_APPEND_WRITE = 0x00000040,
    EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS = 0x00000080,
};

struct _efi_runtime_services {
    efi_table_header_t header;

    efi_status_t (*get_time)(efi_time_t *time, efi_time_capabilities_t *capabilities);
    efi_status_t (*set_time)(efi_time_t *time);
    efi_status_t (*get_wakeup_time)(bool *enabled, bool *pending, efi_time_t *time);
    efi_status_t (*set_wakeup_time)(bool enabled, efi_time_t *time);

    efi_status_t (*set_virtual_address_map)(uintn_t map_size, uintn_t desc_size, uint32_t desc_version, efi_memory_descriptor_t *VirtualMap);
    efi_status_t (*convert_pointer)(uintn_t dbg_dispos, void **address);

    efi_status_t (*get_variable)(wchar_t *var_name, efi_guid_t *ven_guid, uint32_t *attrs, uintn_t *data_size, void *data);
    efi_status_t (*get_next_variable_name)(uintn_t *var_name_size, wchar_t *var_name, efi_guid_t *ven_guid);
    efi_status_t (*set_variable)(wchar_t *var_name, efi_guid_t *ven_guid, uint32_t attrs, uintn_t data_size, void *data);

    efi_status_t (*get_next_high_monotonic_count)(uint32_t *high_count);
    void (*reset_system)(efi_reset_type_t type, efi_status_t status, uintn_t data_size, void *data);

    efi_status_t (*update_capsule)(efi_capsule_header_t **capsule_header_array, uintn_t capsule_count, efi_physical_address_t sg_list);
    efi_status_t (*query_capsule_capabilities)(efi_capsule_header_t **capsule_header_array,
                                               uintn_t count,
                                               uint64_t *max_cap_size,
                                               efi_reset_type_t *ResetType);

    efi_status_t (*query_variable_info)(uint32_t attrs, uint64_t *max_storage_size, uint64_t *size_remaining, uint64_t *max_var_size);
} typedef efi_runtime_services_t;

#define EFI_OPTIONAL_PTR 0x00000001

#endif /* __PLATFORM_EFI_TABLES_RUNTIMESERVICES_H__ */
