// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/platform.h>
#include <lib/efi.h>
#include <lib/pal/pal.h>
#include <lib/secureboot.h>

#define DEFAULT_CPID_AA64   0xAA64 // aarch64
#define DEFAULT_CPID_X86_64 0x8664 // x86-64
#define DEFAULT_CPID_I386   0x1386 // i386

#if TARGET_CPU_X86_64
#define DEFAULT_CPID DEFAULT_CPID_X86_64
#endif

const sb_identity_t default_sb_identity = {
    .cpid = DEFAULT_CPID,
    .bord = 0,
    .ecid = 0,
};

efi_status_t platform_main(efi_handle_t hndl, efi_system_table_t *system_table) {
    if (efi_initialize(hndl, system_table) == EFI_SUCCESS) {
        sb_init(&default_sb_identity, SB_POLICY_FULL);
        pal_send_boot_message();
        app_main();
        return EFI_SUCCESS;
    }

    return EFI_ABORTED;
}
