// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_BOOTSERVICES_H__
#define __PLATFORM_EFI_TABLES_BOOTSERVICES_H__

#include <platform/efi/protocols/device_path.h>
#include <platform/efi/tables/header.h>
#include <platform/efi/types.h>

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION  EFI_SPECIFICATION_VERSION

enum {
    EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL = 0x1,
    EFI_OPEN_PROTOCOL_GET_PROTOCOL = 0x2,
    EFI_OPEN_PROTOCOL_TEST_PROTOCOL = 0x4,
    EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER = 0x8,
    EFI_OPEN_PROTOCOL_BY_DRIVER = 0x10,
    EFI_OPEN_PROTOCOL_EXCLUSIVE = 0x20
};

struct _efi_boot_services {
    efi_table_header_t header;

    /* Task Priority svcs. EFI 1.0+ */
    efi_tpl_t (*raise_tpl)(efi_tpl_t new_tpl);
    void (*restore_tpl)(efi_tpl_t old_tpl);

    /* memory svcs */
    efi_status_t (*allocate_pages)(efi_allocate_type_t type, efi_memory_type_t mem_type, uint32_t num_pages, efi_physical_address_t *mem);
    efi_status_t (*free_pages)(efi_physical_address_t mem, uint32_t num_pages);
    efi_status_t (*get_memory_map)(uintn_t *map_size, efi_memory_descriptor_t *map, uintn_t *out_key, uintn_t *desc_size, uint32_t *desc_version);
    efi_status_t (*allocate_pool)(efi_memory_type_t type, uintn_t size, void **buf);
    efi_status_t (*free_pool)(void *buf);

    /* others */
    efi_status_t (*create_event)(uint32_t type, efi_tpl_t tpl, efi_event_notify_t callback, void *context, efi_event_t *event);
    efi_status_t (*set_timer)(efi_event_t event, efi_timer_delay_t type, uint64_t trigger_time);
    efi_status_t (*wait_for_event)(uintn_t num_events, efi_event_t *event, uintn_t *index);
    efi_status_t (*signal_event)(efi_event_t event);
    efi_status_t (*close_event)(efi_event_t event);
    efi_status_t (*check_event)(efi_event_t event);

    /* Protocol Interfaces */
    efi_status_t (*install_protocol_interface)(efi_handle_t *handle, efi_guid_t *protocol, efi_interface_type_t type, void *interface);
    efi_status_t (*reinstall_protocol_interface)(efi_handle_t handle, efi_guid_t *protocol, void *oldxf, void *newxf);
    efi_status_t (*uninstall_protocol_interface)(efi_handle_t handle, efi_guid_t *protocol, void *interface);
    efi_status_t (*handle_protocol)(efi_handle_t handle, efi_guid_t *protocol, void **interface);
    void *reserved;
    efi_status_t (*register_protocol_notify)(efi_guid_t *protocol, efi_event_t event, void **registration);
    efi_status_t (*locate_handle)(efi_locate_search_type_t type, efi_guid_t *protocol, void *key, uintn_t *buf_size, efi_handle_t *buf);
    efi_status_t (*locate_device_path)(efi_guid_t *protocol, efi_device_path_protocol_t **dp, efi_handle_t *device);
    efi_status_t (*install_configuration_table)(efi_guid_t *guid, void *table);

    // UEFI Image Services
    efi_status_t (*load_image)(bool boot_policy, efi_handle_t parent_img_handle,
                               efi_device_path_protocol_t *dp, void *src_buffer, uintn_t src_size, efi_handle_t *img_handle);
    efi_status_t (*start_image)(efi_handle_t img_handle, uintn_t *exit_data_size, wchar_t **exit_data);
    efi_status_t (*exit)(efi_handle_t img_handle, efi_status_t status, uintn_t exit_data_size, wchar_t **exit_data);
    efi_status_t (*unload_image)(efi_handle_t img_handle);
    efi_status_t (*exit_boot_services)(efi_handle_t handle, uintn_t map_key);

    efi_status_t (*get_next_monotonic_count)(uint64_t *count);
    efi_status_t (*stall)(uint64_t usecs);
    efi_status_t (*set_watchdog_timer)(uintn_t timeout, uint64_t wdg_code, uint16_t data_size, wchar_t *wdg_data);

    efi_status_t (*connect_controller)(efi_handle_t controller_handle, efi_handle_t driver_img_handle,
                                       efi_device_path_protocol_t *remaining_dp, bool recusrive);
    efi_status_t (*disconnect_controller)(efi_handle_t controller_handle, efi_handle_t driver_img_handle, efi_handle_t child_handle);

    efi_status_t (*open_protocol)(efi_handle_t handle, efi_guid_t *protocol, void **interface,
                                  efi_handle_t agent_handle, efi_handle_t controller_handle, uint32_t attrs);
    efi_status_t (*close_protocol)(efi_handle_t handle, efi_guid_t *protocol, efi_handle_t agent_handle, efi_handle_t controller_handle);
    efi_status_t (*open_protocol_information)(efi_handle_t handle, efi_guid_t *protocol,
                                              efi_open_protocol_information_entry_t **entry_buf, uintn_t *num_entries);

    efi_status_t (*protocols_per_handle)(efi_handle_t handle, efi_guid_t ***protocol_buf, uintn_t *num_protocol_buffers);
    efi_status_t (*locate_handle_buffer)(efi_locate_search_type_t type, efi_guid_t *protocol,
                                         void *key, uintn_t *num_handles, efi_handle_t **handles);
    efi_status_t (*locate_protocol)(efi_guid_t *protocol, void *registration, void **interface);
    efi_status_t (*install_multiple_protocol_interfaces)(efi_handle_t *handle, ...);
    efi_status_t (*uninstall_multiple_protocol_interfaces)(efi_handle_t handle, ...);

    efi_status_t (*calculate_crc32)(void *data, uintn_t size, uint32_t *crc32);

    void (*copy_mem)(void *dst, void *src, uintn_t size);
    void (*set_mem)(void *buf, uintn_t size, uint8_t val);
    efi_status_t (*create_event_ex)(uint32_t type, efi_tpl_t notify_tpl, efi_event_notify_t notify_callback,
                                    const void *notify_context, const efi_guid_t *event_group, efi_event_t *event);
} typedef efi_boot_services_t;

#endif /* __PLATFORM_EFI_TABLES_BOOTSERVICES_H__ */
