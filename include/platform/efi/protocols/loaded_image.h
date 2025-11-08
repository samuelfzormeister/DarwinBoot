// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_LOADEDIMAGE_H__
#define __PLATFORM_EFI_PROTOCOLS_LOADEDIMAGE_H__

#include <platform/efi/protocols/device_path.h>
#include <platform/efi/tables.h>
#include <platform/efi/types.h>

#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
    { 0x5B1B31A1, 0x9562, 0x11D2,      \
        { 0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }

#define EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL_GUID \
    { 0xbc62157e, 0x3e33, 0x4fec,                  \
        { 0x99, 0x20, 0x2d, 0x3b, 0x36, 0xd7, 0x50, 0xdf } }

extern efi_guid_t gEfiLoadedImageProtocolGuid;

extern efi_guid_t gEfiLoadedImageDevicePathProtocolGuid;

#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000

typedef struct _efi_loaded_image_protocol efi_loaded_image_protocol_t;

struct _efi_loaded_image_protocol {
    uint32_t revision;
    efi_handle_t parent_handle;
    efi_system_table_t *system_table;
    efi_handle_t device_handle;
    efi_device_path_protocol_t *file_path;
    void *reserved;
    uint32_t load_options_size;
    void *load_options;
    void *image_base;
    uint64_t image_size;
    efi_memory_type_t image_code_type;
    efi_memory_type_t image_data_type;
    efi_status_t (*unload)(efi_loaded_image_protocol_t *this);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_LOADEDIMAGE_H__ */
