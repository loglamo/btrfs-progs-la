/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 */

/*
 * Defines and function declarations for lowmem mode check.
 */
#ifndef __BTRFS_CHECK_MODE_LOWMEM_H__
#define __BTRFS_CHECK_MODE_LOWMEM_H__

#define ROOT_DIR_ERROR		(1U <<  1)	/* bad ROOT_DIR */
#define DIR_ITEM_MISSING	(1U <<  2)	/* DIR_ITEM not found */
#define DIR_ITEM_MISMATCH	(1U <<  3)	/* DIR_ITEM found but not match */
#define INODE_REF_MISSING	(1U <<  4)	/* INODE_REF/INODE_EXTREF not found */
#define INODE_ITEM_MISSING	(1U <<  5)	/* INODE_ITEM not found */
#define INODE_ITEM_MISMATCH	(1U <<  6)	/* INODE_ITEM found but not match */
#define FILE_EXTENT_ERROR	(1U <<  7)	/* bad FILE_EXTENT */
#define ODD_CSUM_ITEM		(1U <<  8)	/* CSUM_ITEM error */
#define CSUM_ITEM_MISSING	(1U <<  9)	/* CSUM_ITEM not found */
#define LINK_COUNT_ERROR	(1U << 10)	/* INODE_ITEM nlink count error */
#define NBYTES_ERROR		(1U << 11)	/* INODE_ITEM nbytes count error */
#define ISIZE_ERROR		(1U << 12)	/* INODE_ITEM size count error */
#define ORPHAN_ITEM		(1U << 13)	/* INODE_ITEM no reference */
#define NO_INODE_ITEM		(1U << 14)	/* no inode_item */
#define LAST_ITEM		(1U << 15)	/* Complete this tree traversal */
#define ROOT_REF_MISSING	(1U << 16)	/* ROOT_REF not found */
#define ROOT_REF_MISMATCH	(1U << 17)	/* ROOT_REF found but not match */
#define DIR_INDEX_MISSING       (1U << 18)	/* INODE_INDEX not found */
#define DIR_INDEX_MISMATCH      (1U << 19)	/* INODE_INDEX found but not match */
#define DIR_COUNT_AGAIN         (1U << 20)	/* DIR isize should be recalculated */
#define BG_ACCOUNTING_ERROR     (1U << 21)	/* Block group accounting error */
#define FATAL_ERROR             (1U << 22)	/* Fatal bit for errno */
#define INODE_FLAGS_ERROR	(1U << 23)	/* Invalid inode flags */
#define DIR_ITEM_HASH_MISMATCH	(1U << 24)	/* Dir item hash mismatch */
#define INODE_MODE_ERROR	(1U << 25)	/* Bad inode mode */
#define INVALID_GENERATION	(1U << 26)	/* Generation is too new */
#define SUPER_BYTES_USED_ERROR	(1U << 27)	/* Super bytes_used is invalid */
#define RAM_BYTES_MISMATCH	(1U << 27)	/* Non-compressed extent has wrong ram_bytes */

/*
 * Error bit for low memory mode check.
 *
 * Currently no caller cares about it yet.  Just internal use for error
 * classification.
 */
#define BACKREF_MISSING		(1U << 0)	/* Backref missing in extent tree */
#define BACKREF_MISMATCH	(1U << 1)	/* Backref exists but does not match */
#define BYTES_UNALIGNED		(1U << 2)	/* Some bytes are not aligned */
#define REFERENCER_MISSING	(1U << 3)	/* Referencer not found */
#define REFERENCER_MISMATCH	(1U << 4)	/* Referencer found but does not match */
#define CROSSING_STRIPE_BOUNDARY (1U << 4)	/* For kernel scrub workaround */
#define ITEM_SIZE_MISMATCH	(1U << 5)	/* Bad item size */
#define UNKNOWN_TYPE		(1U << 6)	/* Unknown type */
#define ACCOUNTING_MISMATCH	(1U << 7)	/* Used space accounting error */
#define CHUNK_TYPE_MISMATCH	(1U << 8)	/* Extent type and chunk type don't match */
#define BACKREF_OUT_OF_ORDER	(1U << 9)	/* Inline backrefs out of order */

int check_fs_roots_lowmem(void);
int check_chunks_and_extents_lowmem(void);

#endif
