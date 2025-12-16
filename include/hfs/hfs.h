// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __hfs_hfs_h_
#define __hfs_hfs_h_

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <errno.h>

#if !defined(__BEGIN_DECLS) && !defined(__END_DECLS)
#if __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS };
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif
#endif

/*
 * hfs: low-level HFS library because I can't be bothered porting something.
 *
 * this is the API header
 */

typedef struct _hfs_context_s hfs_context_t;

/* initialize the HFS library */
void hfs_init(void);

/* BE: 'hfsc' */
#define HFS_CALLBACKS_MAGIC 0x68667363

/*
 * dbh+ - DarwinBoot HFS+
 */
#define HFS_DB_LAST_MOUNTED 'dbh+'

typedef struct _hfs_callbacks_s {
    uint32_t magic;
    void *context;

    uint8_t uuid[16];

    /* --- portability --- */
    void *(*allocate)(void *context, size_t size);
    void (*free)(void *context, void *mem);
    void (*logv)(uint32_t level, const char *format, va_list va);

    /* --- block i/o --- */
    errno_t (*read_block)(void *context, uint32_t block, size_t *size, void *buffer);
    errno_t (*write_block)(void *context, uint32_t block, size_t size, void *buffer);
} hfs_callbacks_t;

hfs_context_t *hfs_create_context(hfs_callbacks_t *callbacks);

/* easy to access API */
errno_t hfs_load_startup_file(hfs_context_t *ctx, size_t *size, void *buffer);



#endif /* __hfs_hfs_h_ */
