/*
 * Copyright (c) 2007-2016 by Apple Inc.. All rights reserved.
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
 
#ifndef __AVAILABILITY__
#define __AVAILABILITY__
 /*     
    These macros are for use in OS header files. They enable function prototypes
    and Objective-C methods to be tagged with the OS version in which they
    were first available; and, if applicable, the OS versions in which they
    became deprecated and obsoleted.
     
    The desktop Mac OS X and iOS each have different version numbers.
    The __OSX_AVAILABLE_STARTING() macro allows you to specify both the desktop
    and iOS version numbers.  For instance:
        __OSX_AVAILABLE_STARTING(__MAC_10_2,__IPHONE_2_0)
    means the function/method was first available on Mac OS X 10.2 on the desktop
    and first available in iOS 2.0 on the iPhone.
    
    If a function is available on one platform, but not the other a _NA (not
    applicable) parameter is used.  For instance:
            __OSX_AVAILABLE_STARTING(__MAC_10_3,__IPHONE_NA)
    means that the function/method was first available on Mac OS X 10.3, and it
    currently not implemented on the iPhone.

    At some point, a function/method may be deprecated.  That means Apple
    recommends applications stop using the function, either because there is a 
    better replacement or the functionality is being phased out.  Deprecated
    functions/methods can be tagged with a __OSX_AVAILABLE_BUT_DEPRECATED()
    macro which specifies the OS version where the function became available
    as well as the OS version in which it became deprecated.  For instance:
        __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0,__MAC_10_5,__IPHONE_NA,__IPHONE_NA)
    means that the function/method was introduced in Mac OS X 10.0, then
    became deprecated beginning in Mac OS X 10.5.  On iOS the function 
    has never been available.  
    
    For these macros to function properly, a program must specify the OS version range 
    it is targeting.  The min OS version is specified as an option to the compiler:
    -mmacosx-version-min=10.x when building for Mac OS X, and -miphoneos-version-min=y.z
    when building for the iPhone.  The upper bound for the OS version is rarely needed,
    but it can be set on the command line via: -D__MAC_OS_X_VERSION_MAX_ALLOWED=10x0 for
    Mac OS X and __IPHONE_OS_VERSION_MAX_ALLOWED = y0z00 for iOS.  
    
    Examples:

        A function available in Mac OS X 10.5 and later, but not on the phone:
        
            extern void mymacfunc() __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_NA);


        An Objective-C method in Mac OS X 10.5 and later, but not on the phone:
        
            @interface MyClass : NSObject
            -(void) mymacmethod __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_NA);
            @end

        
        An enum available on the phone, but not available on Mac OS X:
        
            #if __IPHONE_OS_VERSION_MIN_REQUIRED
                enum { myEnum = 1 };
            #endif
           Note: this works when targeting the Mac OS X platform because 
           __IPHONE_OS_VERSION_MIN_REQUIRED is undefined which evaluates to zero. 
        

        An enum with values added in different iPhoneOS versions:
		
			enum {
			    myX  = 1,	// Usable on iPhoneOS 2.1 and later
			    myY  = 2,	// Usable on iPhoneOS 3.0 and later
			    myZ  = 3,	// Usable on iPhoneOS 3.0 and later
				...
		      Note: you do not want to use #if with enumeration values
			  when a client needs to see all values at compile time
			  and use runtime logic to only use the viable values.
			  

    It is also possible to use the *_VERSION_MIN_REQUIRED in source code to make one
    source base that can be compiled to target a range of OS versions.  It is best
    to not use the _MAC_* and __IPHONE_* macros for comparisons, but rather their values.
    That is because you might get compiled on an old OS that does not define a later
    OS version macro, and in the C preprocessor undefined values evaluate to zero
    in expresssions, which could cause the #if expression to evaluate in an unexpected
    way.
    
        #ifdef __MAC_OS_X_VERSION_MIN_REQUIRED
            // code only compiled when targeting Mac OS X and not iPhone
            // note use of 1050 instead of __MAC_10_5
            #if __MAC_OS_X_VERSION_MIN_REQUIRED < 1050
                // code in here might run on pre-Leopard OS
            #else
                // code here can assume Leopard or later
            #endif
        #endif


*/

/* 
 * __API_TO_BE_DEPRECATED is used as a version number in API that will be deprecated 
 * in an upcoming release. This soft deprecation is an intermediate step before formal 
 * deprecation to notify developers about the API before compiler warnings are generated.
 * You can find all places in your code that use soft deprecated API by redefining the 
 * value of this macro to your current minimum deployment target, for example:
 * (macOS)
 *   clang -D__API_TO_BE_DEPRECATED=10.12 <other compiler flags>
 * (iOS)
 *   clang -D__API_TO_BE_DEPRECATED=11.0 <other compiler flags>
 */
 
 #ifndef __API_TO_BE_DEPRECATED
 #define __API_TO_BE_DEPRECATED 100000
 #endif
 
