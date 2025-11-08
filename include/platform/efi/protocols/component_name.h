// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_COMPONENTNAME_H__
#define __PLATFORM_EFI_PROTOCOLS_COMPONENTNAME_H__

#include <platform/efi/types.h>

#define EFI_COMPONENT_NAME2_PROTOCOL_GUID \
    { 0x6a7a5cff, 0xe8d9, 0x4f70,         \
        { 0xba, 0xda, 0x75, 0xab, 0x30, 0x25, 0xce, 0x14 } }

extern efi_guid_t gEfiComponentName2ProtocolGuid;

typedef struct _efi_component_name2_protocol efi_component_name2_protocol_t;

struct _efi_component_name2_protocol {
    efi_status_t (*get_driver_name)(efi_component_name2_protocol_t *this, const char *language, wchar_t **driver_name);
    efi_status_t (*get_controller_name)(efi_component_name2_protocol_t *this, efi_handle_t controller_handle,
        efi_handle_t child_handle, const char *language, wchar_t **driver_name);
    const char *supported_languages;
};

#endif /* __PLATFORM_EFI_PROTOCOLS_COMPONENTNAME_H__ */
