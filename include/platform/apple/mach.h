// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_MACH_H__
#define __PLATFORM_APPLE_MACH_H__

#include <stdint.h>
#include <lib/types.h>
#include <platform/apple/arm/thread_state.h>
#include <platform/apple/i386/thread_state.h>

/*
 * Reference: https://github.com/apple-oss-distributions/cctools/blob/483f452caad0ebe3fbe198d3f8c2b1bea848df6c/include/mach-o/loader.h
 */

enum : int {
    CPU_ARCH_ABI64 = 0x01000000,
    CPU_ARCH_ABI64_32 = 0x0200000,

    CPU_TYPE_X86 = 7,
    CPU_TYPE_X86_64 = (CPU_TYPE_X86 | CPU_ARCH_ABI64),

    CPU_TYPE_ARM = 12,
    CPU_TYPE_ARM64 = (CPU_TYPE_ARM | CPU_ARCH_ABI64),
    CPU_TYPE_ARM64_32 = (CPU_TYPE_ARM | CPU_ARCH_ABI64_32),
} typedef cpu_type_t;

enum : uint32_t {
    CPU_SUBTYPE_LIB64 = 0x80000000,

    CPU_SUBTYPE_X86_64_ALL = 3,
    CPU_SUBTYPE_X86_ARCH1 = 4,
    CPU_SUBTYPE_X86_64_H = 8,

    CPU_SUBTYPE_ARM_ALL = 0,
    CPU_SUBTYPE_ARM_V4T = 5,
    CPU_SUBTYPE_ARM_V6 = 6,
    CPU_SUBTYPE_ARM_V5TEJ = 7,
    CPU_SUBTYPE_ARM_XSCALE = 8,
    CPU_SUBTYPE_ARM_V7 = 9,
    CPU_SUBTYPE_ARM_V7F = 10,
    CPU_SUBTYPE_ARM_V7S = 11,
    CPU_SUBTYPE_ARM_V7K = 12,
    CPU_SUBTYPE_ARM_V8 = 13,
    CPU_SUBTYPE_ARM_V6M = 14,
    CPU_SUBTYPE_ARM_V7M = 15,
    CPU_SUBTYPE_ARM_V7EM = 16,
    CPU_SUBTYPE_ARM_V8M = 17,
    CPU_SUBTYPE_ARM_V8M_BASE = 18,
    CPU_SUBTYPE_ARM_V8M_1M_MAIN = 19,

    CPU_SUBTYPE_ARM64_ALL = 0,
    CPU_SUBTYPE_ARM64_V8 = 1,
    CPU_SUBTYPE_ARM64E = 2,

    CPU_SUBTYPE_ARM64_32_ALL = 0,
    CPU_SUBTYPE_ARM64_32_V8 = 1,
} typedef cpu_subtype_t;

#define MH_MAGIC 0xFEEDFACE
#define MH_CIGAM 0xCEFAEDFE

struct mach_header {
    uint32_t magic;
    int32_t cputype;
    int32_t cpusubtype;
    uint32_t filetype;
    uint32_t ncmds;
    uint32_t sizeofcmds;
    uint32_t flags;
};

/* type aliases. */
typedef struct mach_header mach_header;
typedef mach_header MachHeader32;

#define MH_MAGIC_64 0xFEEDFACF
#define MH_CIGAM_64 0xCFFAEDFE

struct mach_header_64 {
    uint32_t magic;
    int32_t cputype;
    int32_t cpusubtype;
    uint32_t filetype;
    uint32_t ncmds;
    uint32_t sizeofcmds;
    uint32_t flags;
    uint32_t reserved;
};

typedef struct mach_header_64 mach_header_64;
typedef mach_header_64 MachHeader64;

#define MH_MAGIC_FAT 0xCAFEBABE
#define MH_CIGAM_FAT 0xBEBAFECA

struct mach_fat_header {
    uint32_t magic;
    uint32_t nslices;
    struct {
        cpu_type_t cpu_type;
        cpu_subtype_t cpu_subtype;
        uint32_t slice_offset;
        uint32_t slice_size;
        uint32_t sect_alignment;
    } slices[] __counted_by(nslices);
};

typedef struct mach_fat_header mach_fat_header;

