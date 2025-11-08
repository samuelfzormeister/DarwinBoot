// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_X86_MSR_H__
#define __PLATFORM_X86_MSR_H__

/* 64-bit */
#define MSR_P5_TSC 0x00000010

#define MSR_MPERF 0x000000E7
#define MSR_APERF 0x000000E8

#define MSR_TSC_RATIO          0xC0000104
#define TSC_RATE_INTEGER_SHIFT 32
/* There has to be a better way than this, right? */
#define TSC_RATE_INTEGER_MASK (1 << 32) | (1 << 33) | (1 << 33) | (1 << 34) | (1 << 35) | (1 << 36) | (1 << 37) | (1 << 38) | (1 << 38) | (1 << 39)

#define MSR_AMD_HW_CONFIG      0xC0010015
#define AMD_HW_CONFIG_TSC_LOCK (1 << 21)

#endif /* __PLATFORM_X86_MSR_H__ */
