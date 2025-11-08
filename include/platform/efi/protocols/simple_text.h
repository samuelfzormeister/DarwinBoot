// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_SIMPLETEXT_H__
#define __PLATFORM_EFI_PROTOCOLS_SIMPLETEXT_H__

#include <platform/efi/types.h>

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID \
    { 0x387477c1, 0x69c7, 0x11d2,           \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern efi_guid_t gEfiSimpleTextInputProtocolGuid;

typedef struct _efi_simple_text_input_protocol efi_simple_text_input_protocol_t;

struct _efi_simple_text_input_protocol {
    efi_status_t (*reset)(efi_simple_text_input_protocol_t *this, bool extended_verif);
    efi_status_t (*read_key_stroke)(efi_simple_text_input_protocol_t *this, efi_input_key_t *key);
    efi_event_t wait_for_key;
};

struct {
    int32_t max_mode;
    int32_t mode;
    int32_t attr;
    int32_t cursor_column;
    int32_t cursor_row;
    bool cursor_visible;
} typedef simple_text_output_mode_t;

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID \
    { 0x387477c2, 0x69c7, 0x11d2,            \
        { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

extern efi_guid_t gEfiSimpleTextOutputProtocolGuid;

typedef struct _efi_simple_text_output_protocol efi_simple_text_output_protocol_t;

struct _efi_simple_text_output_protocol {
    efi_status_t (*reset)(efi_simple_text_output_protocol_t *this, bool extended_verif);
    efi_status_t (*output_string)(efi_simple_text_output_protocol_t *this, wchar_t *string);
    efi_status_t (*test_string)(efi_simple_text_output_protocol_t *this, wchar_t *string);
    efi_status_t (*query_mode)(efi_simple_text_output_protocol_t *this, uint32_t mode_number, uint32_t *columns, uint32_t *rows);
    efi_status_t (*set_mode)(efi_simple_text_output_protocol_t *This, uint32_t mode_number);
    efi_status_t (*set_attribute)(efi_simple_text_output_protocol_t *this, uint32_t attribute);
    efi_status_t (*clear_screen)(efi_simple_text_output_protocol_t *this);
    efi_status_t (*set_cursor_position)(efi_simple_text_output_protocol_t *this, uintn_t column, uintn_t row);
    efi_status_t (*enable_cursor)(efi_simple_text_output_protocol_t *This);
    simple_text_output_mode_t *mode;
};

/* Attributes */
#define EFI_BLACK        0x0
#define EFI_BLUE         0x1
#define EFI_GREEN        0x2
#define EFI_CYAN         0x3
#define EFI_RED          0x4
#define EFI_MAGENTA      0x5
#define EFI_BROWN        0x6
#define EFI_LIGHTGRAY    0x7
#define EFI_BRIGHT       0x8
#define EFI_DARKGRAY     (EFI_BLACK | EFI_BRIGHT)
#define EFI_LIGHTBLUE    0x9
#define EFI_LIGHTGREEN   0xA
#define EFI_LIGHTCYAN    0xB
#define EFI_LIGHTRED     0xC
#define EFI_LIGHTMAGENTA 0xD
#define EFI_YELLOW       0xE
#define EFI_WHITE        0xF

#define EFI_BACKGROUND_BLACK     0x00
#define EFI_BACKGROUND_BLUE      0x10
#define EFI_BACKGROUND_GREEN     0x20
#define EFI_BACKGROUND_CYAN      0x30
#define EFI_BACKGROUND_RED       0x40
#define EFI_BACKGROUND_MAGENTA   0x50
#define EFI_BACKGROUND_BROWN     0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70

/* Unicode drawing characters */
#define BOXDRAW_HORIZONTAL                 0x2500
#define BOXDRAW_VERTICAL                   0x2502
#define BOXDRAW_DOWN_RIGHT                 0x250C
#define BOXDRAW_DOWN_LEFT                  0x2510
#define BOXDRAW_UP_RIGHT                   0x2514
#define BOXDRAW_UP_LEFT                    0x2518
#define BOXDRAW_VERTICAL_RIGHT             0x251C
#define BOXDRAW_VERTICAL_LEFT              0x2524
#define BOXDRAW_DOWN_HORIZONTAL            0x252C
#define BOXDRAW_UP_HORIZONTAL              0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL        0x253C
#define BOXDRAW_DOUBLE_HORIZONTAL          0x2550
#define BOXDRAW_DOUBLE_VERTICAL            0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE          0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT          0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT          0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE           0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT           0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT           0x2557
#define BOXDRAW_UP_RIGHT_DOUBLE            0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT            0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT            0x255A
#define BOXDRAW_UP_LEFT_DOUBLE             0x255B
#define BOXDRAW_UP_DOUBLE_LEFT             0x255C
#define BOXDRAW_DOUBLE_UP_LEFT             0x255D
#define BOXDRAW_VERTICAL_RIGHT_DOUBLE      0x255E
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT      0x255F
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT      0x2560
#define BOXDRAW_VERTICAL_LEFT_DOUBLE       0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT       0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT       0x2563
#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE     0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL     0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL     0x2566
#define BOXDRAW_UP_HORIZONTAL_DOUBLE       0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL       0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL       0x2569
#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256A
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256B
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256C

#define BLOCKELEMENT_FULL_BLOCK  0x2588
#define BLOCKELEMENT_LIGHT_SHADE 0x2591

#define GEOMETRICSHAPE_UP_TRIANGLE    0x25B2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE 0x25BA
#define GEOMETRICSHAPE_DOWN_TRIANGLE  0x25BC
#define GEOMETRICSHAPE_LEFT_TRIANGLE  0x25C4

#define ARROW_UP   0x2191
#define ARROW_DOWN 0x2193

#endif /* __PLATFORM_EFI_PROTOCOLS_SIMPLETEXT_H__ */
