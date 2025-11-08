// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_LOADFILE_H__
#define __PLATFORM_EFI_PROTOCOLS_LOADFILE_H__

#include <platform/efi/protocols/device_path.h>
#include <platform/efi/types.h>

#define EFI_LOAD_FILE_PROTOCOL_GUID \
    { 0x56EC3091, 0x954C, 0x11d2,   \
        { 0x8e, 0x3f, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern efi_guid_t gEfiLoadFileProtocolGuid;

typedef struct _efi_load_file_protocol efi_load_file_protocol_t;

struct _efi_load_file_protocol {
    efi_status_t (*load_file)(efi_load_file_protocol_t *this, efi_device_path_protocol_t *Path,
                              bool boot_policy, uintn_t *buf_size, void *buf);
};

#define EFI_LOAD_FILE2_PROTOCOL_GUID \
    { 0x4006c0c1, 0xfcb3, 0x403e,    \
        { 0x99, 0x6d, 0x4a, 0x6c, 0x87, 0x24, 0xe0, 0x6d } }

extern efi_guid_t gEfiLoadFile2ProtocolGuid;

typedef efi_load_file_protocol_t efi_load_file2_protocol_t;

#endif /* __PLATFORM_EFI_PROTOCOLS_LOADFILE_H__ */
