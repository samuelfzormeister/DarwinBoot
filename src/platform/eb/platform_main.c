// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/config.h>
#include <soc/soc.h>

/* called by _start */
void platform_main(void)
{
    /* let the soc code decide what drivers to load and how. */
    soc_init();
}
