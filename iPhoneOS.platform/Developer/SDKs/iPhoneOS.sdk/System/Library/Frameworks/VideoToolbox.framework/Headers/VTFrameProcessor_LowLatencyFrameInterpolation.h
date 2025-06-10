/*
	File:  VTFrameProcessor_LowLatencyFrameInterpolation.h
 
	Framework:  VideoToolbox
 
	Copyright © 2024-2025 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSOR_LOWLATENCYFRAMEINTERPOLATION_H
#define VTFRAMEPROCESSOR_LOWLATENCYFRAMEINTERPOLATION_H

#include <CoreMedia/CMBase.h>

#if ! TARGET_OS_SIMULATOR
#ifdef __OBJC__

#import <VideoToolbox/VTFrameProcessorConfiguration.h>
#import <VideoToolbox/VTFrameProcessorParameters.h>
#import <VideoToolbox/VTFrameProcessorFrame.h>


NS_HEADER_AUDIT_BEGIN(nullability, sendability)


/*!
 @class VTLowLatencyFrameInterpolationConfiguration
 @abstract Configuration that is used to program VTFrameProcessor for Low Latency Frame Interpolation.  This can either do purely temporal interpolation (Frame Rate Conversion) or it can do temporal and spatial interpolation (Scaling and Frame Rate Conversion).

 @discussion This processor requires a source frame and a previous frame.  It does temporal scaling, interpolating frames between the previous frame and the source frame.  When performing both temporal and spatial interpolation, the processor can only perform 2x upscaling, and a single frame of temporal interpolation.  When performing spatial scaling, the processor will produce upscaled intermediate frames as well as an upscaled sourceFrame but will not upscale the previous reference frame provided.
*/

API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos)
NS_SWIFT_SENDABLE
@interface VTLowLatencyFrameInterpolationConfiguration : NSObject <VTFrameProcessorConfiguration>

#pragma mark --- init function(s).
/*!
 @abstract Creates a new VTLowLatencyFrameInterpolationConfiguration with specified frame width and height, configured for temporal interpolation (Frame Rate Conversion).

 @param frameWidth    Width of source frame in pixels.
 
 @param frameHeight   Height of source frame in pixels.

 @param numberOfInterpolatedFrames   The number of uniformly spaced frames that you want to have available for interpolation.
 
 @discussion The available interpolation points will be be the next value of  (2^x -1) which is greater than or equal to numberOfInterpolatedFrames.  For example, if 1 interpolated frame is requested, 1 interpolation point at 0.5 is available.  If 2 interpolated frames are requested, 3 interpolation points at 0.25, 0.5 and 0.75 are available.  Not all available interpolation points need to be used.  Setting a higher numberOfInterpolatedFrames increases the resolution of interpolation in some cases, but will also increase latency.
*/
- (nullable instancetype)initWithFrameWidth:(NSInteger)frameWidth
								frameHeight:(NSInteger)frameHeight
				 numberOfInterpolatedFrames:(NSInteger)numberOfInterpolatedFrames;


/*!
 @abstract Creates a new VTLowLatencyFrameInterpolationConfiguration with specified frame width and height, configured for spatial scaling as well as temporal scaling.

 @param frameWidth    Width of source frame in pixels.
 
 @param frameHeight   Height of source frame in pixels.

 @param spatialScaleFactor   The requested spatial scale factor as an integer.  Currently, only 2x spatial scaling is supported.
 
 @discussion When configured for spatial scaling, the VTLowLatencyFrameInterpolation processor only supports 2x spatial upscaling and a single frame of temporal interpolation at a 0.5 interpolation phase.  Setting the numberOfInterpolatedFrames property will be ignored in this case.
*/
- (nullable instancetype)initWithFrameWidth:(NSInteger)frameWidth
								frameHeight:(NSInteger)frameHeight
						 spatialScaleFactor:(NSInteger)spatialScaleFactor;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * @property frameWidth
 * @abstract Returns the width of source frames in pixels.
*/
@property (nonatomic, readonly) NSInteger frameWidth;

