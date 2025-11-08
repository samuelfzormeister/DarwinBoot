// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __EMBEDDEDBOOT_DRIVERS_BCM2835_AUX_CONTROLLER_H__
#define __EMBEDDEDBOOT_DRIVERS_BCM2835_AUX_CONTROLLER_H__

#include <lib/embeddedboot/driver.h>

__BEGIN_DECLS

typedef struct _bcm2835_aux_controller_s bcm2835_aux_controller_t;

enum {
    BCM2835_AUX_PERIPHERAL_UART = 1,
    BCM2835_AUX_PERIPHERAL_SPI1,
    BCM2835_AUX_PERIPHERAL_SPI2,
} typedef bcm2835_aux_perph_t;

void bcm2835_aux_controller_enable_peripheral(bcm2835_aux_controller_t *aux, bcm2835_aux_perph_t perph);
void bcm2835_aux_controller_disable_peripheral(bcm2835_aux_controller_t *aux, bcm2835_aux_perph_t perph);

#define rAUX_IRQ                         0x0
#define AUX_IRQ__UART1_PENDING_IRQ       (1 << 0)
#define AUX_IRQ__UART1_PENDING_IRQ_MASK  (1 << 0)
#define AUX_IRQ__UART1_PENDING_IRQ_SHIFT 0
#define AUX_IRQ__SPI1_PENDING_IRQ        (1 << 1)
#define AUX_IRQ__SPI1_PENDING_IRQ_MASK   (1 << 1)
#define AUX_IRQ__SPI1_PENDING_IRQ_SHIFT  1
#define AUX_IRQ__SPI2_PENDING_IRQ        (1 << 2)
#define AUX_IRQ__SPI2_PENDING_IRQ_MASK   (1 << 2)
#define AUX_IRQ__SPI2_PENDING_IRQ_SHIFT  2

#define rAUX_ENABLES                    0x4
#define AUX_ENABLES__ENABLE_UART1       (1 << 0)
#define AUX_ENABLES__ENABLE_UART1_MASK  (1 << 0)
#define AUX_ENABLES__ENABLE_UART1_SHIFT 0
#define AUX_ENABLES__ENABLE_SPI1        (1 << 1)
#define AUX_ENABLES__ENABLE_SPI1_MASK   (1 << 1)
#define AUX_ENABLES__ENABLE_SPI1_SHIFT  1
#define AUX_ENABLES__ENABLE_SPI2        (1 << 2)
#define AUX_ENABLES__ENABLE_SPI2_MASK   (1 << 2)
#define AUX_ENABLES__ENABLE_SPI2_SHIFT  2


__END_DECLS

#endif
