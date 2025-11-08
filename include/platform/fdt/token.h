// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_FDT_TOKEN_H__
#define __PLATFORM_FDT_TOKEN_H__

#include <stdint.h>

enum {
    FDT_TOKEN_NODE_BEGIN = 1,
    FDT_TOKEN_NODE_END,
    FDT_TOKEN_NODE_PROPERTY,
    FDT_TOKEN_NODE_NOOP,
    FDT_TOKEN_END,
} typedef fdt_token_t;

#endif /* __PLATFORM_FDT_TOKEN_H__ */
