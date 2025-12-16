// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __soc_board_h_
#define __soc_board_h_

#include <soc/config.h>

#if PLATFORM_SOC_BCM2711
#include <soc/bcm2711/board.h>

#elif PLATFORM_SOC_BCM2712
#include <soc/bcm2712/board.h>

#elif PLATFORM_SOC_VMQEMU
#include <soc/vmqemu/board.h>
#endif

#endif /* __soc_board_h_ */
