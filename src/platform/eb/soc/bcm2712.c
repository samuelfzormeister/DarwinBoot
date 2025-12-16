// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <soc/soc.h>

/* long ass file path - should i change this? */
#include <drivers/bcm2835/aux_contorller.h>

static bcm2835_aux_controller_t *aux_con;

void soc_init(void)
{
    /*
     * STEPS:
     *
     * #1: Initialise the memory region for allocation
     *    - Boot CMS with this region. libc uses CMS.
     *
     * #2: Construct any devices needed at boot time.
     *    - We need serial, SDHCI for reading the parition, etc.
     *
     * #3: Initialise other libEmbeddedBoot subsystems.
     *    - Filesystems are essential, EB will need FAT32 + HFS at a minimum.
     *
     * #4: Proceed with App Boot.
     *    - This will go onto the next stage of booting or load the kernel.
     */
}
