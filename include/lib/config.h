// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_config_h_
#define __lib_config_h_

#include <lib/arch.h>

#if defined(__clang__)
    #define COMPILER_NAME          "clang"
    #define COMPILER_VERSION_MAJOR __clang_major__
    #define COMPILER_VERSION_MINOR __clang_minor__
    #define COMPILER_VERSION_PATCH __clang_patchlevel__
    #define COMPILER_VERSION       __VERSION__

    #if !(__WCHAR_WIDTH__ == 16) && TARGET_ENVIRONMENT_UEFI
        #error "Wide strings aren't 16-bits wide whilst we are configured for UEFI, this is bad!"
    #endif

    #define WSTRING(str) u##str
#else
    #error "Unsupported compiler is being used!"
#endif

/* we only care about this for embedded systems */
#if TARGET_ENVIRONMENT_EMBEDDED_ABI || TARGET_ENVIRONMENT_EMBEDDED_ELF
#include <soc/config.h>
#endif

#ifndef CURRENT_PLATFORM
#define CURRENT_PLATFORM TARGET_CPU_STRING
#endif

#if defined(CONFIG_RELEASE) && CONFIG_RELEASE == 1
    #define CURRENT_CONFIG "RELEASE"
    #define RELEASE        1
#endif

/* have the same optimizations as RELEASE but have DEBUG prints */
#if defined(CONFIG_DEVELOPMENT) && CONFIG_DEVELOPMENT == 1
    #define CURRENT_CONFIG "DEVELOPMENT"
    #define DEVELOPMENT    1
#endif

#if defined(CONFIG_DEBUG) && CONFIG_DEBUG == 1
    #define CURRENT_CONFIG "DEBUG"
    #define DEBUG          1
#endif

#ifndef CURRENT_CONFIG
    #define CONFIG_RELEASE     1
    #define CURRENT_CONFIG     "RELEASE"
    #define RELEASE            1

    #define CONFIG_DEBUG       0
    #define DEBUG              0

    #define CONFIG_DEVELOPMENT 0
    #define DEVELOPMENT        0
#endif

#if defined(APP_BOOT)
#define CURRENT_PAYLOAD "DarwinBoot Booter"
#elif defined (APP_JUMPSTART)
#define CURRENT_PAYLOAD "DarwinBoot Jumpstart"
#else
#define CURRENT_PAYLOAD "Please define an APP_XXX value and add an associated payload name!"
#endif

#ifndef CURRENT_VERSION
#define CURRENT_VERSION "Build " __TIMESTAMP__
#endif

#endif /* __lib_config_h_  */