/* filetype field */
enum {
    MH_OBJECT = 1,
    MH_EXECUTE,
    MH_FVMLIB,
    MH_CORE,
    MH_PRELOAD,
    MH_DYLIB,
    MH_DYLINKER,
    MH_BUNDLE,
    MH_DYILB_STUB,
    MH_DSYM,
    MH_KEXT_BUNDLE,
    MH_FILESET,
    MH_GPU_EXECUTE,
    MH_GPU_DYILB,
};

/* flags */
enum {
    MH_NOUNDEFS = 0x00000001,
    MH_INCRLINK = 0x00000002,
    MH_DYLDLINK = 0x00000004,
    MH_BINDATLOAD = 0x00000008,
    MH_PREBOUND = 0x00000010,
    MH_SPLIT_SEGS = 0x00000020,
    MH_LAZY_INIT = 0x00000040,
    MH_TWOLEVEL = 0x00000080,
    MH_FORCE_FLAT = 0x00000100,
    MH_NOMULTIDEFS = 0x00000200,
    MH_NOFIXPREBINDING = 0x00000400,
    MH_PREBINDABLE = 0x00000800,
    MH_ALLMODSBOUND = 0x00001000,
    MH_SUBSECTIONS_VIA_SYMBOLS = 0x00002000,
    MH_CANONICAL = 0x00004000,
    MH_WEAK_DEFINES = 0x00008000,
    MH_BINDS_TO_WEAK = 0x00010000,
    MH_ALLOW_STACK_EXECUTION = 0x00020000,
    MH_ROOT_SAFE = 0x00040000,
    MH_SETUID_SAFE = 0x00080000,
    MH_NO_REEXPORTED_DYLIBS = 0x00100000,
    MH_PIE = 0x00200000,
    MH_DEAD_STRIPPABLE_DYLIB = 0x00400000,
    MH_HAS_TLV_DESCRIPTORS = 0x00800000,
    MH_NO_HEAP_EXECUTION = 0x01000000,
    MH_APP_EXTENSION_SAFE = 0x02000000,
    MH_NLIST_OUTOFSYNC_WITH_DYLDINFO = 0x04000000,
    MH_SIM_SUPPORT = 0x08000000,
    MH_IMPLICIT_PAGEZERO = 0x10000000,
    MH_DYLIB_IN_CACHE = 0x80000000
};

struct load_command {
    uint32_t cmd;
    uint32_t cmdsize;
};

typedef struct load_command load_command;
typedef load_command MachLoadCommand;

enum : uint32_t {
    LC_REQ_DYLD = 0x80000000,

    LC_SEGMENT = 1,
    LC_SYMTAB,
    LC_SYMSEG,
    LC_THREAD,
    LC_UNIXTHREAD,
    LC_LOADFVMLIB,
    LC_IDFVMLIB,
    LC_IDENT,
    LC_FVMFILE,
    LC_PREPAGE,
    LC_DYSYMTAB,
    LC_LOAD_DYLIB,
    LC_ID_DYLIB,
    LC_LOAD_DYLINKER,
    LC_ID_DYLINKER,
    LC_PREBOUND_DYLIB,
    LC_ROUTINES,
    LC_SUB_FRAMEWORK,
    LC_SUB_UMBRELLA,
    LC_SUB_CLIENT,
    LC_SUB_LIBRARY,
    LC_TWOLEVEL_HINTS,
    LC_PREBIND_CKSUM,
    LC_LOAD_WEAK_DYLIB = (24 | LC_REQ_DYLD),
    LC_SEGMENT_64 = 25,
    LC_ROUTINES_64,
    LC_UUID,
    LC_RPATH = (28 | LC_REQ_DYLD),
    LC_CODE_SIGNATURE = 29,
    LC_SEGMENT_SPLIT_INFO,
    LC_REEXPORT_DYLIB  = (31 | LC_REQ_DYLD),
    LC_LAZY_LOAD_DYILB = 32,
    LC_ENCRYPTION_INFO,
    LC_DYLD_INFO,
    LC_DYLD_INFO_ONLY = (35 | LC_REQ_DYLD),
    LC_LOAD_UPWARD_DYLIB = (36 | LC_REQ_DYLD),
    LC_VERSION_MIN_MACOSX = 37,
    LC_VERSION_MIN_IPHONEOS,
    LC_FUNCTION_STARTS,
    LC_DYLD_ENVIRONMENT,
    LC_MAIN = (41 | LC_REQ_DYLD),
    LC_DATA_IN_CODE = 42,
    LC_SOURCE_VERSION,
    LC_DYLIB_CODE_SIGN_DRS,
    LC_ENCRYPTION_INFO_64,
    LC_LINKER_OPTION,
    LC_LINKER_OPTIMIZATION_HINT,
    LC_VERSION_MIN_TVOS,
    LC_VERSION_MIN_WATCHOS,
    LC_NOTE,
    LC_BUILD_VERSION,
    LC_DYLD_EXPORTS_TRIE = (52 | LC_REQ_DYLD),
    LC_DYLD_CHAINED_FIXSUPS = (53 | LC_REQ_DYLD),
    LC_FILESET_ENTRY = (54 | LC_REQ_DYLD),
    LC_ATOM_INFO = 55,
    LC_FUNCTION_VARIANTS,
    LC_FUNCTION_VARIANT_FIXUPS,
    LC_TARGET_TRIPLE,
};

