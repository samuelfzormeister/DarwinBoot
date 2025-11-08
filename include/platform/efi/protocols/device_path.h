// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_DEVICEPATH_H__
#define __PLATFORM_EFI_PROTOCOLS_DEVICEPATH_H__

#include <platform/efi/types.h>

#define EFI_DEVICE_PATH_PROTOCOL_GUID \
    { 0x09576e91, 0x6d3f, 0x11d2,     \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern efi_guid_t gEfiDevicePathProtocolGuid;

enum {
    EFI_DEVICE_PATH_TYPE_HARDWARE = 1,
    EFI_DEVICE_PATH_TYPE_ACPI,
    EFI_DEVICE_PATH_TYPE_MESSAGING_DEVICE,
    EFI_DEVICE_PATH_TYPE_MEDIA_DEVICE,
    EFI_DEVICE_PATH_TYPE_BIOS_BOOT_SPEC,
};

enum {
    EFI_HARDWARE_PATH_SUBTYPE_PCI = 1,
    EFI_HARDWARE_PATH_SUBTYPE_PCCARD = 2,
    EFI_HARDWARE_PATH_SUBTYPE_MEMORYMAPPED = 3,
    EFI_HARDWARE_PATH_SUBTYPE_VENDOR = 4,
    EFI_HARDWARE_PATH_SUBTYPE_CONTROLLER = 5,
    EFI_HARDWARE_PATH_SUBTYPE_BMC = 6,
};

#define EFI_PNP_ID(ID)  (UINT32)(((ID) << 16) | 0x41D0)
#define EISA_PNP_ID(ID) EFI_PNP_ID(ID)

enum {
    EFI_ACPI_PATH_SUBTYPE_DEVICE = 1,
    EFI_ACPI_PATH_SUBTYPE_EXTENDED_DEVICE = 2,
    EFI_ACPI_PATH_SUBTYPE_ADR = 3,
    EFI_ACPI_PATH_SUBTYPE_NVDIMM = 4,
};

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
} typedef efi_device_path_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint8_t pci_function;
    uint8_t pci_device;
} typedef efi_device_path_pci_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    char hid[4];
    char uid[4];
} typedef efi_device_path_acpi_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    char hid[4];
    char uid[4];
    char cid[4];
    char strs[]; /* bruh */
} typedef efi_device_path_ext_acpi_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    char adr[4];
    char additional_adr[];
} typedef efi_device_path_acpi_adr_protocol_t;

enum {
    EFI_MESSAGED_PATH_SUBTYPE_ATAPI = 1,
    EFI_MESSAGED_PATH_SUBTYPE_SCSI = 2,
    EFI_MESSAGED_PATH_SUBTYPE_FIBRE_CHANNEL = 3,
    EFI_MESSAGED_PATH_SUBTYPE_1394 = 4,
    EFI_MESSAGED_PATH_SUBTYPE_USB = 5,
};

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint8_t primary_secondary;
    uint8_t slave_master;
    uint16_t logical_unit_number;
} typedef efi_device_path_messaged_atapi_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint16_t target_id;
    uint16_t logical_unit_number;
} typedef efi_device_path_messaged_scsi_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint32_t reserved;
    char world_wide_name[8];
    char logical_unit_number[8];
} typedef efi_device_path_messaged_fibre_channel_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint32_t reserved;
    char world_wide_name[8];
    char logical_unit_number[8];
} typedef efi_device_path_messaged_fibre_channel_ex_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint32_t reserved;
    efi_guid_t guid;
} typedef efi_device_path_messaged_1394_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint8_t parent_port_num;
    uint8_t interface_num;
} typedef efi_device_path_messaged_usb_protocol_t;

/* I genuinely cannot be bothered defining the rest of the Messaged types. */

/* Media Paths. Thank god. */

enum {
    EFI_MEDIA_PATH_SUBTYPE_HARD_DRIVE = 1,
    EFI_MEDIA_PATH_SUBTYPE_CDROM = 2,
    EFI_MEDIA_PATH_SUBTYPE_VENDOR = 3,
    EFI_MEDIA_PATH_SUBTYPE_FILE_PATH = 4,
    EFI_MEDIA_PATH_SUBTYPE_MEDIA_PROTOCOL = 5,
    EFI_MEDIA_PATH_SUBTYPE_RAM_DISK = 9,
};

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint32_t part_number;
    efi_lba_t starting_lba;
    uint64_t part_size;
    char part_signature[16];
    uint8_t part_format;
    uint8_t signature_type;
} typedef efi_device_path_media_hd_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    uint32_t boot_entry;
    efi_physical_address_t part_start;
    uint64_t part_size;
} typedef efi_device_path_media_cdrom_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    efi_guid_t vendor_guid;
    uint8_t vendor_data[];
} typedef efi_device_path_media_vendor_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    wchar_t path[];
} typedef efi_device_path_media_file_path_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    efi_guid_t protocol_guid;
} typedef efi_device_path_media_protocol_path_protocol_t;

struct {
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
    efi_physical_address_t base_address;
    efi_physical_address_t top_address;
    efi_guid_t disk_type;
    uint16_t disk_instance;
} typedef efi_device_path_media_ramdisk_protocol_t;

#define EFI_VIRTUAL_DISK_GUID     \
    { 0x77ab535a, 0x45fc, 0x624b, \
        { 0x55, 0x60, 0xf7, 0xb2, 0x81, 0xd1, 0xf9, 0x6e } }

#define EFI_VIRTUAL_CD_GUID       \
    { 0x3d5abd30, 0x4175, 0x87ce, \
        { 0x6d, 0x64, 0xd2, 0xad, 0xe5, 0x23, 0xc4, 0xbb } }

#define EFI_PERSISTENT_VIRTUAL_DISK_GUID \
    { 0x5cea02c9, 0x4d07, 0x69d3,        \
        { 0x26, 0x9f, 0x44, 0x96, 0xfb, 0xe0, 0x96, 0xf9 } }

#define EFI_PERSISTENT_VIRTUAL_CD_GUID \
    { 0x08018188, 0x42cd, 0xbb48,      \
        { 0x10, 0x0f, 0x53, 0x87, 0xd5, 0x3d, 0xed, 0x3d } }

extern efi_guid_t gEfiVirtualDiskGuid;
extern efi_guid_t gEfiVirtualCdGuid;
extern efi_guid_t gEfiPersistentVirtualDiskGuid;
extern efi_guid_t gEfiPersistentVirtualCdGuid;

#endif /* __PLATFORM_EFI_PROTOCOLS_DEVICEPATH_H__ */
