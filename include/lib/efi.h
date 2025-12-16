// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_efi_efi_h_
#define __lib_efi_efi_h_

#include <platform/efi/efi.h>

/*!
 * @function efi_initialize
 * Initialize libefi using the handle and system table of the current image.
 */
efi_status_t efi_initialize(efi_handle_t handle, efi_system_table_t *system_table);

efi_configuration_table_t *efi_get_configuration_table(efi_guid_t guid);

efi_system_table_t *efi_get_system_table(void);
efi_boot_services_t *efi_get_boot_services(void);
efi_runtime_services_t *efi_get_runtime_services(void);

efi_graphics_output_protocol_t *efi_get_graphics_output(void);

#endif /* __lib_efi_efi_h_ */
