// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_NETWORK_H__
#define __PLATFORM_EFI_TYPES_NETWORK_H__

#include <stdint.h>

struct {
    uint8_t address[32];
} typedef efi_mac_address_t;

struct {
    uint8_t address[4];
} typedef efi_ipv4_address_t;

struct {
    uint8_t address[16];
} typedef efi_ipv6_address_t;

union {
    efi_ipv4_address_t ipv4;
    efi_ipv6_address_t ipv6;
} typedef efi_ip_address_t;

#endif /* __PLATFORM_EFI_TYPES_NETWORK_H__ */
