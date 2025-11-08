// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_CONFIGURATIONTABLE_H__
#define __PLATFORM_EFI_TABLES_CONFIGURATIONTABLE_H__

#include <platform/efi/types.h>

typedef struct _efi_configuration_table efi_configuration_table_t;

struct _efi_configuration_table {
    efi_guid_t ven_guid;
    void *ven_tbl;
};

#endif /* __PLATFORM_EFI_TABLES_CONFIGURATIONTABLE_H__ */
