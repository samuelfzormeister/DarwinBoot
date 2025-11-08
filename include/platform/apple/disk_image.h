// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_DISKIMAGE_H__
#define __PLATFORM_APPLE_DISKIMAGE_H__

#include <stdint.h>

// I CANNOT say enough thank yous to the OpenCorePkg contributors, Goldfish, vit, downloadfritz,
// ya'll are saints

#define APPLE_DMG_TRAILER_MAGIC 0x6B6F6C79

#define kRecoveryBootFilesPath "com.apple.recovery.boot"
#define kBaseSystemRamDiskName "BaseSystem.dmg"

// No compression impl yet, so I'll have to use a raw DMG until I decide the time is right
enum {
    kDMGChunkTypeCompressed = 0x80000000,

    kDMGChunkTypeZero = 0,
    kDMGChunkTypeRaw = 1,
    kDMGChunkTypeIgnore = 2,

    /* Compressed Types */
    kDMGChunkTypeADCCompressed = kDMGChunkTypeCompressed | 4, /* Apple Data Compression */
    kDMGChunkTypeZlibCompressed = kDMGChunkTypeCompressed | 5,
    kDMGChunkTypeBZip2Compressed = kDMGChunkTypeCompressed | 6,

    /* Others */
    kDMGChunkTypeComment = 0x7FFFFFFE, /* what does this actually mean */
    kDMGChunkTypeLastChunk = 0xFFFFFFFF,
};

enum {
    kDMGChecksumSize = 32,
};

enum {
    kDMGSectorSize = 512,
};

struct {
    uint32_t magic;
    // wip
} typedef dmg_trailer_t;

#endif /* __PLATFORM_APPLE_DISKIMAGE_H__ */
