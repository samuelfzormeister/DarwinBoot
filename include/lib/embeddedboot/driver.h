// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __EMBEDDEDBOOT_DRIVER_H__
#define __EMBEDDEDBOOT_DRIVER_H__

#include <lib/embeddedboot/device.h>

__BEGIN_DECLS

/*
 * @group Drivers
 */

typedef struct _eb_driver_matching_s {
    const char **compatible_ids;
    uint32_t num_compatible_ids;
} eb_driver_matching_t;

typedef struct _driver_s {
    eb_driver_matching_t match;
} eb_driver_t;

eb_driver_t *eb_driver_create_for_device(eb_device_t *dev);

__END_DECLS

#endif
