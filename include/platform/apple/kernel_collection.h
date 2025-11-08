// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_KERNELCOLLECTION_H__
#define __PLATFORM_APPLE_KERNELCOLLECTION_H__

#include <platform/apple/mach.h>

/*
 * @group KernelCollection
 *
 * The newer KernelCollection format has likely been in the works since around 2018, given the
 * fact that dyld's API for libKernelCollectionBuilder was given an API_AVAILABLE of macOS Mojave.
 *
 * The KernelCollection files are made up of a collection of Mach-O files, being called a 'fileset'
 * under the hood.
 *
 * With fileset kernelcache files, Apple didn't bother with compression, leaving the final file
 * with a standard Mach-O header (thank god) and creating a new Mach-O file type.
 */

#define kBootKernelCollectionPath      "/System/Library/KernelCollections/BootKernelCollection.kc"
#define kSystemKernelCollectionPath    "/System/Library/KernelCollections/SystemKernelCollection.kc"
#define kAuxiliaryKernelCollectionPath "/Library/KernelCollections/AuxiliaryKernelCollection.kc"

#endif /* __PLATFORM_APPLE_KERNELCOLLECTION_H__ */
