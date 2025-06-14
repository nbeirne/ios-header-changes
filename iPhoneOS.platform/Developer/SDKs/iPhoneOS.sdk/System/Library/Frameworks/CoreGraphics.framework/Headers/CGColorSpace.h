/* CoreGraphics - CGColorSpace.h
   Copyright (c) 1999-2013 Apple Inc.
   All rights reserved. */

#ifndef CGCOLORSPACE_H_
#define CGCOLORSPACE_H_

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFAvailability.h>
#include <stdint.h>

typedef struct CF_BRIDGED_TYPE(id) CGColorSpace *CGColorSpaceRef; /* Swift Sendable */

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGDataProvider.h>

CF_IMPLICIT_BRIDGING_ENABLED

/* Color rendering intents. */

typedef CF_ENUM (int32_t, CGColorRenderingIntent) {
    kCGRenderingIntentDefault,
    kCGRenderingIntentAbsoluteColorimetric,
    kCGRenderingIntentRelativeColorimetric,
    kCGRenderingIntentPerceptual,
    kCGRenderingIntentSaturation
};

/* The model of a color space. */

typedef CF_ENUM (int32_t,  CGColorSpaceModel) {
    kCGColorSpaceModelUnknown = -1,
    kCGColorSpaceModelMonochrome,
    kCGColorSpaceModelRGB,
    kCGColorSpaceModelCMYK,
    kCGColorSpaceModelLab,
    kCGColorSpaceModelDeviceN,
    kCGColorSpaceModelIndexed,
    kCGColorSpaceModelPattern,
    kCGColorSpaceModelXYZ
};

CF_ASSUME_NONNULL_BEGIN

#define CG_HDR_BT_2100 1

/* The name of the "Generic" Gray color space. It is a legacy
   color space so use it only if you definitely know that you
   need it. If you need just a reasonable monochrome color space,
   please use Generic Gray Gamma 2.2, i.e. use
   kCGColorSpaceGenericGrayGamma2_2 name instead of
   kCGColorSpaceGenericGray. */

CG_EXTERN const CFStringRef kCGColorSpaceGenericGray
  API_AVAILABLE(macos(10.4), ios(9.0));

/* The name of the "Generic" RGB color space. It is a legacy
   color space so use it only if you definitely know that you
   need it. If you need just a reasonable RGB color space,
   please use sRGB, i.e. use kCGColorSpaceSRGB name
   instead of kCGColorSpaceGenericRGB. */

CG_EXTERN const CFStringRef kCGColorSpaceGenericRGB
  API_AVAILABLE(macos(10.4), ios(9.0));

/* The name of the "Generic" CMYK color space. */

CG_EXTERN const CFStringRef kCGColorSpaceGenericCMYK
  API_AVAILABLE(macos(10.4), ios(9.0));
  
CG_EXTERN const CFStringRef kCGColorSpaceDisplayP3
  API_AVAILABLE(macos(10.11.2), ios(9.3));

/* The name of the "Generic" linear RGB color space. This is the same as
   `kCGColorSpaceGenericRGB' but with a 1.0 gamma. */

CG_EXTERN const CFStringRef kCGColorSpaceGenericRGBLinear
  API_AVAILABLE(macos(10.5), ios(9.0));

/* The name of the Adobe RGB (1998) color space. For more information, see
  "Adobe RGB (1998) Color Image Encoding", Version 2005-05, Adobe Systems
  Inc. (http://www.adobe.com). */

CG_EXTERN const CFStringRef kCGColorSpaceAdobeRGB1998
  API_AVAILABLE(macos(10.5), ios(9.0));

/* The name of the sRGB color space. The capitalization in the name, while
   strictly inaccurate, avoids interpretational ambiguity. For more
   information, see IEC 61966-2-1 (1999-10): "Multimedia systems and
   equipment - Colour measurement and management - Part 2-1: Colour
   management - Default RGB colour space - sRGB". */

CG_EXTERN const CFStringRef kCGColorSpaceSRGB
  API_AVAILABLE(macos(10.5), ios(9.0));

/* The "Generic" gray color space with γ = 1.8. */

