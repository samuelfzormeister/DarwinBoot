// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_devicetree_devicetree_h_
#define __lib_devicetree_devicetree_h_

#include <lib/types.h>
#include <platform/apple/device_tree.h>
#include <platform/fdt/header.h>

typedef struct _device_tree_s *device_tree_t;
typedef struct _dt_node_s *dt_node_t;
typedef struct _dt_prop_s *dt_prop_t;

typedef enum {
    DT_PANIC_ON_IMPROPER_USE = (1 << 0)
} dt_flags_t;

#define DT_MAX_NAME_LENGTH 32

void dt_init(dt_flags_t flags);

/*!
 * @function dt_create
 * Creates an empty Device Tree with a root node already created.
 */
device_tree_t dt_create(void);

/*!
 * @function dt_create_with_adt
 * Creates a Device Tree object based on a pre-existing ADT formatted Device Tree
 */
device_tree_t dt_create_with_adt(adt_node_t *root);

device_tree_t dt_create_with_fdt(fdt_header_t *fdt);

dt_node_t dt_get_node(device_tree_t *dt, const char *path, bool create);

void dt_node_add_property(dt_node_t node, dt_prop_t prop);

dt_prop_t dt_prop_create(void);

void dt_prop_set_name(const char *name);


#endif /* __lib_devicetree_devicetree_h_ */
