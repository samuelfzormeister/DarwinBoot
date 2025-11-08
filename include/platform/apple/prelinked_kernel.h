// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_PRELINKEDKERNEL_H__
#define __PLATFORM_APPLE_PRELINKEDKERNEL_H__

#include <platform/apple/mach.h>

#define kPlatformNameLen 64
#define kRootPathLen     256

#define kPrelinkedKernelPath "/System/Library/PrelinkedKernels/prelinkedkernel"
#define kImmutableKernelPath "/System/Library/PrelinkedKernels/immutablekernel"

enum {
    kPrelinkedKernelCompressionLZVN = 'lzvn',
    kPrelinkedKernelCompressionLZSS = 'lzss',
};

#define kPrelinkedKernelCompressedSignature 'comp'

struct {
    uint32_t siganture;
    uint32_t compression_type;
    uint32_t adler32;
    uint32_t uncompressed_size;
    uint32_t compressed_size;
    uint32_t prelink_version;
    uint32_t reserved[10];
    char platform_name[kPlatformNameLen];
    char root_path[kRootPathLen];
    uint8_t data[];
} typedef prelinked_kernel_header_t;

/* Mach-O prelinked sections/segment names */
#define kPrelinkTextSegment "__PRELINK_TEXT"
#define kPrelinkTextSection "__text"

#define kPrelinkDataSegment "__PRELINK_DATA"
#define kPrelinkDataSection "__data"

#define kPrelinkInfoSegment "__PRELINK_INFO"
#define kPrelinkInfoSection "__info"

#define kBuiltinInfoSection  "__kmod_info"
#define kBuiltinStartSection "__kmod_start"
#define kBuiltinInitSection  "__kmod_init"
#define kBuiltinTermSection  "__kmod_term"

#endif /* __PLATFORM_APPLE_PRELINKEDKERNEL_H__ */
