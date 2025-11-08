// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_devicetree_devicetree_h_
#define __lib_devicetree_devicetree_h_

#include <lib/types.h>
#include <platform/apple/device_tree.h>
#include <platform/fdt/header.h>

typedef struct _device_tree_s device_tree_t;
typedef struct _device_tree_node_s device_tree_node_t;

/*!
 * @function dt_create
 * Creates an empty Device Tree with a root node already created.
 */
device_tree_t *dt_create(void);

/*!
 * @function dt_create_with_adt
 * Creates a Device Tree object based on a pre-existing ADT formatted Device Tree
 */
device_tree_t *dt_create_with_adt(adt_node_t *root);

device_tree_node_t *dt_get_node(device_tree_t *dt, const char *path, bool create);

#endif /* __lib_devicetree_devicetree_h_ */
