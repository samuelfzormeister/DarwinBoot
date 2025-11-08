// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_cms_cms_h_
#define __lib_cms_cms_h_

#include <stdbool.h>
#include <stdio.h>
#include <lib/types.h>

/*!
 * @group Core Memory Services
 * CMS is designed to function as both a memory manager and tracker.
 *
 * CMS's memory management subsystem is configured by setting the 'manager_mode' field
 */

#if DEBUG || DEVELOPMENT
#define __cms_allow_diagnostics__ 1
#else
#define __cms_allow_diagnostics__ 1
#endif

#if UEFI
#define __cms_assume_physical__ 1
#else
#define __cms_assume_physical__ 0
#endif

typedef enum {
    cms_state_uninitialised = 0,
    cms_state_active,
    cms_state_deactivated,
} cms_state_t;

typedef enum {
    cms_memory_region_dontcare = 0,

    cms_memory_region_kernel, /* kernel or kernelcache */
    cms_memory_region_bootargs, /* the boot args structure that's placed into memory prior to jumping to xnu */
    cms_memory_region_devicetree, /* the region the devicetree binary is stored in */
    cms_memory_region_ramdisk, /* region of memory the root ramdisk is stored in */
    cms_memory_region_bootlogos, /* region where the FailedCLUT + other pictures are stored */

    cms_memory_region_kext_dungeon,

    cms_memory_region_max,
} cms_memory_region_t;

typedef struct {
    physical_address_t paddr;
    size_t size;
} cms_memory_range_t;

#define CMS_CURRENT_REVISION 0x01000000

/* Rev 2:  */
#define CMS_WORK_IN_PROGRESS_REV 0x02000000

struct {
    uint32_t revision;

    /* --- Revision 1 --- */
    void *(*calloc)(size_t count, size_t size);
    void *(*malloc)(size_t size);
    void *(*realloc)(size_t size);
    void (*free)(void *ptr);

    /* --- Revision 2 starts here --- */
    bool manager_mode;
    void *allocation_region_base; /* The base region of memory to use for allocation */
    uint64_t region_sizes[cms_memory_region_max]; /* cms_allocate_region will ignore the requested region size and use this instead. */
    cms_memory_range_t *ranges;
    size_t num_ranges;
} typedef cms_init_data_t;

typedef struct _cms_memory_desc_s *cms_memory_desc_t;

bool cms_initialize(const cms_init_data_t *callbacks);

void *cms_allocate_memory_multiple(size_t cnt, size_t size);
void *cms_allocate_memory(size_t size);
void *cms_reallocate_memory(void *orig, size_t size);
void cms_free_memory(void *memory);

void *cms_allocate_region(cms_memory_region_t region, size_t size);

/* this api call should only remove non-region marked allocations. i wouldn't want to free the kernel binary. */
void cms_shutdown(void);

cms_state_t cms_get_current_state(void);

cms_memory_desc_t cms_get_desc_by_address(physical_address_t phys, virtual_address_t virt);
physical_address_t cms_memory_desc_get_physical_address(cms_memory_desc_t);
virtual_address_t cms_memory_desc_get_virtual_address(cms_memory_desc_t);
size_t cms_memory_desc_get_size(cms_memory_desc_t);

void cms_blacklist_range(cms_memory_range_t *range);

#if __cms_allow_diagnostics__
void cms_diagnostic_dump(void);
#endif

#endif /* __lib_cms_cms_h_ */
