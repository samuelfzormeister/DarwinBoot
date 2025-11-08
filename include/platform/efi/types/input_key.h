// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_INPUTKEY_H__
#define __PLATFORM_EFI_TYPES_INPUTKEY_H__

#include <stdint.h>

struct {
    uint16_t scan_code;
    int16_t unicode_char;
} typedef efi_input_key_t;

#endif /* __PLATFORM_EFI_TYPES_INPUTKEY_H__ */
