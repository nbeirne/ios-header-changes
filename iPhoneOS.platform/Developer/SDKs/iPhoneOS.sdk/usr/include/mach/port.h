/*
 * Copyright (c) 2000-2006 Apple Computer, Inc. All rights reserved.
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
/*
 * @OSF_COPYRIGHT@
 */
/*
 * Mach Operating System
 * Copyright (c) 1991,1990,1989,1988,1987 Carnegie Mellon University
 * All Rights Reserved.
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */
/*
 * NOTICE: This file was modified by McAfee Research in 2004 to introduce
 * support for mandatory and extensible security protections.  This notice
 * is included in support of clause 2.2 (b) of the Apple Public License,
 * Version 2.0.
 */
/*
 */
/*
 *	File:	mach/port.h
 *
 *	Definition of a Mach port
 *
 *	Mach ports are the endpoints to Mach-implemented communications
 *	channels (usually uni-directional message queues, but other types
 *	also exist).
 *
 *	Unique collections of these endpoints are maintained for each
 *	Mach task.  Each Mach port in the task's collection is given a
 *	[task-local] name to identify it - and the the various "rights"
 *	held by the task for that specific endpoint.
 *
 *	This header defines the types used to identify these Mach ports
 *	and the various rights associated with them.  For more info see:
 *
 *	<mach/mach_port.h> - manipulation of port rights in a given space
 *	<mach/message.h> - message queue [and port right passing] mechanism
 *
 */

#ifndef _MACH_PORT_H_
#define _MACH_PORT_H_

#include <sys/cdefs.h>
#include <stdint.h>
#include <mach/boolean.h>
#include <mach/machine/vm_types.h>

/*
 *	mach_port_name_t - the local identity for a Mach port
 *
 *	The name is Mach port namespace specific.  It is used to
 *	identify the rights held for that port by the task whose
 *	namespace is implied [or specifically provided].
 *
 *	Use of this type usually implies just a name - no rights.
 *	See mach_port_t for a type that implies a "named right."
 *
 */

typedef natural_t mach_port_name_t;
typedef mach_port_name_t *mach_port_name_array_t;


/*
 *	mach_port_t - a named port right
 *
 *	In user-space, "rights" are represented by the name of the
 *	right in the Mach port namespace.  Even so, this type is
 *	presented as a unique one to more clearly denote the presence
 *	of a right coming along with the name.
 *
 *	Often, various rights for a port held in a single name space
 *	will coalesce and are, therefore, be identified by a single name
 *	[this is the case for send and receive rights].  But not
 *	always [send-once rights currently get a unique name for
 *	each right].
 *
 */

#include <sys/_types.h>
#include <sys/_types/_mach_port_t.h>


typedef mach_port_t                     *mach_port_array_t;

/*
 *  MACH_PORT_NULL is a legal value that can be carried in messages.
 *  It indicates the absence of any port or port rights.  (A port
 *  argument keeps the message from being "simple", even if the
 *  value is MACH_PORT_NULL.)  The value MACH_PORT_DEAD is also a legal
 *  value that can be carried in messages.  It indicates
 *  that a port right was present, but it died.
 */

#define MACH_PORT_NULL          0  /* intentional loose typing */
#define MACH_PORT_DEAD          ((mach_port_name_t) ~0)
#define MACH_PORT_VALID(name)                           \
	        (((name) != MACH_PORT_NULL) &&          \
	         ((name) != MACH_PORT_DEAD))


/*
 *	For kernel-selected [assigned] port names, the name is
 *	comprised of two parts: a generation number and an index.
 *	This approach keeps the exact same name from being generated
 *	and reused too quickly [to catch right/reference counting bugs].
 *	The dividing line between the constituent parts is exposed so
 *	that efficient "mach_port_name_t to data structure pointer"
 *	conversion implementation can be made.
 */

#define MACH_PORT_INDEX(name)           ((name) >> 8)
#define MACH_PORT_GEN(name)             (((name) & 0xff) << 24)
#define MACH_PORT_MAKE(index, gen)      (((index) << 8) | ((gen) >> 24))

/*
 *  These are the different rights a task may have for a port.
 *  The MACH_PORT_RIGHT_* definitions are used as arguments
 *  to mach_port_allocate, mach_port_get_refs, etc, to specify
 *  a particular right to act upon.  The mach_port_names and
 *  mach_port_type calls return bitmasks using the MACH_PORT_TYPE_*
 *  definitions.  This is because a single name may denote
 *  multiple rights.
 */

