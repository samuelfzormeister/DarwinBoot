// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/pal/pal.h>
#include <lib/config.h>

const char *__payload_name = CURRENT_PAYLOAD;

void app_main()
{
    pal_log(PAL_LOG_LEVEL_INFO, "boot", "we're live!");
    while (1) {
        int i = 0;
        i++;
    }
}
