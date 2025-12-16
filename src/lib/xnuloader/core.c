// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/xnuloader.h>
#include "internal.h"

/*
 * DISPATCH TABLE!!!
 */

struct xl_dispatch_entry xl_dispatch[XL_TASK_MAX];

void xl_init(void)
{
    xl_arch_populate_dispatch();
}