CG_EXTERN const CFStringRef kCGColorSpaceGenericGrayGamma2_2
  API_AVAILABLE(macos(10.6), ios(9.0));

CG_EXTERN const CFStringRef kCGColorSpaceGenericXYZ
  API_AVAILABLE(macos(10.11), ios(9.0));

/* The name of the "Generic" L*a*b* color space. This is the same as
 L*a*b* colorspace created by `CGColorSpaceCreateLab' with
 white_point[0.9642, 1.0, 0.8249] (i.e. D50), black_point[0.0, 0.0, 0.0]
 and range [-128, 128, -128, 128]. */

CG_EXTERN const CFStringRef kCGColorSpaceGenericLab
API_AVAILABLE(macos(10.13), ios(11.0));

CG_EXTERN const CFStringRef kCGColorSpaceACESCGLinear
API_AVAILABLE(macos(10.11), ios(9.0));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_709
API_AVAILABLE(macos(10.11), ios(9.0));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_709_PQ
API_AVAILABLE(macos(12.0), ios(15.1));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_709_HLG
API_AVAILABLE(macos(12.0), ios(15.1));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_2020
API_AVAILABLE(macos(10.11), ios(9.0));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_2020_sRGBGamma
API_AVAILABLE(macos(12.0), ios(15.1));

CG_EXTERN const CFStringRef kCGColorSpaceROMMRGB
API_AVAILABLE(macos(10.11), ios(9.0));

CG_EXTERN const CFStringRef kCGColorSpaceDCIP3
API_AVAILABLE(macos(10.11), ios(9.0));

CG_EXTERN const CFStringRef kCGColorSpaceLinearITUR_2020
API_AVAILABLE(macos(12.0), ios(15.0));

CG_EXTERN const CFStringRef kCGColorSpaceExtendedITUR_2020
API_AVAILABLE(macos(11.0), ios(14.0));

CG_EXTERN const CFStringRef kCGColorSpaceExtendedLinearITUR_2020
API_AVAILABLE(macos(10.14.3), ios(12.3));

CG_EXTERN const CFStringRef kCGColorSpaceLinearDisplayP3
API_AVAILABLE(macos(12.0), ios(15.0));

CG_EXTERN const CFStringRef kCGColorSpaceExtendedDisplayP3
API_AVAILABLE(macos(11.0), ios(14.0));

CG_EXTERN const CFStringRef kCGColorSpaceExtendedLinearDisplayP3
API_AVAILABLE(macos(10.14.3), ios(12.3));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_2100_PQ
API_AVAILABLE(macos(11.0), ios(14.0));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_2100_HLG
API_AVAILABLE(macos(11.0), ios(14.0));

CG_EXTERN const CFStringRef kCGColorSpaceDisplayP3_PQ
API_AVAILABLE(macos(10.15.4), ios(13.4));

CG_EXTERN const CFStringRef kCGColorSpaceDisplayP3_HLG
API_AVAILABLE(macos(10.14.6), ios(12.6));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_2020_PQ
API_DEPRECATED("No longer supported", macos(10.15.4,11.0), ios(13.4,14.0));   // Use kCGColorSpaceITUR_2100_PQ.

CG_EXTERN const CFStringRef kCGColorSpaceITUR_2020_HLG
API_DEPRECATED("No longer supported", macos(10.15.6,11.0), ios(12.6,14.0));   // Use kCGColorSpaceITUR_2100_HLG.

CG_EXTERN const CFStringRef kCGColorSpaceDisplayP3_PQ_EOTF
API_DEPRECATED("No longer supported", macos(10.14.6,10.15.4), ios(12.6,13.4));

CG_EXTERN const CFStringRef kCGColorSpaceITUR_2020_PQ_EOTF
API_DEPRECATED("No longer supported", macos(10.14.6,10.15.4), ios(12.6,13.4)); // Use kCGColorSpaceITUR_2100_PQ.

/*  The name of the extended sRGB color space.
    The extended sRGB color space allows to specify colors beyond the range of [0.0, 1.0],
    while still preserving the colorimetry and encoding of sRGB (see above for more details).
    The negative values will be encoded as the signed reflection of original encoding functions,
    i.e. y(x) = sign(x)*f(abs(x)) where f(x) represents the encoding function. 
    The capitalization in the name is for avoiding interpretational ambiguity.  */

