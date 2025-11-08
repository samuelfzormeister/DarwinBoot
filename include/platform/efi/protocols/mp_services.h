// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_MPSERVICES_H__
#define __PLATFORM_EFI_PROTOCOLS_MPSERVICES_H__

#include <platform/efi/types.h>

#define EFI_MP_SERVICES_PROTOCOL_GUID \
    { 0x3fdda605, 0xa76e, 0x4f46,     \
        { 0xad, 0x29, 0x12, 0xf4, 0x53, 0x1b, 0x3d, 0x08 } }

extern efi_guid_t gEfiMpServicesProtocolGuid;

typedef struct _efi_mp_services_protocol efi_mp_services_protocol_t;

typedef struct {
    uint32_t package;
    uint32_t core;
    uint32_t thread;
} efi_cpu_physical_location_t;

typedef struct {
    uint32_t package;
    uint32_t module;
    uint32_t tile;
    uint32_t die;
    uint32_t core;
    uint32_t thread;
} efi_cpu_physical_location2_t;

typedef union {
    efi_cpu_physical_location2_t Location2;
} extended_processor_information_t;

#define PROCESSOR_AS_BSP_BIT        0x1
#define PROCESSOR_ENABLED_BIT       0x2
#define PROCESSOR_HEALTH_STATUS_BIT 0x4

typedef struct {
    uint64_t processor_id;
    uint32_t status_flag;
    efi_cpu_physical_location_t location;
    extended_processor_information_t ext_info;
} efi_processor_information_t;

#define END_OF_CPU_LIST 0xffffffff

typedef void (*efi_ap_procedure_t)(void *Argument);

struct _efi_mp_services_protocol {
    efi_status_t (*get_number_of_processors)(efi_mp_services_protocol_t *this, uintn_t *num, uintn_t *num_enabled);
    efi_status_t (*get_processor_info)(efi_mp_services_protocol_t *this, uintn_t *processor, efi_processor_information_t *info_buf);
    efi_status_t (*startup_all_aps)(efi_mp_services_protocol_t *this,
                                    efi_ap_procedure_t procedure,
                                    bool single_thread,
                                    efi_event_t wait_event,
                                    uintn_t timeout,
                                    void *procedure_argument,
                                    uintn_t **failed_proc_list);
    efi_status_t (*startup_this_ap)(efi_mp_services_protocol_t *this,
                                    efi_ap_procedure_t procedure,
                                    uintn_t proc_number,
                                    efi_event_t wait_event,
                                    uintn_t timeout,
                                    void *procedure_argument,
                                    bool *finished);
    efi_status_t (*switch_bsp)(efi_mp_services_protocol_t *this, uintn_t proc_number, bool enable_old_bsp);
    efi_status_t (*enable_disable_ap)(efi_mp_services_protocol_t *this, uintn_t proc_number, bool enable_ap, uint32_t *health_flag);
    efi_status_t (*who_am_i)(efi_mp_services_protocol_t *this, uintn_t *proc_number);
};

#endif /* __PLATFORM_EFI_PROTOCOLS_MPSERVICES_H__ */