#ifndef __API_TO_BE_DEPRECATED_MACOS
#define __API_TO_BE_DEPRECATED_MACOS 100000
#endif
#ifndef __API_TO_BE_DEPRECATED_MACOSAPPLICATIONEXTENSION
#define __API_TO_BE_DEPRECATED_MACOSAPPLICATIONEXTENSION 100000
#endif

#ifndef __API_TO_BE_DEPRECATED_IOS
#define __API_TO_BE_DEPRECATED_IOS 100000
#endif
#ifndef __API_TO_BE_DEPRECATED_IOSAPPLICATIONEXTENSION
#define __API_TO_BE_DEPRECATED_IOSAPPLICATIONEXTENSION 100000
#endif
#ifndef __API_TO_BE_DEPRECATED_MACCATALYST
#define __API_TO_BE_DEPRECATED_MACCATALYST 100000
#endif
#ifndef __API_TO_BE_DEPRECATED_MACCATALYSTAPPLICATIONEXTENSION
#define __API_TO_BE_DEPRECATED_MACCATALYSTAPPLICATIONEXTENSION 100000
#endif

#ifndef __API_TO_BE_DEPRECATED_WATCHOS
#define __API_TO_BE_DEPRECATED_WATCHOS 100000
#endif
#ifndef __API_TO_BE_DEPRECATED_WATCHOSAPPLICATIONEXTENSION
#define __API_TO_BE_DEPRECATED_WATCHOSAPPLICATIONEXTENSION 100000
#endif

#ifndef __API_TO_BE_DEPRECATED_TVOS
#define __API_TO_BE_DEPRECATED_TVOS 100000
#endif
#ifndef __API_TO_BE_DEPRECATED_TVOSAPPLICATIONEXTENSION
#define __API_TO_BE_DEPRECATED_TVOSAPPLICATIONEXTENSION 100000
#endif



#ifndef __API_TO_BE_DEPRECATED_DRIVERKIT
#define __API_TO_BE_DEPRECATED_DRIVERKIT 100000
#endif

#ifndef __API_TO_BE_DEPRECATED_VISIONOS
#define __API_TO_BE_DEPRECATED_VISIONOS 100000
#endif
#ifndef __API_TO_BE_DEPRECATED_VISIONOSAPPLICATIONEXTENSION
#define __API_TO_BE_DEPRECATED_VISIONOSAPPLICATIONEXTENSION 100000
#endif

#ifndef __API_TO_BE_DEPRECATED_EXCLAVEKIT

#endif

#ifndef __API_TO_BE_DEPRECATED_KERNELKIT
#define __API_TO_BE_DEPRECATED_KERNELKIT 100000
#endif



#ifndef __OPEN_SOURCE__

#endif /* __OPEN_SOURCE__ */

#include <AvailabilityVersions.h>
#include <AvailabilityInternal.h>
#include <AvailabilityInternalLegacy.h>
#if __has_include(<AvailabilityInternalPrivate.h>)
  #include <AvailabilityInternalPrivate.h>
#endif

#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
    #define __OSX_AVAILABLE_STARTING(_osx, _ios) __AVAILABILITY_INTERNAL##_ios
    #define __OSX_AVAILABLE_BUT_DEPRECATED(_osxIntro, _osxDep, _iosIntro, _iosDep) \
                                                    __AVAILABILITY_INTERNAL##_iosIntro##_DEP##_iosDep
    #define __OSX_AVAILABLE_BUT_DEPRECATED_MSG(_osxIntro, _osxDep, _iosIntro, _iosDep, _msg) \
                                                    __AVAILABILITY_INTERNAL##_iosIntro##_DEP##_iosDep##_MSG(_msg)

