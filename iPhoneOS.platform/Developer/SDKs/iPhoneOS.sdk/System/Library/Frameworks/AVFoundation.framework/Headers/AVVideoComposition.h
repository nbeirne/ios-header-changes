#if !__has_include(<AVFCore/AVVideoComposition.h>)
/*
    File:  AVVideoComposition.h

	Framework:  AVFoundation
 
	Copyright 2010-2023 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <AVFoundation/AVAsset.h>
#import <AVFoundation/AVVideoCompositing.h>

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>

NS_ASSUME_NONNULL_BEGIN

@class AVVideoCompositionCoreAnimationTool;
@class AVVideoCompositionInternal;
@class AVVideoCompositionLayerInstruction;
@class AVVideoCompositionInstruction;
@class CIContext;
@class CIImage;

/// An AVVideoComposition object represents an immutable video composition.
/// 
/// A video composition describes, for any time in the aggregate time range of its instructions, the number and IDs of video tracks that are to be used in order to produce a composed video frame corresponding to that time. When AVFoundation's built-in video compositor is used, the instructions an AVVideoComposition contain can specify a spatial transformation, an opacity value, and a cropping rectangle for each video source, and these can vary over time via simple linear ramping functions.
/// 
/// A client can implement their own custom video compositor by implementing the AVVideoCompositing protocol; a custom video compositor is provided with pixel buffers for each of its video sources during playback and other operations and can perform arbitrary graphical operations on them in order to produce visual output.
/// 
/// Subclasses of this type that are used from Swift must fulfill the requirements of a Sendable type.
API_AVAILABLE(macos(10.7), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVVideoComposition : NSObject <NSCopying, NSMutableCopying> {
@private
    AVVideoCompositionInternal    *_videoComposition;
}

/// Configures policy for per frame HDR display metadata
/// 
/// Determines what HDR display metadata should be attached to the rendered frame.
typedef NSString *AVVideoCompositionPerFrameHDRDisplayMetadataPolicy NS_TYPED_ENUM														API_AVAILABLE(macos(14.0), ios(17.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos);
	/// Default. Pass the HDR metadata through, if present on the composed frame.
	AVF_EXPORT AVVideoCompositionPerFrameHDRDisplayMetadataPolicy const AVVideoCompositionPerFrameHDRDisplayMetadataPolicyPropagate		API_AVAILABLE(macos(14.0), ios(17.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos);
	/// AVVideoComposition may generate HDR metadata and attach it to the rendered frame. HDR metadata generation is influenced by the color space of the rendered frame, device, and HDR metadata format platform support. Any previously attached HDR metadata of the same metadata format will be overwritten.
	AVF_EXPORT AVVideoCompositionPerFrameHDRDisplayMetadataPolicy const AVVideoCompositionPerFrameHDRDisplayMetadataPolicyGenerate		API_AVAILABLE(macos(14.0), ios(17.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos);

/// Returns a new instance of AVVideoComposition with values and instructions suitable for presenting the video tracks of the specified asset according to its temporal and geometric properties and those of its tracks.
/// 
/// The returned AVVideoComposition will have instructions that respect the spatial properties and timeRanges of the specified asset's video tracks.
/// It will also have the following values for its properties:
/// 
/// - If the asset has exactly one video track, the original timing of the source video track will be used. If the asset has more than one video track, and the nominal frame rate of any of video tracks is known, the reciprocal of the greatest known nominalFrameRate will be used as the value of frameDuration. Otherwise, a default framerate of 30fps is used.
/// - If the specified asset is an instance of AVComposition, the renderSize will be set to the naturalSize of the AVComposition; otherwise the renderSize will be set to a value that encompasses all of the asset's video tracks.
/// - A renderScale of 1.0.
/// - A nil animationTool.
/// 
/// If the specified asset has no video tracks, this method will return an AVVideoComposition instance with an empty collection of instructions.
/// 
/// - Parameter asset: An instance of AVAsset. Ensure that the duration and tracks properties of the asset are already loaded before invoking this method.
/// 
/// - Returns: An instance of AVVideoComposition.
+ (AVVideoComposition *)videoCompositionWithPropertiesOfAsset:(AVAsset *)asset API_DEPRECATED("Use videoCompositionWithPropertiesOfAsset:completionHandler: instead", macos(10.9, 15.0), ios(6.0, 18.0), tvos(9.0, 18.0)) API_UNAVAILABLE(watchos, visionos);

/// Vends a new instance of AVVideoComposition with values and instructions suitable for presenting the video tracks of the specified asset according to its temporal and geometric properties and those of its tracks.
/// 
/// The new AVVideoComposition will have instructions that respect the spatial properties and timeRanges of the specified asset's video tracks.
/// It will also have the following values for its properties:
/// 
/// - If the asset has exactly one video track, the original timing of the source video track will be used. If the asset has more than one video track, and the nominal frame rate of any of video tracks is known, the reciprocal of the greatest known nominalFrameRate will be used as the value of frameDuration. Otherwise, a default framerate of 30fps is used.
/// - If the specified asset is an instance of AVComposition, the renderSize will be set to the naturalSize of the AVComposition; otherwise the renderSize will be set to a value that encompasses all of the asset's video tracks.
/// - A renderScale of 1.0.
/// - A nil animationTool.
/// 
/// If the specified asset has no video tracks, this method will return an AVVideoComposition instance with an empty collection of instructions.
/// 
/// - Parameter asset: An instance of AVAsset.
/// - Parameter completionHandler: A block that is invoked when the new video composition has finished being created. If the `videoComposition` parameter is nil, the `error` parameter describes the failure that occurred.
+ (void)videoCompositionWithPropertiesOfAsset:(AVAsset *)asset completionHandler:(void (^ NS_SWIFT_SENDABLE)(AVVideoComposition * _Nullable videoComposition, NSError * _Nullable error))completionHandler API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Pass-through initializer, for internal use in AVFoundation only
+ (AVVideoComposition *)videoCompositionWithVideoComposition:(AVVideoComposition *)videoComposition API_UNAVAILABLE(macos, ios, tvos, visionos, watchos);

/// Indicates a custom compositor class to use. The class must implement the AVVideoCompositing protocol. If nil, the default, internal video compositor is used
@property (nonatomic, readonly, nullable) Class<AVVideoCompositing> customVideoCompositorClass API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates the interval which the video composition, when enabled, should render composed video frames
@property (nonatomic, readonly) CMTime frameDuration;

/// If sourceTrackIDForFrameTiming is not kCMPersistentTrackID_Invalid, frame timing for the video composition is derived from the source asset's track with the corresponding ID. This may be used to preserve a source asset's variable frame timing. If an empty edit is encountered in the source asset’s track, the compositor composes frames as needed up to the frequency specified in frameDuration property. */
@property (nonatomic, readonly) CMPersistentTrackID sourceTrackIDForFrameTiming API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates the size at which the video composition, when enabled, should render
@property (nonatomic, readonly) CGSize renderSize;

