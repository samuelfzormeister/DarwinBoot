// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/efi/efi.h>
#include <lib/pal/pal.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static efi_handle_t handle;
static efi_system_table_t *st;
static efi_boot_services_t *bs;
static efi_runtime_services_t *rs;

efi_status_t efi_initialize(efi_handle_t handle, efi_system_table_t *system_table)
{
    handle = handle;
    st = system_table;
    bs = system_table->boot_services;
    rs = system_table->runtime_services;

    return EFI_SUCCESS;
}

efi_system_table_t *efi_get_system_table(void)
{
    return st;
}

efi_boot_services_t *efi_get_boot_services(void)
{
    return bs;
}