union lc_str {
    uint32_t offset;
    /* ptr??? does it actually mean anything */
};

struct segment_command {
    uint32_t cmd;
    uint32_t cmdsize;
    char segname[16];
    uint32_t vmaddr;
    uint32_t vmsize;
    uint32_t fileoff;
    uint32_t filesize;
    int32_t maxprot;
    int32_t initprot;
    uint32_t nsects;
    uint32_t flags;
};

typedef struct segment_command segment_command;
typedef segment_command MachSegmentCommand32;

struct segment_command_64 {
    uint32_t cmd;
    uint32_t cmdsize;
    char segname[16];
    uint64_t vmaddr;
    uint64_t vmsize;
    uint64_t fileoff;
    uint64_t filesize;
    int32_t maxprot;
    int32_t initprot;
    uint32_t nsects;
    uint32_t flags;
};

typedef struct segment_command_64 segment_command_64;
typedef segment_command_64 MachSegmentCommand64;

enum : uint32_t {
    SG_HIGHVM = 0x00000001,
    SG_FVMLIB = 0x00000002,
    SG_NORELOC = 0x00000004,
    SG_PROTECTED_VERSION_1 = 0x00000008,
    SG_READ_ONLY = 0x00000010,
};

struct section {
    char sectname[16];
    char segname[16];
    uint32_t addr;
    uint32_t size;
    uint32_t offset;
    uint32_t align;
    uint32_t reloff;
    uint32_t nreloc;
    uint32_t flags;
    uint32_t reserved[2];
};

typedef struct section section;
typedef section MachSection32;

struct section_64 {
    char sectname[16];
    char segname[16];
    uint64_t addr;
    uint64_t size;
    uint32_t offset;
    uint32_t align;
    uint32_t reloff;
    uint32_t nreloc;
    uint32_t flags;
    uint32_t reserved[3];
};

typedef struct section_64 section_64;
typedef section_64 MachSection64;

enum : uint32_t {
    SECTION_TYPE = 0x000000FF,
    SECTION_ATTRIBUTES = 0xFFFFFF00,

    S_REGULAR = 0,
    S_ZEROFILL,
    S_CSTRING_LITERALS,
    S_4BYTE_LITERALS,
    S_8BYTE_LITERALS,
    S_LITERAL_POINTERS,
    S_NON_LAZY_SYMBOL_POINTERS,
    S_LAZY_SYMBOL_POINTERS,
    S_SYMBOL_STUBS,
    S_MOD_INIT_FUNC_POINTERS,
    S_MOD_TERM_FUNC_POINTERS,
    S_COALESCED,
    S_GB_ZEROFILL,
    S_INTERPOSING,
    S_16BYTE_LITERALS,
    S_DTRACE_DOF,
    S_LAZY_DYLIB_SYMBOL_POINTERS,
    S_THREAD_LOCAL_REGULAR,
    S_THREAD_LOCAL_ZEROFILL,
    S_THREAD_LOCAL_VARIABLES,
    S_THREAD_LOCAL_INIT_FUNCTION_POINTERS,
    S_INIT_FUNC_OFFSETS,

    S_ATTR_LOC_RELOC = 0x00000100,
    S_ATTR_EXT_RELOC = 0x00000200,
    S_ATTR_SOME_INSTRUCTIONS = 0x00000400,