CG_EXTERN const CFStringRef kCGColorSpaceExtendedSRGB
API_AVAILABLE(macos(10.12), ios(10.0));

/*  The name of the sRGB color space variant with linear gamma */

CG_EXTERN const CFStringRef kCGColorSpaceLinearSRGB
API_AVAILABLE(macos(10.12), ios(10.0));

/*  The name of the extended sRGB color space variant with linear gamma */

CG_EXTERN const CFStringRef kCGColorSpaceExtendedLinearSRGB
API_AVAILABLE(macos(10.12), ios(10.0));

/*  The name of the extended Gray color space. This color space has the same colorimetry as Generic Gray 2.2.
    The negative values will be encoded as the signed reflection of original encoding functions,
    i.e. y(x) = sign(x)*f(abs(x)) where f(x) represents the encoding function. */

CG_EXTERN const CFStringRef kCGColorSpaceExtendedGray
API_AVAILABLE(macos(10.12), ios(10.0));

/*  The name of the Generic Gray 2.2 color space variant with linear gamma */

CG_EXTERN const CFStringRef kCGColorSpaceLinearGray
API_AVAILABLE(macos(10.12), ios(10.0));

/*  The name of the extended Generic Gray 2.2 color space variant with linear gamma */

CG_EXTERN const CFStringRef kCGColorSpaceExtendedLinearGray
API_AVAILABLE(macos(10.12), ios(10.0));

CG_EXTERN const CFStringRef kCGColorSpaceCoreMedia709
API_AVAILABLE(macos(15.0), ios(18.0));

/* Create a DeviceGray color space. */

CG_EXTERN CGColorSpaceRef cg_nullable CGColorSpaceCreateDeviceGray(void)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Create a DeviceRGB color space. */

CG_EXTERN CGColorSpaceRef cg_nullable CGColorSpaceCreateDeviceRGB(void)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Create a DeviceCMYK color space. */

CG_EXTERN CGColorSpaceRef cg_nullable CGColorSpaceCreateDeviceCMYK(void)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Create a calibrated gray color space. `whitePoint' is an array of 3
   numbers specifying the tristimulus value, in the CIE 1931 XYZ-space, of
   the diffuse white point. `blackPoint' is an array of 3 numbers specifying
   the tristimulus value, in CIE 1931 XYZ-space, of the diffuse black point.
   `gamma' defines the gamma for the gray component. Specifying `blackPoint'
   is not required and in such a case `blackPoint' will be assumed to be 
   [0.0, 0.0, 0.0]. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateCalibratedGray(const CGFloat
  whitePoint[CG_NONNULL_ARRAY 3], const CGFloat blackPoint[__nullable 3], CGFloat gamma)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Create a calibrated RGB color space. `whitePoint' is an array of 3
   numbers specifying the tristimulus value, in the CIE 1931 XYZ-space, of
   the diffuse white point. `blackPoint' is an array of 3 numbers specifying
   the tristimulus value, in CIE 1931 XYZ-space, of the diffuse black point.
   `gamma' is an array of 3 numbers specifying the gamma for the red, green,
   and blue components of the color space. `matrix' is an array of 9 numbers
   specifying the linear interpretation of the gamma-modified RGB values of
   the color space with respect to the final XYZ representation. 
   Not all parameters need to be specified. If `blackPoint' is NULL it will be
   assumed to be [0.0, 0.0, 0.0]. If `gamma' is NULL it will be assumed to be
   linear for all components. If `matrix' is NULL it will be assumed to be identity. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateCalibratedRGB(const CGFloat
  whitePoint[CG_NONNULL_ARRAY 3], const CGFloat blackPoint[__nullable 3],
  const CGFloat gamma[__nullable 3], const CGFloat matrix[__nullable 9])
  API_AVAILABLE(macos(10.0), ios(2.0));
    
