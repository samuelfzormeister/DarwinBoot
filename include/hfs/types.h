// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __hfs_types_h_
#define __hfs_types_h_

#include <stdint.h>

#define HFSX_MAGIC 0x4858
#define HFSX_VERSION 4

#define HFSPLUS_MAGIC 0x482B
#define HFSPLUS_VERSION 5

#define HFSPLUS_DEFAULT_OFFSET 1024

enum {
    HFS_BTREE_TYPE = 0,

    USER_BTREE_TYPE = 127,

    RESERVED_BTREE_TYPE = 255,
};

enum {
    HFS_CASE_FOLDING = 0xCF,

    HFS_BINARY_COMPARE = 0xBC
};

enum {
    /* BTree wasn't closed properly; reserved on HFS+ */
    BT_BAD_CLOSE = 0x00000001,

    /* keyLength field is a uint16_t, always set on HFS+ */
    BT_BIG_KEYS = 0x00000002,

    /* keys in the node occupy keyLength worth of space, otherwise maxKeyLength */
    BT_VARIABLE_INDEX = 0x00000004,
};

typedef uint16_t hfs_unichar_t;

typedef struct hfs_unistr_255 {
    uint16_t length;
    hfs_unichar_t string[255];
} hfs_unistr_255_t;

/*
 * HFS+ Catalog:
 *
 * Inside the filesystem, there is a catalog file which is used to store data about the hierarchy/structure of files.
 *
 * The catalog file is organised using binary trees.
 */
typedef uint32_t hfs_catalog_node_id_t;

enum {
    HFS_ROOT_PARENT_ID = 1,
    HFS_ROOT_FOLDER_ID,
    HFS_EXTENTS_FILE_ID,
    HFS_CATALOG_FILE_ID,
    HFS_BAD_BLOCK_FILE_ID,
    HFS_ALLOCATION_FILE_ID,
    HFS_STARTUP_FILE_ID,
    HFS_ATTRIBUTES_FILE_ID,

    HFS_REPAIR_CATALOG_FILE_ID = 14,
    HFS_BOGUS_EXTENT_FILE_ID,
    HFS_FIRST_USER_CATALOG_FILE_ID,
};

typedef struct hfsplus_catalog_key {
    uint16_t key_length;
    hfs_catalog_node_id_t parent_id;
} hfsplus_catalog_key_t;

/* extent descriptor */
typedef struct hfsplus_extent_descriptor {
    uint32_t start_block;
    uint32_t block_count;
} hfsplus_extent_descriptor_t;

/* extent record */
typedef hfsplus_extent_descriptor_t hfsplus_extent_record_t[8];

typedef struct hfsplus_fork_data {
    uint64_t logical_size;
    uint32_t clump_size;
    uint32_t total_blocks;
    hfsplus_extent_record_t extents;
} hfsplus_fork_data_t;

typedef struct hfsplus_bsd_info {
    uint32_t owner_id;
    uint32_t group_id;
    uint8_t admin_flags;
    uint8_t owner_flags;
    uint16_t file_mode;
    union {
        uint32_t inode_num;
        uint32_t link_count;
        uint32_t raw_device;
    } special;
} hfsplus_bsd_info_t;

#define SF_ARCHIVED (1 << 0)
#define SF_IMMUTABLE (1 << 1)are
#define SF_APPEND (1 << 2)

typedef struct hfsplus_vol_header {
    /* 'H+' or 'HX' */
    uint16_t signature;
    uint16_t version;

    uint32_t attributes;

    /* 'HFSJ' or 'fsck' depending */
    uint32_t last_mounted_version;

    /* Allocation Block # of the allocation block that contains the HFS+ Journal */
    uint32_t journal_info_block;

    uint32_t create_date;
    uint32_t modified_date;
    uint32_t backup_date;
    uint32_t checked_date;

    uint32_t file_count;
    uint32_t folder_count;

    uint32_t block_size;
    uint32_t total_blocks;
    uint32_t free_blocks;

    uint32_t next_allocation;

    uint32_t rsrc_clump_size;
    uint32_t data_clump_size;

    hfs_catalog_node_id_t next_catalog_id;

    uint32_t write_count;

    uint64_t encodings_bitmap;

    /*
     * finder_info[0] = Directory ID of /System/Library/CoreServices
     * finder_info[1] = Parent Directory ID of startup application (?)
     */
    uint32_t finder_info[8];

    hfsplus_fork_data_t allocation_file; /* this is a bitmap apparently??? */
    hfsplus_fork_data_t extents_file;    /* i'll read the doc later */
    hfsplus_fork_data_t catalog_file;    /* something  */
    hfsplus_fork_data_t attributes_file; /* attrs */
    hfsplus_fork_data_t startup_file;    /* 100% just boot.efi. */
} hfsplus_vol_header_t;

#endif /* __hfs_types_h_ */
