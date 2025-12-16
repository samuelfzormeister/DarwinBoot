// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_fs_fs_h_
#define __lib_fs_fs_h_

#include <errno.h>
#include <lib/types.h>

/* --- This is useful for APFS-based booting. --- */
typedef enum {
    FS_ROLE_NONE = 0,
    FS_ROLE_PREBOOT,
    FS_ROLE_SYSTEM,
    FS_ROLE_DATA,
} fs_role_t;

typedef enum {
    FS_FILE_READ_ONLY = (1 << 0),
    FS_FILE_HIDDEN = (1 << 1),
    FS_FILE_DIRECTORY = (1 << 2),
} fs_file_flags_t;

typedef enum {
    FS_FILE_MODE_READ = (1 << 0),
    FS_FILE_MODE_WRITE = (1 << 1),
    FS_FILE_MODE_CREATE = (1 << 2),
} fs_file_mode_t;

typedef struct _fs fs_t;
typedef struct _fs_file fs_file_t;

/* call on the FS subsystem for init. */
void fs_init(void);

/*
 * These are generic functions.
 */
fs_t **fs_get_all_filesystems(void);
size_t fs_get_filesystem_count(void);

fs_t *fs_find_by_uuid(const uuid_t *uuid);

/* 'current volume' refers to the volume the image was loaded from.  */
fs_t *fs_get_current_volume(void);

fs_role_t fs_get_role(fs_t *handle);

fs_file_t *fs_open_file(fs_t *fs, const char *path, fs_file_mode_t mode);

errno_t fs_file_read(fs_file_t *file, void *buffer, size_t *buf_size);
errno_t fs_file_write(fs_file_t *file, void *buffer, size_t buf_size);

#define DARWINBOOT_BUILDING_LIBPLATFORM 1

#if DARWINBOOT_BUILDING_LIBPLATFORM

/*
 * SPI between FS and PAL.
 */

#define FS_PAL_VERSION 0x010000

// keeping this in-line with APFS.
#define FS_PAL_MAX_FS_NAME 256

/*
 * Flags.
 */
#define FS_PAL_REGISTRATION_IS_BOOT 0x00000001  /* Indicates that the registered volume is the 'boot' (origin) volume. */

typedef struct {
    uint32_t version;     // revision of PAL (fs)

    /* --- Attributes --- */
    void *context;
    char name[FS_PAL_MAX_FS_NAME];
    uuid_t uuid;
    uint32_t flags;

    /* --- PAL callbacks --- */
    void *(*open)(void *context, const char *path, fs_file_mode_t file);
    void (*close)(void *context);



} fs_pal_registration_t;

fs_pal_registration_t *fs_pal_get_registration(fs_t *);

void fs_pal_register(fs_pal_registration_t *reg);

#endif

#endif /* __lib_fs_fs_h_ */
