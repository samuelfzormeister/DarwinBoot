// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_cpu_cpu_h_
#define __lib_cpu_cpu_h_

#include <stdint.h>

void cpu_info_init(void);

typedef struct _cpu_info_s cpu_info_t;

typedef enum {
    CPU_VENDOR_INTEL,     /* x86 + Xscale */
    CPU_VENDOR_AMD,
    CPU_VENDOR_ARM,
    CPU_VENDOR_BROADCOM,  /* NOTE: BCM2712 + 2711 have ARM designed cores. */
} cpu_vendor_t;

cpu_info_t *cpu_get_info(void);

cpu_vendor_t cpu_info_get_vendor(cpu_info_t *info);

const char *cpu_info_get_name(cpu_info_t *info);

uint32_t cpu_info_get_physical_count(cpu_info_t *info);
uint32_t cpu_info_get_logical_count(cpu_info_t *info);   /* NOTE: This is only really a problem on x86, AFAICT. */

uint64_t cpu_info_get_bus_frequency(cpu_info_t *info);

#endif /* __lib_cpu_cpu_h_ */
