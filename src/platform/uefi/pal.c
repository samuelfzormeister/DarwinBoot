// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <stdio.h>
#include <lib/efi/efi.h>
#include <lib/pal/pal.h>
#include <lib/config.h>

// for libprintf in External.
void _putchar(char character)
{
    wchar_t wide[3];
    if (character == '\n' || character == '\r') {
        wide[0] = WSTRING('\r');
        wide[1] = WSTRING('\n');
        wide[2] = 0;
    } else {
        wide[0] = character;
        wide[1] = 0;
        wide[2] = 0;
    }

    efi_get_system_table()->con_out->output_string(efi_get_system_table()->con_out, wide);
}

pal_log_level_t pal_level = PAL_LOG_LEVEL_ERROR;

static const char *pal_get_log_level_str(pal_log_level_t level) {
    switch (level) {
        case PAL_LOG_LEVEL_ERROR:
            return "ERROR";
        case PAL_LOG_LEVEL_WARNING:
            return "WARNING";
        case PAL_LOG_LEVEL_INFO:
            return "INFO";
        case PAL_LOG_LEVEL_DEBUG:
            return "DEBUG";
        default:
            return "INVALID";
    }
}

int pal_log(pal_log_level_t level, const char *lib, const char *format, ...)
{
    va_list list;

    va_start(list, format);
    printf("[%s][%s] ", lib, pal_get_log_level_str(level));
    return vprintf(format, list);
}

void *pal_malloc(size_t size) {
    void *p;

    efi_get_boot_services()->allocate_pool(EfiLoaderData, size, &p);

    return p;
}

void pal_free(void *memory)
{
    efi_get_boot_services()->free_pool(memory);
}
