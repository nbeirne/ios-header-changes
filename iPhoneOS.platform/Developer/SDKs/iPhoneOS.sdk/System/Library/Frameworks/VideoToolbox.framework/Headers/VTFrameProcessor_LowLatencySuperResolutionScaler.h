/*
	File:  VTFrameProcessor_LowLatencySuperResolutionScaler.h

	Framework:  VideoToolbox

	Copyright © 2024-2025 Apple Inc. All rights reserved.

*/

#ifndef VTFRAMEPROCESSOR_LOWLATENCYSUPERRESOLUTIONSCALER_H
#define VTFRAMEPROCESSOR_LOWLATENCYSUPERRESOLUTIONSCALER_H

#include <CoreMedia/CMBase.h>

#if ! TARGET_OS_SIMULATOR
#ifdef __OBJC__

#import <VideoToolbox/VTFrameProcessorConfiguration.h>
#import <VideoToolbox/VTFrameProcessorParameters.h>
#import <VideoToolbox/VTFrameProcessorFrame.h>


NS_HEADER_AUDIT_BEGIN(nullability, sendability)


/*!
 @class VTLowLatencySuperResolutionScalerConfiguration
 @abstract Creates an object which is used to configure VTFrameProcessor for Low Latency Super Resolution Scaler processing.

 @discussion VTLowLatencySuperResolutionScalerConfiguration is used to configure a VTFrameProcessor.  This interface can also queried for important operating details, like the pixel buffer attributes required for frames submitted to the processor.
*/

API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos)
NS_SWIFT_SENDABLE
@interface VTLowLatencySuperResolutionScalerConfiguration : NSObject <VTFrameProcessorConfiguration>

#pragma mark --- init function(s).
/*!
 @abstract Creates a new VTLowLatencySuperResolutionScalerConfiguration with specified frame width and height.

 @param frameWidth    Width of source frame in pixels.

 @param frameHeight   Height of source frame in pixels.
 
 @param scaleFactor   The scale factor to be applied.  This must be a supported value returned by supportedScaleFactorsForFrameWidth:frameHeight.
*/
- (instancetype)initWithFrameWidth:(NSInteger)frameWidth
					   frameHeight:(NSInteger)frameHeight
					   scaleFactor:(float)scaleFactor;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * @property frameWidth
 * @abstract Width of source frame in pixels.
*/
@property (nonatomic, readonly) NSInteger frameWidth;

/**
 * @property frameHeight
 * @abstract Height of source frame in pixels.
*/
@property (nonatomic, readonly) NSInteger frameHeight;

/**
 * @property frameSupportedPixelFormats
 * @abstract list of pixel formats for source frames for the current configuration
 */

@property (nonatomic, readonly) NSArray<NSNumber *> * frameSupportedPixelFormats NS_REFINED_FOR_SWIFT;

/**
 * @property sourcePixelBufferAttributes
 * @abstract returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as source and reference frames
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE sourcePixelBufferAttributes;

/**
 * @property destinationPixelBufferAttributes
 * @abstract returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as destination frames
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE destinationPixelBufferAttributes;

/**
 * @property scaleFactor
 * @abstract Returns the scale factor that the configuration was initialized with.
*/
@property (nonatomic, readonly) float scaleFactor;

/*!
	@property maximumDimensions
	@abstract returns the maximum dimensions for a sourceFrame for the processor
*/
@property (class, nonatomic, readonly) CMVideoDimensions maximumDimensions;

/*!
	@property minimumDimensions
	@abstract returns the minimum dimensions for a sourceFrame for the processor
*/
@property (class, nonatomic, readonly) CMVideoDimensions minimumDimensions;

/*!
	@property supported
	@abstract reports whether this processor is supported on the current config.
*/
@property (class, nonatomic, readonly, getter=isSupported) BOOL supported;

/**
 * Returns the supported scale factors for the provided input dimensions.
 *
 * @abstract returns an array of supported scale factors values, or an empty list if the dimensions are unsupported.
*/
+ (NSArray<NSNumber*>*) supportedScaleFactorsForFrameWidth:(NSInteger)frameWidth
											   frameHeight:(NSInteger)frameHeight NS_REFINED_FOR_SWIFT;

@end


/*!
 @class VTLowLatencySuperResolutionScalerParameters
 @abstract VTLowLatencySuperResolutionScalerParameters object contains both input and output parameters needed for the Low Latency Super Resolution Scaler Frame Processor. This object is used in the processWithParameters call of VTFrameProcessor class.

 @discussion VTLowLatencySuperResolutionScalerParameters are frame level parameters.
*/

API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos)

@interface VTLowLatencySuperResolutionScalerParameters : NSObject <VTFrameProcessorParameters>

/*!
 @abstract Creates a new VTLowLatencySuperResolutionScalerParameters object.

 @param sourceFrame Current source frame. Must be non nil.

 @param destinationFrame User allocated pixel buffer that will receive the results.  Must be non nil.
*/
- (instancetype) initWithSourceFrame:(VTFrameProcessorFrame *)sourceFrame
					destinationFrame:(VTFrameProcessorFrame *)destinationFrame;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * @property sourceFrame
 * @abstract sourceFrame Current source frame. Must be non nil
*/
@property(nonatomic, readonly) VTFrameProcessorFrame * sourceFrame;

/**
 * @property destinationFrame
 * @abstract VTFrameProcessorFrame that contains user allocated pixel buffer that will receive the results.
*/

@property(nonatomic, readonly) VTFrameProcessorFrame * destinationFrame;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // __OBJC__
#endif // ! TARGET_OS_SIMULATOR

#endif // VTFRAMEPROCESSOR_LOWLATENCYSUPERRESOLUTIONSCALER_H
