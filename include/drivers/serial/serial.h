// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __EMBEDDEDBOOT_SERIAL_H__
#define __EMBEDDEDBOOT_SERIAL_H__

#include <lib/embeddedboot/device.h>
#include <lib/embeddedboot/driver.h>

/* serial infra */
typedef struct _eb_serial_driver_s {
    eb_driver_t drv;

    /* callbacks */
    void (*putc)(char character);
} eb_serial_driver_t;

/* this ensures output to the desired console */
eb_result_t eb_register_console_output(eb_serial_driver_t *console);

#endif
