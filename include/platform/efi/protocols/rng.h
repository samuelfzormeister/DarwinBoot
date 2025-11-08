// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_RNG_H__
#define __PLATFORM_EFI_PROTOCOLS_RNG_H__

#include <platform/efi/types.h>

#define EFI_RNG_PROTOCOL_GUID     \
    { 0x3152bca5, 0xeade, 0x433d, \
        { 0x86, 0x2e, 0xc0, 0x1c, 0xdc, 0x29, 0x1f, 0x44 } }

extern efi_guid_t gEfiRngProtocolGuid;

typedef efi_guid_t efi_rng_algorithm_t;

#define EFI_RNG_ALGORITHM_SP800_90_HASH_256_GUID \
    { 0xa7af67cb, 0x603b, 0x4d42,                \
        { 0xba, 0x21, 0x70, 0xbf, 0xb6, 0x29, 0x3f, 0x96 } }

#define EFI_RNG_ALGORITHM_SP800_90_HMAC_256_GUID \
    { 0xc5149b43, 0xae85, 0x4f53,                \
        { 0x99, 0x82, 0xb9, 0x43, 0x35, 0xd3, 0xa9, 0xe7 } }

#define EFI_RNG_ALGORITHM_SP800_90_CTR_256_GUID \
    { 0x44f0de6e, 0x4d8c, 0x4045,               \
        { 0xa8, 0xc7, 0x4d, 0xd1, 0x68, 0x85, 0x6b, 0x9e } }

#define EFI_RNG_ALGORITHM_X9_31_3DES_GUID \
    { 0x63c4785a, 0xca34, 0x4012,         \
        { 0xa3, 0xc8, 0x0b, 0x6a, 0x32, 0x4f, 0x55, 0x46 } }

#define EFI_RNG_ALGORITHM_X9_31_AES_GUID \
    { 0xacd03321, 0x777e, 0x4d3d,        \
        { 0xb1, 0xc8, 0x20, 0xcf, 0xd8, 0x88, 0x20, 0xc9 } }

#define EFI_RNG_ALGORITHM_RAW     \
    { 0xe43176d7, 0xb6e8, 0x4827, \
        { 0xb7, 0x84, 0x7f, 0xfd, 0xc4, 0xb6, 0x85, 0x61 } }

typedef struct _efi_rng_protocol efi_rng_protocol_t;

struct _efi_rng_protocol {
    efi_status_t (*get_info)(efi_rng_protocol_t *This, uintn_t *algorithm_list_size, efi_rng_algorithm_t *algorithm_list);
    efi_status_t (*get_rng)(efi_rng_protocol_t *This, efi_rng_algorithm_t algoritm, uintn_t out_len, uint8_t *out);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_RNG_H__ */
