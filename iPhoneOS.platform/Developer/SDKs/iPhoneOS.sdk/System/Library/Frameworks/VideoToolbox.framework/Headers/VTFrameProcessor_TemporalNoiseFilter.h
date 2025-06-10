/*
	File:  VTFrameProcessor_TemporalNoiseFilter.h
 
	Framework:  VideoToolbox
 
	Copyright © 2024-2025 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSOR_TEMPORALNOISEFILTER_H
#define VTFRAMEPROCESSOR_TEMPORALNOISEFILTER_H

#include <CoreMedia/CMBase.h>

#if ! TARGET_OS_SIMULATOR
#ifdef __OBJC__

#import <VideoToolbox/VTFrameProcessorConfiguration.h>
#import <VideoToolbox/VTFrameProcessorParameters.h>
#import <VideoToolbox/VTFrameProcessorFrame.h>


NS_HEADER_AUDIT_BEGIN(nullability, sendability)
/*!
	@class VTTemporalNoiseFilterConfiguration
	@abstract A configuration object to initiate VTFrameProcessor and use Temporal Noise Filter processor.

	@discussion
		The class properties of VTTemporalNoiseFilterConfiguration help to identify the capabilities of Temporal Noise Filter Processor on the current platform, prior to initiating a session.
		The availability of Temporal Noise Filter processor in the current platform can be confirmed by checking the VTTemporalNoiseFilterConfiguration.isSupported class property.
		Verify the processor's capability to process source frames by ensuring that the dimensions are no less than VTTemporalNoiseFilterConfiguration.minimumDimensions and no greater than VTTemporalNoiseFilterConfiguration.maximumDimensions.
		Use the instance properties such as frameSupportedPixelFormats, sourcePixelBufferAttributes, and destinationPixelBufferAttributes to ensure that the input and output pixel buffer formats and attributes of the processor align with the client's specific requirements.
		The properties previousFrameCount and nextFrameCount represent the maximum number of preceding and subsequent reference frames, used in the processing of a source frame, to achieve optimum noise reduction quality.
 */

API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(visionos) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_SENDABLE
VT_EXPORT @interface VTTemporalNoiseFilterConfiguration : NSObject <VTFrameProcessorConfiguration>

#pragma mark --- init function(s).
/*!
	@abstract Creates a new VTTemporalNoiseConfiguration with specified width and height.

	@param frameWidth    Width of source frame in pixels.
 
	@param frameHeight   Height of source frame in pixels.
 */
- (instancetype)initWithFrameWidth:(NSInteger)frameWidth
					   frameHeight:(NSInteger)frameHeight;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/*!
	@property frameWidth
	@abstract Width of source frame in pixels.
 */
@property (nonatomic, readonly) NSInteger frameWidth;

/*!
	@property frameHeight
	@abstract Height of source frame in pixels.
 */
@property (nonatomic, readonly) NSInteger frameHeight;

/*!
	@property frameSupportedPixelFormats
	@abstract List of supported pixel formats for source frames.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> * frameSupportedPixelFormats NS_REFINED_FOR_SWIFT;

/*!
	@property sourcePixelBufferAttributes
	@abstract Supported pixel buffer attributes for source frames.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE sourcePixelBufferAttributes;

/*!
	@property destinationPixelBufferAttributes
	@abstract Supported pixel buffer attributes for destination frames.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE destinationPixelBufferAttributes;

/*!
	@property nextFrameCount
	@abstract Maximum number of future reference frames used to process a source frame.
 */
@property (nonatomic, readonly) NSInteger nextFrameCount;

/*!
	@property previousFrameCount
	@abstract Maximum number of past reference frames used to process a source frame.
 */
@property (nonatomic, readonly) NSInteger previousFrameCount;

/*!
	@property maximumDimensions
	@abstract The maximum dimensions of a source frame, supported by the processor.
 */
@property (class, nonatomic, readonly) CMVideoDimensions maximumDimensions;

/*!
	@property minimumDimensions
	@abstract The minimum dimensions of a source frame, supported by the processor.
 */
@property (class, nonatomic, readonly) CMVideoDimensions minimumDimensions;

/*!
	@property supported
	@abstract reports whether this processor is supported
*/
@property (class, nonatomic, readonly, getter=isSupported) BOOL supported;

