// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_RAMDISK_H__
#define __PLATFORM_EFI_PROTOCOLS_RAMDISK_H__

#include <platform/efi/protocols/device_path.h>
#include <platform/efi/types.h>

#define EFI_RAM_DISK_PROTOCOL_GUID \
    { 0xab38a0df, 0x6873, 0x44a9,  \
        { 0x87, 0xe6, 0xd4, 0xeb, 0x56, 0x14, 0x84, 0x49 } }

extern efi_guid_t gEfiRamDiskProtocolGuid;

typedef struct _efi_ram_disk_protocol efi_ram_disk_protocol_t;

struct _efi_ram_disk_protocol {
    /* NOTE: function name is this way because of C syntax. */
    efi_status_t (*register_ramdisk)(uint64_t base, uint64_t size, efi_guid_t *type,
                                     efi_device_path_protocol_t *parent_dp, efi_device_path_protocol_t **dp);
    efi_status_t (*unregister_ramdisk)(efi_device_path_protocol_t *dp);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_RAMDISK_H__ */
