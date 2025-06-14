/*
    File:  CMBase.h
	
	Framework:  CoreMedia
	
    Copyright 2006-2018 Apple Inc. All rights reserved.

*/

#ifndef CMBASE_H
#define	CMBASE_H

#include <TargetConditionals.h>
#include <Availability.h>
#include <AvailabilityMacros.h>

#ifndef TARGET_OS_WINDOWS
#define TARGET_OS_WINDOWS 0
#endif

// Pre-10.16, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_16
#define __AVAILABILITY_INTERNAL__MAC_10_16 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre- iOS 14.0 weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_14_0
#define __AVAILABILITY_INTERNAL__IPHONE_14_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-10.15, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_15
#define __AVAILABILITY_INTERNAL__MAC_10_15 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre- iOS 13.0 weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_13_0
#define __AVAILABILITY_INTERNAL__IPHONE_13_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-10.14, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_14
#define __AVAILABILITY_INTERNAL__MAC_10_14 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-10.14.4, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_14_4
#define __AVAILABILITY_INTERNAL__MAC_10_14_4 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre- iOS 12.0 weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_12_0
#define __AVAILABILITY_INTERNAL__IPHONE_12_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre- iOS 12.2 weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_12_2
#define __AVAILABILITY_INTERNAL__IPHONE_12_2 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif




// Pre-10.13, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_13
#define __AVAILABILITY_INTERNAL__MAC_10_13 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre- iOS 11.0 weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_11_0
#define __AVAILABILITY_INTERNAL__IPHONE_11_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-10.12, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_12
#define __AVAILABILITY_INTERNAL__MAC_10_12 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre- iOS 10.0, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_10_0
#define __AVAILABILITY_INTERNAL__IPHONE_10_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-10.11.3, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_11_3
#define __AVAILABILITY_INTERNAL__MAC_10_11_3 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-10.11, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_11
	#define __AVAILABILITY_INTERNAL__MAC_10_11 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-10.10, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_10
	#define __AVAILABILITY_INTERNAL__MAC_10_10 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-10.7, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_7
	#define __AVAILABILITY_INTERNAL__MAC_10_7 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-4.3, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_4_3
	#define __AVAILABILITY_INTERNAL__IPHONE_4_3 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-10.8, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_8
	#define __AVAILABILITY_INTERNAL__MAC_10_8 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
#ifndef AVAILABLE_MAC_OS_X_VERSION_10_8_AND_LATER
	#define AVAILABLE_MAC_OS_X_VERSION_10_8_AND_LATER WEAK_IMPORT_ATTRIBUTE
#endif
// Pre-6.0, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_6_0
	#define __AVAILABILITY_INTERNAL__IPHONE_6_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-10.9, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_9
	#define __AVAILABILITY_INTERNAL__MAC_10_9 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
#ifndef AVAILABLE_MAC_OS_X_VERSION_10_9_AND_LATER
	#define AVAILABLE_MAC_OS_X_VERSION_10_9_AND_LATER WEAK_IMPORT_ATTRIBUTE
#endif
// Pre-7.0, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_7_0
#define __AVAILABILITY_INTERNAL__IPHONE_7_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-7.1, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_7_1
#define __AVAILABILITY_INTERNAL__IPHONE_7_1 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-10.10, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_10
#define __AVAILABILITY_INTERNAL__MAC_10_10 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-9.3, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_9_3
#define __AVAILABILITY_INTERNAL__IPHONE_9_3 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-9.0, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_9_0
#define __AVAILABILITY_INTERNAL__IPHONE_9_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-8.0, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_8_0
#define __AVAILABILITY_INTERNAL__IPHONE_8_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Deprecations
#ifndef __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0
#define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0 WEAK_IMPORT_ATTRIBUTE
#endif

#ifndef __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11 WEAK_IMPORT_ATTRIBUTE
#endif

#ifndef __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_9_0
#define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_9_0 WEAK_IMPORT_ATTRIBUTE
#endif

#include <stdint.h>						// int32_t, etc.
#include <stddef.h>						// size_t

#include <CoreFoundation/CFBase.h>		// OSStatus, Boolean, Float32, Float64, CF_NOESCAPE
#if ! TARGET_OS_WINDOWS
#include <CoreFoundation/CFAvailability.h>	// CF_EXTENSIBLE_STRING_ENUM
#endif

