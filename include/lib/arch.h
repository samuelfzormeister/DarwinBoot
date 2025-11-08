// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_arch_h_
#define __lib_arch_h_

/*
 * Similar in style to TargetConditionals, but with only the CPU definitions + more.
 */

#if __has_builtin(__is_target_arch)
    #if __is_target_arch(arm)
        #define TARGET_CPU_ARM    1
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "ARM"
        #define TARGET_CPU_ADDRESS_WIDTH 32
        #if __is_target_arch(armv6k)
            /*
             * Prioritise ARMv6K over regular ARMV6
             */
            #define __PLATFORM_ARCH_ARMV6K__ 1
        #elif __is_target_arch(armv6)
            #define __PLATFORM_ARCH_ARMV6__  1
        #elif __is_target_arch(armv7k)
            #define __PLATFORM_ARCH_ARMV7K__ 1
        #elif __is_target_arch(armv7s)
            #define __PLATFORM_ARCH_ARMV7S__ 1
        #elif __is_target_arch(armv7)
            #define __PLATFORM_ARCH_ARMV7__  1
        #endif
    #elif __is_target_arch(arm64) || __is_target_arch(arm64e) || __is_target_arch(arm64_32)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  1
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "ARM64"

        /*
         * arm64_32 is ARM64, but with 32-bit pointers.
         */
        #if __is_target_arch(arm64_32)
            #define TARGET_CPU_ADDRESS_WIDTH 32
        #else
            #define TARGET_CPU_ADDRESS_WIDTH 64
        #endif
    #elif __is_target_arch(i386)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   1
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "i386"
        #define TARGET_CPU_ADDRESS_WIDTH 32
    #elif __is_target_arch(x86_64)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 1
        #define TARGET_CPU_STRING "x86_64"
        #define TARGET_CPU_ADDRESS_WIDTH 64
    #endif
#else
    #if defined(__arm__) || defined(_M_ARM)
        #define TARGET_CPU_ARM    1
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "ARM"
        #define TARGET_CPU_ADDRESS_WIDTH 32
    #elif defined(__arm64__) || defined(_M_ARM64) || defined(__aarch64__)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  1
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "ARM64"
        #define TARGET_CPU_ADDRESS_WIDTH 64
    #elif defined(__i386__) || defined(_M_IX86)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   1
        #define TARGET_CPU_X86_64 0
        #define TARGET_CPU_STRING "i386"
        #define TARGET_CPU_ADDRESS_WIDTH 32
    #elif defined(__x86_64__) || defined(_M_AMD64)
        #define TARGET_CPU_ARM    0
        #define TARGET_CPU_ARM64  0
        #define TARGET_CPU_I386   0
        #define TARGET_CPU_X86_64 1
        #define TARGET_CPU_STRING "x86_64"
        #define TARGET_CPU_ADDRESS_WIDTH 64
    #endif
#endif

/*
 * This section should be as portable as possible.
 *          1
 * Hopefully segments of code can be used in userspace context for unit testing.
 */
#if __is_target_vendor(pc)
    #if __is_target_os(windows)
        /* FIXME: relies on toolchain adding the 'UEFI' macro. */
        #if UEFI
            #define TARGET_ENVIRONMENT_UEFI 1
        #else
            #define TARGET_ENVIRONMENT_WINDOWS 1
        #endif
    #elif __is_target_os(linux)
        #define TARGET_ENVIRONMENT_LINUX 1
    #endif
#elif __is_target_vendor(apple)
    #define TARGET_ENVIRONMENT_DARWIN 1
#else
    /* assume this is the none vendor */
    #if __is_target_environment(eabi)
        #define TARGET_ENVIRONMENT_EMBEDDED_ABI 1
    #elif __is_target_environment(elf)
        #define TARGET_ENVIRONMENT_EMBEDDED_ELF 1
    #endif
#endif

#endif /* __lib_arch_h_ */
