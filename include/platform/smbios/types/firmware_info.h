// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_FIRMWAREINFO_H__
#define __PLATFORM_SMBIOS_TYPES_FIRMWAREINFO_H__

#include <platform/smbios/types/entry_point.h>
#include <platform/smbios/types/header.h>

struct {
    smbios_table_header_t header;
    smbios_string_t firmware_vendor;
    smbios_string_t firmware_version;           /* string */
    uint16_t bios_location;             /* always zero for UEFI */
    smbios_string_t firmware_release_date;       /* string */
    uint8_t firmware_rom_size;           /* size = fwInfoTbl->FirmwareROMSize * 64KiB, 0xFF == 16MiB or larger */
    uint64_t firmware_features;         /* 'characteristics' */
    uint8_t firmware_features_ext;       /* extension bytes, vers 2.1+ */
    uint8_t firmware_features_ext2;      /* extension byte 2, vers 2.3+ */
    uint8_t platform_firmware_vers_major; /* 2.4+  from here */
    uint8_t platform_firmware_vers_minor;
    uint8_t ec_fw_version_major;
    uint8_t ec_fw_version_minor;
    uint16_t extended_rom_size; /* bits 0 - 13 are the size, bits 14 and 15 are unit indicators, 3.1+ */
} PACKED typedef smbios_firmware_info_t;

#define EXTENDEDROMSIZE_UNIT_SHIFT (14)

enum {
    /* bits 0 to 2 are unk/rsvd */
    FirmwareFeaturesUnsupported = (1 << 3),
    FirmwareFeaturesHasISA = (1 << 4),
    FirmwareFeaturesHasMCA = (1 << 5),
    FirmwareFeaturesHasEISA = (1 << 6),
    FirmwareFeaturesHasPCI = (1 << 7),
    FirmwareFeaturesHasPCMCIA = (1 << 8),
    FirmwareFeaturesHasPNP = (1 << 9),
    FirmwareFeaturesHasAPM = (1 << 10),
    FirmwareFeaturesHasUpgradableFwFlash = (1 << 11),
    FirmwareFeaturesFwShadowingAllowed = (1 << 12),
    FirmwareFeaturesHasVLVESA = (1 << 13),
    FirmwareFeaturesHasESCD = (1 << 14),
    FirmwareFeaturesHasCDBoot = (1 << 15),
    FirmwareFeaturesHasSelectableBoot = (1 << 16),
    FirmwareFeaturesHasSocketedROM = (1 << 17),
    FirmwareFeaturesCanBootFromPCMCIA = (1 << 18),
    FirmwareFeaturesHasEDDSpec = (1 << 19),
    FirmwareFeaturesHasNEC9800Support = (1 << 20),
    FirmwareFeaturesHasToshiba1dot2MbSupport = (1 << 21),
    FirmwareFeaturesHas360KbFloppySupport = (1 << 22),
    FirmwareFeaturesHas1dot2MbFloppySupport = (1 << 23),
    FirmwareFeaturesHas720KbFloppySupport = (1 << 24),
    FirmwareFeaturesHas2dot88MbFloppySupport = (1 << 25),
    FirmwareFeaturesHasInt5PrintScreenSupport = (1 << 26),
    FirmwareFeaturesHasInt98042KeyboardSupport = (1 << 27),
    FirmwareFeaturesHasInt14SerialSupport = (1 << 28),
    FirmwareFeaturesHasInt17PrinterSupport = (1 << 29),
    FirmwareFeaturesHasInt10CGAMonoVideoSupport = (1 << 30),
    FirmwareFeaturesHasNECPC98 = (1 << 31),
};

enum {
    ExtFirmwareFeaturesHasACPI = (1 << 0),
    ExtFirmwareFeaturesHasLegacyUSB = (1 << 1),
    ExtFirmwareFeaturesHasAGP = (1 << 2),
    ExtFirmwareFeaturesHasI2OBoot = (1 << 3),
    ExtFirmwareFeaturesHasLS120SuperDiskBoot = (1 << 4),
    ExtFirmwareFeaturesHasATAPIZIPDriveBoot = (1 << 5),
    ExtFirmwareFeaturesHas1394Boot = (1 << 6),
    ExtFirmwareFeaturesHasSmartBattery = (1 << 7),
};

enum {
    ExtFirmwareFeatures2HasBIOSBootSpec = (1 << 0),
    ExtFirmwareFeatures2HasFnKeyNetBoot = (1 << 1),
    ExtFirmwareFeatures2HasTargetedDistrib = (1 << 2),
    ExtFirmwareFeatures2HasUEFI = (1 << 3),
    ExtFirmwareFeatures2IsVMM = (1 << 4),
    ExtFirmwareFeatures2IsInManufacturingMode = (1 << 5),
    ExtFirmwareFeatures2ManufacturingModeEnabled = (1<< 6),
};

#endif /* __PLATFORM_SMBIOS_TYPES_FIRMWAREINFO_H__ */
