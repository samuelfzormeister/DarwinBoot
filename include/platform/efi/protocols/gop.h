// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_GOP_H__
#define __PLATFORM_EFI_PROTOCOLS_GOP_H__

#include <platform/efi/types.h>

#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \
    { 0x9042a9de, 0x23dc, 0x4a38,         \
        { 0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a } }

extern efi_guid_t gEfiGraphicsOutputProtocolGuid;

struct {
    uint32_t red_mask;
    uint32_t green_mask;
    uint32_t blue_mask;
    uint32_t reserved_mask;
} typedef efi_pixel_bitmask_t;

typedef enum {
    PixelRedGreenBlueReserved8BitPerColor,
    PixelBlueGreenRedReserved8BitPerColor,
    PixelBitMask,
    PixelBltOnly,
    PixelFormatMax
} efi_graphics_pixel_format_t;

struct {
    uint32_t version;
    uint32_t width;
    uint32_t height;
    efi_graphics_pixel_format_t format;
    efi_pixel_bitmask_t bitmask;
    uint32_t pixels_per_scan_line;
} typedef efi_graphics_output_mode_information_t;

struct {
    uint32_t max_mode;
    uint32_t mode;
    efi_graphics_output_mode_information_t *mode_info;
    uintn_t size_of_mode_info;
    efi_physical_address_t base_address;
    uintn_t fb_size;
} typedef efi_graphics_output_protocol_mode_t;

typedef struct _efi_graphics_output_protocol efi_graphics_output_protocol_t;

struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t Rsvd;
} typedef efi_graphics_output_blt_pixel_t;

typedef enum {
    EfiBltVideoFill,
    EfiBltVideoToBltBuffer,
    EfiBltBufferToVideo,
    EfiBltVideoToVideo,
    EfiGraphicsOutputBltOperationMax
} efi_graphics_output_blt_operation_t;

struct _efi_graphics_output_protocol {
    efi_status_t (*query_mode)(efi_graphics_output_protocol_t *this, uint32_t mode_number,
                               uintn_t *mode_info_size, efi_graphics_output_mode_information_t **mode_info);
    efi_status_t (*set_node)(efi_graphics_output_protocol_t *this, uint32_t mode_number);
    efi_status_t (*blt)(efi_graphics_output_protocol_t *this, efi_graphics_output_blt_pixel_t *blt_buf,
                    efi_graphics_output_blt_operation_t op, uintn_t src_x, uintn_t src_y,
                    uintn_t dst_x, uintn_t dst_y, uintn_t width, uintn_t height, uintn_t delta);
    efi_graphics_output_protocol_mode_t *Mode;
};

#endif /* __PLATFORM_EFI_PROTOCOLS_GOP_H__ */
