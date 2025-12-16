// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "internal.h"

bool hfs_callbacks_valid(hfs_callbacks_t *callbacks)
{
    if (callbacks->magic != HFS_CALLBACKS_MAGIC) {
        return false;
    }

    if (callbacks->logv == NULL) {
        return false;
    }

    if (callbacks->allocate == NULL) {
        return false;
    }

    if (callbacks->free == NULL) {
        return false;
    }

    if (callbacks->read_block == NULL) {
        return false;
    }

    if (callbacks->write_block == NULL) {
        return false;
    }

    return true;
}
