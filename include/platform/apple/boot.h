// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_BOOT_H__
#define __PLATFORM_APPLE_BOOT_H__

#include <stdint.h>

/*
 * The Preboot volume is unique per boot on Apple Silicon platforms, I believe.
 *
 * Or at least unique enough to make me think that.
 *
 * The UUID is the UUID of the System volume, I believe.
 *
 * Within the Apple Silicon scheme, the 'active' file is a string for the 'boot ID' (I'm calling it that.)
 *
 * Tied to LocalPolicy?
 */
#define kPrebootActiveBootPath "/boot/active"

#define kAPTicketPath "/System/Library/Caches/apticket.der"

#if DEBUG
#define kDefaultSuffix ".debug"
#elif DEVELOPMENT
#define kDefaultSuffix ".development"
#else
#define kDefaultSuffix ""
#endif

/*
 * Common path for firmware files that live on-disk and on the Preboot volume.
 */
#define kFirmwarePath "/usr/standalone/firmware"

/*
 * There's plenty of other firmware files in the FUD directory, eg it has firmware for the:
 * - AGX
 * - ANE
 * - AOP
 * - DCP
 *
 * and plenty more other SoC components.
 */
#define kPersonalizedDeviceTreeFileName "devicetree"
#define kPersonalizedARVFileName "root_hash"
#define kPersonalizedBSARVFileName "base_system_root_hash"
#define kPersonalizediBootFileName "iBoot"
#define kPersonalizedBSTrustCacheFileName "FUD/BaseSystemTrustCache"
#define kPersonalizedStaticTrustCacheFileName "FUD/StaticTrustCache"

#define kFirmwareExtensionImage4 ".img4"
#define kFirmwareExtensionImage3 ".img3"

#endif /* __PLATFORM_APPLE_BOOT_H__ */