typedef natural_t mach_port_right_t;

#define MACH_PORT_RIGHT_SEND            ((mach_port_right_t) 0)
#define MACH_PORT_RIGHT_RECEIVE         ((mach_port_right_t) 1)
#define MACH_PORT_RIGHT_SEND_ONCE       ((mach_port_right_t) 2)
#define MACH_PORT_RIGHT_PORT_SET        ((mach_port_right_t) 3)
#define MACH_PORT_RIGHT_DEAD_NAME       ((mach_port_right_t) 4)
#define MACH_PORT_RIGHT_LABELH          ((mach_port_right_t) 5) /* obsolete right */
#define MACH_PORT_RIGHT_NUMBER          ((mach_port_right_t) 6) /* right not implemented */

#define MACH_PORT_TYPE(right)                                   \
	((mach_port_type_t)(((mach_port_type_t) 1)              \
	<< ((right) + ((mach_port_right_t) 16))))

typedef natural_t mach_port_type_t;
typedef mach_port_type_t *mach_port_type_array_t;

#define MACH_PORT_TYPE_NONE             ((mach_port_type_t) 0L)
#define MACH_PORT_TYPE_SEND             MACH_PORT_TYPE(MACH_PORT_RIGHT_SEND)
#define MACH_PORT_TYPE_RECEIVE          MACH_PORT_TYPE(MACH_PORT_RIGHT_RECEIVE)
#define MACH_PORT_TYPE_SEND_ONCE        MACH_PORT_TYPE(MACH_PORT_RIGHT_SEND_ONCE)
#define MACH_PORT_TYPE_PORT_SET         MACH_PORT_TYPE(MACH_PORT_RIGHT_PORT_SET)
#define MACH_PORT_TYPE_DEAD_NAME        MACH_PORT_TYPE(MACH_PORT_RIGHT_DEAD_NAME)
#define MACH_PORT_TYPE_LABELH           MACH_PORT_TYPE(MACH_PORT_RIGHT_LABELH) /* obsolete */
/* Dummy type bits that mach_port_type/mach_port_names can return. */
#define MACH_PORT_TYPE_DNREQUEST        0x80000000
#define MACH_PORT_TYPE_SPREQUEST        0x40000000
#define MACH_PORT_TYPE_SPREQUEST_DELAYED 0x20000000

/* Convenient combinations. */

#define MACH_PORT_TYPE_SEND_RECEIVE                                     \
	(MACH_PORT_TYPE_SEND|MACH_PORT_TYPE_RECEIVE)
#define MACH_PORT_TYPE_SEND_RIGHTS                                      \
	(MACH_PORT_TYPE_SEND|MACH_PORT_TYPE_SEND_ONCE)
#define MACH_PORT_TYPE_PORT_RIGHTS                                      \
	(MACH_PORT_TYPE_SEND_RIGHTS|MACH_PORT_TYPE_RECEIVE)
#define MACH_PORT_TYPE_PORT_OR_DEAD                                     \
	(MACH_PORT_TYPE_PORT_RIGHTS|MACH_PORT_TYPE_DEAD_NAME)
#define MACH_PORT_TYPE_ALL_RIGHTS                                       \
	(MACH_PORT_TYPE_PORT_OR_DEAD|MACH_PORT_TYPE_PORT_SET)

/* User-references for capabilities. */

typedef natural_t mach_port_urefs_t;
typedef integer_t mach_port_delta_t;                    /* change in urefs */

/* Attributes of ports.  (See mach_port_get_receive_status.) */

typedef natural_t mach_port_seqno_t;            /* sequence number */
typedef natural_t mach_port_mscount_t;          /* make-send count */
typedef natural_t mach_port_msgcount_t;         /* number of msgs */
typedef natural_t mach_port_rights_t;           /* number of rights */

/*
 *	Are there outstanding send rights for a given port?
 */
#define MACH_PORT_SRIGHTS_NONE          0               /* no srights */
#define MACH_PORT_SRIGHTS_PRESENT       1               /* srights */
typedef unsigned int mach_port_srights_t;       /* status of send rights */

