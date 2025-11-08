// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_TIMESTAMP_H__
#define __PLATFORM_EFI_PROTOCOLS_TIMESTAMP_H__

#include <platform/efi/types.h>

#define EFI_TIMESTAMP_PROTOCOL_GUID \
    { 0xafbfde41, 0x2e6e, 0x4262,   \
        { 0xba, 0x65, 0x62, 0xb9, 0x23, 0x6e, 0x54, 0x95 } }

extern efi_guid_t gEfiTimestampProtocolGuid;

struct {
    uint64_t frequency;
    uint64_t end_value;
} typedef efi_timestamp_properties_t;

typedef struct _efi_timestamp_protocol efi_timestamp_protocol_t;

struct _efi_timestamp_protocol {
    uint64_t (*get_timestamp)(void);
    efi_status_t (*get_properties)(efi_timestamp_properties_t *Properties);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_TIMESTAMP_H__ */
