// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_X86_CPUID_H__
#define __PLATFORM_X86_CPUID_H__

#include <stdint.h>

// vendor strings
#define CPUID_VENDOR_INTEL "GenuineIntel"
#define CPUID_VENDOR_AMD   "AuthenticAMD"

// ^ should i even bother accounting for other vendors?

#define CPUID_VMM_VENDOR_QEMU   "TCGTCGTCG"
#define CPUID_VMM_VENDOR_KVM    " KVMKVMKVM "
#define CPUID_VMM_VENDOR_VBOX   "VBoxVBoxVBox"
#define CPUID_VMM_VENDOR_VMWARE "VMwareVMware"

typedef uint32_t cpuid_reg_t[4];

// should be what i want
#define eax 0
#define ebx 1
#define ecx 2
#define edx 3

inline void cpuid(cpuid_reg_t reg)
{
    __asm__ volatile (
        "cpuid" : "=a"(reg[eax]),
                  "=b"(reg[ebx]),
                  "=c"(reg[ecx]),
                  "=d"(reg[edx])
                : "a"(reg[eax]),
                  "b"(reg[ebx]),
                  "c"(reg[ecx]),
                  "d"(reg[edx])
    );
}

inline void cpuid_leaf(uint32_t leaf, cpuid_reg_t reg)
{
    __asm__ volatile (
        "cpuid" : "=a"(reg[eax]),
                  "=b"(reg[ebx]),
                  "=c"(reg[ecx]),
                  "=d"(reg[edx])
                : "a"(leaf),
                  "b"(0),
                  "c"(0),
                  "d"(0)
    );
}

#endif /* __PLATFORM_X86_CPUID_H__ */
