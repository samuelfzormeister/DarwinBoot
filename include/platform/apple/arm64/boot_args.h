// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_ARM64_BOOTARGS_H__
#define __PLATFORM_APPLE_ARM64_BOOTARGS_H__

#include <stdint.h>

#define XNU_CURRENT_ARGS_REVISION 2
#define XNU_CURRENT_ARGS_VERSION  2

/* !!! SYNCED AGAINST XNU 6153.141.1 !!! */
#define XNU_COMMANDLINE_SIZE 608

#define DISPLAYPARAMS_DEPTH_SHIFT      (0)
#define DISPLAYPARAMS_ROTATION_SHIFT   (8)
#define DISPLAYPARAMS_SCALE_SHIFT      (16)
#define DISPLAYPARAMS_BOOTROTATE_SHIFT (24)

/* UNSIGNED LONG... */
struct {
    unsigned long base_address;
    unsigned long display_code;
    unsigned long row_bytes;
    unsigned long width;
    unsigned long height;
    unsigned long display_params; /* pixel depth + rotation + scale + boot rotation? */
} typedef xnu_video_args_t;

#define BOOT_FLAG_DARKBOOT (1 << 0) // What is 'darkboot?'

struct {
    uint16_t revision;
    uint16_t version;
    uint64_t virtual_base;     /* Kernel address - Virtual */
    uint64_t physical_base;    /* Kernel address - Physical */
    uint64_t memory_size;      /* I don't actually know what this referse to, maximum Virtual mem space? */
    uint64_t top_of_kernel_data; /* "Highest physical address used in kernel data area", This essentially just means 'where does our __DATA segment end?' */
    xnu_video_args_t video_args;
    uint32_t machine_type;  /* ??? */
    void *device_tree_ptr; /* i assume this helps with native addressing, in the event that the DT is outside of a 32-bit address */
    uint32_t device_tree_size;
    char command_line[XNU_COMMANDLINE_SIZE];
    uint64_t boot_flags;
    uint64_t real_memory_size; /* Physical RAM size, I think. */
} typedef XNUBootArguments;

#endif /* __PLATFORM_APPLE_ARM64_BOOTARGS_H__ */
