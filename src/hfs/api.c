// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "internal.h"

hfs_context_t *hfs_create_context(hfs_callbacks_t *callbacks)
{
    hfs_context_t *ctx = NULL;

    if (hfs_callbacks_valid(callbacks)) {
        ctx = (hfs_context_t *)callbacks->allocate(callbacks->context, sizeof(struct _hfs_context_s));


    }

    return ctx;
}
