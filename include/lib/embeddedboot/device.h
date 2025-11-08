// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __EMBEDDEDBOOT_DEVICE_H__
#define __EMBEDDEDBOOT_DEVICE_H__

#include <stdbool.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <lib/embeddedboot/memory.h>

__BEGIN_DECLS

/*
 * built for MMIO devices.
 */

typedef struct _eb_device_s eb_device_t;

typedef struct _eb_device_memory_ops_s {
    uint8_t (*read8)(eb_device_t *dev, uint32_t offset);
    uint16_t (*read16)(eb_device_t *dev, uint32_t offset);
    uint32_t (*read32)(eb_device_t *dev, uint32_t offset);
    void (*write8)(eb_device_t *dev, uint32_t offset, uint8_t value);
    void (*write16)(eb_device_t *dev, uint32_t offset, uint16_t value);
    void (*write32)(eb_device_t *dev, uint32_t offset, uint32_t value);
} eb_device_memory_ops_t;

struct _eb_device_s {
    const char *name;
    eb_memory_range_t *memory;
    eb_device_memory_ops_t memory_ops;
};

__END_DECLS

#endif
