// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_TASKPRIORITYLEVEL_H__
#define __PLATFORM_EFI_TYPES_TASKPRIORITYLEVEL_H__

#include <stdint.h>

typedef uint64_t efi_tpl_t;

#define TPL_APPLICATION 4
#define TPL_CALLBACK    8
#define TPL_NOTIFY      16
#define TPL_HIGH_LEVEL  31

#endif /* __PLATFORM_EFI_TYPES_TASKPRIORITYLEVEL_H__ */
