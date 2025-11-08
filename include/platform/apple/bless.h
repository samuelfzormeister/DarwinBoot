// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_BLESS_H__
#define __PLATFORM_APPLE_BLESS_H__

// efi-boot-device NVRAM variable contents
// array {
//   dict {
//     dict : IOMatch {
//       string : IOProviderClass
//       dict : IOPropertyMatch {
//         string : UUID  - root volume?
//	      }
//     }
//     string : BLLastBSDName - root volume BSD name?
//   }
//   dict {
//     string : IOEFIDevicePathType
//     string : Path
//   }

#define kIOMatchKey "IOMatch"

#define kIOProviderClassKey "IOProviderClass"
#define kIOPropertyMatchKey "IOPropertyMatch"

#define kBlessLastBSDName "BLLastBSDName"

#define kBlessDevicePathType "IOEFIDevicePathType"

#endif /* __PLATFORM_APPLE_BLESS_H__ */
