// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/sb/sb.h>

/* Major WIP. */

static const sb_identity_t *current_identity;

void sb_init(const sb_identity_t *ident, sb_policy_t policy)
{
    current_identity = ident;
}

const sb_identity_t *sb_get_identity(void)
{
    return current_identity;
}
