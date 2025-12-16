// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __soc_vmqemu64_memmap_h_
#define __soc_vmqemu64_memmap_h_

#define FLASH_BASE 0x00000000

/*
 * ALIAS: Device Tree blob base.
 */
#define SDRAM_BASE 0x40000000

#define DEVICETREE_BASE SDRAM_BASE

#endif /* __soc_vmqemu_memmap_h_ */