/// Indicates the scale at which the video composition should render. May only be other than 1.0 for a video composition set on an AVPlayerItem
@property (nonatomic, readonly) float renderScale API_AVAILABLE(macos(10.14), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates instructions for video composition via an NSArray of instances of classes implementing the AVVideoCompositionInstruction protocol. For the first instruction in the array, timeRange.start must be less than or equal to the earliest time for which playback or other processing will be attempted (note that this will typically be kCMTimeZero). For subsequent instructions, timeRange.start must be equal to the prior instruction's end time. The end time of the last instruction must be greater than or equal to the latest time for which playback or other processing will be attempted (note that this will often be the duration of the asset with which the instance of AVVideoComposition is associated).
@property (nonatomic, readonly, copy) NSArray<id <AVVideoCompositionInstruction>> *instructions;

/// Indicates a special video composition tool for use of Core Animation; may be nil
@property (nonatomic, readonly, retain, nullable) AVVideoCompositionCoreAnimationTool *animationTool;

/// List of all track IDs for tracks from which sample data should be presented to the compositor at any point in the overall composition. The sample data will be delivered to the custom compositor via AVAsynchronousVideoCompositionRequest.
@property (nonatomic, readonly) NSArray<NSNumber *> *sourceSampleDataTrackIDs API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// The output buffers of the video composition can be specified with the outputBufferDescription. The value is an array of CMTagCollectionRef objects that describes the output buffers.
/// 
/// If the video composition will output tagged buffers, the details of those buffers should be specified with CMTags. Specifically, the StereoView (eyes) must be specified. The behavior is undefined if the output tagged buffers do not match the outputBufferDescription.
/// The default is nil, which means monoscopic output. Note that an empty array is not valid. An exception will be thrown if the objects in the array are not of type CMTagCollectionRef.
/// Note that tagged buffers are only supported for custom compositors.
@property (nonatomic, readonly, copy, nullable) NSArray *outputBufferDescription NS_REFINED_FOR_SWIFT API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

@end

/// Indicates the color space of the frames output from the video composition.
/// 
/// Collectively the properties colorPrimaries, colorYCbCrMatrix, and colorTransferFunction define the color space that the rendered frames will be tagged with. For custom video compositing these properties are also used to specify the required color space of the source frames.
/// 
/// For examples of common color spaces see AVVideoSettings.h.
/// 
/// How to preserve the color space of the source frames:
/// 
/// Decide which color space to be preserved by examining the source asset's video tracks. Copy the source track's primaries, matrix and transfer function into the video composition's colorPrimaries, colorYCbCrMatrix and colorTransferFunction respectively.
/// 
/// - When using custom video compositing
/// Setting these properties will cause source frames to be converted into the specified color space and tagged as such. New frames allocated using -[AVVideoCompositionRenderContext newPixelBuffer] will also be tagged correctly.
/// 
/// - When using Core Image via videoCompositionWithAsset:options:applyingCIFiltersWithHandler:
/// Setting these properties will cause source frames to be converted into the specified color space and tagged as such. The source frames provided as CIImages will have the appropriate CGColorSpace applied. The color space is preserved when the output CIImage is finally rendered internally.
/// 
/// - When using basic compositing (i.e. AVVideoCompositionLayerInstruction)
/// Setting these properties will ensure that the internal compositor renders (or passes through) frames in specified color space and are tagged as such.
API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVVideoComposition (AVVideoCompositionColorimetery)

/// Rendering will use these primaries and frames will be tagged as such. If the value of this property is nil then the source's primaries will be propagated and used.
/// 
/// Default is nil. Valid values are those suitable for AVVideoColorPrimariesKey. Generally set as a triple along with colorYCbCrMatrix and colorTransferFunction.
@property (nonatomic, readonly, nullable) NSString *colorPrimaries API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Rendering will use this matrix and frames will be tagged as such. If the value of this property is nil then the source's matrix will be propagated and used.
/// 
/// Default is nil. Valid values are those suitable for AVVideoYCbCrMatrixKey. Generally set as a triple along with colorPrimaries and colorTransferFunction.
@property (nonatomic, readonly, nullable) NSString *colorYCbCrMatrix API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Rendering will use this transfer function and frames will be tagged as such. If the value of this property is nil then the source's transfer function will be propagated and used.
/// 
/// Default is nil. Valid values are those suitable for AVVideoTransferFunctionKey. Generally set as a triple along with colorYCbCrMatrix and colorYCbCrMatrix.
@property (nonatomic, readonly, nullable) NSString *colorTransferFunction API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Configures policy for per frame HDR display metadata on the rendered frame
/// 
/// Allows the system to identify situations where HDR metadata can be generated and attached to the rendered video frame.
/// Default is AVVideoCompositionPerFrameHDRDisplayMetadataPolicyPropagate. Any HDR metadata attached to the composed frame will be propagated to the rendered video frames.
@property (nonatomic, readonly) AVVideoCompositionPerFrameHDRDisplayMetadataPolicy perFrameHDRDisplayMetadataPolicy API_AVAILABLE(macos(14.0), ios(17.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos);

@end

@interface AVVideoComposition (AVVideoCompositionFiltering)

/// Returns a new instance of AVVideoComposition with values and instructions that will apply the specified handler block to video frames represented as instances of CIImage.
/// 
/// The returned AVVideoComposition will cause the specified handler block to be called to filter each frame of the asset's first enabled video track. The handler block should use the properties of the provided AVAsynchronousCIImageFilteringRequest and respond using finishWithImage:context: with a "filtered" new CIImage (or the provided source image for no affect). In the event of an error, respond to the request using finishWithError:. The error can be observed via AVPlayerItemFailedToPlayToEndTimeNotification, see AVPlayerItemFailedToPlayToEndTimeErrorKey in notification payload.
/// 
/// NOTE: The returned AVVideoComposition's properties are private and support only CIFilter-based operations. Mutations are not supported, either in the values of properties of the AVVideoComposition itself or in its private instructions. If rotations or other transformations are desired, they must be accomplished via the application of CIFilters during the execution of your specified handler.
/// 
/// The video composition will also have the following values for its properties:
/// 
/// - The original timing of the asset's first enabled video track will be used.
/// - A renderSize that encompasses the asset's first enabled video track respecting the track's preferredTransform.
/// - A renderScale of 1.0.
/// 
/// The default CIContext has the following properties:
/// 
/// - iOS: Device RGB color space
/// - macOS: sRGB color space
/// 
/// Example usage:
/// ```objc
/// playerItem.videoComposition = [AVVideoComposition videoCompositionWithAsset:srcAsset applyingCIFiltersWithHandler:
/// 	^(AVAsynchronousCIImageFilteringRequest *request)
/// 	{
/// 		NSError *err = nil;
/// 		CIImage *filtered = myRenderer(request, &err);
/// 		if (filtered)
/// 			[request finishWithImage:filtered context:nil];
/// 		else
/// 			[request finishWithError:err];
/// 	}];
/// ```
/// 
/// - Parameter asset: An instance of AVAsset. For best performance, ensure that the duration and tracks properties of the asset are already loaded before invoking this method.
/// 
/// - Returns: An instance of AVVideoComposition.
+ (AVVideoComposition *)videoCompositionWithAsset:(AVAsset *)asset applyingCIFiltersWithHandler:(void (^ NS_SWIFT_SENDABLE)(AVAsynchronousCIImageFilteringRequest *request))applier API_DEPRECATED("Use videoCompositionWithAsset:applyingCIFiltersWithHandler:completionHandler: instead", macos(10.11, 15.0), ios(9.0, 18.0), tvos(9.0, 18.0)) API_UNAVAILABLE(watchos, visionos);

/// Vends a new instance of AVVideoComposition with values and instructions that will apply the specified handler block to video frames represented as instances of CIImage.
/// 
/// The new AVVideoComposition will cause the specified handler block to be called to filter each frame of the asset's first enabled video track. The handler block should use the properties of the provided AVAsynchronousCIImageFilteringRequest and respond using finishWithImage:context: with a "filtered" new CIImage (or the provided source image for no affect). In the event of an error, respond to the request using finishWithError:. The error can be observed via AVPlayerItemFailedToPlayToEndTimeNotification, see AVPlayerItemFailedToPlayToEndTimeErrorKey in notification payload.
/// 
/// NOTE: The returned AVVideoComposition's properties are private and support only CIFilter-based operations. Mutations are not supported, either in the values of properties of the AVVideoComposition itself or in its private instructions. If rotations or other transformations are desired, they must be accomplished via the application of CIFilters during the execution of your specified handler.
/// 
/// The video composition will also have the following values for its properties:
/// 
/// - The original timing of the asset's first enabled video track will be used.
/// - A renderSize that encompasses the asset's first enabled video track respecting the track's preferredTransform.
/// - A renderScale of 1.0.
/// 
/// The default CIContext has the following properties:
/// 
/// - iOS: Device RGB color space
/// - macOS: sRGB color space
/// 
/// Example usage:
/// ```objc
/// [AVVideoComposition videoCompositionWithAsset:srcAsset applyingCIFiltersWithHandler:
/// 	^(AVAsynchronousCIImageFilteringRequest *request)
/// 	{
/// 		NSError *err = nil;
/// 		CIImage *filtered = myRenderer(request, &err);
/// 		if (filtered)
/// 			[request finishWithImage:filtered context:nil];
/// 		else
/// 			[request finishWithError:err];
/// 	} completionHandler:
/// 	^(AVVideoComposition * _Nullable videoComposition, NSError * _Nullable error)
/// 	{
/// 		if (videoComposition != nil) {
/// 			playerItem.videoComposition = videoComposition
/// 		else {
/// 			// handle error
/// 	}];
/// ```
/// - Parameter asset: An instance of AVAsset.
/// - Parameter completionHandler: A block that is invoked when the new video composition has finished being created. If the `videoComposition` parameter is nil, the `error` parameter describes the failure that occurred.
+ (void)videoCompositionWithAsset:(AVAsset *)asset applyingCIFiltersWithHandler:(void (^ NS_SWIFT_SENDABLE)(AVAsynchronousCIImageFilteringRequest *request))applier completionHandler:(void (^ NS_SWIFT_SENDABLE)(AVVideoComposition * _Nullable videoComposition, NSError * _Nullable error))completionHandler
#if __swift__
API_DEPRECATED("Use init(with:applyingCIFiltersWithHandler:)", macos(13.0, API_TO_BE_DEPRECATED), ios(16.0, API_TO_BE_DEPRECATED), tvos(16.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
;

@end


@class AVMutableVideoCompositionInternal;

/// The AVMutableVideoComposition class is a mutable subclass of AVVideoComposition.
#if __swift__
API_DEPRECATED("Use AVVideoComposition.Configuration instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.7), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
@interface AVMutableVideoComposition : AVVideoComposition {
@private
    AVMutableVideoCompositionInternal    *_mutableVideoComposition __attribute__((unused));
}

/// Returns a new instance of AVMutableVideoComposition.
/// 
/// The returned AVMutableVideoComposition will have a frameDuration of kCMTimeZero, a renderSize of {0.0, 0.0}, a nil array of instructions, and a nil animationTool.
+ (AVMutableVideoComposition *)videoComposition;

/// Returns a new instance of AVMutableVideoComposition with values and instructions suitable for presenting the video tracks of the specified asset according to its temporal and geometric properties and those of its tracks.
/// 
/// The returned AVMutableVideoComposition will have instructions that respect the spatial properties and timeRanges of the specified asset's video tracks. The client can set sourceTrackIDForFrameTiming to kCMPersistentTrackID_Invalid and frameDuration to an appropriate value in order to specify the maximum output frame rate independent of the source track timing.
/// It will also have the following values for its properties:
/// 
/// - If the asset has exactly one video track, the original timing of the source video track will be used. If the asset has more than one video track, and the nominal frame rate of any of video tracks is known, the reciprocal of the greatest known nominalFrameRate will be used as the value of frameDuration. Otherwise, a default framerate of 30fps is used.
/// - If the specified asset is an instance of AVComposition, the renderSize will be set to the naturalSize of the AVComposition; otherwise the renderSize will be set to a value that encompasses all of the asset's video tracks.
/// - A renderScale of 1.0.
/// - A nil animationTool.
/// 
/// If the specified asset has no video tracks, this method will return an AVMutableVideoComposition instance with an empty collection of instructions.
/// 
/// - Parameter asset: An instance of AVAsset. For best performance, ensure that the duration and tracks properties of the asset are already loaded before invoking this method.
/// 
/// - Returns: An instance of AVMutableVideoComposition.
+ (AVMutableVideoComposition *)videoCompositionWithPropertiesOfAsset:(AVAsset *)asset API_DEPRECATED("Use videoCompositionWithPropertiesOfAsset:completionHandler: instead", macos(10.9, 15.0), ios(6.0, 18.0), tvos(9.0, 18.0)) API_UNAVAILABLE(watchos, visionos);

/// Vends a new instance of AVMutableVideoComposition with values and instructions suitable for presenting the video tracks of the specified asset according to its temporal and geometric properties and those of its tracks.
/// 
/// The new AVMutableVideoComposition will have instructions that respect the spatial properties and timeRanges of the specified asset's video tracks. The client can set sourceTrackIDForFrameTiming to kCMPersistentTrackID_Invalid and frameDuration to an appropriate value in order to specify the maximum output frame rate independent of the source track timing.
/// It will also have the following values for its properties:
/// 
/// - If the asset has exactly one video track, the original timing of the source video track will be used. If the asset has more than one video track, and the nominal frame rate of any of video tracks is known, the reciprocal of the greatest known nominalFrameRate will be used as the value of frameDuration. Otherwise, a default framerate of 30fps is used.
/// - If the specified asset is an instance of AVComposition, the renderSize will be set to the naturalSize of the AVComposition; otherwise the renderSize will be set to a value that encompasses all of the asset's video tracks.
/// - A renderScale of 1.0.
/// - A nil animationTool.
/// 
/// If the specified asset has no video tracks, this method will return an AVMutableVideoComposition instance with an empty collection of instructions.
/// 
/// - Parameter asset: An instance of AVAsset.
/// - Parameter completionHandler: A block that is invoked when the new video composition has finished being created. If the `videoComposition` parameter is nil, the `error` parameter describes the failure that occurred.
+ (void)videoCompositionWithPropertiesOfAsset:(AVAsset *)asset completionHandler:(void (^ NS_SWIFT_SENDABLE)(AVMutableVideoComposition * _Nullable videoComposition, NSError * _Nullable error))completionHandler API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Returns a new instance of AVMutableVideoComposition with values and instructions suitable for presenting the video tracks of the specified asset according to its temporal and geometric properties and those of its tracks, and also overrides default properties with those from a prototypeInstruction.
/// 
/// Also see videoCompositionWithPropertiesOfAsset:.
/// The returned AVVideoComposition will have instructions that respect the spatial properties and timeRanges of the specified asset's video tracks. Anything not pertaining to spatial layout and timing, such as background color for their composition or post-processing behaviors, is eligible to be specified via a prototype instruction.
/// Example: To add a background color,
/// ```objc
/// myPrototypeInstruction = [[AVMutableVideoCompositionInstruction alloc] init];
/// myPrototypeInstruction.backgroundColor = myCGColorRef; // Do not use constant CGColorRef colors here.
/// myVideoComposition = [AVVideoComposition videoCompositionWithPropertiesOfAsset:myAsset prototypeInstruction:myPrototypeInstruction];
/// ```
/// - Parameter asset: An instance of AVAsset. For best performance, ensure that the duration and tracks properties of the asset are already loaded before invoking this method.
/// - Parameter prototypeInstruction: Custom instructions that the client can choose to override.
/// 
/// - Returns: An instance of AVMutableVideoComposition.
+ (AVMutableVideoComposition *)videoCompositionWithPropertiesOfAsset:(AVAsset *)asset prototypeInstruction:(AVVideoCompositionInstruction *)prototypeInstruction API_DEPRECATED("Use videoCompositionWithPropertiesOfAsset:prototypeInstruction:completionHandler: instead", macos(10.15, 15.0), ios(13.0, 18.0), tvos(13.0, 18.0)) API_UNAVAILABLE(watchos, visionos);

/// Vends a new instance of AVMutableVideoComposition with values and instructions suitable for presenting the video tracks of the specified asset according to its temporal and geometric properties and those of its tracks, and also overrides default properties with those from a prototypeInstruction.
/// 
/// Also see videoCompositionWithPropertiesOfAsset:completionHandler:.
/// The new AVMutableVideoComposition will have instructions that respect the spatial properties and timeRanges of the specified asset's video tracks. Anything not pertaining to spatial layout and timing, such as background color for their composition or post-processing behaviors, is eligible to be specified via a prototype instruction.
/// Example: To add a background color,
/// ```objc
/// myPrototypeInstruction = [[AVMutableVideoCompositionInstruction alloc] init];
/// myPrototypeInstruction.backgroundColor = myCGColorRef; // Do not use constant CGColorRef colors here.
/// myVideoComposition = [AVVideoComposition videoCompositionWithPropertiesOfAsset:myAsset prototypeInstruction:myPrototypeInstruction completionHandler:^(AVMutableVideoComposition * _Nullable myVideoComposition, NSError * _Nullable error) {
/// 	if (myVideoComposition != nil) {
/// 		// use myVideoComposition
/// 	}
/// 	else {
/// 		// handle error
/// 	}
/// }];
/// ```
/// - Parameter asset: An instance of AVAsset.
/// - Parameter prototypeInstruction: Custom instructions that the client can choose to override.
/// - Parameter completionHandler: A block that is invoked when the new video composition has finished being created. If the `videoComposition` parameter is nil, the `error` parameter describes the failure that occurred.
+ (void)videoCompositionWithPropertiesOfAsset:(AVAsset *)asset prototypeInstruction:(AVVideoCompositionInstruction *)prototypeInstruction completionHandler:(void (^ NS_SWIFT_SENDABLE)(AVMutableVideoComposition * _Nullable videoComposition, NSError * _Nullable error))completionHandler API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates the custom compositor class to use. If nil, the default, internal video compositor is used
@property (nonatomic, retain, nullable) Class<AVVideoCompositing> customVideoCompositorClass API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates the interval which the video composition, when enabled, should render composed video frames
@property (nonatomic) CMTime frameDuration;

/// If sourceTrackIDForFrameTiming is not kCMPersistentTrackID_Invalid, frame timing for the video composition is derived from the source asset's track with the corresponding ID. This may be used to preserve a source asset's variable frame timing. If an empty edit is encountered in the source asset’s track, the compositor composes frames as needed up to the frequency specified in frameDuration property.
@property (nonatomic) CMPersistentTrackID sourceTrackIDForFrameTiming API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates the size at which the video composition, when enabled, should render
@property (nonatomic) CGSize renderSize;

/// Indicates the scale at which the video composition should render. May only be other than 1.0 for a video composition set on an AVPlayerItem
@property (nonatomic) float renderScale API_AVAILABLE(macos(10.14), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates instructions for video composition via an NSArray of instances of classes implementing the AVVideoCompositionInstruction protocol.
///
/// For the first instruction in the array, timeRange.start must be less than or equal to the earliest time for which playback or other processing will be attempted (note that this will typically be kCMTimeZero). For subsequent instructions, timeRange.start must be equal to the prior instruction's end time. The end time of the last instruction must be greater than or equal to the latest time for which playback or other processing will be attempted (note that this will often be the duration of the asset with which the instance of AVVideoComposition is associated).
@property (nonatomic, copy) NSArray<id <AVVideoCompositionInstruction>> *instructions;

/// Indicates a special video composition tool for use of Core Animation; may be nil
@property (nonatomic, retain, nullable) AVVideoCompositionCoreAnimationTool *animationTool;

/// List of all track IDs for tracks from which sample data should be presented to the compositor at any point in the overall composition.  Currently only tracks of type kCMMediaType_Metadata are allowed to be specified.
@property (nonatomic, copy) NSArray<NSNumber *> *sourceSampleDataTrackIDs API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// The output buffers of the video composition can be specified with the outputBufferDescription. The value is an array of CMTagCollectionRef objects that describes the output buffers.
/// 
/// If the video composition will output tagged buffers, the details of those buffers should be specified with CMTags. Specifically, the StereoView (eyes) must be specified. The behavior is undefined if the output tagged buffers do not match the outputBufferDescription.
/// The default is nil, which means monoscopic output. Note that an empty array is not valid. An exception will be thrown if the objects in the array are not of type CMTagCollectionRef.
/// Note that tagged buffers are only supported for custom compositors.
@property (nonatomic, copy, nullable) NSArray *outputBufferDescription NS_REFINED_FOR_SWIFT API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

@end

/// Indicates the color space of the frames output from the video composition.
/// 
/// Collectively the properties colorPrimaries, colorYCbCrMatrix, and colorTransferFunction define the color space that the rendered frames will be tagged with. For custom video compositing these properties are also used to specify the required color space of the source frames.
/// 
/// For examples of common color spaces see AVVideoSettings.h.
/// 
/// How to preserve the color space of the source frames:
/// 
/// Decide which color space to be preserved by examining the source asset's video tracks. Copy the source track's primaries, matrix and transfer function into the video composition's colorPrimaries, colorYCbCrMatrix and colorTransferFunction respectively.
/// 
/// - When using custom video compositing
/// Setting these properties will cause source frames to be converted into the specified color space and tagged as such. New frames allocated using -[AVVideoCompositionRenderContext newPixelBuffer] will also be tagged correctly.
/// 
/// - When using Core Image via videoCompositionWithAsset:options:applyingCIFiltersWithHandler:
/// Setting these properties will cause source frames to be converted into the specified color space and tagged as such. The source frames provided as CIImages will have the appropriate CGColorSpace applied. The color space is preserved when the output CIImage is finally rendered internally.
/// 
/// - When using basic compositing (i.e. AVVideoCompositionLayerInstruction)
/// Setting these properties will ensure that the internal compositor renders (or passes through) frames in specified color space and are tagged as such.
API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVMutableVideoComposition (AVMutableVideoCompositionColorimetery)

/// Rendering will use these primaries and frames will be tagged as such. If the value of this property is nil then the source's primaries will be propagated and used.
/// 
/// Default is nil. Valid values are those suitable for AVVideoColorPrimariesKey. Generally set as a triple along with colorYCbCrMatrix and colorTransferFunction.
@property (nonatomic, copy, nullable) NSString *colorPrimaries API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Rendering will use this matrix and frames will be tagged as such. If the value of this property is nil then the source's matrix will be propagated and used.
/// 
/// Default is nil. Valid values are those suitable for AVVideoYCbCrMatrixKey. Generally set as a triple along with colorPrimaries and colorTransferFunction.
@property (nonatomic, copy, nullable) NSString *colorYCbCrMatrix API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Rendering will use this transfer function and frames will be tagged as such. If the value of this property is nil then the source's transfer function will be propagated and used.
/// 
/// Default is nil. Valid values are those suitable for AVVideoTransferFunctionKey. Generally set as a triple along with colorYCbCrMatrix and colorYCbCrMatrix.
@property (nonatomic, copy, nullable) NSString *colorTransferFunction API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Configures policy for per frame HDR display metadata on the rendered frame
/// 
/// Allows the system to identify situations where HDR metadata can be generated and attached to the rendered video frame.
/// Default is AVVideoCompositionPerFrameHDRDisplayMetadataPolicyPropagate. Any HDR metadata attached to the composed frame will be propagated to the rendered video frames.
@property (nonatomic, copy) AVVideoCompositionPerFrameHDRDisplayMetadataPolicy perFrameHDRDisplayMetadataPolicy API_AVAILABLE(macos(14.0), ios(17.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos);

@end

API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVMutableVideoComposition (AVMutableVideoCompositionFiltering)

/// Returns a new instance of AVMutableVideoComposition with values and instructions that will apply the specified handler block to video frames represented as instances of CIImage.
/// 
/// The returned AVMutableVideoComposition will cause the specified handler block to be called to filter each frame of the asset's first enabled video track. The handler block should use the properties of the provided AVAsynchronousCIImageFilteringRequest and respond using finishWithImage:context: with a "filtered" new CIImage (or the provided source image for no affect). In the event of an error, respond to the request using finishWithError:. The error can be observed via AVPlayerItemFailedToPlayToEndTimeNotification, see AVPlayerItemFailedToPlayToEndTimeErrorKey in notification payload. The client can set sourceTrackIDForFrameTiming to kCMPersistentTrackID_Invalid and frameDuration to an appropriate value in order to specify the maximum output frame rate independent of the source track timing.
/// 
/// The video composition will also have the following values for its properties:
/// 
/// - The original timing of the asset's first enabled video track will be used.
/// - A renderSize that encompasses the asset's first enabled video track respecting the track's preferredTransform.
/// - A renderScale of 1.0.
/// 
/// The default CIContext has the following properties:
/// 
/// - iOS: Device RGB color space
/// - macOS: sRGB color space
/// 
/// Example usage:
/// ```objc
/// playerItem.videoComposition = [AVMutableVideoComposition videoCompositionWithAsset:srcAsset applyingCIFiltersWithHandler:
/// 	^(AVAsynchronousCIImageFilteringRequest *request)
/// 	{
/// 		NSError *err = nil;
/// 		CIImage *filtered = myRenderer(request, &err);
/// 		if (filtered)
/// 			[request finishWithImage:filtered context:nil];
/// 		else
/// 			[request finishWithError:err];
/// 	}];
/// ```
/// - Parameter asset: An instance of AVAsset. For best performance, ensure that the duration and tracks properties of the asset are already loaded before invoking this method.
/// 
/// - Returns: An instance of AVMutableVideoComposition.
+ (AVMutableVideoComposition *)videoCompositionWithAsset:(AVAsset *)asset applyingCIFiltersWithHandler:(void (^ NS_SWIFT_SENDABLE)(AVAsynchronousCIImageFilteringRequest *request))applier API_DEPRECATED("Use videoCompositionWithAsset:applyingCIFiltersWithHandler:completionHandler: instead", macos(10.11, 15.0), ios(9.0, 18.0), tvos(9.0, 18.0)) API_UNAVAILABLE(watchos, visionos);

/// Vends a new instance of AVMutableVideoComposition with values and instructions that will apply the specified handler block to video frames represented as instances of CIImage.
/// 
/// The new AVMutableVideoComposition will cause the specified handler block to be called to filter each frame of the asset's first enabled video track. The handler block should use the properties of the provided AVAsynchronousCIImageFilteringRequest and respond using finishWithImage:context: with a "filtered" new CIImage (or the provided source image for no affect). In the event of an error, respond to the request using finishWithError:. The error can be observed via AVPlayerItemFailedToPlayToEndTimeNotification, see AVPlayerItemFailedToPlayToEndTimeErrorKey in notification payload. The client can set sourceTrackIDForFrameTiming to kCMPersistentTrackID_Invalid and frameDuration to an appropriate value in order to specify the maximum output frame rate independent of the source track timing.
/// 
/// The video composition will also have the following values for its properties:
/// 
/// - The original timing of the asset's first enabled video track will be used.
/// - A renderSize that encompasses the asset's first enabled video track respecting the track's preferredTransform.
/// - A renderScale of 1.0.
/// 
/// The default CIContext has the following properties:
/// 
/// - iOS: Device RGB color space
/// - macOS: sRGB color space
/// 
/// Example usage:
/// ```objc
/// [AVMutableVideoComposition videoCompositionWithAsset:srcAsset applyingCIFiltersWithHandler:
/// ^(AVAsynchronousCIImageFilteringRequest *request)
/// {
/// 	NSError *err = nil;
/// 	CIImage *filtered = myRenderer(request, &err);
/// 	if (filtered)
/// 		[request finishWithImage:filtered context:nil];
/// 	else
/// 		[request finishWithError:err];
/// 	} completionHandler:
/// 	^(AVMutableVideoComposition * _Nullable videoComposition, NSError * _Nullable error)
/// 	{
/// 		if (videoComposition != nil) {
/// 			playerItem.videoComposition = videoComposition
/// 		else {
/// 		// handle error
/// 	}];
/// ```
/// - Parameter asset: An instance of AVAsset.
/// - Parameter completionHandler: A block that is invoked when the new video composition has finished being created. If the `videoComposition` parameter is nil, the `error` parameter describes the failure that occurred.
+ (void)videoCompositionWithAsset:(AVAsset *)asset applyingCIFiltersWithHandler:(void (^ NS_SWIFT_SENDABLE)(AVAsynchronousCIImageFilteringRequest *request))applier completionHandler:(void (^ NS_SWIFT_SENDABLE)(AVMutableVideoComposition * _Nullable videoComposition, NSError * _Nullable error))completionHandler API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end


@class AVVideoCompositionInstructionInternal;

/// An AVVideoCompositionInstruction object represents an operation to be performed by a compositor.
/// 
/// An AVVideoComposition object maintains an array of instructions to perform its composition. This class is not intended to be subclassed; instead, conform to AVVideoCompositionInstructionProtocol ("AVVideoCompositionInstruction" in Objective-C). Subclasses of this type that are used from Swift must fulfill the requirements of a Sendable type.
NS_SWIFT_SENDABLE
API_AVAILABLE(macos(10.7), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVVideoCompositionInstruction : NSObject <NSSecureCoding, NSCopying, NSMutableCopying, AVVideoCompositionInstruction> {
@private
	AVVideoCompositionInstructionInternal	*_instruction;
}

/// Pass-through initializer, for internal use in AVFoundation only
+ (AVVideoCompositionInstruction *)videoCompositionInstructionWithInstruction:(AVVideoCompositionInstruction *)instruction API_UNAVAILABLE(macos, ios, tvos, visionos, watchos);

/// Indicates the timeRange during which the instruction is effective. Note requirements for the timeRanges of instructions described in connection with AVVideoComposition's instructions key above.
@property (nonatomic, readonly) CMTimeRange timeRange;

/// Indicates the background color of the composition.
///
/// Solid BGRA colors only are supported; patterns and other color refs that are not supported will be ignored.
/// - If the background color is not specified the video compositor will use a default backgroundColor of opaque black.
/// - If the rendered pixel buffer does not have alpha, the alpha value of the backgroundColor will be ignored.
@property (nonatomic, readonly, retain, nullable) __attribute__((NSObject)) CGColorRef backgroundColor;

///  Provides an array of instances of AVVideoCompositionLayerInstruction that specify how video frames from source tracks should be layered and composed.
///
/// Tracks are layered in the composition according to the top-to-bottom order of the layerInstructions array; the track with trackID of the first instruction in the array will be layered on top, with the track with the trackID of the second instruction immediately underneath, etc. If this key is nil, the output will be a fill of the background color.
@property (nonatomic, readonly, copy) NSArray<AVVideoCompositionLayerInstruction *> *layerInstructions;

/// If NO, indicates that post-processing should be skipped for the duration of this instruction.  YES by default.
///
/// See +[AVVideoCompositionCoreAnimationTool videoCompositionToolWithPostProcessingAsVideoLayer:inLayer:].
@property (nonatomic, readonly) BOOL enablePostProcessing;

/// List of video track IDs required to compose frames for this instruction. The value of this property is computed from the layer instructions.
@property (nonatomic, readonly) NSArray<NSValue *> *requiredSourceTrackIDs API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// If the video composition result is one of the source frames for the duration of the instruction, this property returns the corresponding track ID. The compositor won't be run for the duration of the instruction and the proper source frame will be used instead. The value of this property is computed from the layer instructions
@property (nonatomic, readonly) CMPersistentTrackID passthroughTrackID API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos); // kCMPersistentTrackID_Invalid if not a passthrough instruction

/// List of track IDs for which sample data should be presented to the compositor for this instruction.
@property (nonatomic, readonly) NSArray<NSNumber *> *requiredSourceSampleDataTrackIDs API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end


@class AVMutableVideoCompositionInstructionInternal;

/// An AVMutableVideoCompositionInstruction object represents an operation to be performed by a compositor.
/// 
/// An AVVideoComposition object maintains an array of instructions to perform its composition.
#if __swift__
API_DEPRECATED("Use AVVideoCompositionInstruction.Configuration instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.7), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
@interface AVMutableVideoCompositionInstruction : AVVideoCompositionInstruction {
@private
	AVMutableVideoCompositionInstructionInternal	*_mutableInstruction __attribute__((unused));
}

/// Returns a new instance of AVMutableVideoCompositionInstruction.
/// 
/// The returned AVMutableVideoCompositionInstruction will have a timeRange of kCMTimeRangeInvalid, a NULL backgroundColor, and a nil array of layerInstructions.
+ (instancetype)videoCompositionInstruction;

/// Indicates the timeRange during which the instruction is effective. Note requirements for the timeRanges of instructions described in connection with AVVideoComposition's instructions key above.
@property (nonatomic, assign) CMTimeRange timeRange;

///  Indicates the background color of the composition.
///
///  Solid BGRA colors only are supported; patterns and other color refs that are not supported will be ignored.
/// - If the background color is not specified the video compositor will use a default backgroundColor of opaque black.
/// - If the rendered pixel buffer does not have alpha, the alpha value of the backgroundColor will be ignored.
@property (nonatomic, retain, nullable) __attribute__((NSObject)) CGColorRef backgroundColor;

/// Provides an array of instances of AVVideoCompositionLayerInstruction that specify how video frames from source tracks should be layered and composed.
///
/// Tracks are layered in the composition according to the top-to-bottom order of the layerInstructions array; the track with trackID of the first instruction in the array will be layered on top, with the track with the trackID of the second instruction immediately underneath, etc.
/// If this key is nil, the output will be a fill of the background color.
@property (nonatomic, copy) NSArray<AVVideoCompositionLayerInstruction *> *layerInstructions;

/// If NO, indicates that post-processing should be skipped for the duration of this instruction.  YES by default.
///
/// See +[AVVideoCompositionCoreAnimationTool videoCompositionToolWithPostProcessingAsVideoLayer:inLayer:].
@property (nonatomic, assign) BOOL enablePostProcessing;

/// List of sample data track IDs required to compose frames for this instruction.
///
/// Currently only tracks of type kCMMediaType_Metadata are allowed to be specified.  If this property is unspecified or is an empty array, no sample data is considered to be required for this instruction.  Note that you must also specify all tracks for which sample data is required for ANY instruction in the AVVideoComposition, in AVVideoComposition's property sourceSampleDataTrackIDs.
@property (nonatomic, copy) NSArray<NSNumber *> *requiredSourceSampleDataTrackIDs API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end


@class AVVideoCompositionLayerInstructionInternal;

/// An AVVideoCompositionLayerInstruction object represents the transform, opacity, and cropping ramps to apply to a given track. Subclasses of this type that are used from Swift must fulfill the requirements of a Sendable type.
NS_SWIFT_SENDABLE
API_AVAILABLE(macos(10.7), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVVideoCompositionLayerInstruction : NSObject <NSSecureCoding, NSCopying, NSMutableCopying> {
@private
	AVVideoCompositionLayerInstructionInternal	*_layerInstruction;
};

/// Pass-through initializer, for internal use in AVFoundation only
+ (AVVideoCompositionLayerInstruction *)videoCompositionLayerInstructionWithLayerInstruction:(AVVideoCompositionLayerInstruction *)instruction API_UNAVAILABLE(macos, ios, tvos, visionos, watchos);

/// Indicates the trackID of the source track to which the compositor will apply the instruction.
@property (nonatomic, readonly, assign) CMPersistentTrackID trackID;

/// Obtains the transform ramp that includes the specified time.
/// 
/// - Parameter time: If a ramp with a timeRange that contains the specified time has been set, information about the effective ramp for that time is supplied. Otherwise, information about the first ramp that starts after the specified time is supplied.
/// - Parameter startTransform: A pointer to a float to receive the starting transform value for the transform ramp. May be NULL.
/// - Parameter endTransform: A pointer to a float to receive the ending transform value for the transform ramp. May be NULL.
/// - Parameter timeRange: A pointer to a CMTimeRange to receive the timeRange of the transform ramp. May be NULL.
/// 
/// - Returns: An indication of success. NO will be returned if the specified time is beyond the duration of the last transform ramp that has been set.
- (BOOL)getTransformRampForTime:(CMTime)time startTransform:(nullable CGAffineTransform *)startTransform endTransform:(nullable CGAffineTransform *)endTransform timeRange:(nullable CMTimeRange *)timeRange;

/// Obtains the opacity ramp that includes the specified time.
/// 
/// - Parameter time: If a ramp with a timeRange that contains the specified time has been set, information about the effective ramp for that time is supplied. Otherwise, information about the first ramp that starts after the specified time is supplied.
/// - Parameter startOpacity: A pointer to a float to receive the starting opacity value for the opacity ramp. May be NULL.
/// - Parameter endOpacity: A pointer to a float to receive the ending opacity value for the opacity ramp. May be NULL.
/// - Parameter timeRange: A pointer to a CMTimeRange to receive the timeRange of the opacity ramp. May be NULL.
/// 
/// - Returns: An indication of success. NO will be returned if the specified time is beyond the duration of the last opacity ramp that has been set.
- (BOOL)getOpacityRampForTime:(CMTime)time startOpacity:(nullable float *)startOpacity endOpacity:(nullable float *)endOpacity timeRange:(nullable CMTimeRange *)timeRange;

/// Obtains the crop rectangle ramp that includes the specified time.
/// 
/// - Parameter time: If a ramp with a timeRange that contains the specified time has been set, information about the effective ramp for that time is supplied. Otherwise, information about the first ramp that starts after the specified time is supplied.
/// - Parameter startCropRectangle: A pointer to a CGRect to receive the starting crop rectangle value for the crop rectangle ramp. May be NULL.
/// - Parameter endCropRecrangle: A pointer to a CGRect to receive the ending crop rectangle value for the crop rectangle ramp. May be NULL.
/// - Parameter timeRange: A pointer to a CMTimeRange to receive the timeRange of the crop rectangle ramp. May be NULL.
/// 
/// - Returns: An indication of success. NO will be returned if the specified time is beyond the duration of the last crop rectangle ramp that has been set.
- (BOOL)getCropRectangleRampForTime:(CMTime)time startCropRectangle:(nullable CGRect *)startCropRectangle endCropRectangle:(nullable CGRect *)endCropRectangle timeRange:(nullable CMTimeRange *)timeRange API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end


@class AVMutableVideoCompositionLayerInstructionInternal;

/// AVMutableVideoCompositionLayerInstruction is a mutable subclass of AVVideoCompositionLayerInstruction that is used to modify the transform, cropping, and opacity ramps to apply to a given track in a composition.
#if __swift__
API_DEPRECATED("Use AVVideoCompositionLayerInstruction.Configuration instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.7), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
@interface AVMutableVideoCompositionLayerInstruction : AVVideoCompositionLayerInstruction {
@private
	AVMutableVideoCompositionLayerInstructionInternal	*_mutableLayerInstruction __attribute__((unused));
};

/// Returns a new instance of AVMutableVideoCompositionLayerInstruction with no transform or opacity ramps and a trackID set to the specified track's trackID.
/// 
/// - Parameter track: A reference to an AVAssetTrack.
+ (instancetype)videoCompositionLayerInstructionWithAssetTrack:(AVAssetTrack *)track;

/// Returns a new instance of AVMutableVideoCompositionLayerInstruction with no transform or opacity ramps and a trackID initialized to kCMPersistentTrackID_Invalid.
+ (instancetype)videoCompositionLayerInstruction;

/// Indicates the trackID of the source track to which the compositor will apply the instruction.
@property (nonatomic, assign) CMPersistentTrackID trackID;

/// Sets a transform ramp to apply during the specified timerange.
/// 
/// For purposes of spatial positioning of video frames, the origin is in the top-left corner, so
/// (a) positive translation values in an affine transform move a video frame right and down; and
/// (b) with an identity transform a video frame is positioned with its top-left corner in the top-left corner of the composited frame.
/// Video frames shall be interpreted at their display sizes (as described by CVImageBufferGetDisplaySize,
/// ie, taking pixel aspect ratio attachments into account) before any affine transform is applied.
/// 
/// During a transform ramp, the affine transform is interpolated between the values set at the ramp's start time and end time.
/// Before the first specified time for which a transform is set, the affine transform is held constant at the value of CGAffineTransformIdentity;
/// after the last time for which a transform is set, the affine transform is held constant at that last value;
/// 
/// This method throws an exception if the time range overlaps the time range of an existing transform ramp or if the time range of a does not have a numeric start time and duration.
/// 
/// - Parameter startTransform: The transform to be applied at the starting time of the timeRange. See the discussion below of how transforms are applied to video frames.
/// - Parameter endTransform: The transform to be applied at the end time of the timeRange.
/// - Parameter timeRange: The timeRange over which the value of the transform will be interpolated between startTransform and endTransform.
- (void)setTransformRampFromStartTransform:(CGAffineTransform)startTransform toEndTransform:(CGAffineTransform)endTransform timeRange:(CMTimeRange)timeRange;

/// Sets a value of the transform at a time within the timeRange of the instruction.
/// 
/// For purposes of spatial positioning of video frames, the origin is in the top-left corner, so
/// (a) positive translation values in an affine transform move a video frame right and down; and
/// (b) with an identity transform a video frame is positioned with its top-left corner in the top-left corner of the composited frame.
/// Video frames shall be interpreted at their display sizes (as described by CVImageBufferGetDisplaySize,
/// ie, taking pixel aspect ratio attachments into account) before any affine transform is applied.
/// 
/// Sets a fixed transform to apply from the specified time until the next time at which a transform is set; this is the same as setting a flat ramp for that time range.
/// Before the first specified time for which a transform is set, the affine transform is held constant at the value of CGAffineTransformIdentity;
/// after the last time for which a transform is set, the affine transform is held constant at that last value;
/// 
/// This method throws an exception if time is not numeric.
/// 
/// - Parameter transform: The transform to be applied at the specified time. See the discussion below of how transforms are applied to video frames.
/// - Parameter time: A time value within the timeRange of the composition instruction.
- (void)setTransform:(CGAffineTransform)transform atTime:(CMTime)time;

/// Sets an opacity ramp to apply during the specified timerange.
/// 
/// During an opacity ramp, opacity is computed using a linear interpolation.
/// Before the first time for which an opacity is set, the opacity is held constant at 1.0; after the last specified time, the opacity is held constant at the last value
/// This method throws an exception if the time range of a does not have a numeric start time and duration.
/// 
/// - Parameter startOpacity: The opacity to be applied at the starting time of the timeRange. The value must be between 0.0 and 1.0.
/// - Parameter endOpacity: The opacity to be applied at the end time of the timeRange. The value must be between 0.0 and 1.0.
/// - Parameter timeRange: The timeRange over which the value of the opacity will be interpolated between startOpacity and endOpacity.
- (void)setOpacityRampFromStartOpacity:(float)startOpacity toEndOpacity:(float)endOpacity timeRange:(CMTimeRange)timeRange;

/// Sets a value of the opacity at a time within the timeRange of the instruction.
/// 
/// Sets a fixed opacity to apply from the specified time until the next time at which an opacity is set; this is the same as setting a flat ramp for that time range.
/// Before the first time for which an opacity is set, the opacity is held constant at 1.0; after the last specified time, the opacity is held constant at the last value.
/// This method throws an exception if time is not numeric.
/// 
/// - Parameter opacity: The opacity to be applied at the specified time. The value must be between 0.0 and 1.0.
/// - Parameter time: A time value within the timeRange of the composition instruction.
- (void)setOpacity:(float)opacity atTime:(CMTime)time;

/// Sets an crop rectangle ramp to apply during the specified timerange.
/// 
/// The origin of the crop rectangle is the top-left corner of the buffer clean aperture rectangle. The crop rectangle is defined in
/// square pixel space, i.e. without taking the pixel aspect ratio into account. Crop rectangles extending outside of the clean aperture,
/// are cropped to the clean aperture.
/// 
/// During a crop rectangle ramp, the rectangle is interpolated between the values set at the ramp's start time and end time. 
/// When the starting or ending rectangle is empty, interpolations take into account the origin and size of the empty rectangle.
/// Before the first specified time for which a crop rectangle is set, the crop rectangle is held constant to CGRectInfinite
/// after the last time for which a crop rectangle is set, the crop rectangle is held constant at that last value.
/// 
/// This method throws an exception if the time range overlaps the time range of an existing crop rectangle ramp, or if the time range does not have a numeric start time and duration.
/// 
/// - Parameter startCropRectangle: The crop rectangle to be applied at the starting time of the timeRange. See the discussion below of how crop rectangles are applied to video frames.
/// - Parameter endCropRectangle: The crop rectangle to be applied at the end time of the timeRange.
/// - Parameter timeRange: The timeRange over which the value of the opacity will be interpolated between startCropRectangle and endCropRectangle.
- (void)setCropRectangleRampFromStartCropRectangle:(CGRect)startCropRectangle toEndCropRectangle:(CGRect)endCropRectangle timeRange:(CMTimeRange)timeRange API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Sets a value of the crop rectangle at a time within the timeRange of the instruction.
/// 
/// The origin of the crop rectangle is the top-left corner of the buffer clean aperture rectangle. The crop rectangle is defined in
/// square pixel space, i.e. without taking the pixel aspect ratio into account. Crop rectangles extending outside of the clean aperture,
/// are cropped to the clean aperture.
/// 
/// Sets a fixed crop rectangle to apply from the specified time until the next time at which a crop rectangle is set; this is the same as setting a flat ramp for that time range.
/// Before the first specified time for which a crop rectangle is set, the crop rectangle is held constant to CGRectInfinite
/// after the last time for which a crop rectangle is set, the crop rectangle is held constant at that last value.
/// 
/// This method throws an exception if time is not numeric.
/// 
/// - Parameter cropRectangle: The crop rectangle to be applied at the specified time. See the discussion below of how crop rectangles are applied to video frames.
/// - Parameter time: A time value within the timeRange of the composition instruction.
- (void)setCropRectangle:(CGRect)cropRectangle atTime:(CMTime)time API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end

@class CALayer;
@class AVVideoCompositionCoreAnimationToolInternal;

/// A tool for using Core Animation in a video composition.
/// 
/// Instances of AVVideoCompositionCoreAnimationTool are for use with offline rendering (AVAssetExportSession and AVAssetReader), not with AVPlayer.
/// To synchronize real-time playback with other CoreAnimation layers, use AVSynchronizedLayer.
/// 
/// Any animations will be interpreted on the video's timeline, not real-time, so
/// (a) set animation beginTimes to small positive value such as AVCoreAnimationBeginTimeAtZero rather than 0,
/// because CoreAnimation will replace a value of 0 with CACurrentMediaTime(); 
/// (b) set removedOnCompletion to NO on animations so they are not automatically removed;
/// (c) do not use layers associated with UIViews.
/// 
/// Subclasses of this type that are used from Swift must fulfill the requirements of a Sendable type.
NS_SWIFT_SENDABLE
API_AVAILABLE(macos(10.7), ios(4.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVVideoCompositionCoreAnimationTool : NSObject {
@private
	AVVideoCompositionCoreAnimationToolInternal	*_videoCompositionTool;
}

/// Add a Core Animation layer to the video composition
/// 
/// Include a Core Animation layer as an individual track input in video composition.
/// This layer should not come from, or be added to, another layer tree.
/// trackID should not match any real trackID in the source. Use -[AVAsset unusedTrackID] 
/// to obtain a trackID that's guaranteed not to coincide with the trackID of any track of the asset.
/// AVVideoCompositionInstructions should reference trackID where the rendered animation should be included.
/// For best performance, no transform should be set in the AVVideoCompositionLayerInstruction for this trackID.
/// Be aware that on iOS, CALayers backing a UIView usually have their content flipped (as defined by the
/// -contentsAreFlipped method). It may be required to insert a CALayer with its geometryFlipped property set
/// to YES in the layer hierarchy to get the same result when attaching a CALayer to a AVVideoCompositionCoreAnimationTool
/// as when using it to back a UIView.
+ (instancetype)videoCompositionCoreAnimationToolWithAdditionalLayer:(CALayer *)NS_SWIFT_SENDING layer asTrackID:(CMPersistentTrackID)trackID;

/// Compose the composited video frames with the Core Animation layer
/// 
/// Place composited video frames in videoLayer and render animationLayer 
/// to produce the final frame. Normally videoLayer should be in animationLayer's sublayer tree.
/// The animationLayer should not come from, or be added to, another layer tree.
/// Be aware that on iOS, CALayers backing a UIView usually have their content flipped (as defined by the
/// -contentsAreFlipped method). It may be required to insert a CALayer with its geometryFlipped property set
/// to YES in the layer hierarchy to get the same result when attaching a CALayer to a AVVideoCompositionCoreAnimationTool
/// as when using it to back a UIView.
+ (instancetype)videoCompositionCoreAnimationToolWithPostProcessingAsVideoLayer:(CALayer *) videoLayer inLayer:(CALayer *) animationLayer
#if __swift__
API_DEPRECATED("Use .init(configuration: AVVideoCompositionCoreAnimationTool.Configuration) instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(watchos);
#endif
;

/// Compose the composited video frames with the Core Animation layer
/// 
/// Duplicate the composited video frames in each videoLayer and render animationLayer 
/// to produce the final frame. Normally videoLayers should be in animationLayer's sublayer tree.
/// The animationLayer should not come from, or be added to, another layer tree.
/// Be aware that on iOS, CALayers backing a UIView usually have their content flipped (as defined by the
/// -contentsAreFlipped method). It may be required to insert a CALayer with its geometryFlipped property set
/// to YES in the layer hierarchy to get the same result when attaching a CALayer to a AVVideoCompositionCoreAnimationTool
/// as when using it to back a UIView.
+ (instancetype)videoCompositionCoreAnimationToolWithPostProcessingAsVideoLayers:(NSArray<CALayer *> *) videoLayers inLayer:(CALayer *) animationLayer API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#if __swift__
API_DEPRECATED("Use .init(configuration: AVVideoCompositionCoreAnimationTool.Configuration) instead", macos(10.9, API_TO_BE_DEPRECATED), ios(7.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(watchos);
#endif
;

@end


@interface AVAsset (AVAssetVideoCompositionUtility)

- (CMPersistentTrackID)unusedTrackID
#if __swift__
API_DEPRECATED("Use findUnusedTrackID() instead", macos(10.7, 13.0), ios(4.0, 16.0), tvos(9.0, 16.0), watchos(1.0, 9.0)) API_UNAVAILABLE(visionos);
#else
API_DEPRECATED("Use findUnusedTrackIDWithCompletionHandler: instead", macos(10.7, 15.0), ios(4.0, 18.0), tvos(9.0, 18.0), watchos(1.0, 11.0)) API_UNAVAILABLE(visionos);
#endif

/// Loads a track ID that will not collide with any existing track
/// 
/// - Parameter completionHandler: A block that is invoked when loading is complete, vending the track ID or an error.
- (void)findUnusedTrackIDWithCompletionHandler:(void (^ NS_SWIFT_SENDABLE)(CMPersistentTrackID, NSError * _Nullable))completionHandler API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), watchos(8.0), visionos(1.0));

@end

@protocol AVVideoCompositionValidationHandling;

@interface AVVideoComposition (AVVideoCompositionValidation)

/// Indicates whether the timeRanges of the receiver's instructions conform to the requirements described for them immediately above (in connection with the instructions property) and also whether all of the layer instructions have a value for trackID that corresponds either to a track of the specified asset or to the receiver's animationTool.
/// 
/// In the course of validation, the receiver will invoke its validationDelegate with reference to any trouble spots in the video composition.
/// An exception will be raised if the delegate modifies the receiver's array of instructions or the array of layerInstructions of any AVVideoCompositionInstruction contained therein during validation.
/// 
/// - Parameter asset: Pass a reference to an AVAsset if you wish to validate the timeRanges of the instructions against the duration of the asset and the trackIDs of the layer instructions against the asset's tracks. Pass nil to skip that validation. Clients should ensure that the keys @"tracks" and @"duration" are already loaded on the AVAsset before validation is attempted.
/// - Parameter timeRange: A CMTimeRange. Only those instructions with timeRanges that overlap with the specified timeRange will be validated. To validate all instructions that may be used for playback or other processing, regardless of timeRange, pass CMTimeRangeMake(kCMTimeZero, kCMTimePositiveInfinity).
/// - Parameter validationDelegate: Indicates an object implementing the AVVideoCompositionValidationHandling protocol to receive information about troublesome portions of a video composition during processing of -isValidForAsset:. May be nil.
- (BOOL)isValidForAsset:(nullable AVAsset *)asset timeRange:(CMTimeRange)timeRange validationDelegate:(nullable id<AVVideoCompositionValidationHandling>)validationDelegate API_DEPRECATED("Use isValidForTracks:assetDuration:timeRange:validationDelegate: instead", macos(10.8, 15.0), ios(5.0, 18.0), tvos(9.0, 18.0)) API_UNAVAILABLE(watchos, visionos);

/// Determines whether the timeRanges of the receiver's instructions conform to the requirements described for them immediately above (in connection with the instructions property) and also whether all of the layer instructions have a value for trackID that corresponds either to a track of the specified asset or to the receiver's animationTool.
/// 
/// In the course of validation, the receiver will invoke its validationDelegate with reference to any trouble spots in the video composition.
/// An exception will be raised if the delegate modifies the receiver's array of instructions or the array of layerInstructions of any AVVideoCompositionInstruction contained therein during validation.
/// 
/// - Parameter asset: Pass a reference to an AVAsset if you wish to validate the timeRanges of the instructions against the duration of the asset and the trackIDs of the layer instructions against the asset's tracks. Pass nil to skip that validation.
/// - Parameter timeRange: A CMTimeRange. Only those instructions with timeRanges that overlap with the specified timeRange will be validated. To validate all instructions that may be used for playback or other processing, regardless of timeRange, pass CMTimeRangeMake(kCMTimeZero, kCMTimePositiveInfinity).
/// - Parameter validationDelegate: Indicates an object implementing the AVVideoCompositionValidationHandling protocol to receive information about troublesome portions of a video composition during processing of -determineValidityForAsset:. May be nil.
/// - Parameter completionHandler: A block that is invoked when a determination is made about whether the video composition is valid. If the `isValid` parameter is NO, either the video composition is not valid, in which case the `error` parameter will be nil, or the answer could not be determined, in which case the `error` parameter will be non-nil and describe the failure that occurred.
- (void)determineValidityForAsset:(nullable AVAsset *)asset timeRange:(CMTimeRange)timeRange validationDelegate:(nullable id<AVVideoCompositionValidationHandling>)validationDelegate completionHandler:(void (^ NS_SWIFT_SENDABLE)(BOOL isValid, NSError * _Nullable error))completionHandler NS_SWIFT_ASYNC_NAME(isValid(for:timeRange:validationDelegate:)) API_DEPRECATED_WITH_REPLACEMENT("isValidForTracks:assetDuration:timeRange:validationDelegate:", macos(13.0, 15.0), ios(16.0, 18.0), tvos(16.0, 18.0), visionos(1.0, 2.0)) API_UNAVAILABLE(watchos);

/// Indicates whether the timeRanges of the receiver's instructions conform to the requirements described for them immediately above (in connection with the instructions property) and also whether all of the layer instructions have a value for trackID that corresponds either to a track of the specified asset or to the receiver's animationTool.
/// 
/// In the course of validation, the receiver will invoke its validationDelegate with reference to any trouble spots in the video composition.
/// An exception will be raised if the delegate modifies the receiver's array of instructions or the array of layerInstructions of any AVVideoCompositionInstruction contained therein during validation.
/// 
/// - Parameter tracks: Pass a reference to an AVAsset's tracks if you wish to validate the trackIDs of the layer instructions against the asset's tracks. Pass nil to skip that validation. This method throws an exception if the tracks are not all from the same asset.
/// - Parameter duration: Pass an AVAsset if you wish to validate the timeRanges of the instructions against the duration of the asset. Pass kCMTimeInvalid to skip that validation.
/// - Parameter timeRange: A CMTimeRange. Only those instructions with timeRanges that overlap with the specified timeRange will be validated. To validate all instructions that may be used for playback or other processing, regardless of timeRange, pass CMTimeRangeMake(kCMTimeZero, kCMTimePositiveInfinity).
/// - Parameter validationDelegate: Indicates an object implementing the AVVideoCompositionValidationHandling protocol to receive information about troublesome portions of a video composition during processing of -isValidForAsset:. May be nil.
- (BOOL)isValidForTracks:(NSArray<AVAssetTrack *> *)tracks assetDuration:(CMTime)duration timeRange:(CMTimeRange)timeRange validationDelegate:(nullable id<AVVideoCompositionValidationHandling>)validationDelegate API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), visionos(2.0)) API_UNAVAILABLE(watchos);

@end

API_AVAILABLE(macos(10.8), ios(5.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@protocol AVVideoCompositionValidationHandling <NSObject>

@optional

/// Invoked by an instance of AVVideoComposition when validating an instance of AVVideoComposition, to report a key that has an invalid value.
/// 
/// - Returns: An indication of whether the AVVideoComposition should continue validation in order to report additional problems that may exist.
- (BOOL)videoComposition:(AVVideoComposition *)videoComposition shouldContinueValidatingAfterFindingInvalidValueForKey:(NSString *)key API_AVAILABLE(macos(10.8), ios(5.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Invoked by an instance of AVVideoComposition when validating an instance of AVVideoComposition, to report a timeRange that has no corresponding video composition instruction.
/// 
/// - Returns: An indication of whether the AVVideoComposition should continue validation in order to report additional problems that may exist.
- (BOOL)videoComposition:(AVVideoComposition *)videoComposition shouldContinueValidatingAfterFindingEmptyTimeRange:(CMTimeRange)timeRange API_AVAILABLE(macos(10.8), ios(5.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Invoked by an instance of AVVideoComposition when validating an instance of AVVideoComposition, to report a video composition instruction with a timeRange that's invalid, that overlaps with the timeRange of a prior instruction, or that contains times earlier than the timeRange of a prior instruction.
/// 
/// Use CMTIMERANGE_IS_INVALID, defined in CMTimeRange.h, to test whether the timeRange itself is invalid. Refer to headerdoc for AVVideoComposition.instructions for a discussion of how timeRanges for instructions must be formulated.
/// 
/// - Returns: An indication of whether the AVVideoComposition should continue validation in order to report additional problems that may exist.
- (BOOL)videoComposition:(AVVideoComposition *)videoComposition shouldContinueValidatingAfterFindingInvalidTimeRangeInInstruction:(id<AVVideoCompositionInstruction>)videoCompositionInstruction API_AVAILABLE(macos(10.8), ios(5.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Invoked by an instance of AVVideoComposition when validating an instance of AVVideoComposition, to report a video composition layer instruction with a trackID that does not correspond either to the trackID used for the composition's animationTool or to a track of the asset specified in -[AVVideoComposition isValidForAsset:timeRange:delegate:].
/// 
/// - Returns: An indication of whether the AVVideoComposition should continue validation in order to report additional problems that may exist.
- (BOOL)videoComposition:(AVVideoComposition *)videoComposition shouldContinueValidatingAfterFindingInvalidTrackIDInInstruction:(id<AVVideoCompositionInstruction>)videoCompositionInstruction layerInstruction:(AVVideoCompositionLayerInstruction *)layerInstruction asset:(AVAsset *)asset API_AVAILABLE(macos(10.8), ios(5.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end

NS_ASSUME_NONNULL_END

#else
#import <AVFCore/AVVideoComposition.h>
#endif