#elif defined(__MAC_OS_X_VERSION_MIN_REQUIRED)

   #if defined(__has_builtin)
    #if __has_builtin(__is_target_arch)
     #if __has_builtin(__is_target_vendor)
      #if __has_builtin(__is_target_os)
       #if __has_builtin(__is_target_environment)
        #if __has_builtin(__is_target_variant_os)
         #if __has_builtin(__is_target_variant_environment)
          #if (__is_target_arch(x86_64) && __is_target_vendor(apple) && ((__is_target_os(ios) && __is_target_environment(macabi)) || (__is_target_variant_os(ios) && __is_target_variant_environment(macabi))))
            #define __OSX_AVAILABLE_STARTING(_osx, _ios) __AVAILABILITY_INTERNAL##_osx __AVAILABILITY_INTERNAL##_ios
            #define __OSX_AVAILABLE_BUT_DEPRECATED(_osxIntro, _osxDep, _iosIntro, _iosDep) \
                                                            __AVAILABILITY_INTERNAL##_osxIntro##_DEP##_osxDep __AVAILABILITY_INTERNAL##_iosIntro##_DEP##_iosDep
            #define __OSX_AVAILABLE_BUT_DEPRECATED_MSG(_osxIntro, _osxDep, _iosIntro, _iosDep, _msg) \
                                                            __AVAILABILITY_INTERNAL##_osxIntro##_DEP##_osxDep##_MSG(_msg) __AVAILABILITY_INTERNAL##_iosIntro##_DEP##_iosDep##_MSG(_msg)
          #endif /* # if __is_target_arch... */
         #endif /* #if __has_builtin(__is_target_variant_environment) */
        #endif /* #if __has_builtin(__is_target_variant_os) */
       #endif /* #if __has_builtin(__is_target_environment) */
      #endif /* #if __has_builtin(__is_target_os) */
     #endif /* #if __has_builtin(__is_target_vendor) */
    #endif /* #if __has_builtin(__is_target_arch) */
   #endif /* #if defined(__has_builtin) */

    #ifndef __OSX_AVAILABLE_STARTING
      #if defined(__has_attribute) && defined(__has_feature)
          #if __has_attribute(availability)      
        #define __OSX_AVAILABLE_STARTING(_osx, _ios) __AVAILABILITY_INTERNAL##_osx
        #define __OSX_AVAILABLE_BUT_DEPRECATED(_osxIntro, _osxDep, _iosIntro, _iosDep) \
                                                        __AVAILABILITY_INTERNAL##_osxIntro##_DEP##_osxDep
        #define __OSX_AVAILABLE_BUT_DEPRECATED_MSG(_osxIntro, _osxDep, _iosIntro, _iosDep, _msg) \
                                                        __AVAILABILITY_INTERNAL##_osxIntro##_DEP##_osxDep##_MSG(_msg)
        #else
        #define __OSX_AVAILABLE_STARTING(_osx, _ios)
        #define __OSX_AVAILABLE_BUT_DEPRECATED(_osxIntro, _osxDep, _iosIntro, _iosDep)
        #define __OSX_AVAILABLE_BUT_DEPRECATED_MSG(_osxIntro, _osxDep, _iosIntro, _iosDep, _msg)
        #endif
      #else
      #define __OSX_AVAILABLE_STARTING(_osx, _ios)
      #define __OSX_AVAILABLE_BUT_DEPRECATED(_osxIntro, _osxDep, _iosIntro, _iosDep)
      #define __OSX_AVAILABLE_BUT_DEPRECATED_MSG(_osxIntro, _osxDep, _iosIntro, _iosDep, _msg)
    #endif
#endif /* __OSX_AVAILABLE_STARTING */

#else
    #define __OSX_AVAILABLE_STARTING(_osx, _ios)
    #define __OSX_AVAILABLE_BUT_DEPRECATED(_osxIntro, _osxDep, _iosIntro, _iosDep)
    #define __OSX_AVAILABLE_BUT_DEPRECATED_MSG(_osxIntro, _osxDep, _iosIntro, _iosDep, _msg)
#endif


#if defined(__has_feature)
  #if __has_feature(attribute_availability_with_message)
    #define __OS_AVAILABILITY(_target, _availability)            __attribute__((availability(_target,_availability)))
    #define __OS_AVAILABILITY_MSG(_target, _availability, _msg)  __attribute__((availability(_target,_availability,message=_msg)))
  #elif __has_feature(attribute_availability)
    #define __OS_AVAILABILITY(_target, _availability)            __attribute__((availability(_target,_availability)))
    #define __OS_AVAILABILITY_MSG(_target, _availability, _msg)  __attribute__((availability(_target,_availability)))
  #else
    #define __OS_AVAILABILITY(_target, _availability)
    #define __OS_AVAILABILITY_MSG(_target, _availability, _msg)
  #endif
#else
    #define __OS_AVAILABILITY(_target, _availability)
    #define __OS_AVAILABILITY_MSG(_target, _availability, _msg)
#endif


