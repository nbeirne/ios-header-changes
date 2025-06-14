/*
 * Copyright (c) 2016 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _SYS_SNAPSHOT_H_
#define _SYS_SNAPSHOT_H_


#include <sys/cdefs.h>
#include <machine/_types.h>
#include <sys/_types/_size_t.h>
#include <_types/_uint32_t.h>
#include <sys/attr.h>
#include <Availability.h>

__BEGIN_DECLS

int fs_snapshot_create(int, const char *, uint32_t) __OSX_AVAILABLE(10.12) __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

int fs_snapshot_list(int, struct attrlist  *, void *, size_t, uint32_t) __OSX_AVAILABLE(10.12) __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

int fs_snapshot_delete(int, const char *, uint32_t) __OSX_AVAILABLE(10.12) __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

int fs_snapshot_rename(int, const char *, const char *, uint32_t) __OSX_AVAILABLE(10.12) __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);


/* fs_snapshot_mount() supported flags */
#define SNAPSHOT_MNT_RESERVED1          0x00000001    /* same as MNT_RDONLY */
#define SNAPSHOT_MNT_NOEXEC             0x00000004    /* same as MNT_NOEXEC */
#define SNAPSHOT_MNT_NOSUID             0x00000008    /* same as MNT_NOSUID */
#define SNAPSHOT_MNT_NODEV              0x00000010    /* same as MNT_NODEV */
#define SNAPSHOT_MNT_DONTBROWSE         0x00100000    /* same as MNT_DONTBROWSE */
#define SNAPSHOT_MNT_IGNORE_OWNERSHIP   0x00200000    /* same as MNT_IGNORE_OWNERSHIP */
#define SNAPSHOT_MNT_NOFOLLOW           0x08000000    /* same as MNT_NOFOLLOW */

#define SNAPSHOT_MNT_VALIDMASK          0x0830001d


int fs_snapshot_mount(int, const char *, const char *, uint32_t) __OSX_AVAILABLE(10.12) __IOS_AVAILABLE(10.0)       __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

int fs_snapshot_revert(int, const char *, uint32_t) __OSX_AVAILABLE(10.12) __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);


__END_DECLS



#endif /* !_SYS_SNAPSHOT_H_ */
