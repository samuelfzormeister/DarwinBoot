// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __EMBEDDEDBOOT_MEMORY_H__
#define __EMBEDDEDBOOT_MEMORY_H__

#include <sys/cdefs.h>
#include <lib/embeddedboot/base.h>

/*
 * @group memory
 */

__BEGIN_DECLS

#if __SIZEOF_POINTER__ == 4
    typedef uint32_t eb_address_t;
#elif __SIZEOF_POINTER__ == 8
    typedef uint64_t eb_address_t;
#else
    #error "Unknown pointer size!"
#endif

#define MEMORY_DEBUG_CLIENT_COMPONENT(c) (c << 8)
#define MEMORY_DEBUG_CLIENT_SUBSYSTEM(c) (c << 4)

/* mem dbg client for the libEmbeddedBoot components. */
#define MEMORY_DEBUG_CLIENT_LIBEMBEDDEDBOOT MEMORY_DEBUG_CLIENT_COMPONENT(1)

/*!
 *  @typedef eb_memory_debug_info_t
 *  Information for a runtime diagnostic on allocated memory.
 */
typedef struct _eb_memory_debug_info_s {
    const char *client;
    uint32_t    client_id;
    uint64_t    timestamp;
} eb_memory_debug_info_t;

typedef enum {
    EB_MEMORY_RANGE_TYPE_PHYSICAL,
    EB_MEMORY_RANGE_TYPE_VIRTUAL,
    EB_MEMORY_RANGE_TYPE_BUS,
} eb_memory_range_type_t;

typedef struct _eb_memory_range_s {
    eb_address_t        start;
    uint32_t            length;
    eb_memory_debug_info_t debug_info;
} eb_memory_range_t;

eb_result_t init_malloc(eb_memory_range_t *range);

__END_DECLS

#endif