typedef struct mach_port_status {
	mach_port_rights_t      mps_pset;       /* count of containing port sets */
	mach_port_seqno_t       mps_seqno;      /* sequence number */
	mach_port_mscount_t     mps_mscount;    /* make-send count */
	mach_port_msgcount_t    mps_qlimit;     /* queue limit */
	mach_port_msgcount_t    mps_msgcount;   /* number in the queue */
	mach_port_rights_t      mps_sorights;   /* how many send-once rights */
	boolean_t               mps_srights;    /* do send rights exist? */
	boolean_t               mps_pdrequest;  /* port-deleted requested? */
	boolean_t               mps_nsrequest;  /* no-senders requested? */
	natural_t               mps_flags;              /* port flags */
} mach_port_status_t;

/* System-wide values for setting queue limits on a port */
#define MACH_PORT_QLIMIT_ZERO           (0)
#define MACH_PORT_QLIMIT_BASIC          (5)
#define MACH_PORT_QLIMIT_SMALL          (16)
#define MACH_PORT_QLIMIT_LARGE          (1024)
#define MACH_PORT_QLIMIT_KERNEL         (65534)
#define MACH_PORT_QLIMIT_MIN            MACH_PORT_QLIMIT_ZERO
#define MACH_PORT_QLIMIT_DEFAULT        MACH_PORT_QLIMIT_BASIC
#define MACH_PORT_QLIMIT_MAX            MACH_PORT_QLIMIT_LARGE

typedef struct mach_port_limits {
	mach_port_msgcount_t    mpl_qlimit;     /* number of msgs */
} mach_port_limits_t;

/* Possible values for mps_flags (part of mach_port_status_t) */
#define MACH_PORT_STATUS_FLAG_TEMPOWNER         0x01
#define MACH_PORT_STATUS_FLAG_GUARDED           0x02
#define MACH_PORT_STATUS_FLAG_STRICT_GUARD      0x04
#define MACH_PORT_STATUS_FLAG_IMP_DONATION      0x08
#define MACH_PORT_STATUS_FLAG_REVIVE            0x10
#define MACH_PORT_STATUS_FLAG_TASKPTR           0x20
#define MACH_PORT_STATUS_FLAG_GUARD_IMMOVABLE_RECEIVE 0x40
#define MACH_PORT_STATUS_FLAG_NO_GRANT          0x80 /* Obsolete */

typedef struct mach_port_info_ext {
	mach_port_status_t      mpie_status;
	mach_port_msgcount_t    mpie_boost_cnt;
	uint32_t                reserved[6];
} mach_port_info_ext_t;

typedef struct mach_port_guard_info {
	uint64_t    mpgi_guard;     /* guard value */
} mach_port_guard_info_t;

typedef integer_t *mach_port_info_t;            /* varying array of natural_t */

/* Flavors for mach_port_get/set/assert_attributes() */
typedef int     mach_port_flavor_t;
#define MACH_PORT_LIMITS_INFO           1       /* uses mach_port_limits_t */
#define MACH_PORT_RECEIVE_STATUS        2       /* uses mach_port_status_t */
#define MACH_PORT_DNREQUESTS_SIZE       3       /* info is int */
#define MACH_PORT_TEMPOWNER             4       /* indicates receive right will be reassigned to another task */
#define MACH_PORT_IMPORTANCE_RECEIVER   5       /* indicates recieve right accepts priority donation */
#define MACH_PORT_DENAP_RECEIVER        6       /* indicates receive right accepts de-nap donation */
#define MACH_PORT_INFO_EXT              7       /* uses mach_port_info_ext_t */
#define MACH_PORT_GUARD_INFO            8       /* asserts if the strict guard value is correct */
#define MACH_PORT_SERVICE_THROTTLED     9       /* info is an integer that indicates if service port is throttled or not */

#define MACH_PORT_LIMITS_INFO_COUNT     ((natural_t) \
	(sizeof(mach_port_limits_t)/sizeof(natural_t)))
#define MACH_PORT_RECEIVE_STATUS_COUNT  ((natural_t) \
	(sizeof(mach_port_status_t)/sizeof(natural_t)))
#define MACH_PORT_DNREQUESTS_SIZE_COUNT 1
#define MACH_PORT_INFO_EXT_COUNT        ((natural_t) \
	(sizeof(mach_port_info_ext_t)/sizeof(natural_t)))
#define MACH_PORT_GUARD_INFO_COUNT      ((natural_t) \
	(sizeof(mach_port_guard_info_t)/sizeof(natural_t)))