/* for use to document app extension usage */
#if defined(__has_feature)
  #if __has_feature(attribute_availability_app_extension)
    #define __OSX_EXTENSION_UNAVAILABLE(_msg)  __OS_AVAILABILITY_MSG(macosx_app_extension,unavailable,_msg)
    #define __IOS_EXTENSION_UNAVAILABLE(_msg)  __OS_AVAILABILITY_MSG(ios_app_extension,unavailable,_msg)
  #else
    #define __OSX_EXTENSION_UNAVAILABLE(_msg)
    #define __IOS_EXTENSION_UNAVAILABLE(_msg)
  #endif
#else
    #define __OSX_EXTENSION_UNAVAILABLE(_msg)
    #define __IOS_EXTENSION_UNAVAILABLE(_msg)
#endif

#define __OS_EXTENSION_UNAVAILABLE(_msg)  __OSX_EXTENSION_UNAVAILABLE(_msg) __IOS_EXTENSION_UNAVAILABLE(_msg)



/* for use marking APIs available info for Mac OSX */
#if defined(__has_attribute)
  #if __has_attribute(availability)
    #define __OSX_UNAVAILABLE                    __OS_AVAILABILITY(macosx,unavailable)
    #define __OSX_AVAILABLE(_vers)               __OS_AVAILABILITY(macosx,introduced=_vers)
    #define __OSX_DEPRECATED(_start, _dep, _msg) __OSX_AVAILABLE(_start) __OS_AVAILABILITY_MSG(macosx,deprecated=_dep,_msg)
  #endif
#endif

#ifndef __OSX_UNAVAILABLE
  #define __OSX_UNAVAILABLE
#endif

#ifndef __OSX_AVAILABLE
  #define __OSX_AVAILABLE(_vers)
#endif

#ifndef __OSX_DEPRECATED
  #define __OSX_DEPRECATED(_start, _dep, _msg)
#endif


#if __has_include(<AvailabilityProhibitedInternal.h>)
  #include <AvailabilityProhibitedInternal.h>
#endif

/* for use marking APIs available info for iOS */
#if defined(__has_attribute)
  #if __has_attribute(availability)
    #define __IOS_UNAVAILABLE                    __OS_AVAILABILITY(ios,unavailable)
    #ifndef __IOS_PROHIBITED
      #define __IOS_PROHIBITED                     __OS_AVAILABILITY(ios,unavailable)
    #endif
    #define __IOS_AVAILABLE(_vers)               __OS_AVAILABILITY(ios,introduced=_vers)
    #define __IOS_DEPRECATED(_start, _dep, _msg) __IOS_AVAILABLE(_start) __OS_AVAILABILITY_MSG(ios,deprecated=_dep,_msg)
  #endif
#endif

#ifndef __IOS_UNAVAILABLE
  #define __IOS_UNAVAILABLE
#endif

#ifndef __IOS_PROHIBITED
  #define __IOS_PROHIBITED
#endif

#ifndef __IOS_AVAILABLE
  #define __IOS_AVAILABLE(_vers)
#endif

#ifndef __IOS_DEPRECATED
  #define __IOS_DEPRECATED(_start, _dep, _msg)
#endif


/* for use marking APIs available info for tvOS */
#if defined(__has_feature)
  #if __has_feature(attribute_availability_tvos)
    #define __TVOS_UNAVAILABLE                    __OS_AVAILABILITY(tvos,unavailable)
    #ifndef __TVOS_PROHIBITED
      #define __TVOS_PROHIBITED                     __OS_AVAILABILITY(tvos,unavailable)
    #endif
    #define __TVOS_AVAILABLE(_vers)               __OS_AVAILABILITY(tvos,introduced=_vers)
    #define __TVOS_DEPRECATED(_start, _dep, _msg) __TVOS_AVAILABLE(_start) __OS_AVAILABILITY_MSG(tvos,deprecated=_dep,_msg)
  #endif
#endif

#ifndef __TVOS_UNAVAILABLE
  #define __TVOS_UNAVAILABLE
#endif

#ifndef __TVOS_PROHIBITED
  #define __TVOS_PROHIBITED
#endif

#ifndef __TVOS_AVAILABLE
  #define __TVOS_AVAILABLE(_vers)
#endif

#ifndef __TVOS_DEPRECATED
  #define __TVOS_DEPRECATED(_start, _dep, _msg)
#endif