/* Create an L*a*b* color space. `whitePoint' is an array of 3 numbers
   specifying the tristimulus value, in the CIE 1931 XYZ-space, of the
   diffuse white point. `blackPoint' is an array of 3 numbers specifying the
   tristimulus value, in CIE 1931 XYZ-space, of the diffuse black point.
   `range' is an array of four numbers specifying the range of valid values
   for the a* and b* components of the color space. Not all parameters need to be
   specified. If `blackPoint'in NULL it will be assumed to be [0.0, 0.0, 0.0].
   If `range' is NULL it will be assumed to be [-100, 100, -100, 100]. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateLab(const CGFloat whitePoint[CG_NONNULL_ARRAY 3],
  const CGFloat blackPoint[__nullable 3], const CGFloat range[__nullable 4])
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Create an ICC-based color space using the ICC profile raw data specified by
   `data' which can be either CFDataRef or CGDataProviderRef */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateWithICCData(CFTypeRef cg_nullable data)
  API_AVAILABLE(macos(10.12), ios(10.0));

/* Create an ICC-based color space. `nComponents' specifies the number of
   color components in the color space defined by the ICC profile data. This
   must match the number of components actually in the ICC profile, and must
   be 1, 3, or 4. `range' is an array of 2*nComponents numbers specifying
   the minimum and maximum valid values of the corresponding color
   components, so that for color component k, range[2*k] <= c[k] <=
   range[2*k+1], where c[k] is the k'th color component. `profile' is a data
   provider specifying the ICC profile. `alternate' specifies an alternate
   color space to be used in case the ICC profile is not supported. It must
   have `nComponents' color components. If `alternate' is NULL, then the
   color space used will be DeviceGray, DeviceRGB, or DeviceCMYK, depending
   on whether `nComponents' is 1, 3, or 4, respectively. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateICCBased(size_t nComponents,
  const CGFloat * __nullable range, CGDataProviderRef cg_nullable profile,
  CGColorSpaceRef __nullable alternate)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Create an indexed color space. A sample value in an indexed color space
   is treated as an index into the color table of the color space. `base'
   specifies the base color space in which the values in the color table are
   to be interpreted. `lastIndex' is an integer which specifies the maximum
   valid index value; it must be less than or equal to 255. `colorTable' is
   an array of m * (lastIndex + 1) bytes, where m is the number of color
   components in the base color space. Each byte is an unsigned integer in
   the range 0 to 255 that is scaled to the range of the corresponding color
   component in the base color space. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateIndexed(CGColorSpaceRef cg_nullable baseSpace,
  size_t lastIndex, const unsigned char * cg_nullable colorTable)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Create a pattern color space. `baseSpace' is the underlying color space
   of the pattern color space. For colored patterns, `baseSpace' should be
   NULL; for uncolored patterns, `baseSpace' specifies the color space of
   colors which will be painted through the pattern. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreatePattern(CGColorSpaceRef __nullable baseSpace)
  API_AVAILABLE(macos(10.0), ios(2.0));

typedef const struct CF_BRIDGED_TYPE(id) ColorSyncProfile* ColorSyncProfileRef;

CG_EXTERN const CFStringRef kCGColorSpaceExtendedRange;

/* Create a color space using ColorSyncProfileRef.
   To create an extended color space include kCGColorSpaceExtendedRange/kCFBooleanTrue
   key/value pair in `options' dictionary. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateWithColorSyncProfile(ColorSyncProfileRef __nullable, CFDictionaryRef __nullable options)
API_AVAILABLE(macos(12.0), ios(15.0));

/* Create a color space using `name' as the identifier for the color
   space. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateWithName(CFStringRef cg_nullable name)
  API_AVAILABLE(macos(10.2), ios(2.0));

/* Equivalent to `CFRetain(space)', except it doesn't crash (as CFRetain
   does) if `space' is NULL. */

CG_EXTERN CGColorSpaceRef cg_nullable CGColorSpaceRetain(CGColorSpaceRef cg_nullable space)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Equivalent to `CFRelease(space)', except it doesn't crash (as CFRelease
   does) if `space' is NULL. */

