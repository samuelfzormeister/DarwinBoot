// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_FILE_H__
#define __PLATFORM_EFI_PROTOCOLS_FILE_H__

#include <platform/efi/types.h>

typedef struct {
    efi_event_t event;
    efi_status_t status;
    uintn_t buf_size;
    void *buf;
} efi_file_io_token_t;

#define EFI_FILE_PROTOCOL_REVISION        0x00010000
#define EFI_FILE_PROTOCOL_REVISION2       0x00020000
#define EFI_FILE_PROTOCOL_LATEST_REVISION EFI_FILE_PROTOCOL_REVISION2

typedef struct _efi_file_protocol efi_file_protocol_t;

struct _efi_file_protocol {
    uint64_t revision;

    efi_status_t (*open)(efi_file_protocol_t *this, efi_file_protocol_t **new_handle, wchar_t *file_name, uint64_t mode, uint64_t attrs);
    efi_status_t (*close)(efi_file_protocol_t *this);
    efi_status_t (*delete)(efi_file_protocol_t *this);
    efi_status_t (*read)(efi_file_protocol_t *this, uintn_t *buf_size, void *buf);
    efi_status_t (*write)(efi_file_protocol_t *this, uintn_t *buf_size, void *buf);
    efi_status_t (*get_position)(efi_file_protocol_t *this, uint64_t *position);
    efi_status_t (*set_position)(efi_file_protocol_t *this, uint64_t position);
    efi_status_t (*get_info)(efi_file_protocol_t *this, efi_guid_t *info_type, uintn_t *buf_size, void *buf);
    efi_status_t (*set_info)(efi_file_protocol_t *this, efi_guid_t *info_type, uintn_t buf_size, void *buf);
    efi_status_t (*flush)(efi_file_protocol_t *this);

    /* Revision 2 functions. */
    efi_status_t (*open_ex)(efi_file_protocol_t *this, efi_file_protocol_t **new_handle,
                            wchar_t *file_name, uint64_t mode, uint64_t attrs, efi_file_io_token_t *token);
    efi_status_t (*read_ex)(efi_file_protocol_t *this, efi_file_io_token_t *token);
    efi_status_t (*write_ex)(efi_file_protocol_t *this, efi_file_io_token_t *token);
    efi_status_t (*flush_ex)(efi_file_protocol_t *this, efi_file_io_token_t *token);
};

enum {
    EFI_FILE_MODE_READ = 0x1,
    EFI_FILE_MODE_WRITE = 0x2,
    EFI_FILE_MODE_CREATE = 0x8000000000000000,
};

enum {
    EFI_FILE_READ_ONLY = 0x1,
    EFI_FILE_HIDDEN = 0x2,
    EFI_FILE_SYSTEM = 0x4,
    EFI_FILE_RESERVED = 0x8,
    EFI_FILE_DIRECTORY = 0x10,
    EFI_FILE_ARCHIVE = 0x20,
    EFI_FILE_VALID_ATTR = 0x37,
};

#define EFI_FILE_INFO_ID          \
    { 0x09576e92, 0x6d3f, 0x11d2, \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

struct {
    uint64_t size;
    uint64_t file_size;
    uint64_t physical_size;
    efi_time_t create_time;
    efi_time_t last_access_time;
    efi_time_t modification_time;
    uint64_t attributes;
    wchar_t file_name[];
} typedef efi_file_info_t;

#define EFI_FILE_SYSTEM_INFO_ID   \
    { 0x09576e93, 0x6d3f, 0x11d2, \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

struct {
    uint64_t size;
    bool read_only;
    uint64_t volume_size;
    uint64_t free_space;
    uint32_t block_size;
    wchar_t volume_name[];
} typedef efi_file_system_info_t;

#define EFI_FILE_SYSTEM_VOLUME_LABEL_ID   \
    { 0xdb47d7d3, 0xfe81, 0x11d3, 0x9a35, \
        { 0x00, 0x90, 0x27, 0x3f, 0xC1, 0x4d } }

struct {
    wchar_t volume_name[];
} typedef efi_file_system_volume_label_t;

#endif /* __PLATFORM_EFI_PROTOCOLS_FILE_H__ */
