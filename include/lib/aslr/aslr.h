// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_aslr_aslr_h_
#define __lib_aslr_aslr_h_

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    ASLR_BASE_X86 = 0x100000,
    ASLR_BASE_ARM = 0x1000000,
} aslr_base_t;

typedef enum {
    ASLR_TECHNIQUE_RANDOM_WITH_SHA1, /* we generate random bytes then SHA1 hash it */
} aslr_technique_t;

#if TARGET_CPU_X86_64 || TARGET_CPU_I386
#define ASLR_BASE_DEFAULT ASLR_BASE_X86
#else
#define ASLR_BASE_DEFAULT ASLR_BASE_ARM
#endif

void aslr_init(void);

uint32_t aslr_gen_with_base(aslr_base_t base, aslr_technique_t technique);

#endif