/* for use marking APIs available info for Watch OS */
#if defined(__has_feature)
  #if __has_feature(attribute_availability_watchos)
    #define __WATCHOS_UNAVAILABLE                    __OS_AVAILABILITY(watchos,unavailable)
    #ifndef __WATCHOS_PROHIBITED
      #define __WATCHOS_PROHIBITED                     __OS_AVAILABILITY(watchos,unavailable)
    #endif
    #define __WATCHOS_AVAILABLE(_vers)               __OS_AVAILABILITY(watchos,introduced=_vers)
    #define __WATCHOS_DEPRECATED(_start, _dep, _msg) __WATCHOS_AVAILABLE(_start) __OS_AVAILABILITY_MSG(watchos,deprecated=_dep,_msg)
  #endif
#endif

#ifndef __WATCHOS_UNAVAILABLE
  #define __WATCHOS_UNAVAILABLE
#endif

#ifndef __WATCHOS_PROHIBITED
  #define __WATCHOS_PROHIBITED
#endif

#ifndef __WATCHOS_AVAILABLE
  #define __WATCHOS_AVAILABLE(_vers)
#endif

#ifndef __WATCHOS_DEPRECATED
  #define __WATCHOS_DEPRECATED(_start, _dep, _msg)
#endif

/* for use marking APIs unavailable for swift */
#if defined(__has_feature)
  #if __has_feature(attribute_availability_swift)
    #define __SWIFT_UNAVAILABLE                   __OS_AVAILABILITY(swift,unavailable)
    #define __SWIFT_UNAVAILABLE_MSG(_msg)         __OS_AVAILABILITY_MSG(swift,unavailable,_msg)
  #endif
#endif

#ifndef __SWIFT_UNAVAILABLE
  #define __SWIFT_UNAVAILABLE
#endif

#ifndef __SWIFT_UNAVAILABLE_MSG
  #define __SWIFT_UNAVAILABLE_MSG(_msg)
#endif

/*
 Macros for defining which versions/platform a given symbol can be used.
 
 @see http://clang.llvm.org/docs/AttributeReference.html#availability
 
 * Note that these macros are only compatible with clang compilers that
 * support the following target selection options:
 *
 * -mmacosx-version-min
 * -miphoneos-version-min
 * -mwatchos-version-min
 * -mtvos-version-min
 */

