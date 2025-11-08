// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_DEVICETREE_H__
#define __PLATFORM_APPLE_DEVICETREE_H__

#include <stdint.h>

struct _adt_prop_s {
    char name[32];
    uint32_t length;
    /* value sits here. */
} typedef adt_prop_t;

struct _adt_node_s {
    uint32_t num_properties;
    uint32_t num_children;
    /* properties go here */
    /* children go here */
} typedef adt_node_t;

#endif /* __PLATFORM_APPLE_DEVICETREE_H__ */
