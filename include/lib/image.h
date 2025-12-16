// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_image_image_h_
#define __lib_image_image_h_

#include <stdbool.h>
#include <lib/types.h>
#include <lib/fs.h>

/*!
 * @group image
 * Library for looking up and loading boot images.
 */

/*
 * The (executable - and payload) type of boot object
 */
typedef enum {
    BOOT_IMAGE_TYPE_MACH,
    BOOT_IMAGE_TYPE_PECOFF,
    BOOT_IMAGE_TYPE_ELF,

    /* other image packaging formats */
    BOOT_IMAGE_TYPE_IMG4,
    BOOT_IMAGE_TYPE_IMG3,

    /* if any others don't apply; eg: raw Apple DT */
    BOOT_IMAGE_TYPE_BINARY,
} boot_image_type_t;

typedef struct _boot_image boot_image_t;

boot_image_t *boot_image_from_fs_with_path(fs_t *filesystem);

#endif /* __lib_image_image_h_ */
