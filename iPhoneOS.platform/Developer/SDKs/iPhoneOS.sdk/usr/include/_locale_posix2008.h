/*
 * Copyright (c) 2005 - 2025 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef __LOCALE_POSIX2008_H_
#define __LOCALE_POSIX2008_H_

#include <sys/cdefs.h>
#include <_types.h>

_LIBC_SINGLE_BY_DEFAULT()

/*
 * These definitions were all historically provided by <xlocale.h>, but they
 * became standardized in POSIX.1-2008.  We make them available via either
 * <xlocale.h> or <locale.h> at the appropriate conformance level.
 */
#define LC_ALL_MASK			(  LC_COLLATE_MASK \
					 | LC_CTYPE_MASK \
					 | LC_MESSAGES_MASK \
					 | LC_MONETARY_MASK \
					 | LC_NUMERIC_MASK \
					 | LC_TIME_MASK )
#define LC_COLLATE_MASK			(1 << 0)
#define LC_CTYPE_MASK			(1 << 1)
#define LC_MESSAGES_MASK		(1 << 2)
#define LC_MONETARY_MASK		(1 << 3)
#define LC_NUMERIC_MASK			(1 << 4)
#define LC_TIME_MASK			(1 << 5)

#define _LC_NUM_MASK			6
#define _LC_LAST_MASK			(1 << (_LC_NUM_MASK - 1))

#define LC_GLOBAL_LOCALE		((locale_t)-1)
#define LC_C_LOCALE				((locale_t)NULL)

#include <_types/_locale_t.h>

__BEGIN_DECLS
locale_t	duplocale(locale_t);
int		freelocale(locale_t);
locale_t	newlocale(int, __const char *, locale_t);
locale_t	uselocale(locale_t);
__END_DECLS

#endif /* __LOCALE_POSIX2008_H_ */
