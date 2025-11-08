// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_PARTITIONINFO_H__
#define __PLATFORM_EFI_PROTOCOLS_PARTITIONINFO_H__

#include <lib/types.h>
#include <platform/efi/types.h>

#define EFI_PARTITION_INFO_PROTOCOL_GUID \
    { 0x8cf2f62c, 0xbc9b, 0x4821,        \
        { 0x80, 0x8d, 0xec, 0x9e, 0xc4, 0x21, 0xa1, 0xa0 } }

extern efi_guid_t gEfiPartitionInfoProtocolGuid;

#define EFI_PARTITION_INFO_PROTOCOL_REVISION 0x0001000
#define PARTITION_TYPE_OTHER                 0x00
#define PARTITION_TYPE_MBR                   0x01
#define PARTITION_TYPE_GPT                   0x02

#define EFI_MBR_PARTITION_OSTYPE_SYSTEM_PARTITION 0xEF
#define EFI_MBR_PARTITION_OSTYPE_PMBR             0xEE

/*
 * This header was built for 64-bit architectures.
 *
 * That is to say, I have no idea how a 32-bit environment would handle my code.
 */

typedef struct {
    uint8_t boot_indicator;
    uint8_t starting_chs[3];
    uint8_t os_type;
    uint8_t ending_chs[3];
    uint32_t starting_lba;
    uint32_t ending_lba;
} __packed efi_mbr_partition_record_t;

TYPE_SIZE_CHECK(efi_mbr_partition_record_t, 16);

typedef struct {
    char boot_code[440];
    uint32_t unique_signature;
    uint16_t unknown;
    efi_mbr_partition_record_t partition_records[4];
    uint16_t signature;
} __packed efi_legacy_mbr_t;

TYPE_SIZE_CHECK(efi_legacy_mbr_t, 512);

#define EFI_GPT_PARTITION_SIG 0x5452415020494645

typedef struct {
    uint64_t signature;
    uint32_t revision;
    uint32_t header_size;
    uint32_t header_crc32;
    uint32_t reserved;
    efi_lba_t my_lba;
    efi_lba_t alt_header_lba;
    efi_lba_t first_usable_lba;
    efi_lba_t last_usable_lba;
    efi_guid_t disk_guid;
    efi_lba_t partition_entry_lba;
    uint32_t num_partition_entries;
    uint32_t partition_entry_size;
    uint32_t partition_array_crc32;
} __packed efi_gpt_header_t;

TYPE_SIZE_CHECK(efi_gpt_header_t, 92);

typedef struct {
    efi_guid_t partition_guid;
    efi_guid_t unique_partition_guid;
    efi_lba_t starting_lba;
    efi_lba_t ending_lba;
    uint64_t attrs;
    char partition_name[72];
} __packed efi_gpt_partition_entry_t;

#define EFI_GPT_PARTITION_REQUIRED_PARTITON    0x00000001
#define EFI_GPT_PARTITION_NO_BLOCK_IO          0x00000002
#define EFI_GPT_PARTITION_LEGACY_BIOS_BOOTABLE 0x00000004

TYPE_SIZE_CHECK(efi_gpt_partition_entry_t, 128);

typedef struct {
    uint32_t revision;
    uint32_t type;
    uint8_t system;
    uint8_t rsvd[7];
    union {
        efi_mbr_partition_record_t mbr;
        efi_gpt_partition_entry_t gpt;
    } info;
} __packed efi_partition_info_protocol_t;

#endif /* __PLATFORM_EFI_PROTOCOLS_PARTITIONINFO_H__ */
