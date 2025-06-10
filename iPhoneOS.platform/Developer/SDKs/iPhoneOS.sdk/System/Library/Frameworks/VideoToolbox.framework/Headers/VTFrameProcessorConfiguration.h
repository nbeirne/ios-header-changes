/*
	File:  VTFrameProcessorConfiguration.h
 
	Framework:  VideoToolbox
 
	Copyright © 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSORCONFIGURATION_H
#define VTFRAMEPROCESSORCONFIGURATION_H

#ifdef __OBJC__

#import <CoreMedia/CMBase.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMFormatDescription.h>

NS_HEADER_AUDIT_BEGIN(nullability)

/*!
	@protocol VTFrameProcessorConfiguration
	@abstract The VTFrameProcessorConfiguration protocol describes the configuration of a processor to be used during a video processing session.
 
	@discussion VTFrameProcessorConfiguration protocol conformance is used to start an frame processing session.  These properties can be  queried on an implementation conforming to VTFrameProcessorConfiguration without starting a session.
*/

API_AVAILABLE(macos(15.4), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos)
NS_SWIFT_SENDABLE
@protocol VTFrameProcessorConfiguration <NSObject>

@required

/*!
	@property supported
	@abstract Returns a Boolean indicating whether the processor supported on the current config.
*/
@property (class, nonatomic, readonly, getter=isSupported) BOOL supported;

/*!
	@property frameSupportedPixelFormats
	@abstract Returns a list of supported pixel formats for the current configuration
*/

@property (nonatomic, readonly) NSArray<NSNumber *> * frameSupportedPixelFormats NS_REFINED_FOR_SWIFT;

/*!
	@property sourcePixelBufferAttributes
	@abstract Returns a dictionary of CVPixelBuffer attributes which source and reference frames passed to the processor must conform to.
*/

@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE sourcePixelBufferAttributes;

/*!
	@property destinationPixelBufferAttributes
	@abstract Returns a dictionary of CVPixelBuffer attributes which output frames passed to the processor must conform to.
*/

@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE destinationPixelBufferAttributes;

@optional // WARNING: Optional properties must be refined for swift

/*!
	@property nextFrameCount
	@abstract returns the number of "next" frames that this processor requires for processing.
*/
@property (nonatomic, readonly) NSInteger nextFrameCount NS_REFINED_FOR_SWIFT;

/*!
	@property previousFrameCount
	@abstract returns the number of "previous" frames that this processor requires for processing.
*/
@property (nonatomic, readonly) NSInteger previousFrameCount NS_REFINED_FOR_SWIFT;

/*!
	@property maximumDimensions
	@abstract returns the maximum dimensions for a sourceFrame for the processor
*/
@property (class, nonatomic, readonly) CMVideoDimensions maximumDimensions NS_REFINED_FOR_SWIFT;

/*!
	@property minimumDimensions
	@abstract returns the minimum dimensions for a sourceFrame for the processor
*/
@property (class, nonatomic, readonly) CMVideoDimensions minimumDimensions NS_REFINED_FOR_SWIFT;

@end

NS_HEADER_AUDIT_END(nullability)

#endif // __OBJC__

#endif // VTFRAMEPROCESSORCONFIGURATION_H