CG_EXTERN void CGColorSpaceRelease(CGColorSpaceRef cg_nullable CF_RELEASES_ARGUMENT space)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Return the system name of the color space. This applies to all color spaces
   created using `CGColorSpaceCreateWithName' as well as to ICC-based colorspaces
   created using `CGColorSpaceCreateWithICCData' or `CGColorSpaceCreateICCBased'
   if they are equivalent to respective named system color spaces. Device color spaces
   also return unique names. This function will return NULL for other color spaces.
   Example:
          CGColorSpaceRef space = CGColorSpaceCreateWithICCData(icc_data);
          CFStringRef name = CGColorSpaceGetName(space);
          if (name != NULL && CFEqual(name, kCGColorSpaceDisplayP3)) {
              // your color space is Display P3
              ...
          }
 */

CG_EXTERN CFStringRef __nullable CGColorSpaceGetName(CGColorSpaceRef cg_nullable space)
  API_AVAILABLE(macos(10.13), ios(11.0));

/* Same as `CGColorSpaceGetName' but with ownership released to the caller. */
CG_EXTERN CFStringRef __nullable CGColorSpaceCopyName(CGColorSpaceRef cg_nullable space)
  API_AVAILABLE(macos(10.6), ios(10.0));

/* Return the CFTypeID for CGColorSpaces. */

CG_EXTERN CFTypeID CGColorSpaceGetTypeID(void)
  API_AVAILABLE(macos(10.2), ios(2.0));

/* Return the number of color components in the color space `space'. */

CG_EXTERN size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef cg_nullable space)
  API_AVAILABLE(macos(10.0), ios(2.0));

/* Return the color space model of `space'. */

CG_EXTERN CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef cg_nullable space)
  API_AVAILABLE(macos(10.5), ios(2.0));

/* Return the base color space of `space' if `space' is a pattern or indexed
   color space; otherwise, return NULL. To determine whether a color space
   is an indexed or pattern color space, use `CGColorSpaceGetModel'. */

CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceGetBaseColorSpace(CGColorSpaceRef cg_nullable space)
  API_AVAILABLE(macos(10.5), ios(2.0));

/* Similar to 'CGColorSpaceGetBaseColorSpace' if `space' is a pattern or indexed
   color space, in which case the retained base color space is returned.
   In the case of a color space containing image specific metadata associated with
   the gain map, a new color space without the metadata will be returned.
   For all other color spaces this function will return NULL.
*/

CG_EXTERN CGColorSpaceRef CGColorSpaceCopyBaseColorSpace(CGColorSpaceRef space)
API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0));

/* Return the number of entries in the color table of `space' if `space' is
   an indexed color space; otherwise, return 0. To determine whether a color
   space is an indexed color space, use `CGColorSpaceGetModel'. */

CG_EXTERN size_t CGColorSpaceGetColorTableCount(CGColorSpaceRef cg_nullable space)
  API_AVAILABLE(macos(10.5), ios(2.0));

/* Copy the entries in the color table of `space' to `table' if `space' is
   an indexed color space; otherwise, do nothing. The array pointed to by
   `table' should be at least as large as the number of entries in the color
   table; the returned data is in the same format as that passed to
   `CGColorSpaceCreateIndexed'. To determine whether a color space is an
   indexed color space, use `CGColorSpaceGetModel'. */

CG_EXTERN void CGColorSpaceGetColorTable(CGColorSpaceRef cg_nullable space,
  uint8_t * cg_nullable table) API_AVAILABLE(macos(10.5), ios(2.0));

/* Return a copy of the ICC profile data of `space', or NULL if the color space
   doesn't have an ICC profile. */

CG_EXTERN CFDataRef __nullable CGColorSpaceCopyICCData(CGColorSpaceRef cg_nullable space)
API_AVAILABLE(macos(10.12), ios(10.0));

/* Return true if gamut of the RGB color space is greater than 85% of NTSC gamut */

CG_EXTERN bool CGColorSpaceIsWideGamutRGB(CGColorSpaceRef)
API_AVAILABLE(macos(10.12), ios(10.0));

/* Return true if color space uses transfer functions defined in ITU Rec.2100
   Please use CGColorSpaceUsesITUR_2100TF instead */

