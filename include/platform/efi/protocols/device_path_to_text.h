// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_DEVICEPATHTOTEXT_H__
#define __PLATFORM_EFI_PROTOCOLS_DEVICEPATHTOTEXT_H__

#include <platform/efi/protocols/device_path.h>
#include <platform/efi/types.h>

#define EFI_DEVICE_PATH_TO_TEXT_PROTOCOL_GUID \
    { 0x8b843e20, 0x8132, 0x4852,             \
        { 0x90, 0xcc, 0x55, 0x1a, 0x4e, 0x4a, 0x7f, 0x1c } }

extern efi_guid_t gEfiDevicePathToTextProtocolGuid;

typedef struct _efi_device_path_to_text_protocol efi_device_path_to_text_protocol_t;

struct _efi_device_path_to_text_protocol {
    wchar_t *(*convert_device_node_to_text)(const efi_device_path_protocol_t *node, bool display_only, bool allow_shortcuts);
    wchar_t *(*convert_device_path_to_text)(const efi_device_path_protocol_t *node, bool display_only, bool allow_shortcuts);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_DEVICEPATHTOTEXT_H__ */
