// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_xnuloader_internal_h_
#define __lib_xnuloader_internal_h_

#include <lib/xnuloader.h>
#include <platform/apple/boot_args.h>

typedef struct xl_ctx {
    xnu_boot_args_t *args;
} *xl_ctx_t;

struct xl_dispatch_entry {
    int (*task_callback)(xl_ctx_t context);
};

extern struct xl_dispatch_entry xl_dispatch[XL_TASK_MAX];

void xl_arch_populate_dispatch(void);

#endif
