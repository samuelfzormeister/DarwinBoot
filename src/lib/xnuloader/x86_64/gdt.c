// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <stdint.h>

/*
 * GDT:
 *
 * This is a dummy to use whilst booting the kernel
 */

 struct gdt_entry {
     uint16_t limit_lo;
     uint16_t base_lo;
     uint8_t base_mid;
     uint8_t bit_lo;
     uint8_t bit_hi;
     uint8_t base_hi;
 };

/* used by launch.s */
struct gdt_entry _xl_gdt[8] =
{
    {0,0,0,0},
};