#if defined(__has_feature) && defined(__has_attribute)
 #if __has_attribute(availability)

    /*
     * API Introductions
     *
     * Use to specify the release that a particular API became available.
     *
     * Platform names:
     *   macos, macOSApplicationExtension, macCatalyst, macCatalystApplicationExtension,
     *   ios, iOSApplicationExtension, tvos, tvOSApplicationExtension, watchos,
     *   watchOSApplicationExtension, driverkit, visionos, visionOSApplicationExtension
     *
     * Examples:
     *    __API_AVAILABLE(macos(10.10))
     *    __API_AVAILABLE(macos(10.9), ios(10.0))
     *    __API_AVAILABLE(macos(10.4), ios(8.0), watchos(2.0), tvos(10.0))
     *    __API_AVAILABLE(driverkit(19.0))
     */
    #define __API_AVAILABLE(...) __API_AVAILABLE_GET_MACRO_93585900(__VA_ARGS__,__API_AVAILABLE15,__API_AVAILABLE14,__API_AVAILABLE13,__API_AVAILABLE12,__API_AVAILABLE11,__API_AVAILABLE10,__API_AVAILABLE9,__API_AVAILABLE8,__API_AVAILABLE7,__API_AVAILABLE6,__API_AVAILABLE5,__API_AVAILABLE4,__API_AVAILABLE3,__API_AVAILABLE2,__API_AVAILABLE1,__API_AVAILABLE0,0)(__VA_ARGS__)

    #define __API_AVAILABLE_BEGIN(...) _Pragma("clang attribute push") __API_AVAILABLE_BEGIN_GET_MACRO_93585900(__VA_ARGS__,__API_AVAILABLE_BEGIN15,__API_AVAILABLE_BEGIN14,__API_AVAILABLE_BEGIN13,__API_AVAILABLE_BEGIN12,__API_AVAILABLE_BEGIN11,__API_AVAILABLE_BEGIN10,__API_AVAILABLE_BEGIN9,__API_AVAILABLE_BEGIN8,__API_AVAILABLE_BEGIN7,__API_AVAILABLE_BEGIN6,__API_AVAILABLE_BEGIN5,__API_AVAILABLE_BEGIN4,__API_AVAILABLE_BEGIN3,__API_AVAILABLE_BEGIN2,__API_AVAILABLE_BEGIN1,__API_AVAILABLE_BEGIN0,0)(__VA_ARGS__)
    #define __API_AVAILABLE_END _Pragma("clang attribute pop")

    /*
     * API Deprecations
     *
     * Use to specify the release that a particular API became deprecated.
     *
     * Platform names:
     *   macos, macOSApplicationExtension, macCatalyst, macCatalystApplicationExtension,
     *   ios, iOSApplicationExtension, tvos, tvOSApplicationExtension, watchos,
     *   watchOSApplicationExtension, driverkit, visionos, visionOSApplicationExtension
     *
     *   Within each platform a tuple of versions will represent the version the API was
     *   introduced in, followed by the version it was deperecated in.
     *
     * Examples:
     *
     *    __API_DEPRECATED("Deprecated", macos(10.4, 10.8))
     *    __API_DEPRECATED("Deprecated", macos(10.4, 10.8), ios(2.0, 3.0), watchos(2.0, 3.0), tvos(9.0, 10.0))
     *
     *    __API_DEPRECATED_WITH_REPLACEMENT("-setName:", tvos(10.0, 10.4), ios(9.0, 10.0))
     *    __API_DEPRECATED_WITH_REPLACEMENT("SomeClassName", macos(10.4, 10.6), watchos(2.0, 3.0))
     */
    #define __API_DEPRECATED(...) __API_DEPRECATED_MSG_GET_MACRO_93585900(__VA_ARGS__,__API_DEPRECATED_MSG15,__API_DEPRECATED_MSG14,__API_DEPRECATED_MSG13,__API_DEPRECATED_MSG12,__API_DEPRECATED_MSG11,__API_DEPRECATED_MSG10,__API_DEPRECATED_MSG9,__API_DEPRECATED_MSG8,__API_DEPRECATED_MSG7,__API_DEPRECATED_MSG6,__API_DEPRECATED_MSG5,__API_DEPRECATED_MSG4,__API_DEPRECATED_MSG3,__API_DEPRECATED_MSG2,__API_DEPRECATED_MSG1,__API_DEPRECATED_MSG0,0,0)(__VA_ARGS__)
    #define __API_DEPRECATED_WITH_REPLACEMENT(...) __API_DEPRECATED_REP_GET_MACRO_93585900(__VA_ARGS__,__API_DEPRECATED_REP15,__API_DEPRECATED_REP14,__API_DEPRECATED_REP13,__API_DEPRECATED_REP12,__API_DEPRECATED_REP11,__API_DEPRECATED_REP10,__API_DEPRECATED_REP9,__API_DEPRECATED_REP8,__API_DEPRECATED_REP7,__API_DEPRECATED_REP6,__API_DEPRECATED_REP5,__API_DEPRECATED_REP4,__API_DEPRECATED_REP3,__API_DEPRECATED_REP2,__API_DEPRECATED_REP1,__API_DEPRECATED_REP0,0,0)(__VA_ARGS__)

    #define __API_DEPRECATED_BEGIN(...) _Pragma("clang attribute push") __API_DEPRECATED_BEGIN_GET_MACRO_93585900(__VA_ARGS__,__API_DEPRECATED_BEGIN15,__API_DEPRECATED_BEGIN14,__API_DEPRECATED_BEGIN13,__API_DEPRECATED_BEGIN12,__API_DEPRECATED_BEGIN11,__API_DEPRECATED_BEGIN10,__API_DEPRECATED_BEGIN9,__API_DEPRECATED_BEGIN8,__API_DEPRECATED_BEGIN7,__API_DEPRECATED_BEGIN6,__API_DEPRECATED_BEGIN5,__API_DEPRECATED_BEGIN4,__API_DEPRECATED_BEGIN3,__API_DEPRECATED_BEGIN2,__API_DEPRECATED_BEGIN1,__API_DEPRECATED_BEGIN0,0,0)(__VA_ARGS__)
    #define __API_DEPRECATED_END _Pragma("clang attribute pop")

    #define __API_DEPRECATED_WITH_REPLACEMENT_BEGIN(...) _Pragma("clang attribute push") __API_DEPRECATED_WITH_REPLACEMENT_BEGIN_GET_MACRO_93585900(__VA_ARGS__,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN15,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN14,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN13,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN12,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN11,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN10,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN9,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN8,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN7,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN6,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN5,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN4,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN3,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN2,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN1,__API_DEPRECATED_WITH_REPLACEMENT_BEGIN0,0,0)(__VA_ARGS__)
    #define __API_DEPRECATED_WITH_REPLACEMENT_END _Pragma("clang attribute pop")

    