    S_ATTR_DEBUG = 0x02000000,
    S_ATTR_SELF_MODIFYING_CODE = 0x04000000,
    S_ATTR_LIVE_SUPPORT = 0x08000000,
    S_ATTR_NO_DEAD_STRIP = 0x10000000,
    S_ATTR_STRIP_STATIC_SYMS = 0x20000000,
    S_ATTR_NO_TOC = 0x40000000,
    S_ATTR_PURE_INSTRUCTIONS = 0x80000000,
};

#define SEG_TEXT "__TEXT"

#define SEG_DATA "__DATA"

#define SEG_LINKEDIT "__LINKEDIT"

struct thread_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t flavor;
    uint32_t count;
    /* thread state structure */
};

struct symtab_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t symoff;
    uint32_t nsyms;
    uint32_t stroff;
    uint32_t strsize;
};

struct dysymtab_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t ilocalsym;
    uint32_t nlocalsym;
    uint32_t iextdefsym;
    uint32_t nextdefsym;
    uint32_t iundefsym;
    uint32_t nundefsym;
    uint32_t tocoff;
    uint32_t ntoc;
    uint32_t modtaboff;
    uint32_t nmodtab;
    uint32_t extrefsymoff;
    uint32_t nextrefsyms;
    uint32_t indirectsymoff;
    uint32_t nindirectsyms;
    uint32_t extreloff;
    uint32_t nextrel;
    uint32_t locreloff;
    uint32_t nlocrel;
};

enum {
    INDIRECT_SYMBOL_LOCAL = 0x80000000,
    INDIRECT_SYMBOL_ABS = 0x40000000,
};

struct uuid_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uuid_t uuid;
};

struct linkedit_data_command {
    uint32_t cmd; /* split seg, cs, chained fixups, atom info... */
    uint32_t cmdsize;
    uint32_t dataoff;
    uint32_t datasize;
};

enum : uint32_t {
    PLATFORM_UNKNOWN = 0,
    PLATFORM_ANY = 0xFFFFFFFF,

    PLATFORM_MACOS = 1,
    PLATFORM_IOS,
    PLATFORM_TVOS,
    PLATFORM_WATCHOS,
    PLATFORM_BRIDGEOS,
    PLATFORM_MACCATALYST,
    PLATFORM_IOSSIMULATOR,
    PLATFORM_TVOSSIMULATOR,
    PLATFORM_WATCHOSSIMULATOR,
    PLATFORM_DRIVERKIT,
    PLATFORM_VISIONOS,
    PLATFORM_VISIONOSSIMULATOR,
    PLATFORM_FIRMWARE,
    PLATFORM_SEPOS,
    PLATFORM_MACOS_EXCLAVECORE,
    PLATFORM_MACOS_EXCLAVEKIT,
    PLATFORM_IOS_EXCLAVECORE,
    PLATFORM_IOS_EXCLAVEKIT,
    PLATFORM_TVOS_EXCLAVECORE,
    PLATFORM_TVOS_EXCLAVEKIT,
    PLATFORM_WATCHOS_EXCLAVECORE,
    PLATFORM_WATCHOS_EXCLAVEKIT,
    PLATFORM_VISIONOS_EXCLAVECORE,
    PLATFORM_VISIONOS_EXCLAVEKIT,
};

enum {
    TOOL_CLANG = 1,
    TOOL_SWIFT,
    TOOL_LD,
    TOOL_LLD,

    TOOL_METAL = 1024,
    TOOL_AIRLLD,
    TOOL_AIRNT,
    TOOL_AIRNT_PLUGIN,
    TOOL_AIRPACK,
    TOOL_GPUARCHIVER,
    TOOL_METAL_FRAMEWORK,
};

struct build_tool_version {
    uint32_t tool;
    uint32_t version;
};

struct build_version_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t platform;
    uint32_t minos;
    uint32_t sdk;
    uint32_t ntools;
    struct build_tool_version tools[] __counted_by(ntools);
};

struct source_version_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint64_t version;
};

struct fileset_entry_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint64_t vmaddr;
    uint64_t fileoff;
    union lc_str entry_id;
    uint32_t reserved;
};

#endif /* __PLATFORM_APPLE_MACH_H__ */
