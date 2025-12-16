// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/compression.h>

/* jesus... */
#define LZVN_SCRATCH_BUFFER_SIZE 0x80000

extern size_t lzvn_encode_buffer(void *out, size_t out_size, const void *in, size_t in_size, void *work);

const compression_info compression_lzvn_ci = {
    .size = LZVN_SCRATCH_BUFFER_SIZE,
};
