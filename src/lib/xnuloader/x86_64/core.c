// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/cms.h>
#include <lib/xnuloader.h>
#include "../internal.h"

static int xl_x86_init(xl_ctx_t ctx)
{
    ctx->args = cms_allocate_memory(sizeof(xnu_boot_args_t));

    return 0;
}

void xl_arch_populate_dispatch(void)
{
    xl_dispatch[XL_TASK_INIT].task_callback = &xl_x86_init;
}
