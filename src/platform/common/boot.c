// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <stdio.h>
#include <lib/pal/pal.h>
#include <lib/sb/sb.h>
#include <lib/config.h>

const char boot_msg_fmt[] = {
    "=======================================\n"
    "::\n"
    /*  <Payload> <Board Config> */
    ":: %s for %s, Copyright (C) 2024-2025 Samuel Zormeister\n"
    "::\n"
    ":: VERSION: %s\n"
    "::\n"
    ":: BUILD_STYLE: %s\n"
    "::\n"
    ":: COMPILER: %s (%s)\n"
    "::\n"
    ":: CPID: %04x BORD: %02x ECID: %08llX\n"
    "::\n"
    "=======================================\n"
};

#define APP __payload_name
#define PL CURRENT_PLATFORM
#define V CURRENT_VERSION
#define C COMPILER_NAME
#define CV COMPILER_VERSION

extern const char *__payload_name;

void pal_send_boot_message(void)
{
    const sb_identity_t *ident;

    printf(boot_msg_fmt, APP, PL, V, C, CV, ident->cpid, ident->bord, ident->ecid);
}