#define MACH_PORT_SERVICE_THROTTLED_COUNT 1

/*
 * Structure used to pass information about port allocation requests.
 * Must be padded to 64-bits total length.
 */
typedef struct mach_port_qos {
	unsigned int            name:1;         /* name given */
	unsigned int            prealloc:1;     /* prealloced message */
	boolean_t               pad1:30;
	natural_t               len;
} mach_port_qos_t;

/*
 * Structure used to pass information about the service port
 */
#define MACH_SERVICE_PORT_INFO_STRING_NAME_MAX_BUF_LEN  255    /* Maximum length of the port string name buffer */

typedef struct mach_service_port_info {
	char                    mspi_string_name[MACH_SERVICE_PORT_INFO_STRING_NAME_MAX_BUF_LEN]; /* Service port's string name */
	uint8_t                 mspi_domain_type;          /* Service port domain */
} mach_service_port_info_data_t;

#define MACH_SERVICE_PORT_INFO_COUNT ((char) \
	(sizeof(mach_service_port_info_data_t)/sizeof(char)))

typedef struct mach_service_port_info * mach_service_port_info_t;

/*
 * Platform binaries are not allowed to send OOL port array to any port.
 *
 * MACH_MSG_OOL_PORTS_DESCRIPTOR are allowed to be sent ONLY to receive
 * rights that are explicitly allow to receive that descriptor.
 *
 * Such ports have a dedicated port type, and are created using the
 * MPO_CONNECTION_PORT_WITH_PORT_ARRAY flag.
 *
 * Creation of such ports requires the binary to have the following entitlement.
 */
#define MACH_PORT_CONNECTION_PORT_WITH_PORT_ARRAY "com.apple.developer.allow-connection-port-with-port-array"

/* Allows 1p process to create provisional reply port (to be rename to weak reply port) */
#define MACH_PORT_PROVISIONAL_REPLY_ENTITLEMENT "com.apple.private.allow-weak-reply-port"

/*
 * Flags for mach_port_options (used for
 * invocation of mach_port_construct).
 * Indicates attributes to be set for the newly
 * allocated port.
 */

/* MPO options flags */
#define MPO_OPTIONS_MASK                    (~MPO_PORT_TYPE_MASK)
#define MPO_CONTEXT_AS_GUARD                 0x01    /* Add guard to the port */
#define MPO_QLIMIT                           0x02    /* Set qlimit for the port msg queue */
#define MPO_TEMPOWNER                        0x04    /* Set the tempowner bit of the port */
#define MPO_IMPORTANCE_RECEIVER              0x08    /* Mark the port as importance receiver */
#define MPO_INSERT_SEND_RIGHT                0x10    /* Insert a send right for the port */
#define MPO_STRICT                           0x20    /* Apply strict guarding for port */
#define MPO_DENAP_RECEIVER                   0x40    /* Mark the port as App de-nap receiver */
#define MPO_IMMOVABLE_RECEIVE                0x80    /* Mark the port as immovable; protected by the guard context */
#define MPO_FILTER_MSG                       0x100   /* Allow message filtering */
#define MPO_TG_BLOCK_TRACKING                0x200   /* Track blocking relationship for thread group during sync IPC */
#define MPO_ENFORCE_REPLY_PORT_SEMANTICS     0x2000  /* When talking to this port, local port of mach msg needs to follow reply port semantics.*/
/* This service port has requested security hardening */
#define MPO_STRICT_SERVICE_PORT         (MPO_SERVICE_PORT | MPO_ENFORCE_REPLY_PORT_SEMANTICS)

/* MPO port type flags */
#define MPO_MAKE_PORT_TYPE(a, b)   (((a & 0x7) << 14) | ((b & 0x7) << 10))
#define MPO_PORT_TYPE_MASK          MPO_MAKE_PORT_TYPE(0x7, 0x7) /* 0x1dc00 */
/* These need to be defined for libxpc and other clients who `#ifdef` */
	#define MPO_PORT                            MPO_PORT
	#define MPO_SERVICE_PORT                    MPO_SERVICE_PORT
	#define MPO_CONNECTION_PORT                 MPO_CONNECTION_PORT
	#define MPO_REPLY_PORT                      MPO_REPLY_PORT
	#define MPO_PROVISIONAL_REPLY_PORT          MPO_PROVISIONAL_REPLY_PORT
	#define MPO_EXCEPTION_PORT                  MPO_EXCEPTION_PORT
	#define MPO_CONNECTION_PORT_WITH_PORT_ARRAY MPO_CONNECTION_PORT_WITH_PORT_ARRAY
