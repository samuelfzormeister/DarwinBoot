// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_DEVICEPATHUTILITIES_H__
#define __PLATFORM_EFI_PROTOCOLS_DEVICEPATHUTILITIES_H__

#include <platform/efi/protocols/device_path.h>

#define EFI_DEVICE_PATH_UTILITIES_PROTOCOL_GUID \
    { 0x379be4e, 0xd706, 0x437d,                \
        { 0xb0, 0x37, 0xed, 0xb8, 0x2f, 0xb7, 0x72, 0xa4 } }

extern efi_guid_t gEfiDevicePathUtilitiesProtocolGuid;

typedef struct _efi_device_path_utilities_protocol efi_device_path_utilities_protocol_t;

struct _efi_device_path_utilities_protocol {
    uintn_t (*get_device_path_size)(const efi_device_path_protocol_t *device_path);
    efi_device_path_protocol_t *(*duplicate_device_path)(const efi_device_path_protocol_t *device_path);
    efi_device_path_protocol_t *(*append_device_path)(const efi_device_path_protocol_t *src1, const efi_device_path_protocol_t *src2);
    efi_device_path_protocol_t *(*append_device_node)(const efi_device_path_protocol_t *device_path, const efi_device_path_protocol_t *device_node);
    efi_device_path_protocol_t *(*append_device_path_instance)(const efi_device_path_protocol_t *device_path, const efi_device_path_protocol_t *device_node);
    efi_device_path_protocol_t *(*get_next_device_path_instance)(efi_device_path_protocol_t **device_path_instance, uintn_t *instance_size);
    bool (*is_device_path_multi_instance)(const efi_device_path_protocol_t *device_path);
    efi_device_path_protocol_t *(*create_device_node)(uint8_t type, uint8_t sub_type, uint16_t length);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_DEVICEPATHUTILITIES_H__ */
