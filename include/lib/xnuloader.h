// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_xnuloader_xnuloader_h_
#define __lib_xnuloader_xnuloader_h_

#include <stdbool.h>
#include <lib/types.h>
#include <lib/image.h>
#include <platform/apple/boot_args.h>

typedef enum {

    /*!
     * @constant XL_BOOT_MODE_RAW
     * Raw kernel, loads kexts from System volume
     */
    XL_BOOT_MODE_RAW,
    XL_BOOT_MODE_MKEXT,
    XL_BOOT_MODE_PRELINKED,
    XL_BOOT_MODE_FILESET,
} xl_boot_mode_t;

typedef enum {
    XL_TASK_INIT,               /* init xnuloader data */
    XL_TASK_LOAD_KERNEL,        /* load kernel from disk */
    XL_TASK_BUILD_DT,           /* build/modify in-memory dt */
    XL_TASK_INIT_BOOT_ARGS,     /* init the boot args structure */
    XL_TASK_FINISH_DT,          /* finish off the devicetree */
    XL_TASK_UPDATE_BOOT_ARGS,   /* fill in the boot arguments */
    XL_TASK_PREFLIGHT_CLEANUP,  /* do any tasks to cleanup darwinboot's data */
    XL_TASK_LAUNCH,             /* boot the kernel */

    XL_TASK_MAX,
} xl_task_t;

typedef enum {
    XL_SB_POLICY_STRICT,
    XL_SB_POLICY_MEDIUM,
    XL_SB_POLICY_RELAXED,
} xl_sb_policy_t;

typedef enum {
    XL_IMAGE_KERNEL,        /* Either raw kernel or kernel cache */
    XL_IMAGE_RAMDISK,
    XL_IMAGE_BOOTLOGO,
    XL_IMAGE_DEVICETREE,

    XL_IMAGE_MAX
} xl_image_t;

typedef struct {
    xl_sb_policy_t policy;
    xl_boot_mode_t mode;

    boot_image_t *images[XL_IMAGE_MAX];
} xl_args_t;

void xl_init(void);

void xl_oneshot_load(const xl_args_t *args);

#endif /* __lib_xnuloader_xnuloader_h_ */
