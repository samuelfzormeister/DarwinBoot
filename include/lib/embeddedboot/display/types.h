// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __EMBEDDEDBOOT_DISPLAY_TYPES_H__
#define __EMBEDDEDBOOT_DISPLAY_TYPES_H__

#include <stdint.h>

typedef char eb_display_pixel_encoding[64];

typedef struct _display_mode_s {
    uint32_t width;
    uint32_t height;
    uint32_t pixel_depth;
    eb_display_pixel_encoding pixel_encoding;
} eb_display_mode_t;

#endif
