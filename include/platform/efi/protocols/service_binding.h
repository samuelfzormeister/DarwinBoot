// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_SERVICEBINDING_H__
#define __PLATFORM_EFI_PROTOCOLS_SERVICEBINDING_H__

#include <platform/efi/types.h>

/* The Service Binding protocol is an abstract interface. No GUID for it. */

typedef struct _efi_service_binding_protocol efi_service_binding_protocol_t;

struct _efi_service_binding_protocol {
    efi_status_t (*create_child)(efi_service_binding_protocol_t *this, efi_handle_t *child);
    efi_status_t (*destroy_child)(efi_service_binding_protocol_t *this, efi_handle_t *child);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_SERVICEBINDING_H__ */
