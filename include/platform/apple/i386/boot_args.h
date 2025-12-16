// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_I386_BOOTARGS_H__
#define __PLATFORM_APPLE_I386_BOOTARGS_H__

#include <lib/types.h>

#define XNU_CURRENT_ARGS_VERSION  2
#define XNU_CURRENT_ARGS_REVISION 1

#define XNU_COMMANDLINE_SIZE 1024

/* doesn't seem to apply for ARM64/ARM32, interesting. */
enum {
    XNU_DISPLAY_CODE_GFX_MODE = 1,
    XNU_DISPLAY_CODE_FB_TEXT_MODE = 2,
} typedef xnu_display_code_t;

struct {
    uint32_t base_address;
    uint32_t display_code;
    uint32_t row_bytes;
    uint32_t width;
    uint32_t height;
    uint32_t pixel_depth;
} typedef xnu_video_args_v1_t;

struct {
    uint32_t display_code;
    uint32_t row_bytes;
    uint32_t width;
    uint32_t height;
    uint32_t pixel_depth;
    uint32_t rotation;
    uint8_t rsvd_bytes[3];
    uint32_t rsvd[6];
    uint64_t base_address;
} typedef xnu_video_args_t;

/* TODO: Legacy Backwards-compat? Mac OS X Snow Leopard and older have a different structure */

#define BOOT_ARGS_FLAGS_REBOOT_ON_PANIC   0x00000001
#define BOOT_ARGS_FLAGS_HIDPI             0x00000002
#define BOOT_ARGS_FLAGS_BLACK             0x00000004 /* disables the progress bar? */
#define BOOT_ARGS_FLAGS_CSR_ACTIVE_CONFIG 0x00000008
#define BOOT_ARGS_FLAGS_CSR_CONFIG_MODE   0x00000010
#define BOOT_ARGS_FLAGS_CSR_BOOT          0x00000020
#define BOOT_ARGS_FLAGS_BLACK_BACKGROUND  0x00000040
#define BOOT_ARGS_FLAGS_LOGINUI           0x00000080 /* filevault? */
#define BOOT_ARGS_FLAGS_INSTALLUI         0x00000100

typedef struct __packed {
    uint16_t revision;
    uint16_t version;
    uint8_t efi_mode;                           /* 32 for IA32 EFI, 64 for X64 EFI */
    uint8_t debug_mode;                         /* what does this actually do? */
    char command_line[XNU_COMMANDLINE_SIZE];
    uint32_t memory_map_ptr;                    /* 32-bit pointer/address to/of the memory map. (Physical) */

    /*
     * Here's another XNU mishap:
     * The MemMap gets copied over to a single page,
     * which can very quickly be violated by large memory maps,
     * Thx to OpenCorePkg & contributors for this knowledge
     */
    uint32_t memory_map_size;
    uint32_t memory_map_desc_size;
    uint32_t memory_map_desc_version;
    xnu_video_args_v1_t video_args_v1;
    uint32_t device_tree_ptr;                   /* 32-bit pointer/address to/of the DT. (Physical) */
    uint32_t device_tree_size;
    uint32_t kernel_address;                    /* Allegedly the start of __TEXT? */
    uint32_t kernel_size;                       /* Allegedly __TEXT size + __DATA size + EFI? how does this even work? Should I consult old Clover/Chameleon? */
    uint32_t efi_runtime_physical_page_base;    /* "physical address of defragmented runtime pages" */
    uint32_t efi_runtime_physical_page_count;
    uint32_t efi_runtime_virtual_page_base;     /* "virtual address of defragmented runtime pages" */
    uint32_t efi_system_table_ptr;              /* "physical address of system table in runtime area" */

    /*
     * So. I don't actually know how EfiBoot computes this but I might use the same tricks iOS does.
     *
     * The kernel can only reside in an address < 4GB, which eliminates a lot of wiggleroom.
     *
     * Dortania makes mention of slide values being computed similarly to this:
     * 0x100000 + ((1+0xRR) * 0x00200000)
     *
     * The key difference being that first literal, '0x100000' is '0x01000000' on iOS.
     *
     * So uh. Fun.
     */
    uint32_t kernel_slide;

    uint32_t perf_data_base;
    uint32_t perf_data_size;

    uint32_t keystore_data_base;
    uint32_t keystore_data;

    uint64_t boot_mem_base;
    uint64_t boot_mem_size;

    /*
     * This is collected from the SMBIOS data.
     */
    uint64_t phys_mem_size;

    /*
     * Bus Frequency... I'll have to research OpenCore for this.
     */
    uint64_t fsb_frequency;

    /*
     * STATUS UPDATE:
     *
     * PDACPIPlatform uses these fields for any PCI reads that might happen
     * before it grabs the MCFG table from the ACPICA layer, and while I doubt that's
     * even possible, it's better to be safe than sorry.
     */
    uint64_t pci_seg0_cfg_base;
    uint32_t pci_seg0_start_bus_num;
    uint32_t pci_seg0_end_bus_num;

    /*
     * CSR, 'Configurable Security Restriction' according to https://khronokernel.com/macos/2022/12/09/SIP.html,
     * Alternatively known as 'rootless' in userspace.
     *
     * This is configured in the csr-active-config NVRAM variable.
     */
    uint32_t csr_active_config;
    uint32_t csr_caps;

    /*
     * I believe macOS' EfiBoot reads from the SMC for this.
     */
    uint32_t boot_smc_plimit;

    uint16_t progress_meter_start; /* what */
    uint16_t progress_meter_end;   /* what */

    xnu_video_args_t video_args;

    /*
     * I don't know what these are.
     *
     * 'Physical address of apfs volume key structure'
     */
    uint32_t apfs_data_base;
    uint32_t apfs_data_size;

    uint64_t kc_hdrs_virtual_address; /* VAddr of the filesets? or just of the whole file? */

    /*
     * ARV - Authenticated Root Volume (I believe?)
     *
     * The 'hash' base might be the base address of the hash Image4 Payload? Or the hash itself?
     * As for the manifest base, I'd assume that's the base of an Image4 Manifest file.
     *
     * I guess the APFS kext validates these later down the line?
     *
     * I can also spot macOS' EfiBoot loading the cryptexes for some reason?
     * Does it place them in the memory-map for apfs.kext to graft it at boot?
     * How in the grand hell do cryptexes even work?
     */
    uint64_t arv_hash_base;
    uint64_t arv_hash_size;
    uint64_t arv_manifest_base;
    uint64_t arv_manifest_size;

    /*
     * These are alternatives for the BaseSystem.dmg image?
     *
     * I don't actually know where these come from, because Apple still has to support
     * the old chunklist method of authentication and signing.
     */
    uint64_t bs_arv_hash_base;
    uint64_t bs_arv_hash_size;
    uint64_t bs_arv_manifest_base;
    uint64_t bs_arv_manifest_size;
    uint32_t reserved[692];
} xnu_boot_args_t;

/* do i need to BootServices->SetVirtualAddressMap() before booting XNU? */
/* does it expect me to have switched to Virtual Memory before kernel load? */

#endif /* __PLATFORM_APPLE_I386_BOOTARGS_H__ */
