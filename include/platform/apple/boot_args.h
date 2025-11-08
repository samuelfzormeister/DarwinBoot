// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_BOOTARGS_H__
#define __PLATFORM_APPLE_BOOTARGS_H__

#include <stdint.h>

#if TARGET_CPU_ARM
    #include <platform/apple/arm/boot_args.h>
#elif TARGET_CPU_ARM64
    #include <platform/apple/arm64/boot_args.h>
#elif TARGET_CPU_I386 || TARGET_CPU_X86_64
    #include <platform/apple/i386/boot_args.h>
#else
    #error "Unsupported architecture!"
#endif

/* apparently you can also load Dexts this way, interesting. */
struct {
    uint32_t info_plist_address;
    uint32_t info_plist_size;
    uint32_t exec_address;
    uint32_t exec_size;
    uint32_t bundle_path_address;
    uint32_t bundle_path_length;
} typedef boot_kext_entry_t;

// The 32-bit address limitation seems annoying though.

#endif /* __PLATFORM_APPLE_BOOTARGS_H__ */
