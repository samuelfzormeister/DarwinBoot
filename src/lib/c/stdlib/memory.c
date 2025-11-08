// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/cms/cms.h>
#include <stdlib.h>
#include "stdlib_internal.h"

bool cms_once = false;

const cms_init_data_t cms_callbacks = {
    .calloc = NULL,
    .malloc = &platform_malloc,
    .realloc = NULL,
    .free = &platform_free,
    .allocation_region_base = 0,
    .ranges = NULL,
};

void malloc_init(void)
{
    cms_initialize(&cms_callbacks);
}

void *malloc(size_t size)
{
    return cms_allocate_memory(size);
}

void free(void *mem)
{
    return cms_free_memory(mem);
}
