// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_SIMPLEFILESYSTEM_H__
#define __PLATFORM_EFI_PROTOCOLS_SIMPLEFILESYSTEM_H__

#include <platform/efi/protocols/file.h>

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID \
    { 0x0964e5b22, 0x6459, 0x11d2,           \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern efi_guid_t gEfiSimpleFileSystemProtocolGuid;

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_REVISION 0x00010000

typedef struct _efi_simple_file_system_protocol efi_simple_file_system_protocol_t;

struct _efi_simple_file_system_protocol {
    uint64_t revision;

    efi_status_t (*open_volume)(efi_simple_file_system_protocol_t *this, efi_file_protocol_t **root);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_SIMPLEFILESYSTEM_H__ */
