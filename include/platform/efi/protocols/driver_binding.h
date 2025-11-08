// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_DRIVERBINDING_H__
#define __PLATFORM_EFI_PROTOCOLS_DRIVERBINDING_H__

#include <platform/efi/protocols/device_path.h>

#define EFI_DRIVER_BINDING_PROTOCOL_GUID \
    { 0x18A031AB, 0xB443, 0x4D1A,        \
        { 0xA5, 0xC0, 0x0C, 0x09, 0x26, 0x1E, 0x9F, 0x71 } }

extern efi_guid_t gEfiDriverBindingProtocolGuid;

typedef struct _efi_driver_binding_protocol efi_driver_binding_protocol_t;

struct _efi_driver_binding_protocol {
    efi_status_t (*supported)(efi_driver_binding_protocol_t *this, efi_handle_t controller_handle, efi_device_path_protocol_t *remaining_dp);
    efi_status_t (*start)(efi_driver_binding_protocol_t *this, efi_handle_t controller_handle, efi_device_path_protocol_t *remaining_dp);
    efi_status_t (*stop)(efi_driver_binding_protocol_t *this, efi_handle_t controller_handle, uintn_t *num_children, efi_handle_t *child_handle_buffer);
    uint32_t version;
    efi_handle_t image_handle;
    efi_handle_t driver_binding_handle;
};

#endif /* __PLATFORM_EFI_PROTOCOLS_DRIVERBINDING_H__ */
