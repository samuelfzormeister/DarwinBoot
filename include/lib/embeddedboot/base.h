// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __EMBEDDEDBOOT_BASE_H__
#define __EMBEDDEDBOOT_BASE_H__

#include <stdint.h>

typedef enum {
    EB_RESULT_OK = 0,

    EB_RESULT_INVALID_PARAMETER,
    EB_RESULT_UNSUPPORTED,
    EB_RESULT_NOT_FOUND,
    EB_RESULT_NO_RESOURCES,
} eb_result_t;

#endif