#ifndef API_AVAILABLE
#define API_AVAILABLE(...)
#endif

#ifndef API_UNAVAILABLE
#define API_UNAVAILABLE(...)
#endif


#ifdef __cplusplus
extern "C" {
#endif
    
#pragma pack(push, 4)

#define COREMEDIA_TRUE (1 && 1)
#define COREMEDIA_FALSE (0 && 1)

#ifndef COREMEDIA_EXPORTS_USE_EXPLICIT_VISIBILITY
	#define  COREMEDIA_EXPORTS_USE_EXPLICIT_VISIBILITY 0
#endif

#if COREMEDIA_EXPORTS_USE_EXPLICIT_VISIBILITY
	#define COREMEDIA_EXPORT_VISIBILITY __attribute__((visibility("default")))
#else
	#define COREMEDIA_EXPORT_VISIBILITY
#endif

#if TARGET_OS_WIN32
	#define CM_EXPORT __declspec( dllimport ) extern
	#define VT_EXPORT __declspec( dllimport ) extern
	#define MT_EXPORT __declspec( dllimport ) extern
	#define ME_EXPORT __declspec( dllimport ) extern
#else
	#define CM_EXPORT extern COREMEDIA_EXPORT_VISIBILITY
	#define VT_EXPORT extern COREMEDIA_EXPORT_VISIBILITY
	#define MT_EXPORT extern COREMEDIA_EXPORT_VISIBILITY
	#define ME_EXPORT extern COREMEDIA_EXPORT_VISIBILITY
#endif

// These have 32-bit range in a 32-bit build, and 64-bit range in a 64-bit build.
typedef CFIndex CMItemCount;
typedef CFIndex CMItemIndex;
#define CMITEMCOUNT_MAX INTPTR_MAX

#ifndef COREMEDIA_USE_ALIGNED_CMBASECLASS_VERSION
#define COREMEDIA_USE_ALIGNED_CMBASECLASS_VERSION COREMEDIA_TRUE
#endif

#if ! COREMEDIA_USE_ALIGNED_CMBASECLASS_VERSION
	typedef uint32_t CMBaseClassVersion, CMStructVersion;
	#define COREMEDIA_CMBASECLASS_VERSION_IS_POINTER_ALIGNED COREMEDIA_FALSE
#else
#if (TARGET_OS_OSX || TARGET_OS_MACCATALYST || TARGET_OS_WINDOWS) && TARGET_CPU_X86_64
	typedef uint32_t CMBaseClassVersion, CMStructVersion;
	#define COREMEDIA_CMBASECLASS_VERSION_IS_POINTER_ALIGNED COREMEDIA_FALSE
#else
	typedef uintptr_t CMBaseClassVersion, CMStructVersion;
	#define COREMEDIA_CMBASECLASS_VERSION_IS_POINTER_ALIGNED COREMEDIA_TRUE
#endif
#endif

#if (__cplusplus && __cplusplus >= 201103L && (__has_extension(cxx_strong_enums) || __has_feature(objc_fixed_enum))) || (!__cplusplus && __has_feature(objc_fixed_enum))
#define COREMEDIA_USE_DERIVED_ENUMS_FOR_CONSTANTS COREMEDIA_TRUE
#else
#define COREMEDIA_USE_DERIVED_ENUMS_FOR_CONSTANTS COREMEDIA_FALSE
#endif

#if (TARGET_OS_IPHONE || TARGET_OS_MAC || TARGET_OS_LINUX) && defined(__has_feature)
#if __has_feature(nullability)
	#define COREMEDIA_DECLARE_NULLABILITY COREMEDIA_TRUE
#endif
#if __has_feature(assume_nonnull)
	#define COREMEDIA_DECLARE_NULLABILITY_BEGIN_END COREMEDIA_TRUE
#endif
#if __has_feature(objc_bridge_id)
	#define COREMEDIA_DECLARE_BRIDGED_TYPES COREMEDIA_TRUE
#endif
#if __has_feature(attribute_cf_returns_retained)
	#define COREMEDIA_DECLARE_RETURNS_RETAINED COREMEDIA_TRUE
#endif
#if __has_feature(attribute_cf_returns_on_parameters)
	#define COREMEDIA_DECLARE_RETURNS_RETAINED_ON_PARAMETERS COREMEDIA_TRUE
	#define COREMEDIA_DECLARE_RETURNS_NOT_RETAINED_ON_PARAMETERS COREMEDIA_TRUE
#endif
#if __has_feature(attribute_ns_returns_retained)
	#define COREMEDIA_DECLARE_RETURNS_RETAINED_BLOCK COREMEDIA_TRUE
#endif
#if __has_feature(attribute_cf_consumed)
	#define COREMEDIA_DECLARE_RELEASES_ARGUMENT COREMEDIA_TRUE
#endif

#endif // (TARGET_OS_IPHONE || TARGET_OS_MAC || TARGET_OS_LINUX) && defined(__has_feature)

#ifndef COREMEDIA_DECLARE_NULLABILITY
#define COREMEDIA_DECLARE_NULLABILITY COREMEDIA_FALSE
#endif

#ifndef COREMEDIA_DECLARE_NULLABILITY_BEGIN_END
#define COREMEDIA_DECLARE_NULLABILITY_BEGIN_END COREMEDIA_FALSE
#endif

#ifndef COREMEDIA_DECLARE_BRIDGED_TYPES
#define COREMEDIA_DECLARE_BRIDGED_TYPES COREMEDIA_FALSE
#endif

#ifndef COREMEDIA_DECLARE_RETURNS_RETAINED
#define COREMEDIA_DECLARE_RETURNS_RETAINED COREMEDIA_FALSE
#endif

#ifndef COREMEDIA_DECLARE_RETURNS_RETAINED_ON_PARAMETERS
#define COREMEDIA_DECLARE_RETURNS_RETAINED_ON_PARAMETERS COREMEDIA_FALSE
#endif

#ifndef COREMEDIA_DECLARE_RETURNS_NOT_RETAINED_ON_PARAMETERS
#define COREMEDIA_DECLARE_RETURNS_NOT_RETAINED_ON_PARAMETERS COREMEDIA_FALSE
#endif

#ifndef COREMEDIA_DECLARE_RETURNS_RETAINED_BLOCK
#define COREMEDIA_DECLARE_RETURNS_RETAINED_BLOCK COREMEDIA_FALSE
#endif

#ifndef COREMEDIA_DECLARE_RELEASES_ARGUMENT
#define COREMEDIA_DECLARE_RELEASES_ARGUMENT COREMEDIA_FALSE
#endif

#if COREMEDIA_DECLARE_NULLABILITY
#if TARGET_OS_LINUX
#define CM_NULLABLE _Nullable
#define CM_NONNULL _Nonnull
#else // TARGET_OS_LINUX
#define CM_NULLABLE __nullable
#define CM_NONNULL __nonnull
#endif //TARGET_OS_LINUX
#else
#define CM_NULLABLE
#define CM_NONNULL
#endif

#if COREMEDIA_DECLARE_NULLABILITY_BEGIN_END
#define CM_ASSUME_NONNULL_BEGIN _Pragma("clang assume_nonnull begin")
#define CM_ASSUME_NONNULL_END   _Pragma("clang assume_nonnull end")
#else
#define CM_ASSUME_NONNULL_BEGIN
#define CM_ASSUME_NONNULL_END
#endif
	
#if COREMEDIA_DECLARE_BRIDGED_TYPES
#define CM_BRIDGED_TYPE(type)	CF_BRIDGED_TYPE(type)
#else
#define CM_BRIDGED_TYPE(type)
#endif

// Marks functions returning a CoreFoundation object that the caller is responsible for releasing. Blocks are Objective-C objects and functions returning them use CM_RETURNS_RETAINED_BLOCK instead.
#if COREMEDIA_DECLARE_RETURNS_RETAINED
#define CM_RETURNS_RETAINED		CF_RETURNS_RETAINED
#else
#define CM_RETURNS_RETAINED
#endif
	
#if COREMEDIA_DECLARE_RETURNS_RETAINED_ON_PARAMETERS
#define CM_RETURNS_RETAINED_PARAMETER	CF_RETURNS_RETAINED
#else
#define CM_RETURNS_RETAINED_PARAMETER
#endif
	
#if COREMEDIA_DECLARE_RETURNS_NOT_RETAINED_ON_PARAMETERS
#define CM_RETURNS_NOT_RETAINED_PARAMETER	CF_RETURNS_NOT_RETAINED
#else
#define CM_RETURNS_NOT_RETAINED_PARAMETER
#endif

// Marks functions returning a block that the caller is responsible for releasing.
#if COREMEDIA_DECLARE_RETURNS_RETAINED_BLOCK
#define CM_RETURNS_RETAINED_BLOCK		DISPATCH_RETURNS_RETAINED_BLOCK
#else
#define CM_RETURNS_RETAINED_BLOCK
#endif

#if COREMEDIA_DECLARE_RELEASES_ARGUMENT	// Marks function arguments which are released by the callee
	#define CM_RELEASES_ARGUMENT CF_RELEASES_ARGUMENT
#else
	#define CM_RELEASES_ARGUMENT
#endif

typedef int32_t CMPersistentTrackID;
#if COREMEDIA_USE_DERIVED_ENUMS_FOR_CONSTANTS
enum : CMPersistentTrackID
#else
enum
#endif
{
	kCMPersistentTrackID_Invalid = 0
};

#if !defined(CM_INLINE)
	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		#define CM_INLINE static inline
	#elif defined(__MWERKS__) || defined(__cplusplus)
		#define CM_INLINE static inline
	#elif defined(__GNUC__)
		#define CM_INLINE static __inline__
	#elif defined(_MSC_VER)
		#define CM_INLINE static __inline
	#else
		#define CM_INLINE static    
	#endif
#endif

// These defines are copied over from CFNSObjCRuntime.h
#if __SWIFT_ATTR_SUPPORTS_SENDABLE_DECLS
	// The typedef or struct should be imported as 'Sendable' in Swift
	#define CM_SWIFT_SENDABLE __attribute__((swift_attr("@Sendable")))
	// The struct should *not* be imported as 'Sendable' in Swift even if it normally would be
	#define CM_SWIFT_NONSENDABLE __attribute__((swift_attr("@_nonSendable")))
#else
	#define CM_SWIFT_SENDABLE
	#define CM_SWIFT_NONSENDABLE
#endif // __SWIFT_ATTR_SUPPORTS_SENDABLE_DECLS

#if __has_attribute(__swift_attr__) && __SWIFT_ATTR_SUPPORTS_SENDING
	#define CM_SWIFT_SENDING __attribute__((swift_attr("sending")))
#else
	#define CM_SWIFT_SENDING
#endif

#define CM_SWIFT_SENDING_RETAINED_PARAMETER CM_SWIFT_SENDING CM_RETURNS_RETAINED_PARAMETER
#define CM_SWIFT_SENDING_RELEASED_PARAMETER CM_SWIFT_SENDING CM_RELEASES_ARGUMENT
#define CM_SWIFT_SENDING_RETAINED_RESULT CM_SWIFT_SENDING CM_RETURNS_RETAINED

// Swift macros not available on Windows builds
#if TARGET_OS_WINDOWS
#define CF_SWIFT_UNAVAILABLE(_unused)
#define CF_REFINED_FOR_SWIFT
#endif // TARGET_OS_WINDOWS

// CM_SWIFT_INIT_FOR_CF_TYPE creates a Swift init function for CF type that has the signature `init(referencing: Self)`
// This "trampoline" init is used to provide convenient initializers for the type. This is a workaround for Swift
// error - convenience initializers are not supported in extensions of CF types.
// See https://github.com/swiftlang/swift/commit/1593c2aeeb17fda181485bd6dc33d9909c600139
#if __SWIFT_COMPILER_VERSION
#define CM_SWIFT_INIT_FOR_CF_TYPE(type, availability) \
CM_INLINE CM_RETURNS_RETAINED_PARAMETER type##Ref CM_NONNULL _swiftInitFor##type(type##Ref CM_NONNULL object) \
  CF_SWIFT_NAME(type.init(referencing:)) CF_REFINED_FOR_SWIFT availability ;\
CM_INLINE CM_RETURNS_RETAINED_PARAMETER type##Ref CM_NONNULL _swiftInitFor##type(type##Ref CM_NONNULL object) \
{ return (type##Ref)CFRetain(object); }
#else
#define CM_SWIFT_INIT_FOR_CF_TYPE(type, availability)
#endif // __SWIFT__

#pragma pack(pop)
    
#ifdef __cplusplus
}
#endif

#endif // CMBASE_H