@end


/*!
	@class VTTemporalNoiseFilterParameters
	@abstract VTTemporalNoiseFilterParameters object encapsulates the frame-level parameters necessary for processing a source frame using Temporal Noise Filter processor.

	@discussion
		This object is intended for sending input parameters into the processWithParameters method of the VTFrameProcessor class.
		Temporal Noise Filter processor utilizes past and future reference frames, provided in presentation time order, to reduce noise from the source frame. The previousFrameCount and nextFrameCount properties in VTTemporalNoiseFilterConfiguration represent the maximum number of past and future reference frames that can be used by the processor to achieve optimum noise reduction quality. The number of reference frames provided shall depend on their availability, but at a minimum, one reference frame, either past or future, must be provided.
		The parameter destinationFrame stores the output frame that is returned to the caller upon the successful completion of the processWithParameters operation.
 */
API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(visionos) API_UNAVAILABLE(tvos, watchos)
VT_EXPORT @interface VTTemporalNoiseFilterParameters : NSObject <VTFrameProcessorParameters>

/*!
	@abstract Creates a new VTTemporalNoiseFilterParameters object.

	@param sourceFrame Current source frame. Must be non nil.

	@param nextFrames Future reference frames in presentation time order to be used for processing the source frame. The number of frames can vary from 0 to the number specified by the nextFrameCount property in VTTemporalNoiseFilterConfiguration.

	@param previousFrames Past reference frames in presentation time order to be used for processing the source frame. The number of frames can vary from 0 to the number specified by the previousFrameCount property in VTTemporalNoiseFilterConfiguration.

	@param destinationFrame User allocated pixel buffer that will receive the output frame. The pixel format of the destinationFrame must match with that of the sourceFrame.

	@param filterStrength Used to control strength of the noise filtering. The value can range from the minimum strength of 0.0 to the maximum strength of 1.0. Change in filter strength causes the processor to flush all frames in the queue prior to processing the source frame.

	@param discontinuity Marks sequence discontinuity, forcing the processor to reset prior to processing the source frame.
 */
- (instancetype) initWithSourceFrame:(VTFrameProcessorFrame *)sourceFrame
						  nextFrames:(NSArray<VTFrameProcessorFrame *> * _Nullable)nextFrames
					  previousFrames:(NSArray<VTFrameProcessorFrame *> * _Nullable)previousFrames
					destinationFrame:(VTFrameProcessorFrame *)destinationFrame
					  filterStrength:(float)filterStrength
					   discontinuity:(Boolean)discontinuity;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/*!
	@property sourceFrame
	@abstract Current source frame. Must be non-nil.
 */
@property(nonatomic, readonly) VTFrameProcessorFrame * sourceFrame;

/*!
	@property nextFrames
	@abstract Future reference frames in presentation time order to be used for processing the source frame. The number of frames can vary from 0 to the number specified by the nextFrameCount property in VTTemporalNoiseFilterConfiguration.
 */
@property(nonatomic, readonly, nullable) NSArray<VTFrameProcessorFrame *> * nextFrames;

/*!
	@property previousFrames
	@abstract Past reference frames in presentation time order to be used for processing the source frame. The number of frames can vary from 0 to the number specified by the previousFrameCount property in VTTemporalNoiseFilterConfiguration.
 */
@property(nonatomic, readonly, nullable) NSArray<VTFrameProcessorFrame *> * previousFrames;

/*!
	@property filterStrength
	@abstract Parameter used to control strength of the noise filtering. The value can range from the minimum strength of 0.0 to the maximum strength of 1.0. Change in filter strength causes the processor to flush all frames in the queue prior to processing the source frame.
 */
@property (nonatomic) float filterStrength;

/*!
	@property discontinuity
	@abstract Marks sequence discontinuity, forcing the processor to reset prior to processing the source frame.
 */
@property (nonatomic) Boolean discontinuity;

/*!
	@property destinationFrame
	@abstract VTFrameProcessorFrame that contains user allocated pixel buffer that will receive the output frame.
 */
@property(nonatomic, readonly) VTFrameProcessorFrame * destinationFrame;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // __OBJC__
#endif // ! TARGET_OS_SIMULATOR

#endif // VTFRAMEPROCESSOR_TEMPORALNOISEFILTER_H
