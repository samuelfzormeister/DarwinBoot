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

typedef void *cms_ctx_t;

/* We assume that this is a PHYSICAL address. */
typedef uint64_t cms_addr_t;

typedef enum {
    CMS_STATE_UNINITIALISED = 0,
    CMS_STATE_ACTIVE,
    CMS_STATE_ACTIVE_MM,
    CMS_STATE_DEACTIVATED,
} cms_state_t;

typedef enum {
    CMS_MEM_REGION_BOOT = 0,   /* libEmbeddedBoot or EB data */

    CMS_MEM_REGION_KERNEL,     /* Any data for the kernel, kargs, ramdisk, boot picts, etc. */

    CMS_MEM_REGION_MAX,
} cms_mem_region_t;

typedef struct {
    cms_addr_t addr;
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
    uint64_t region_sizes[CMS_MEM_REGION_MAX]; /* cms_allocate_region will ignore the requested region size and use this instead. */
    cms_memory_range_t *ranges;
    size_t num_ranges;
} typedef cms_init_data_t;

typedef struct {
    uint32_t api_rev;
    uint32_t api_struct_size;

    void *(*allocate)(cms_ctx_t ctx, size_t size);
    void *(*allocate_multiple)(cms_ctx_t ctx, size_t size);
} cms_api_t;

typedef struct _cms_memory_desc_s *cms_memory_desc_t;

bool cms_initialize(const cms_init_data_t *callbacks);

void *cms_allocate_memory_multiple(size_t cnt, size_t size);
void *cms_allocate_memory(size_t size);
void *cms_reallocate_memory(void *orig, size_t size);
void cms_free_memory(void *memory);

void *cms_allocate_region(cms_mem_region_t region, size_t size);

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
