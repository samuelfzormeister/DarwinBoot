// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_FDT_HEADER_H__
#define __PLATFORM_FDT_HEADER_H__

#include <stdint.h>

#define FLATTENED_DEVICETREE_MAGIC 0xD00DFEED

struct {
    uint32_t magic;
    uint32_t total_size;
    uint32_t dt_struct_offset;
    uint32_t dt_strings_offset;
    uint32_t mem_reservation_map_offset;
    uint32_t version;
    uint32_t last_compatible_version;
    uint32_t boot_cpu_phys_id;
    uint32_t dt_strings_size;
    uint32_t dt_structure_size;
} typedef fdt_header_t;

#endif /* __PLATFORM_FDT_HEADER_H__ */
