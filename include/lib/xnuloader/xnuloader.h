// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_xnuloader_xnuloader_h_
#define __lib_xnuloader_xnuloader_h_

#include <stdbool.h>
#include <lib/types.h>
#include <platform/apple/boot_args.h>

bool xnuloader_init_with_binary(uint8_t *binary);

xnu_boot_args_t *xnuloader_get_current_args(void);

/* ... */
void xnuloader_boot_kernel_at_address_with_args(physical_address_t paddr, xnu_boot_args_t *args);

uint64_t xnuloader_get_kernel_base(void);

#endif /* __lib_xnuloader_xnuloader_h_ */
