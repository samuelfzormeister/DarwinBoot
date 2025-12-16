// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_env_h_
#define __lib_env_h_

#include <lib/types.h>

enum {
    ENV_FLAGS_IMMUTABLE = (1 << 0),
};

bool env_get_value(const char *value, size_t *size, void *buffer);
bool env_set_value(const char *value, size_t size, void *buffer);

#endif /* __lib_env_env_h_ */
