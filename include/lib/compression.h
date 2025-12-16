// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_compression_h_
#define __lib_compression_h_

#include <lib/types.h>

typedef enum {
    COMPRESSION_RESULT_OK,
    COMPRESSION_RESULT_INVALID,
    COMPRESSION_RESULT_UNSUPPORTED,
} compression_result_t;

typedef union {
    uint8_t data[];
} compression_ctx_t;

typedef struct {
    uint32_t size;

    compression_result_t (*encode)(compression_ctx_t *ctx, const void *data, size_t size, void *out, size_t out_size);
    compression_result_t (*decode)(compression_ctx_t *ctx, const void *data, size_t size, void *out, size_t out_size);
} compression_info;

const compression_info compression_lzvn_ci;
const compression_info compression_lzfse_ci;
const compression_info compression_lzss_ci;

compression_result_t compression_encode(const compression_info *ci, compression_ctx_t ctx);

#endif /* __lib_compression_h_ */