#if 0
// Bringup rdar://150542072
    #define __API_OBSOLETED(...) __API_OBSOLETED_MSG_GET_MACRO_93585900(__VA_ARGS__,__API_OBSOLETED_MSG15,__API_OBSOLETED_MSG14,__API_OBSOLETED_MSG13,__API_OBSOLETED_MSG12,__API_OBSOLETED_MSG11,__API_OBSOLETED_MSG10,__API_OBSOLETED_MSG9,__API_OBSOLETED_MSG8,__API_OBSOLETED_MSG7,__API_OBSOLETED_MSG6,__API_OBSOLETED_MSG5,__API_OBSOLETED_MSG4,__API_OBSOLETED_MSG3,__API_OBSOLETED_MSG2,__API_OBSOLETED_MSG1,__API_OBSOLETED_MSG0,0,0)(__VA_ARGS__)
    #define __API_OBSOLETED_WITH_REPLACEMENT(...) __API_OBSOLETED_REP_GET_MACRO_93585900(__VA_ARGS__,__API_OBSOLETED_REP15,__API_OBSOLETED_REP14,__API_OBSOLETED_REP13,__API_OBSOLETED_REP12,__API_OBSOLETED_REP11,__API_OBSOLETED_REP10,__API_OBSOLETED_REP9,__API_OBSOLETED_REP8,__API_OBSOLETED_REP7,__API_OBSOLETED_REP6,__API_OBSOLETED_REP5,__API_OBSOLETED_REP4,__API_OBSOLETED_REP3,__API_OBSOLETED_REP2,__API_OBSOLETED_REP1,__API_OBSOLETED_REP0,0,0)(__VA_ARGS__)

    #define __API_OBSOLETED_BEGIN(...) _Pragma("clang attribute push") __API_OBSOLETED_BEGIN_GET_MACRO_93585900(__VA_ARGS__,__API_OBSOLETED_BEGIN15,__API_OBSOLETED_BEGIN14,__API_OBSOLETED_BEGIN13,__API_OBSOLETED_BEGIN12,__API_OBSOLETED_BEGIN11,__API_OBSOLETED_BEGIN10,__API_OBSOLETED_BEGIN9,__API_OBSOLETED_BEGIN8,__API_OBSOLETED_BEGIN7,__API_OBSOLETED_BEGIN6,__API_OBSOLETED_BEGIN5,__API_OBSOLETED_BEGIN4,__API_OBSOLETED_BEGIN3,__API_OBSOLETED_BEGIN2,__API_OBSOLETED_BEGIN1,__API_OBSOLETED_BEGIN0,0,0)(__VA_ARGS__)
    #define __API_OBSOLETED_END _Pragma("clang attribute pop")

    #define __API_OBSOLETED_WITH_REPLACEMENT_BEGIN(...) _Pragma("clang attribute push") __API_OBSOLETED_WITH_REPLACEMENT_BEGIN_GET_MACRO_93585900(__VA_ARGS__,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN15,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN14,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN13,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN12,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN11,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN10,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN9,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN8,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN7,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN6,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN5,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN4,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN3,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN2,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN1,__API_OBSOLETED_WITH_REPLACEMENT_BEGIN0,0,0)(__VA_ARGS__)
    #define __API_OBSOLETED_WITH_REPLACEMENT_END _Pragma("clang attribute pop")
#endif

    /*
     * API Unavailability
     * Use to specify that an API is unavailable for a particular platform.
     *
     * Example:
     *    __API_UNAVAILABLE(macos)
     *    __API_UNAVAILABLE(watchos, tvos)
     */
    #define __API_UNAVAILABLE(...) __API_UNAVAILABLE_GET_MACRO_93585900(__VA_ARGS__,__API_UNAVAILABLE15,__API_UNAVAILABLE14,__API_UNAVAILABLE13,__API_UNAVAILABLE12,__API_UNAVAILABLE11,__API_UNAVAILABLE10,__API_UNAVAILABLE9,__API_UNAVAILABLE8,__API_UNAVAILABLE7,__API_UNAVAILABLE6,__API_UNAVAILABLE5,__API_UNAVAILABLE4,__API_UNAVAILABLE3,__API_UNAVAILABLE2,__API_UNAVAILABLE1,__API_UNAVAILABLE0,0)(__VA_ARGS__)
  
    #define __API_UNAVAILABLE_BEGIN(...) _Pragma("clang attribute push") __API_UNAVAILABLE_BEGIN_GET_MACRO_93585900(__VA_ARGS__,__API_UNAVAILABLE_BEGIN15,__API_UNAVAILABLE_BEGIN14,__API_UNAVAILABLE_BEGIN13,__API_UNAVAILABLE_BEGIN12,__API_UNAVAILABLE_BEGIN11,__API_UNAVAILABLE_BEGIN10,__API_UNAVAILABLE_BEGIN9,__API_UNAVAILABLE_BEGIN8,__API_UNAVAILABLE_BEGIN7,__API_UNAVAILABLE_BEGIN6,__API_UNAVAILABLE_BEGIN5,__API_UNAVAILABLE_BEGIN4,__API_UNAVAILABLE_BEGIN3,__API_UNAVAILABLE_BEGIN2,__API_UNAVAILABLE_BEGIN1,__API_UNAVAILABLE_BEGIN0,0)(__VA_ARGS__)
    #define __API_UNAVAILABLE_END _Pragma("clang attribute pop")
 #endif /* __has_attribute(availability) */
