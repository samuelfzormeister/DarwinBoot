// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __lib_acpi_acpi_h_
#define __lib_acpi_acpi_h_

#include <stdbool.h>
#include <lib/types.h>
#include <platform/acpi/acpi.h>

#if CONFIG_EFI
#include <lib/efi/efi.h>
#endif

enum {
    ACPI_SUCCESS = 0,
    ACPI_BAD_CHECKSUM,
    ACPI_INVALID_SIGNATURE,
    ACPI_INVALID_PARAMETER,
    ACPI_NOT_FOUND,
} typedef acpi_result_t;

/*!
 * @function acpi_set_rsdp
 * Set the RSDP for libacpi to use for table manipulation
 *
 * @param rsdp
 * A pointer to the RSDP to use.
 *
 * @return
 * Returns true on success.
 */
acpi_result_t acpi_set_rsdp(acpi_rsdp_table_t *rsdp);

/*!
 * @function acpi_set_xsdp
 * Set the XSDP for libacpi to use for table manipulation
 *
 * @param xsdp
 * A pointer to the XSDP to use.
 *
 * @return
 * Returns true on success.
 */
acpi_result_t acpi_set_xsdp(acpi_xsdp_table_t *xsdp);

/*
 * @function apci_get_table_by_signature
 * Locate an ACPI table using the signature provided.
 *
 * @param signature
 * The signature of the ACPI table
 */
acpi_table_header_t *acpi_get_table_by_signature(const char *signature);

acpi_result_t acpi_validate_table(acpi_table_header_t *table);

#endif /* __lib_acpi_acpi_h_ */
