// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <stdio.h>
#include <stdlib.h>
#include <lib/mach.h>

struct _mach_file_s {
    mach_header *header_32;
    mach_header_64 *header_64;
    mach_fat_header *header_fat;
    cpu_type_t type;

    bool is_64bit;
    bool is_fat;
};

mach_file_t *mach_file_create_with_binary(uint8_t *binary)
{
    mach_file_t *f = NULL;
    uint32_t *magic = (uint32_t *)binary;

    f = malloc(sizeof(struct _mach_file_s));

    switch (*magic) {
        case MH_MAGIC:
        case MH_CIGAM: {
            printf("[mach]: Mach 32 file.\n");
            f->header_32 = (mach_header *)binary;
            break;
        }
    }

    return f;
}