#endif /*  #if defined(__has_feature) && defined(__has_attribute) */

/* 
 * Evaluate to nothing for compilers that don't support availability.
 */

#ifndef __API_AVAILABLE
  #define __API_AVAILABLE(...)
#endif

#ifndef __API_AVAILABLE_BEGIN
  #define __API_AVAILABLE_BEGIN(...)
#endif

#ifndef __API_AVAILABLE_END
  #define __API_AVAILABLE_END
#endif

#ifndef __API_DEPRECATED
  #define __API_DEPRECATED(...)
#endif

#ifndef __API_DEPRECATED_BEGIN
  #define __API_DEPRECATED_BEGIN(...)
#endif

#ifndef __API_DEPRECATED_END
  #define __API_DEPRECATED_END
#endif

#ifndef __API_DEPRECATED_WITH_REPLACEMENT
  #define __API_DEPRECATED_WITH_REPLACEMENT(...)
#endif

#ifndef __API_DEPRECATED_WITH_REPLACEMENT_BEGIN
  #define __API_DEPRECATED_WITH_REPLACEMENT_BEGIN(...)
#endif

#ifndef __API_DEPRECATED_WITH_REPLACEMENT_END
  #define __API_DEPRECATED_WITH_REPLACEMENT_END
#endif

#ifndef __API_OBSOLETED
  #define __API_OBSOLETED(...)
#endif

#ifndef __API_OBSOLETED_BEGIN
  #define __API_OBSOLETED_BEGIN(...)
#endif

#ifndef __API_OBSOLETED_END
  #define __API_OBSOLETED_END
#endif

#ifndef __API_OBSOLETED_WITH_REPLACEMENT
  #define __API_OBSOLETED_WITH_REPLACEMENT(...)
#endif

#ifndef __API_OBSOLETED_WITH_REPLACEMENT_BEGIN
  #define __API_OBSOLETED_WITH_REPLACEMENT_BEGIN(...)
#endif

#ifndef __API_OBSOLETED_WITH_REPLACEMENT_END
  #define __API_OBSOLETED_WITH_REPLACEMENT_END
#endif

#ifndef __API_UNAVAILABLE
  #define __API_UNAVAILABLE(...)
#endif

#ifndef __API_UNAVAILABLE_BEGIN
  #define __API_UNAVAILABLE_BEGIN(...)
#endif

#ifndef __API_UNAVAILABLE_END
  #define __API_UNAVAILABLE_END
#endif

/*
 * If SPI decorations have not been defined elsewhere, disable them.
 */

#ifndef __SPI_AVAILABLE
  #define __SPI_AVAILABLE(...)
#endif

#ifndef __SPI_AVAILABLE_BEGIN
  #define __SPI_AVAILABLE_BEGIN(...)
#endif

#ifndef __SPI_AVAILABLE_END
  #define __SPI_AVAILABLE_END
#endif

#ifndef __SPI_DEPRECATED
  #define __SPI_DEPRECATED(...)
#endif

#ifndef __SPI_DEPRECATED_WITH_REPLACEMENT
  #define __SPI_DEPRECATED_WITH_REPLACEMENT(...)
#endif

#endif /* __AVAILABILITY__ */

#ifndef __OPEN_SOURCE__
// This is explicitly outside the header guard
#ifndef __AVAILABILITY_VERSIONS_VERSION_HASH
#define __AVAILABILITY_VERSIONS_VERSION_HASH 93585900U
#define __AVAILABILITY_VERSIONS_VERSION_STRING "Local"
#define __AVAILABILITY_FILE "Availability.h"
#elif __AVAILABILITY_VERSIONS_VERSION_HASH != 93585900U
#pragma GCC error "Already found AvailabilityVersions version " __AVAILABILITY_FILE " from " __AVAILABILITY_VERSIONS_VERSION_STRING ", which is incompatible with Availability.h from Local. Mixing and matching Availability from different SDKs is not supported"
#endif /* __AVAILABILITY_VERSIONS_VERSION_HASH */
#endif /* __OPEN_SOURCE__ */
