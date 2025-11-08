// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_TIME_H__
#define __PLATFORM_EFI_TYPES_TIME_H__

#include <stdbool.h>
#include <stdint.h>

struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t padding;
    uint32_t nanosecond;
    int32_t timezone;
    uint8_t daylight;
    uint8_t padding2;
} typedef efi_time_t;

#define EFI_TIME_ADJUST_DAYLIGHT 0x1
#define EFI_TIME_IN_DAYLIGHT     0x2

#define EFI_UNSPECIFIED_TIMEZONE 0x7FF

struct {
    uint32_t resolution;
    uint32_t accuracy;
    bool sets_to_zero;
} typedef efi_time_capabilities_t;

#endif /* __PLATFORM_EFI_TYPES_TIME_H__ */
