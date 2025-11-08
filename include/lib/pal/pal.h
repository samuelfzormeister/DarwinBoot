// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_pal_pal_h_
#define __lib_pal_pal_h_

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define PAL_PRINTFLIKE(...) __attribute__((format(printf, __VA_ARGS__)))

/*!
 * @group PAL
 *
 * Platform Abstraction Layer, these set of functions are for libplatform to implement and for the
 * other libraries within DarwinBoot to use, not intended for use by the application code under src/apps.
 */

enum {
    PAL_LOG_LEVEL_ERROR = (1 << 0),
    PAL_LOG_LEVEL_WARNING = (1 << 1),
    PAL_LOG_LEVEL_INFO = (1 << 2),
    PAL_LOG_LEVEL_DEBUG = (1 << 3),
} typedef pal_log_level_t;

/* can be overridden by libplatform or the app at runtime */
bool pal_set_log_policy(pal_log_level_t level);

int pal_log(pal_log_level_t level, const char *lib, const char *format, ...) PAL_PRINTFLIKE(3,4);

/* Always use the libc versions where possible, this is a direct call to the allocator. */
void *pal_malloc(size_t size);
void pal_free(void *memory);

void pal_send_boot_message(void);

/* PAL SPI for libfs to call into. This reduces code complexity in libfs, as I can 100% say that abstracting embeddedboot and UEFI would be hard. */

typedef struct _pal_fs pal_fs_t;
typedef struct _pal_fs_file pal_fs_file_t;

pal_fs_t **pal_fs_get_all_filesystems(void);


#endif /* __lib_pal_pal_h_ */
