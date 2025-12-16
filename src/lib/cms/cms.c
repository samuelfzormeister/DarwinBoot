// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/cms.h>
#include <panic.h>
#include <stdio.h>

#define CMS_MEMORY_DESC_MAGIC 0x434D5321

struct _cms_memory_desc_s {
    uint32_t sig;
    size_t size;
    physical_address_t phys;
    virtual_address_t virt;
    cms_mem_region_t region;
    cms_memory_desc_t next;
};

static const char *cms_region_names[CMS_MEM_REGION_MAX] = {
    "boot",
    "kernel",
};

#define cms_debug(fmt, args...) \
    printf("[cms][%s]: " fmt "\n", (__func__+4), ##args); \

#define cms_panic(fmt, args ...) \
    panic("[cms][%s]: " fmt, (__func__+4), ##args); \

static cms_memory_desc_t cms_regions[CMS_MEM_REGION_MAX];
static const cms_init_data_t *cms_callbacks;

#define malloc(size) cms_callbacks->malloc(size)
#define free(ptr) cms_callbacks->free(ptr);

static struct _cms_memory_desc_s cms_root_desc;

static cms_memory_desc_t cms_last_desc;

static cms_state_t cms_state = CMS_STATE_UNINITIALISED;

cms_state_t cms_get_current_state(void)
{
    return cms_state;
}

inline bool cms_is_initialized()
{
    if (cms_state == CMS_STATE_ACTIVE) {
        return true;
    } else {
        return false;
    }
}

bool cms_initialize(const cms_init_data_t *callbacks)
{
    if (cms_callbacks) {
        cms_panic("attempted a second initialization");
    }

    if (callbacks == NULL) {
        cms_debug("bad callbacks?");
        return false;
    }

    cms_callbacks = callbacks;

    cms_state = CMS_STATE_ACTIVE;

    cms_last_desc = &cms_root_desc;

    return true;
}

cms_memory_desc_t cms_get_desc_by_address(physical_address_t phys, virtual_address_t virt)
{
    cms_memory_desc_t desc = &cms_root_desc;

    while ((desc = desc->next)) {
        if ((desc->phys == phys) && (desc->virt == virt)) {
            return desc;
        } else if ((desc->phys == phys) && (virt == 0)) {
            return desc;
        } else if ((desc->virt == virt) && (phys == 0)) {
            return desc;
        }
    }

    return NULL;
}

static void cms_prune_memory_desc(cms_memory_desc_t desc)
{
    cms_memory_desc_t cur = &cms_root_desc;

    while ((cur = cur->next)) {
        if (cur->next == desc) {
            /* move the list along */
            cur->next = desc->next;
            free(desc);
        }
    }
}

void *cms_allocate_memory(size_t size)
{
    cms_memory_desc_t desc;
    void *memory;

    if (!cms_is_initialized()) {
        cms_panic("attempted call whilst CMS is unavailable.");
    }

    desc = malloc(sizeof(struct _cms_memory_desc_s));
    memory = malloc(size);

#if __cms_assume_physical__
    desc->sig = CMS_MEMORY_DESC_MAGIC;
    desc->phys = (physical_address_t)memory;
    desc->size = size;
#else
    desc->sig = CMS_MEMORY_DESC_MAGIC;
    desc->virt = (virtual_address_t)memory;
    desc->size = size;
#endif

    /* todo: translate addrs from p to v and v to p */

    return memory;
}

void cms_free_memory(void *memory)
{
    cms_memory_desc_t desc;

#if __cms_assume_physical__
    desc = cms_get_desc_by_address((physical_address_t)memory, 0);
#else
    desc = cms_get_desc_by_address(0, (virtual_address_t)memory);
#endif

    cms_prune_memory_desc(desc);

    free(memory);
}