__options_decl(mpo_flags_t, uint32_t, {
	/* Your classic IOT_PORT, an uninteresting message queue */
	MPO_PORT                            = MPO_MAKE_PORT_TYPE(0, 0),  /* 0x0 */
	/* Create a service port with the given name; should be used only by launchd */
	MPO_SERVICE_PORT                    = MPO_MAKE_PORT_TYPE(0, 1),  /* 0x400 */
	/* Derive new peer connection port from a given service port */
	MPO_CONNECTION_PORT                 = MPO_MAKE_PORT_TYPE(0, 2),  /* 0x800 */
	/* Designate port as a reply port */
	MPO_REPLY_PORT                      = MPO_MAKE_PORT_TYPE(0, 4),  /* 0x1000 */
	/* Designate port as a provisional (fake) reply port */
	MPO_PROVISIONAL_REPLY_PORT          = MPO_MAKE_PORT_TYPE(1, 0),  /* 0x4000 */
	/* Used for hardened exceptions - immovable */
	MPO_EXCEPTION_PORT                  = MPO_MAKE_PORT_TYPE(2, 0),  /* 0x8000 */
	/* Can receive OOL port array descriptors */
	MPO_CONNECTION_PORT_WITH_PORT_ARRAY = MPO_MAKE_PORT_TYPE(4, 0),  /* 0x10000 */
});
#define MPO_UNUSED_BITS         ~(MPO_OPTIONS_MASK | MPO_PORT_TYPE_MASK)

/* Denotes an anonymous service */
#define MPO_ANONYMOUS_SERVICE   (MACH_PORT_DEAD - 1)

/*
 * Structure to define optional attributes for a newly
 * constructed port.
 */
typedef struct mach_port_options {
	uint32_t                flags;
	mach_port_limits_t      mpl;            /* Message queue limit for port */
	union {
		uint64_t                   reserved[2];           /* Reserved */
		mach_port_name_t           work_interval_port;    /* Work interval port */
		mach_service_port_info_t   service_port_info;     /* Service port (MPO_SERVICE_PORT) */
		mach_port_name_t           service_port_name;     /* Service port (MPO_CONNECTION_PORT) */
	};
}mach_port_options_t;

typedef mach_port_options_t *mach_port_options_ptr_t;

/* Mach Port Guarding definitions */

/*
 * EXC_GUARD represents a guard violation for both
 * mach ports and file descriptors. GUARD_TYPE_ is used
 * to differentiate among them.
 */
#define GUARD_TYPE_MACH_PORT    0x1

/*
 * Reasons for exception for a guarded mach port
 *
 * Arguments are documented in doc/mach_ipc/guard_exceptions.md,
 * please update when adding a new type.
 *
 * Note: these had been designed as bitfields,
 *       hence the weird spaced values,
 *       but are truly an enum, please add new values in the "holes".
 */
