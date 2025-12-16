// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_devicetree_internal_h_
#define __lib_devicetree_internal_h_

#include <lib/devicetree.h>

device_tree_t dt_from_adt(adt_node_t *root);

struct _device_tree_s {
    dt_node_t root;
    dt_flags_t flags;
};

struct _dt_node_s {
    device_tree_t my_tree;

    dt_prop_t props; /* TODO: linked list */
};

struct _dt_prop_s {
    char name[DT_MAX_NAME_LENGTH];
    size_t data_size;
    void *data_buffer;
};

#endif
