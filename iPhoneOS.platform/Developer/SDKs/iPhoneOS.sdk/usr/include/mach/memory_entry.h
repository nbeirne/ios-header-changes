#ifndef	_memory_entry_user_
#define	_memory_entry_user_

/* Module memory_entry */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>
	
/* BEGIN MIG_STRNCPY_ZEROFILL CODE */

#if defined(__has_include)
#if __has_include(<mach/mig_strncpy_zerofill_support.h>)
#ifndef USING_MIG_STRNCPY_ZEROFILL
#define USING_MIG_STRNCPY_ZEROFILL
#endif
#ifndef __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#define __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#ifdef __cplusplus
extern "C" {
#endif
#ifndef __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS_CSTRING_ATTR
#define __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS_CSTRING_COUNTEDBY_ATTR(C) __unsafe_indexable
#endif
	extern int mig_strncpy_zerofill(char * dest, const char * src, int len) __attribute__((weak_import));
#ifdef __cplusplus
}
#endif
#endif /* __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__ */
#endif /* __has_include(<mach/mig_strncpy_zerofill_support.h>) */
#endif /* __has_include */
	
/* END MIG_STRNCPY_ZEROFILL CODE */


#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            * name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry   *function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef	memory_entry_MSG_COUNT
#define	memory_entry_MSG_COUNT	4
#endif	/* memory_entry_MSG_COUNT */

#include <Availability.h>
#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include <mach_debug/mach_debug_types.h>

#ifdef __BeforeMigUserHeader
__BeforeMigUserHeader
#endif /* __BeforeMigUserHeader */

#include <sys/cdefs.h>
__BEGIN_DECLS


/* Routine mach_memory_entry_purgable_control */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_memory_entry_purgable_control
(
	mem_entry_name_port_t mem_entry,
	vm_purgable_t control,
	int *state
);

/* Routine mach_memory_entry_access_tracking */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_memory_entry_access_tracking
(
	mem_entry_name_port_t mem_entry,
	int *access_tracking,
	uint32_t *access_tracking_reads,
	uint32_t *access_tracking_writes
);

/* Routine mach_memory_entry_ownership */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_memory_entry_ownership
(
	mem_entry_name_port_t mem_entry,
	task_t owner,
	int ledger_tag,
	int ledger_flags
);

/* Routine mach_memory_entry_get_page_counts */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_memory_entry_get_page_counts
(
	mem_entry_name_port_t mem_entry,
	uint64_t *resident_cnt,
	uint64_t *dirty_cnt,
	uint64_t *swapped_cnt
);

__END_DECLS

/********************** Caution **************************/
/* The following data types should be used to calculate  */
/* maximum message sizes only. The actual message may be */
/* smaller, and the position of the arguments within the */
/* message layout may vary from what is presented here.  */
/* For example, if any of the arguments are variable-    */
/* sized, and less than the maximum is sent, the data    */
/* will be packed tight in the actual message to reduce  */
/* the presence of holes.                                */
/********************** Caution **************************/

/* typedefs for all requests */

#ifndef __Request__memory_entry_subsystem__defined
#define __Request__memory_entry_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		vm_purgable_t control;
		int state;
	} __Request__mach_memory_entry_purgable_control_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int access_tracking;
	} __Request__mach_memory_entry_access_tracking_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t owner;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int ledger_tag;
		int ledger_flags;
	} __Request__mach_memory_entry_ownership_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__mach_memory_entry_get_page_counts_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Request__memory_entry_subsystem__defined */

/* union of all requests */

#ifndef __RequestUnion__memory_entry_subsystem__defined
#define __RequestUnion__memory_entry_subsystem__defined
union __RequestUnion__memory_entry_subsystem {
	__Request__mach_memory_entry_purgable_control_t Request_mach_memory_entry_purgable_control;
	__Request__mach_memory_entry_access_tracking_t Request_mach_memory_entry_access_tracking;
	__Request__mach_memory_entry_ownership_t Request_mach_memory_entry_ownership;
	__Request__mach_memory_entry_get_page_counts_t Request_mach_memory_entry_get_page_counts;
};
#endif /* !__RequestUnion__memory_entry_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__memory_entry_subsystem__defined
#define __Reply__memory_entry_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		int state;
	} __Reply__mach_memory_entry_purgable_control_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		int access_tracking;
		uint32_t access_tracking_reads;
		uint32_t access_tracking_writes;
	} __Reply__mach_memory_entry_access_tracking_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_memory_entry_ownership_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		uint64_t resident_cnt;
		uint64_t dirty_cnt;
		uint64_t swapped_cnt;
	} __Reply__mach_memory_entry_get_page_counts_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Reply__memory_entry_subsystem__defined */

/* union of all replies */

#ifndef __ReplyUnion__memory_entry_subsystem__defined
#define __ReplyUnion__memory_entry_subsystem__defined
union __ReplyUnion__memory_entry_subsystem {
	__Reply__mach_memory_entry_purgable_control_t Reply_mach_memory_entry_purgable_control;
	__Reply__mach_memory_entry_access_tracking_t Reply_mach_memory_entry_access_tracking;
	__Reply__mach_memory_entry_ownership_t Reply_mach_memory_entry_ownership;
	__Reply__mach_memory_entry_get_page_counts_t Reply_mach_memory_entry_get_page_counts;
};
#endif /* !__RequestUnion__memory_entry_subsystem__defined */

#ifndef subsystem_to_name_map_memory_entry
#define subsystem_to_name_map_memory_entry \
    { "mach_memory_entry_purgable_control", 4900 },\
    { "mach_memory_entry_access_tracking", 4901 },\
    { "mach_memory_entry_ownership", 4902 },\
    { "mach_memory_entry_get_page_counts", 4903 }
#endif

#ifdef __AfterMigUserHeader
__AfterMigUserHeader
#endif /* __AfterMigUserHeader */

#endif	 /* _memory_entry_user_ */
