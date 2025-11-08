// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __SOC_BCM2711_MEMORY_MAP_H__
#define __SOC_BCM2711_MEMORY_MAP_H__


// todo: validate.
#define BCM2711_ARMIO_BASE 0x7E000000

#define BCM2711_AUXIO_BASE BCM2711_ARMIO_BASE + 0x215000

#define BCM2711_AUX_UART_BASE BCM2711_AUXIO_BASE + 0x40

#define BCM2711_SPI1_BASE BCM2711_AUXIO_BASE + 0x80
#define BCM2711_SPI2_BASE BCM2711_AUXIO_BASE + 0xC0

#endif
