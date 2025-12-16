// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_mach_mach_h_
#define __lib_mach_mach_h_

#include <lib/types.h>
#include <platform/apple/mach.h>

typedef struct _mach_loader_ctx mach_loader_ctx_t;
typedef struct _mach_file_s mach_file_t;

mach_file_t *mach_file_create_with_binary(uint8_t *binary);

cpu_type_t mach_file_get_arch(mach_file_t *file);

bool mach_file_is_fat(mach_file_t *file);

mach_file_t *mach_file_get_slice(mach_file_t *file, cpu_type_t cpu, cpu_subtype_t sub_type);

mach_loader_ctx_t *mach_loader_create(void);

bool mach_loader_load_file(mach_loader_ctx_t *ldr, mach_file_t *file);

#if TARGET_CPU_ARM
#define MACH_DEFAULT_CPU_TYPE CPU_TYPE_ARM
#elif TARGET_CPU_ARM64
#if TARGET_CPU_ADDRESS_WIDTH == 64
#define MACH_DEFAULT_CPU_TYPE CPU_TYPE_ARM64
#else
#define MACH_DEFAULT_CPU_TYPE CPU_TYPE_ARM64_32
#endif
#elif TARGET_CPU_I386
#define MACH_DEFAULT_CPU_TYPE CPU_TYPE_X86
#elif TARGET_CPU_X86_64
#define MACH_DEFAULT_CPU_TYPE CPU_TYPE_X86_64
#endif

#endif /* __lib_mach_mach_h_ */
