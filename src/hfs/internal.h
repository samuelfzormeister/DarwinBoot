// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __hfs_internal_h_
#define __hfs_internal_h_

#include <stdbool.h>
#include <hfs/hfs.h>
#include <hfs/types.h>

struct _hfs_context_s {
    hfs_callbacks_t *callbacks;
};

bool hfs_callbacks_valid(hfs_callbacks_t *callbacks);
void *hfs_allocate(hfs_context_t *ctx, size_t size);

#endif /* __hfs_internal_h_ */