/**
 * @property frameHeight
 * @abstract Returns the height of source frames in pixels.
*/
@property (nonatomic, readonly) NSInteger frameHeight;

/**
 * @property spatialScaleFactor
 * @abstract Returns the configured spatial scale factor as an integer.
*/
@property (nonatomic, readonly) NSInteger spatialScaleFactor;

/**
 * @property numberOfInterpolatedFrames
 * @abstract Returns the number of uniformly spaced frames that the processor is configured for..
*/
@property (nonatomic, readonly) NSInteger numberOfInterpolatedFrames;

/**
 * @property frameSupportedPixelFormats
 * @abstract Returns a list of supported pixel formats for current configuration
 */

@property (nonatomic, readonly) NSArray<NSNumber *> * frameSupportedPixelFormats NS_REFINED_FOR_SWIFT;

/**
 * @property sourcePixelBufferAttributes
 * @abstract Returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as source and reference frames
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE sourcePixelBufferAttributes;

/**
 * @property destinationPixelBufferAttributes
 * @abstract Returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as destination frames
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE destinationPixelBufferAttributes;

/*!
	@property supported
	@abstract reports whether this processor is supported
*/
@property (class, nonatomic, readonly, getter=isSupported) BOOL supported;

@end


/*!
 @class VTLowLatencyFrameInterpolationParameters
 @abstract VTLowLatencyFrameInterpolationParameters object contains both input and output parameters needed for the Temporal Noise Filter Frame Processor. This object is used in the processWithParameters call of VTFrameProcessor class.
 
 @discussion VTLowLatencyFrameInterpolationParameters are frame level parameters.
*/

API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos)
@interface VTLowLatencyFrameInterpolationParameters : NSObject <VTFrameProcessorParameters>

/*!
 @abstract Creates a new VTLowLatencyFrameInterpolationParameters used to generate interpolated frames between a previous frame and a sourceFrame.

 @param sourceFrame Current source frame. Must be non nil.
  
 @param previousFrame  Previous frame used for interpolation.  Must be non nil.

 @param interpolationPhase The list of interpolation phase locations for the frames to be interpolated.  Must be greater than 0 and less than 1.0  0.5 is midway between the previous frame and the source frame.  If spatial scaling has been enabled, the only supported interpolation phase is 0.5.
 
 @param destinationFrames The list of VTFrameProcessorFrame to receive the interpolated frames.  This must have the same number of elements as the the interpolationPhase.  If spatial scaling is enabled, it must also contain an element to hold the scaled version of sourceFrame.
 
*/
- (nullable instancetype) initWithSourceFrame:(VTFrameProcessorFrame *)sourceFrame
					   previousFrame:(VTFrameProcessorFrame *)previousFrame
				  interpolationPhase:(NSArray<NSNumber *> *) interpolationPhase
				   destinationFrames:(NSArray<VTFrameProcessorFrame *> *)destinationFrames NS_REFINED_FOR_SWIFT;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * @property sourceFrame
 * @abstract Returns the source frame that was provided when the VTLowLatencyFrameInterpolationParameters object was created.
*/
@property(nonatomic, readonly) VTFrameProcessorFrame * sourceFrame;

/**
 * @property previousFrame
 * @abstract Returns the previous frame that was provided when the VTLowLatencyFrameInterpolationParameters object was created.
*/
@property(nonatomic, readonly) VTFrameProcessorFrame * previousFrame;

/**
 * @property interpolationPhase
 * @abstract Returns the array of interpolation [phases that were provided when the VTLowLatencyFrameInterpolationParameters object was created.
*/
@property (nonatomic, readonly) NSArray<NSNumber *> * interpolationPhase NS_REFINED_FOR_SWIFT;

/**
 * @property destinationFrames
 * @abstract Returns the array of destination frames that were provided when the VTLowLatencyFrameInterpolationParameters object was created.
*/
@property(nonatomic, readonly) NSArray<VTFrameProcessorFrame *> * destinationFrames;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // __OBJC__
#endif // ! TARGET_OS_SIMULATOR

#endif // VTFRAMEPROCESSOR_LOWLATENCYFRAMEINTERPOLATION_H
