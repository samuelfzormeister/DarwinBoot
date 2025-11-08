// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_ARM_THREADSTATE_H__
#define __PLATFORM_APPLE_ARM_THREADSTATE_H__

#include <stdint.h>

struct arm_thread_state {
    uint32_t r[13];
    uint32_t sp;
    uint32_t lr;
    uint32_t pc;
    uint32_t cpsr;
};

struct arm_thread_state64 {
    uint64_t x[29];
    uint64_t fp;
    uint64_t lr;
    uint64_t sp;
    uint32_t cpsr;
    uint32_t pad;
};

#endif /* __PLATFORM_APPLE_ARM_THREADSTATE_H__ */
