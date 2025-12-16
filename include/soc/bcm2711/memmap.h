// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __SOC_BCM2711_MEMORY_MAP_H__
#define __SOC_BCM2711_MEMORY_MAP_H__

#define IO_BASE 0xFE000000

#define TIMER_BASE IO_BASE + 0x0000

#define SDRAM_BASE 0x00000000
#define VRAM_BASE 0x40000000

#define DMA_N_BASE(n) (IO_BASE + (0x7000) + (n * 0x100))

#define DMA0_BASE DMA_N_BASE(0)

#endif