CG_EXTERN bool CGColorSpaceIsHDR(CGColorSpaceRef)
API_AVAILABLE(macos(10.15), ios(13.0));

/* Return true if color space uses transfer functions defined in ITU Rec.2100 */

CG_EXTERN bool CGColorSpaceUsesITUR_2100TF(CGColorSpaceRef)
API_AVAILABLE(macos(11.0), ios(14.0));

CG_EXTERN bool CGColorSpaceIsPQBased(CGColorSpaceRef s)
API_AVAILABLE(macos(12.0), ios(15.0));

CG_EXTERN bool CGColorSpaceIsHLGBased(CGColorSpaceRef s)
API_AVAILABLE(macos(12.0), ios(15.0));


/* Return true if `space' can be used as a destination color space; false
 otherwise. */

CG_EXTERN bool CGColorSpaceSupportsOutput(CGColorSpaceRef space)
API_AVAILABLE(macos(10.12), ios(10.0));

/*  CGColorSpaceCopyPropertyList will return NULL for special color spaces
    (e.g. kCGColorSpaceDeviceN or kCGColorSpacePattern), except Indexed Color Space */
CG_EXTERN CFPropertyListRef __nullable
CGColorSpaceCopyPropertyList(CGColorSpaceRef space)
API_AVAILABLE(macos(10.12), ios(10.0));

CG_EXTERN CGColorSpaceRef __nullable
CGColorSpaceCreateWithPropertyList(CFPropertyListRef plist)
API_AVAILABLE(macos(10.12), ios(10.0));

/* Return true if `space' uses extended range [-Inf, +Inf]; false
 otherwise. */

CG_EXTERN bool CGColorSpaceUsesExtendedRange(CGColorSpaceRef space)
API_AVAILABLE(macos(10.12), ios(10.0));

/* Create a linearized copy of the color space if the color space is matrix based.
   Return NULL if otherwise */
CG_EXTERN CGColorSpaceRef  __nullable CGColorSpaceCreateLinearized(CGColorSpaceRef space)
API_AVAILABLE(macos(11.0), ios(14.0));

/* Create a copy of the color space which uses extended range [-Inf, +Inf] if the color space is
   matrix based. Return NULL if otherwise */
CG_EXTERN CGColorSpaceRef  __nullable CGColorSpaceCreateExtended(CGColorSpaceRef space)
API_AVAILABLE(macos(11.0), ios(14.0));

/* Create a linearized copy of the color space which uses extended range [-Inf, +Inf]
   if the color space is matrix based. Return NULL if otherwise */
CG_EXTERN CGColorSpaceRef  __nullable CGColorSpaceCreateExtendedLinearized(CGColorSpaceRef space)
API_AVAILABLE(macos(11.0), ios(14.0));

/* Create a copy of the color space which uses standard range [0.0, 1.0]. */
CG_EXTERN CGColorSpaceRef CGColorSpaceCreateCopyWithStandardRange(CGColorSpaceRef s)
API_AVAILABLE(macos(13.0), ios(16.0));

/* Deprecated functions */

/* Please use `CGColorSpaceCreateWithICCData' */
CG_EXTERN CGColorSpaceRef __nullable CGColorSpaceCreateWithICCProfile(CFDataRef cg_nullable data)
  API_DEPRECATED("No longer supported", macos(10.5,10.13), ios(2.0,11.0));

/* Please use `CGColorSpaceCopyICCData' */
CG_EXTERN CFDataRef __nullable CGColorSpaceCopyICCProfile(CGColorSpaceRef cg_nullable space)
  API_DEPRECATED("No longer supported", macos(10.5,10.13), ios(2.0,11.0));

/* Please use `CGColorSpaceCreateWithColorSyncProfile' */
CG_EXTERN CGColorSpaceRef __nullable
  CGColorSpaceCreateWithPlatformColorSpace(const void * cg_nullable ref)
  API_DEPRECATED("No longer supported", macos(10.0,12.0), ios(9.0,15.0));


CF_ASSUME_NONNULL_END

CF_IMPLICIT_BRIDGING_DISABLED

#endif /* CGCOLORSPACE_H_ */
