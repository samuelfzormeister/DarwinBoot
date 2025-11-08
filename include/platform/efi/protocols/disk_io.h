// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_DISKIO_H__
#define __PLATFORM_EFI_PROTOCOLS_DISKIO_H__

#include <platform/efi/types.h>

#define EFI_DISK_IO_PROTOCOL_GUID \
    { 0xCE345171, 0xBA0B, 0x11d2, \
        { 0x8e, 0x4F, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern efi_guid_t gEfiDiskIoProtocolGuid;

#define EFI_DISK_IO_PROTOCOL_REVISION 0x00010000

typedef struct _efi_disk_io_protocol efi_disk_io_protocol_t;

struct _efi_disk_io_protocol {
    uint64_t revision;
    efi_status_t (*read_disk)(efi_disk_io_protocol_t *this, uint32_t media_id, uint64_t offset, uintn_t buf_size, void *buf);
    efi_status_t (*write_disk)(efi_disk_io_protocol_t *this, uint32_t media_id, uint64_t offset, uintn_t buf_size, void *buf);
};

#define EFI_DISK_IO2_PROTOCOL_GUID \
    { 0x151c8eae, 0x7f2c, 0x472c,  \
        { 0x9e, 0x54, 0x98, 0x28, 0x19, 0x4f, 0x6a, 0x88 } }

extern efi_guid_t gEfiDiskIo2ProtocolGuid;

typedef struct {
    efi_event_t event;
    efi_status_t transaction_status;
} efi_disk_io2_token_t;

#define EFI_DISK_IO2_PROTOCOL_REVISION 0x00020000

typedef struct _efi_disk_io2_protocol efi_disk_io2_protocol_t;

struct _EFI_DISK_IO2_PROTOCOL {
    uint64_t revision;
    efi_status_t (*cancel)(efi_disk_io2_protocol_t *this);
    efi_status_t (*read_disk_ex)(efi_disk_io2_protocol_t *this, uint32_t media_id,
                                 uint64_t offset, efi_disk_io2_token_t *token, uintn_t buf_size, void *buf);
    efi_status_t (*write_disk_ex)(efi_disk_io2_protocol_t *this, uint32_t media_id,
                                  uint64_t offset, efi_disk_io2_token_t *token, uintn_t buf_size, void *buf);
    efi_status_t (*flush_disk_ex)(efi_disk_io2_protocol_t *this, efi_disk_io2_token_t *token);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_DISKIO_H__ */
