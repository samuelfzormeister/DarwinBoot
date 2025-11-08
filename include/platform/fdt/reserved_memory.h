// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_FDT_RESERVEDMEMORY_H__
#define __PLATFORM_FDT_RESERVEDMEMORY_H__

#include <stdint.h>

struct {
    uint64_t base;
    uint64_t size;
} typedef fdt_reserved_memory_entry_t;

#endif /* __PLATFORM_FDT_RESERVEDMEMORY_H__ */