enum mach_port_guard_exception_codes {
	kGUARD_EXC_NONE                         = 0,        /* never sent */
	kGUARD_EXC_DESTROY                      = 1,
	kGUARD_EXC_MOD_REFS                     = 2,
	kGUARD_EXC_INVALID_OPTIONS              = 3,
	kGUARD_EXC_SET_CONTEXT                  = 4,
	kGUARD_EXC_THREAD_SET_STATE             = 5,
	kGUARD_EXC_EXCEPTION_BEHAVIOR_ENFORCE   = 6,
	kGUARD_EXC_SERVICE_PORT_VIOLATION_FATAL = 7,        /* unused, for future sp defense enablement */
	kGUARD_EXC_UNGUARDED                    = 8,
	kGUARD_EXC_KOBJECT_REPLY_PORT_SEMANTICS = 9,
	kGUARD_EXC_REQUIRE_REPLY_PORT_SEMANTICS = 10,
	kGUARD_EXC_INCORRECT_GUARD              = 16,
	kGUARD_EXC_IMMOVABLE                    = 32,
	kGUARD_EXC_STRICT_REPLY                 = 64,
	kGUARD_EXC_INVALID_NOTIFICATION_REQ     = 65,
	kGUARD_EXC_INVALID_MPO_ENTITLEMENT      = 66,
	kGUARD_EXC_MSG_FILTERED                 = 128,
	/* start of [optionally] non-fatal guards */
	kGUARD_EXC_INVALID_RIGHT                = 256,
	kGUARD_EXC_INVALID_NAME                 = 512,
	kGUARD_EXC_INVALID_VALUE                = 1u << 10,
	kGUARD_EXC_INVALID_ARGUMENT             = 1u << 11, /* really kGUARD_EXC_ALREADY_GUARDED */
	kGUARD_EXC_RIGHT_EXISTS                 = 1u << 12, /* unused */
	kGUARD_EXC_KERN_NO_SPACE                = 1u << 13, /* unused */
	kGUARD_EXC_KERN_FAILURE                 = 1u << 14, /* really kGUARD_EXC_INVALID_PDREQUEST */
	kGUARD_EXC_KERN_RESOURCE                = 1u << 15, /* unused */
	kGUARD_EXC_SEND_INVALID_REPLY           = 1u << 16,
	kGUARD_EXC_SEND_INVALID_VOUCHER         = 1u << 17,
	kGUARD_EXC_SEND_INVALID_RIGHT           = 1u << 18,
	kGUARD_EXC_RCV_INVALID_NAME             = 1u << 19,
	/* start of always non-fatal guards */
	kGUARD_EXC_RCV_GUARDED_DESC             = 0x00100000,     /* for development only */
	kGUARD_EXC_SERVICE_PORT_VIOLATION_NON_FATAL = 0x00100001, /* unused, for future sp defense enablement */
	kGUARD_EXC_PROVISIONAL_REPLY_PORT       = 0x00100002,
	kGUARD_EXC_OOL_PORT_ARRAY_CREATION      = 0x00100003,
	kGUARD_EXC_MOVE_PROVISIONAL_REPLY_PORT  = 0x00100004,
	kGUARD_EXC_MOD_REFS_NON_FATAL           = 1u << 21,
	kGUARD_EXC_IMMOVABLE_NON_FATAL          = 1u << 22,
};

#define MAX_FATAL_kGUARD_EXC_CODE               kGUARD_EXC_MSG_FILTERED
#define MAX_OPTIONAL_kGUARD_EXC_CODE            kGUARD_EXC_RCV_INVALID_NAME

/*
 * Mach port guard payload construction helpers
 *
 * The order of the argument is the same as their position in
 * the payload, with flag being the MSB and the last argument
 * in the least siginificant end.
 */
#define MPG_24BIT_MASK ((0x1ULL << 24) - 1)

/*
 * +-------------+----------------+----------------------+
 * |[63:56] flag | [55:32] unused | [31:0] a             |
 * +-------------+----------------+----------------------+
 */
__header_always_inline __attribute__((overloadable))
uint64_t
MPG_PAYLOAD(uint8_t flag, uint32_t a)
{
	return ((uint64_t)flag << 56) | a;
}

/*
 * +-------------+----------------+----------------------+
 * |[63:56] flag | [55:32] a      | [31:0] b             |
 * +-------------+----------------+----------------------+
 */
__header_always_inline __attribute__((overloadable))
uint64_t
MPG_PAYLOAD(uint8_t flag, uint32_t a, uint32_t b)
{
	return ((uint64_t)flag << 56) |
	       ((uint64_t)(a & MPG_24BIT_MASK) << 32) | b;
}

/*
 * +-------------+----------------+-----------+----------+
 * |[63:56] flag | [55:32] a      | [31:16] b | [15:0] c |
 * +-------------+----------------+-----------+----------+
 */
__header_always_inline __attribute__((overloadable))
uint64_t
MPG_PAYLOAD(uint8_t flag, uint32_t a, uint16_t b, uint16_t c)
{
	return ((uint64_t)flag << 56) |
	       ((uint64_t)(a & MPG_24BIT_MASK) << 32) |
	       ((uint64_t)b << 16) |
	       c;
}

/*
 * Mach port guard flags.
 */
#define MPG_FLAGS_NONE                             0x00

/*
 * These flags are used as bits in the subcode of kGUARD_EXC_STRICT_REPLY exceptions.
 */
#define MPG_FLAGS_STRICT_REPLY_INVALID_VOUCHER     0x04
#define MPG_FLAGS_STRICT_REPLY_MISMATCHED_PERSONA  0x10

