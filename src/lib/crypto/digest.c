// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <corecrypto/ccsha1.h>
#include <corecrypto/ccsha2.h>
#include <lib/crypto/crypto.h>

const struct ccdigest_info *digests[CRYPTO_DIGEST_ALGORITHM_MAX];

void crypto_init(void)
{
    digests[CRYPTO_DIGEST_ALGORITHM_SHA1] = ccsha1_di();
    digests[CRYPTO_DIGEST_ALGORITHM_SHA224] = ccsha224_di();
    digests[CRYPTO_DIGEST_ALGORITHM_SHA256] = ccsha256_di();
    digests[CRYPTO_DIGEST_ALGORITHM_SHA384] = ccsha384_di();
    digests[CRYPTO_DIGEST_ALGORITHM_SHA512] = ccsha512_di();
}
