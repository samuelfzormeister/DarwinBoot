// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_HASH_H__
#define __PLATFORM_EFI_PROTOCOLS_HASH_H__

#include <platform/efi/types.h>

#define EFI_HASH_ALGORITHM_SHA1_GUID \
    { 0x2ae9d80f, 0x3fb2, 0x4095,    \
        { 0xb7, 0xb1, 0xe9, 0x31, 0x57, 0xb9, 0x46, 0xb6 } }

#define EFI_HASH_ALGORITHM_SHA224_GUID \
    { 0x8df01a06, 0x9bd5, 0x4bf7,      \
        { 0xb0, 0x21, 0xdb, 0x4f, 0xd9, 0xcc, 0xf4, 0x5b } }

#define EFI_HASH_ALGORITHM_SHA256_GUID \
    { 0x51aa59de, 0xfdf2, 0x4ea3,      \
        { 0xbc, 0x63, 0x87, 0x5f, 0xb7, 0x84, 0x2e, 0xe9 } }

#define EFI_HASH_ALGORITHM_SHA384_GUID \
    { 0xefa96432, 0xde33, 0x4dd2,      \
        { 0xae, 0xe6, 0x32, 0x8c, 0x33, 0xdf, 0x77, 0x7a } }

#define EFI_HASH_ALGORITHM_SHA512_GUID \
    { 0xcaa4381e, 0x750c, 0x4770,      \
        { 0xb8, 0x70, 0x7a, 0x23, 0xb4, 0xe4, 0x21, 0x30 } }

#define EFI_HASH_ALGORITHM_MD5_GUID \
    { 0xaf7c79c, 0x65b5, 0x4319,    \
        { 0xb0, 0xae, 0x44, 0xec, 0x48, 0x4e, 0x4a, 0xd7 } }

#define EFI_HASH_SERVICE_BINDING_PROTOCOL_GUID \
    { 0x42881c98, 0xa4f3, 0x44b0,              \
        { 0xa3, 0x9d, 0xdf, 0xa1, 0x86, 0x67, 0xd8, 0xcd } }

#define EFI_HASH_PROTOCOL_GUID    \
    { 0xc5184932, 0xdba5, 0x46db, \
        { 0xa5, 0xba, 0xcc, 0x0b, 0xda, 0x9c, 0x14, 0x35 } }

extern efi_guid_t gEfiHashServiceBindingProtocolGuid;
extern efi_guid_t gEfiHashProtocolGuid;

extern efi_guid_t gEfiHashAlgorithmSha1Guid;
extern efi_guid_t gEfiHashAlgorithmSha224Guid;
extern efi_guid_t gEfiHashAlgorithmSha256Guid;
extern efi_guid_t gEfiHashAlgorithmSha384Guid;
extern efi_guid_t gEfiHashAlgorithmSha512Guid;
extern efi_guid_t gEfiHashAlgorithmMd5Guid;

typedef uint8_t efi_md5_hash_t[16];
typedef uint8_t efi_sha1_hash_t[20];
typedef uint8_t efi_sha224_hash_t[28];
typedef uint8_t efi_sha256_hash_t[32];
typedef uint8_t efi_sha384_hash_t[48];
typedef uint8_t efi_sha512_hash_t[64];

typedef union {
    efi_md5_hash_t *md5_hash;
    efi_sha1_hash_t *sha1_hash;
    efi_sha224_hash_t *sha224_hash;
    efi_sha256_hash_t *sha256_hash;
    efi_sha384_hash_t *sha384_hash;
    efi_sha512_hash_t *sha512_hash;
} efi_hash_output_t;

typedef struct _efi_hash_protocol efi_hash_protocol_t;

struct _efi_hash_protocol {
    efi_status_t (*get_hash_size)(const efi_hash_protocol_t *this, const efi_guid_t *guid, uintn_t *size);
    efi_status_t (*hash)(const efi_hash_protocol_t *this, const efi_guid_t *guid, bool extend,
                         const uint8_t *msg, uint64_t msg_len, efi_hash_output_t *Hash);
};

#define EFI_HASH2_SERVICE_BINDING_PROTOCOL_GUID \
    { 0xda836f8d, 0x217f, 0x4ca0,               \
        { 0x99, 0xc2, 0x1c, 0xa4, 0xe1, 0x60, 0x77, 0xea } }

#define EFI_HASH2_PROTOCOL_GUID   \
    { 0x55b1d734, 0xc5e1, 0x49db, \
        { 0x96, 0x47, 0xb1, 0x6a, 0xfb, 0xe, 0x30, 0x5b } }

extern efi_guid_t gEfiHash2ServiceBindingProtocolGuid;
extern efi_guid_t gEfiHash2ProtocolGuid;

typedef uint8_t efi_md5_hash2_t[16];
typedef uint8_t efi_sha1_hash2_t[20];
typedef uint8_t efi_sha224_hash2_t[28];
typedef uint8_t efi_sha256_hash2_t[32];
typedef uint8_t efi_sha384_hash2_t[48];
typedef uint8_t efi_sha512_hash2_t[64];

typedef union {
    efi_md5_hash2_t md5_hash;
    efi_sha1_hash2_t sha1_hash;
    efi_sha224_hash2_t sha224_hash;
    efi_sha256_hash2_t sha256_hash;
    efi_sha384_hash2_t sha384_hash;
    efi_sha512_hash2_t sha512_hash;
} efi_hash2_output_t;

typedef struct _efi_hash2_protocol efi_hash2_protocol_t;

struct _efi_hash2_protocol {
    efi_status_t (*get_hash_size)(const efi_hash2_protocol_t *this, const efi_guid_t *algorithm, uintn_t *size);
    efi_status_t (*hash)(const efi_hash2_protocol_t *this, const efi_guid_t *algorithm, const uint8_t *msg,
                         uint64_t msg_size, efi_hash2_output_t *hash);
    efi_status_t (*hash_init)(const efi_hash2_protocol_t *this, const efi_guid_t *algorithm);
    efi_status_t (*hash_update)(const efi_hash2_protocol_t *this, const uint8_t *msg, uint64_t msg_size);
    efi_status_t (*hash_final)(const efi_hash2_protocol_t *this, const efi_hash2_output_t *hash);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_HASH_H__ */
