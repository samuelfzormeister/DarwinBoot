// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_BLOCKIO_H__
#define __PLATFORM_EFI_PROTOCOLS_BLOCKIO_H__

#include <platform/efi/types.h>

#define EFI_BLOCK_IO_PROTOCOL_GUID \
    { 0x964e5b21, 0x6459, 0x11d2,  \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern efi_guid_t gEfiBlockIoProtocolGuid;

#define EFI_BLOCK_IO_PROTOCOL_REVISION2 0x00020001
#define EFI_BLOCK_IO_PROTOCOL_REVISION3 ((2 << 16) | (31))

struct {
    uint32_t media_id;
    bool is_removable;
    bool is_present;
    bool is_logical_partition;
    bool is_read_only;
    bool is_write_caching;
    uint32_t block_size;
    uint32_t io_alignment;
    efi_lba_t last_block;

    /* Revision 2 data */
    efi_lba_t lowest_aligned_lba;
    uint32_t logical_per_physical_blocks;

    /* Revision 3 data */
    uint32_t optimal_transfer_length_granularity;
} typedef efi_block_io_media_t;

typedef struct _efi_block_io_protocol efi_block_io_protocol_t;

struct _efi_block_io_protocol {
    uint64_t revision;
    efi_block_io_media_t *media;

    efi_status_t (*reset)(efi_block_io_protocol_t *this, bool extended_verif);
    efi_status_t (*read_blocks)(efi_block_io_protocol_t *this, uint32_t media_id, efi_lba_t lba, uintn_t buf_size, void *buf);
    efi_status_t (*write_blocks)(efi_block_io_protocol_t *this, uint32_t media_id, efi_lba_t lba, uintn_t buf_size, void *buf);
    efi_status_t (*flush_all_blocks)(efi_block_io_protocol_t *this);
};

/* Block I/O 2 stuff */

#define EFI_BLOCK_IO2_PROTOCOL_GUID \
    { 0xa77b2472, 0xe282, 0x4e9f,   \
        { 0xa2, 0x45, 0xc2, 0xc0, 0xe2, 0x7b, 0xbc, 0xc1 } }

extern efi_guid_t gEfiBlockIo2ProtocolGuid;

struct {
    efi_event_t event;
    efi_status_t transaction_status;
} typedef efi_block_io2_token_t;

typedef struct _efi_block_io2_protocol efi_block_io2_protocol_t;

struct _efi_block_io2_protocol {
    efi_block_io_media_t *media;

    efi_status_t (*reset)(efi_block_io2_protocol_t *this, bool extended_verif);
    efi_status_t (*read_blocks)(efi_block_io2_protocol_t *this, uint32_t media_id,
                                efi_lba_t lba, efi_block_io2_token_t *token, uintn_t buf_size, void *buf);
    efi_status_t (*write_blocks)(efi_block_io2_protocol_t *this, uint32_t media_id,
                                 efi_lba_t lba, efi_block_io2_token_t *token, uintn_t buf_size, void *buf);
    efi_status_t (*flush_all_blocks)(efi_block_io2_protocol_t *this, efi_block_io2_token_t *token);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_BLOCKIO_H__ */
