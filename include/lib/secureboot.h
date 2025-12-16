// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_secureboot_h_
#define __lib_secureboot_h_

#include <errno.h>
#include <lib/image.h>

typedef struct {
    uint32_t cpid;
    uint32_t bord;
    uint64_t ecid;
    uint32_t esec;
    uint32_t epro;
    uint32_t sdom;
    uint32_t prod;
} sb_identity_t;

typedef enum {
    SB_POLICY_FULL,         /* ensure that all parameters match */
    SB_POLICY_HASHING_ONLY, /* skip configuring parameters, this will check the signature and sig only. */
} sb_policy_t;

void sb_init(const sb_identity_t *identity, sb_policy_t policy);

const sb_identity_t *sb_get_identity(void);

errno_t sb_authenticate_image(boot_image_t *img);

#endif /* __lib_secureboot_h_ */
