// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <lib/acpi/acpi.h>
#include <string.h>

static acpi_rsdp_table_t *g_rsdp;
static acpi_xsdp_table_t *g_xsdp;

acpi_result_t acpi_validate_table(acpi_table_header_t *table)
{
    uint8_t sum = 0;

    for (size_t i = 0; i < table->length; i++) {
        sum += ((char *)table)[i];
    }

    if (sum == 0) {
        return ACPI_SUCCESS;
    } else {
        return ACPI_BAD_CHECKSUM;
    }
}

acpi_result_t acpi_set_rsdp(acpi_rsdp_table_t *rsdp)
{
    if (rsdp == NULL) {
        return ACPI_INVALID_PARAMETER;
    }

    if (strncmp(rsdp->signature, ACPI_RSDP_SIGNATURE, 8)) {
        return ACPI_INVALID_SIGNATURE;
    }

    uint32_t sum = 0;

    for (size_t i = 0; i < sizeof(acpi_rsdp_table_t); i++) {
        sum += ((uint8_t *)rsdp)[i];
    }

    // 'make sure the lowest byte of the result is equal to zero.'
    if ((sum & 0x000000FF) == 0) {
        g_rsdp = rsdp;
        return ACPI_SUCCESS;
    } else {
        return ACPI_BAD_CHECKSUM
    }
}
