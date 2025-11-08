// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_MISC_H__
#define __PLATFORM_EFI_TYPES_MISC_H__

#include <lib/types.h>
#include <platform/efi/types/handle.h>

typedef enum {
    TimerCancel,
    TimerPeriodic,
    TimerRelative,
} efi_timer_delay_t;

typedef enum {
    EFI_NATIVE_INTERFACE
} efi_interface_type_t;

typedef enum {
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} efi_locate_search_type_t;

struct {
    efi_handle_t agent_handle;
    efi_handle_t controller_handle;
    uint32_t attributes;
    uint32_t open_count;
} typedef efi_open_protocol_information_entry_t;

enum {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} typedef efi_reset_type_t;

/*
 * FIXME: The __counted_by invocation is ignored by clang.
 */
struct {
    uint8_t type;
    uint32_t id_size;
    uint8_t id[] __counted_by(id_size);
} typedef efi_variable_authentication_3_cert_id_t;

#endif /* __PLATFORM_EFI_TYPES_MISC_H__ */