/*
 * These flags are used as bits in the subcode of kGUARD_EXC_MOD_REFS exceptions.
 */
#define MPG_FLAGS_MOD_REFS_PINNED_DEALLOC          0x01
#define MPG_FLAGS_MOD_REFS_PINNED_DESTROY          0x02
#define MPG_FLAGS_MOD_REFS_PINNED_COPYIN           0x03

/*
 * These flags are used as bits in the subcode of kGUARD_EXC_INVALID_RIGHT exceptions.
 */
#define MPG_FLAGS_INVALID_RIGHT_RECV               0x01    /* does not have receive right */
#define MPG_FLAGS_INVALID_RIGHT_DELTA              0x02    /* ipc_right_delta() */
#define MPG_FLAGS_INVALID_RIGHT_DESTRUCT           0x03    /* ipc_right_destruct() */
#define MPG_FLAGS_INVALID_RIGHT_COPYIN             0x04    /* ipc_right_copyin() */
#define MPG_FLAGS_INVALID_RIGHT_DEALLOC            0x05    /* ipc_right_dealloc() */
#define MPG_FLAGS_INVALID_RIGHT_DEALLOC_KERNEL     0x06    /* mach_port_deallocate_kernel() */
#define MPG_FLAGS_INVALID_RIGHT_TRANSLATE_PORT     0x07    /* port in ipc_object_translate_port_pset() */
#define MPG_FLAGS_INVALID_RIGHT_TRANSLATE_PSET     0x08    /* pset in ipc_object_translate_port_pset() */

/*
 * These flags are used as bits in the subcode of kGUARD_EXC_INVALID_VALUE exceptions.
 */
#define MPG_FLAGS_INVALID_VALUE_PEEK               0x01    /* mach_port_peek() */
#define MPG_FLAGS_INVALID_VALUE_DELTA              0x02    /* ipc_right_delta() */
#define MPG_FLAGS_INVALID_VALUE_DESTRUCT           0x03    /* ipc_right_destruct() */

/*
 * These flags are used as bits in the subcode of kGUARD_EXC_KERN_FAILURE exceptions.
 */
#define MPG_FLAGS_KERN_FAILURE_TASK                0x01    /* task other than launchd arm pd on service ports */
#define MPG_FLAGS_KERN_FAILURE_NOTIFY_TYPE         0x02    /* not using IOT_NOTIFICATION_PORT for pd notification */
#define MPG_FLAGS_KERN_FAILURE_NOTIFY_RECV         0x03    /* notification port not owned by launchd */
#define MPG_FLAGS_KERN_FAILURE_MULTI_NOTI          0x04    /* register multiple pd notification */

/*
 * These flags are used as bits in the subcode of kGUARD_EXC_SEND_INVALID_RIGHT exceptions.
 */
#define MPG_FLAGS_SEND_INVALID_RIGHT_PORT          0x01    /* ipc_kmsg_copyin_port_descriptor() */
#define MPG_FLAGS_SEND_INVALID_RIGHT_OOL_PORT      0x02    /* ipc_kmsg_copyin_ool_ports_descriptor() */
#define MPG_FLAGS_SEND_INVALID_RIGHT_GUARDED       0x03    /* ipc_kmsg_copyin_guarded_port_descriptor */


/*
 * Flags for mach_port_guard_with_flags. These flags extend
 * the attributes associated with a guarded port.
 */
#define MPG_STRICT              0x01    /* Apply strict guarding for a port */
#define MPG_IMMOVABLE_RECEIVE   0x02    /* Receive right cannot be moved out of the space */

#if     !__DARWIN_UNIX03 && !defined(_NO_PORT_T_FROM_MACH)
/*
 *  Mach 3.0 renamed everything to have mach_ in front of it.
 *  These types and macros are provided for backward compatibility
 *	but are deprecated.
 */
typedef mach_port_t             port_t;
typedef mach_port_name_t        port_name_t;
typedef mach_port_name_t        *port_name_array_t;

#define PORT_NULL               ((port_t) 0)
#define PORT_DEAD               ((port_t) ~0)
#define PORT_VALID(name) \
	        ((port_t)(name) != PORT_NULL && (port_t)(name) != PORT_DEAD)

#endif  /* !__DARWIN_UNIX03 && !_NO_PORT_T_FROM_MACH */

#endif  /* _MACH_PORT_H_ */
