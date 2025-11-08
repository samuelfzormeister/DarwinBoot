// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_crypto_crypto_h_
#define __lib_crypto_crypto_h_

#include <lib/types.h>

typedef struct _crypto_digest_ctx *crypto_digest_ctx_t;

typedef enum {
    CRYPTO_DIGEST_ALGORITHM_SHA1,
    CRYPTO_DIGEST_ALGORITHM_SHA224,
    CRYPTO_DIGEST_ALGORITHM_SHA256,
    CRYPTO_DIGEST_ALGORITHM_SHA384,
    CRYPTO_DIGEST_ALGORITHM_SHA512,
    CRYPTO_DIGEST_ALGORITHM_SHA512_256,

    CRYPTO_DIGEST_ALGORITHM_MAX,
} crypto_digest_algorithm_t;

/* initialize libcrypto */
void crypto_init(void);

crypto_digest_ctx_t *crypto_digest_alloc(crypto_digest_algorithm_t algorithm);



#endif /* __lib_crypto_crypto_h_ */
