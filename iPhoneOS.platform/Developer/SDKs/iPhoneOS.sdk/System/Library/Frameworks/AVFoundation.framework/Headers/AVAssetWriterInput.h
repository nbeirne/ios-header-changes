#if !__has_include(<AVFCore/AVAssetWriterInput.h>)
/*
	File:  AVAssetWriterInput.h

	Framework:  AVFoundation
 
	Copyright 2010-2023 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <AVFoundation/AVMediaFormat.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>
#import <CoreMedia/CMSampleBuffer.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <CoreMedia/CMFormatDescription.h>

#import <CoreMedia/CMTaggedBufferGroup.h>

@class AVMetadataItem;
@class AVAssetWriterInputInternal;
@class AVCaption;
@class AVCaptionGroup;
@class AVAssetWriterInputCaptionAdaptorInternal;

NS_ASSUME_NONNULL_BEGIN

/// AVAssetWriterInput defines an interface for appending either new media samples or references to existing media samples packaged as CMSampleBuffer objects to a single track of the output file of an AVAssetWriter.
/// 
/// Clients that need to write multiple concurrent tracks of media data should use one AVAssetWriterInput instance per track. In order to write multiple concurrent tracks with ideal interleaving of media data, clients should observe the value returned by the readyForMoreMediaData property of each AVAssetWriterInput instance.
/// 
/// AVAssetWriterInput also supports writing per-track metadata collections to the output file.
/// 
/// As of macOS 10.10 and iOS 8.0 AVAssetWriterInput can also be used to create tracks that are not self-contained. Such tracks reference sample data that is located in another file. This is currently supported only for instances of AVAssetWriterInput attached to an instance of AVAssetWriter that writes files of type AVFileTypeQuickTimeMovie.
API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVAssetWriterInput : NSObject
{
@private
	AVAssetWriterInputInternal	*_internal;
}
AV_INIT_UNAVAILABLE

/// Creates a new input of the specified media type to receive sample buffers for writing to the output file.
/// 
/// Each new input accepts data for a new track of the AVAssetWriter's output file. Inputs are added to an asset writer using -[AVAssetWriter addInput:].
/// 
/// Passing nil for output settings instructs the input to pass through appended samples, doing no processing before they are written to the output file. This is useful if, for example, you are appending buffers that are already in a desirable compressed format. However, if not writing to a QuickTime Movie file (i.e. the AVAssetWriter was initialized with a file type other than AVFileTypeQuickTimeMovie), AVAssetWriter only supports passing through a restricted set of media types and subtypes. In order to pass through media data to files other than AVFileTypeQuickTimeMovie, a non-NULL format hint must be provided using +assetWriterInputWithMediaType:outputSettings:sourceFormatHint: instead of this method.
/// 
/// For AVMediaTypeAudio the following keys are not currently supported in the outputSettings dictionary: AVSampleRateConverterAudioQualityKey. When using this method to construct a new instance, an audio settings dictionary must be fully specified, meaning that it must contain AVFormatIDKey, AVSampleRateKey, and AVNumberOfChannelsKey. If no other channel layout information is available, a value of 1 for AVNumberOfChannelsKey will result in mono output and a value of 2 will result in stereo output. If AVNumberOfChannelsKey specifies a channel count greater than 2, the dictionary must also specify a value for AVChannelLayoutKey. For kAudioFormatLinearPCM, all relevant AVLinearPCM*Key keys must be included, and for kAudioFormatAppleLossless, AVEncoderBitDepthHintKey keys must be included. See +assetWriterInputWithMediaType:outputSettings:sourceFormatHint: for a way to avoid having to specify a value for each of those keys.
/// 
/// For AVMediaTypeVideo, any output settings dictionary must request a compressed video format. This means that the value passed in for outputSettings must follow the rules for compressed video output, as laid out in AVVideoSettings.h. When using this method to construct a new instance, a video settings dictionary must be fully specified, meaning that it must contain AVVideoCodecKey, AVVideoWidthKey, and AVVideoHeightKey. See +assetWriterInputWithMediaType:outputSettings:sourceFormatHint: for a way to avoid having to specify a value for each of those keys. On iOS, the only values currently supported for AVVideoCodecKey are AVVideoCodecTypeH264 and AVVideoCodecTypeJPEG. AVVideoCodecTypeH264 is not supported on iPhone 3G. For AVVideoScalingModeKey, the value AVVideoScalingModeFit is not supported.
/// 
/// - Parameter mediaType: The media type of samples that will be accepted by the input. Media types are defined in AVMediaFormat.h.
/// - Parameter outputSettings: The settings used for encoding the media appended to the output. See AVAudioSettings.h for AVMediaTypeAudio or AVVideoSettings.h for AVMediaTypeVideo and for more information on how to construct an output settings dictionary. If you only require simple preset-based output settings, see AVOutputSettingsAssistant.
/// 
/// - Returns: An instance of AVAssetWriterInput.
+ (instancetype)assetWriterInputWithMediaType:(AVMediaType)mediaType outputSettings:(nullable NSDictionary<NSString *, id> *)outputSettings;

/// Creates a new input of the specified media type to receive sample buffers for writing to the output file.
/// 
/// A version of +assetWriterInputWithMediaType:outputSettings: that includes the ability to hint at the format of media data that will be appended to the new instance of AVAssetWriterInput. When a source format hint is provided, the outputSettings dictionary is not required to be fully specified. For AVMediaTypeAudio, this means that AVFormatIDKey is the only required key. For AVMediaTypeVideo, this means that AVVideoCodecKey is the only required key. Values for the remaining keys will be chosen by the asset writer input, with consideration given to the attributes of the source format. To guarantee successful file writing, clients who specify a format hint should ensure that subsequently-appended buffers are of the specified format.
/// 
/// This method throws an exception for any of the following reasons:
/// - the media type of the format description does not match the media type passed into this method
/// - the width and height of video format hint are not positive
/// - the output settings do not match the supplied media type
/// - for video inputs, the output settings do not contain a required key (AVVideoCodecKey, AVVideoWidthKey, AVVideoHeightKey)
/// - the output scaling mode is AVVideoScalingModeFit
/// - the output settings contain AVSampleRateConverterAudioQualityKey or AVVideoDecompressionPropertiesKey
/// 
/// - Parameter mediaType: The media type of samples that will be accepted by the input. Media types are defined in AVMediaFormat.h.
/// - Parameter outputSettings: The settings used for encoding the media appended to the output. See AVAudioSettings.h for AVMediaTypeAudio or AVVideoSettings.h for AVMediaTypeVideo and for more information on how to construct an output settings dictionary. If you only require simple preset-based output settings, see AVOutputSettingsAssistant.
/// - Parameter sourceFormatHint: A hint about the format of media data that will be appended to the new input.
/// 
/// - Returns: An instance of AVAssetWriterInput.
+ (instancetype)assetWriterInputWithMediaType:(AVMediaType)mediaType outputSettings:(nullable NSDictionary<NSString *, id> *)outputSettings sourceFormatHint:(nullable CMFormatDescriptionRef)sourceFormatHint API_AVAILABLE(macos(10.8), ios(6.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Creates a new input of the specified media type to receive sample buffers for writing to the output file.
/// 
/// Each new input accepts data for a new track of the AVAssetWriter's output file. Inputs are added to an asset writer using -[AVAssetWriter addInput:].
/// 
/// Passing nil for output settings instructs the input to pass through appended samples, doing no processing before they are written to the output file. This is useful if, for example, you are appending buffers that are already in a desirable compressed format. However, if not writing to a QuickTime Movie file (i.e. the AVAssetWriter was initialized with a file type other than AVFileTypeQuickTimeMovie), AVAssetWriter only supports passing through a restricted set of media types and subtypes. In order to pass through media data to files other than AVFileTypeQuickTimeMovie, a non-NULL format hint must be provided using -initWithMediaType:outputSettings:sourceFormatHint: instead of this method.
/// 
/// For AVMediaTypeAudio the following keys are not currently supported in the outputSettings dictionary: AVSampleRateConverterAudioQualityKey. When using this initializer, an audio settings dictionary must be fully specified, meaning that it must contain AVFormatIDKey, AVSampleRateKey, and AVNumberOfChannelsKey. If no other channel layout information is available, a value of 1 for AVNumberOfChannelsKey will result in mono output and a value of 2 will result in stereo output. If AVNumberOfChannelsKey specifies a channel count greater than 2, the dictionary must also specify a value for AVChannelLayoutKey. For kAudioFormatLinearPCM, all relevant AVLinearPCM*Key keys must be included, and for kAudioFormatAppleLossless, AVEncoderBitDepthHintKey keys must be included. See -initWithMediaType:outputSettings:sourceFormatHint: for a way to avoid having to specify a value for each of those keys.
/// 
/// For AVMediaTypeVideo, any output settings dictionary must request a compressed video format. This means that the value passed in for outputSettings must follow the rules for compressed video output, as laid out in AVVideoSettings.h. When using this initializer, a video settings dictionary must be fully specified, meaning that it must contain AVVideoCodecKey, AVVideoWidthKey, and AVVideoHeightKey. See -initWithMediaType:outputSettings:sourceFormatHint: for a way to avoid having to specify a value for each of those keys. On iOS, the only values currently supported for AVVideoCodecKey are AVVideoCodecTypeH264 and AVVideoCodecTypeJPEG. AVVideoCodecTypeH264 is not supported on iPhone 3G. For AVVideoScalingModeKey, the value AVVideoScalingModeFit is not supported.
/// 
/// This method throws an exception for any of the following reasons:
/// - the media type of the format description does not match the media type passed into this method
/// - the output settings do not match the supplied media type
/// - for video inputs, the output settings do not contain a required key (AVVideoCodecKey, AVVideoWidthKey, AVVideoHeightKey)
/// - the output scaling mode is AVVideoScalingModeFit
/// - the output settings contain AVSampleRateConverterAudioQualityKey or AVVideoDecompressionPropertiesKey
/// 
/// - Parameter mediaType: The media type of samples that will be accepted by the input. Media types are defined in AVMediaFormat.h.
/// - Parameter outputSettings: The settings used for encoding the media appended to the output. See AVAudioSettings.h for AVMediaTypeAudio or AVVideoSettings.h for AVMediaTypeVideo and for more information on how to construct an output settings dictionary. If you only require simple preset-based output settings, see AVOutputSettingsAssistant.
/// 
/// - Returns: An instance of AVAssetWriterInput.
- (instancetype)initWithMediaType:(AVMediaType)mediaType outputSettings:(nullable NSDictionary<NSString *, id> *)outputSettings;

/// Creates a new input of the specified media type to receive sample buffers for writing to the output file. This is the designated initializer of AVAssetWriterInput.
/// 
/// A version of -initWithMediaType:outputSettings: that includes the ability to hint at the format of media data that will be appended to the new instance of AVAssetWriterInput. When a source format hint is provided, the outputSettings dictionary is not required to be fully specified. For AVMediaTypeAudio, this means that AVFormatIDKey is the only required key. For AVMediaTypeVideo, this means that AVVideoCodecKey is the only required key. Values for the remaining keys will be chosen by the asset writer input, with consideration given to the attributes of the source format. To guarantee successful file writing, clients who specify a format hint should ensure that subsequently-appended buffers are of the specified format.
/// 
/// This method throws an exception for any of the following reasons:
/// - the media type of the format description does not match the media type passed into this method
/// - the width and height of video format hint are not positive
/// - the output settings do not match the supplied media type
/// - for video inputs, the output settings do not contain a required key (AVVideoCodecKey, AVVideoWidthKey, AVVideoHeightKey)
/// - the output scaling mode is AVVideoScalingModeFit
/// - the output settings contain AVSampleRateConverterAudioQualityKey or AVVideoDecompressionPropertiesKey
/// 
/// - Parameter mediaType: The media type of samples that will be accepted by the input. Media types are defined in AVMediaFormat.h.
/// - Parameter outputSettings: The settings used for encoding the media appended to the output. See AVAudioSettings.h for AVMediaTypeAudio or AVVideoSettings.h for AVMediaTypeVideo and for more information on how to construct an output settings dictionary. If you only require simple preset-based output settings, see AVOutputSettingsAssistant.
/// - Parameter sourceFormatHint: A hint about the format of media data that will be appended to the new input.
/// 
/// - Returns: An instance of AVAssetWriterInput.
- (instancetype)initWithMediaType:(AVMediaType)mediaType outputSettings:(nullable NSDictionary<NSString *, id> *)outputSettings sourceFormatHint:(nullable CMFormatDescriptionRef)sourceFormatHint API_AVAILABLE(macos(10.8), ios(6.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos) NS_DESIGNATED_INITIALIZER;

/// The media type of the samples that can be appended to the receiver.
/// 
/// The value of this property is one of the media types defined in AVMediaFormat.h.
@property (nonatomic, readonly) AVMediaType mediaType;

/// The settings used for encoding the media appended to the output.
/// 
/// The value of this property is an NSDictionary that contains values for keys as specified by either AVAudioSettings.h for AVMediaTypeAudio or AVVideoSettings.h for AVMediaTypeVideo. A value of nil indicates that the receiver will pass through appended samples, doing no processing before they are written to the output file.
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> *outputSettings;

/// The hint given at initialization time about the format of incoming media data.
/// 
/// AVAssetWriterInput may be able to use this hint to fill in missing output settings or perform more upfront validation. To guarantee successful file writing, clients who specify a format hint should ensure that subsequently-appended media data are of the specified format.
@property (nonatomic, readonly, nullable) __attribute__((NSObject)) CMFormatDescriptionRef sourceFormatHint API_AVAILABLE(macos(10.8), ios(6.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// A collection of metadata to be written to the track corresponding to the receiver.
/// 
/// The value of this property is an array of AVMetadataItem objects representing the collection of track-level metadata to be written in the output file.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
@property (nonatomic, copy) NSArray<AVMetadataItem *> *metadata;

/// Indicates the readiness of the input to accept more media data.
/// 
/// When there are multiple inputs, AVAssetWriter tries to write media data in an ideal interleaving pattern for efficiency in storage and playback. Each of its inputs signals its readiness to receive media data for writing according to that pattern via the value of readyForMoreMediaData. You can append media data to an input only while its readyForMoreMediaData property is YES.
/// 
/// Clients writing media data from a non-real-time source, such as an instance of AVAssetReader, should hold off on generating or obtaining more media data to append to an input when the value of readyForMoreMediaData is NO. To help with control of the supply of non-real-time media data, such clients can use -requestMediaDataWhenReadyOnQueue:usingBlock in order to specify a block that the input should invoke whenever it's ready for input to be appended.
/// 
/// Clients writing media data from a real-time source, such as an instance of AVCaptureOutput, should set the input's expectsMediaDataInRealTime property to YES to ensure that the value of readyForMoreMediaData is calculated appropriately. When expectsMediaDataInRealTime is YES, readyForMoreMediaData will become NO only when the input cannot process media samples as quickly as they are being provided by the client. If readyForMoreMediaData becomes NO for a real-time source, the client may need to drop samples or consider reducing the data rate of appended samples.
/// 
/// When the value of canPerformMultiplePasses is YES for any input attached to this input's asset writer, the value for this property may start as NO and/or be NO for long periods of time.
/// 
/// The value of readyForMoreMediaData will often change from NO to YES asynchronously, as previously supplied media data is processed and written to the output. It is possible for all of an AVAssetWriter's AVAssetWriterInputs temporarily to return NO for readyForMoreMediaData.
/// 
/// This property is key value observable. Observers should not assume that they will be notified of changes on a specific thread.
@property (nonatomic, readonly, getter=isReadyForMoreMediaData) BOOL readyForMoreMediaData
#if __swift__
API_DEPRECATED("Use the input receiver's async append(...) method instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.1, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED))
API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
;

/// Indicates whether the input should tailor its processing of media data for real-time sources.
/// 
/// Clients appending media data to an input from a real-time source, such as an AVCaptureOutput, should set expectsMediaDataInRealTime to YES. This will ensure that readyForMoreMediaData is calculated appropriately for real-time usage.
/// 
/// For best results, do not set both this property and performsMultiPassEncodingIfSupported to YES.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
@property (nonatomic) BOOL expectsMediaDataInRealTime
#if __swift__
API_DEPRECATED("Use the input receiver's appendImmediately(...) method instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.1, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED))
API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
;

/// Instructs the receiver to invoke a client-supplied block repeatedly, at its convenience, in order to gather media data for writing to the output file.
/// 
/// The block should append media data to the input either until the input's readyForMoreMediaData property becomes NO or until there is no more media data to supply (at which point it may choose to mark the input as finished via -markAsFinished). The block should then exit. After the block exits, if the input has not been marked as finished, once the input has processed the media data it has received and becomes ready for more media data again, it will invoke the block again in order to obtain more.
/// 
/// A typical use of this method, with a block that supplies media data to an input while respecting the input's readyForMoreMediaData property, might look like this:
/// ```objc
/// [myAVAssetWriterInput requestMediaDataWhenReadyOnQueue:myInputSerialQueue usingBlock:^{
/// 	while ([myAVAssetWriterInput isReadyForMoreMediaData])
/// 	{
/// 		CMSampleBufferRef nextSampleBuffer = [self copyNextSampleBufferToWrite];
/// 		if (nextSampleBuffer)
/// 		{
/// 			[myAVAssetWriterInput appendSampleBuffer:nextSampleBuffer];
/// 			CFRelease(nextSampleBuffer);
/// 		}
/// 		else
/// 		{
/// 			[myAVAssetWriterInput markAsFinished];
/// 			break;
/// 		}
/// 	}
/// }];
/// ```
/// This method is not recommended for use with a push-style buffer source, such as AVCaptureAudioDataOutput or AVCaptureVideoDataOutput, because such a combination will likely require intermediate queueing of buffers. Instead, this method is better suited to a pull-style buffer source such as AVAssetReaderOutput, as illustrated in the above example.
/// 
/// When using a push-style buffer source, it is generally better to immediately append each buffer to the AVAssetWriterInput, directly via -[AVAssetWriter appendSampleBuffer:], as it is received. Using this strategy, it is often possible to avoid having to queue up buffers in between the buffer source and the AVAssetWriterInput. Note that many of these push-style buffer sources also produce buffers in real-time, in which case the client should set expectsMediaDataInRealTime to YES.
/// 
/// Before calling this method, you must ensure that the receiver is attached to an AVAssetWriter via a prior call to -addInput: and that -startWriting has been called on the asset writer.
/// 
/// This method throws an exception if this method is called more than once.
/// 
/// - Parameter queue: The queue on which the block should be invoked.
/// - Parameter block: The block the input should invoke to obtain media data.
- (void)requestMediaDataWhenReadyOnQueue:(dispatch_queue_t)queue usingBlock:(void (^ NS_SWIFT_SENDABLE)(void))block
#if __swift__
API_DEPRECATED("Use the input receiver's async append(...) method on its own task instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.1, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED))
API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
;

/// Appends samples to the receiver.
/// 
/// The timing information in the sample buffer, considered relative to the time passed to -[AVAssetWriter startSessionAtSourceTime:], will be used to determine the timing of those samples in the output file.
/// 
/// For track types other than audio tracks, to determine the duration of all samples in the output file other than the very last sample that's appended, the difference between the sample buffer's output DTS and the following sample buffer's output DTS will be used. The duration of the last sample is determined as follows:
/// 1. If a marker sample buffer with kCMSampleBufferAttachmentKey_EndsPreviousSampleDuration is appended following the last media-bearing sample, the difference between the output DTS of the marker sample buffer and the output DTS of the last media-bearing sample will be used.
/// 2. If the marker sample buffer is not provided and if the output duration of the last media-bearing sample is valid, it will be used.
/// 3. if the output duration of the last media-bearing sample is not valid, the duration of the second-to-last sample will be used.
/// 
/// For audio tracks, the properties of each appended sample buffer are used to determine corresponding output durations.
/// 
/// The receiver will retain the CMSampleBuffer until it is done with it, and then release it. Do not modify a CMSampleBuffer or its contents after you have passed it to this method.
/// 
/// If the sample buffer contains audio data and the AVAssetWriterInput was intialized with an outputSettings dictionary then the format must be linear PCM. If the outputSettings dictionary was nil then audio data can be provided in a compressed format, and it will be passed through to the output without any re-compression. Note that advanced formats like AAC will have encoder delay present in their bitstreams. This data is inserted by the encoder and is necessary for proper decoding, but it is not meant to be played back. Clients who provide compressed audio bitstreams must use kCMSampleBufferAttachmentKey_TrimDurationAtStart to mark the encoder delay (generally restricted to the first sample buffer). Packetization can cause there to be extra audio frames in the last packet which are not meant to be played back. These remainder frames should be marked with kCMSampleBufferAttachmentKey_TrimDurationAtEnd. CMSampleBuffers obtained from AVAssetReader will already have the necessary trim attachments. Please see http://developer.apple.com/mac/library/technotes/tn2009/tn2258.html for more information about encoder delay. When attaching trims make sure that the output PTS of the sample buffer is what you expect. For example if you called -[AVAssetWriter startSessionAtSourceTime:kCMTimeZero] and you want your audio to start at time zero in the output file then make sure that the output PTS of the first non-fully trimmed audio sample buffer is kCMTimeZero.
/// 
/// If the sample buffer contains a CVPixelBuffer then the choice of pixel format will affect the performance and quality of the encode. For optimal performance the format of the pixel buffer should match one of the native formats supported by the selected video encoder. Below are some recommendations:
/// 
/// The H.264 and HEVC encoders natively support kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange and kCVPixelFormatType_420YpCbCr8BiPlanarFullRange, which should be used with 8-bit 4:2:0 video and full range input respectively; other related pixel formats in CoreVideo/CVPixelBuffer.h are ideal for 4:2:2 and 4:4:4 (and for HEVC, 10-bit). The JPEG encoder on iOS and Apple Silicon macOS natively supports kCVPixelFormatType_422YpCbCr8FullRange. If you need to work in the RGB domain then kCVPixelFormatType_32BGRA is recommended on iOS and macOS.
/// 
/// Pixel buffers not in a natively supported format will be converted internally prior to encoding when possible. Pixel format conversions within the same range (video or full) are generally faster than conversions between different ranges.
/// 
/// The ProRes encoders can preserve high bit depth sources, supporting up to 12bits/ch. ProRes 4444 can contain a mathematically lossless alpha channel and it doesn't do any chroma subsampling. This makes ProRes 4444 ideal for quality critical applications. If you are working with 8bit sources ProRes is also a good format to use due to its high image quality. Use either of the recommended pixel formats above. Note that RGB pixel formats by definition have 4:4:4 chroma sampling.
/// 
/// If you are working with high bit depth sources the following yuv pixel formats are recommended when encoding to ProRes: kCVPixelFormatType_4444AYpCbCr16, kCVPixelFormatType_422YpCbCr16, and kCVPixelFormatType_422YpCbCr10. When working in the RGB domain kCVPixelFormatType_64ARGB is recommended. Scaling and color matching are not currently supported when using AVAssetWriter with any of these high bit depth pixel formats. Please make sure that your track's output settings dictionary specifies the same width and height as the buffers you will be appending. Do not include AVVideoScalingModeKey or AVVideoColorPropertiesKey.
/// 
/// As of macOS 10.10 and iOS 8.0, this method can be used to add sample buffers that reference existing data in a file instead of containing media data to be appended to the file. This can be used to generate tracks that are not self-contained. In order to append such a sample reference to the track create a CMSampleBufferRef with a NULL dataBuffer and dataReady set to true and set the kCMSampleBufferAttachmentKey_SampleReferenceURL and kCMSampleBufferAttachmentKey_SampleReferenceByteOffset attachments on the sample buffer. Further documentation on how to create such a "sample reference" sample buffer can be found in the description of the kCMSampleBufferAttachmentKey_SampleReferenceURL and kCMSampleBufferAttachmentKey_SampleReferenceByteOffset attachment keys in the CMSampleBuffer documentation.
/// 
/// Before calling this method, you must ensure that the receiver is attached to an AVAssetWriter via a prior call to -addInput: and that -startWriting has been called on the asset writer. It is an error to invoke this method before starting a session (via -[AVAssetWriter startSessionAtSourceTime:]) or after ending a session (via -[AVAssetWriter endSessionAtSourceTime:]).
/// 
/// This method throws an exception if the sample buffer's media type does not match the asset writer input's media type.
/// 
/// - Parameter sampleBuffer: The CMSampleBuffer to be appended.
/// 
/// - Returns: A BOOL value indicating success of appending the sample buffer. If a result of NO is returned, clients can check the value of AVAssetWriter.status to determine whether the writing operation completed, failed, or was cancelled.  If the status is AVAssetWriterStatusFailed, AVAsset.error will contain an instance of NSError that describes the failure.
- (BOOL)appendSampleBuffer:(CMSampleBufferRef)sampleBuffer
#if __swift__
API_DEPRECATED("Use SampleBufferReceiver.append(_:) instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.1, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED))
API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
;

/// Indicates to the AVAssetWriter that no more buffers will be appended to this input.
/// 
/// Clients that are monitoring each input's readyForMoreMediaData value must call markAsFinished on an input when they are done appending buffers to it. This is necessary to prevent other inputs from stalling, as they may otherwise wait forever for that input's media data, attempting to complete the ideal interleaving pattern.
/// 
/// After invoking this method from the serial queue passed to -requestMediaDataWhenReadyOnQueue:usingBlock:, the receiver is guaranteed to issue no more invocations of the block passed to that method. The same is true of -respondToEachPassDescriptionOnQueue:usingBlock:.
/// 
/// Before calling this method, you must ensure that the receiver is attached to an AVAssetWriter via a prior call to -addInput: and that -startWriting has been called on the asset writer.
- (void)markAsFinished;

@end

API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVAssetWriterInput (AVAssetWriterInputLanguageProperties)

/// Indicates the language to associate with the track corresponding to the receiver, as an ISO 639-2/T language code; can be nil.
/// 
/// Also see extendedLanguageTag below.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
/// 
/// This property throws an exception if a language code is set which does not conform to the ISO 639-2/T language codes.
@property (nonatomic, copy, nullable) NSString *languageCode API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates the language tag to associate with the track corresponding to the receiver, as an IETF BCP 47 (RFC 4646) language identifier; can be nil.
/// 
/// Extended language tags are normally set only when an ISO 639-2/T language code by itself is ambiguous, as in cases in which media data should be distinguished not only by language but also by the regional dialect in use or the writing system employed.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
/// 
/// This property throws an exception if an extended language tag is set which does not conform to the IETF BCP 47 (RFC 4646) language identifiers.
@property (nonatomic, copy, nullable) NSString *extendedLanguageTag API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end

API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVAssetWriterInput (AVAssetWriterInputPropertiesForVisualCharacteristic)

/// The size specified in the output file as the natural dimensions of the visual media data for display purposes.
/// 
/// If the default value, CGSizeZero, is specified, the naturalSize of the track corresponding to the receiver is set according to dimensions indicated by the format descriptions that are ultimately written to the output track.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
@property (nonatomic) CGSize naturalSize API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// The transform specified in the output file as the preferred transformation of the visual media data for display purposes.
/// 
/// If no value is specified, the identity transform is used.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
@property (nonatomic) CGAffineTransform transform;

@end

API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVAssetWriterInput (AVAssetWriterInputPropertiesForAudibleCharacteristic)

/// The preferred volume level to be stored in the output file.
/// 
/// The value for this property should typically be in the range of 0.0 to 1.0. The default value is 1.0, which is equivalent to a "normal" volume level for audio media type. For all other media types the default value is 0.0.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
@property (nonatomic) float preferredVolume API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end

API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVAssetWriterInput (AVAssetWriterInputFileTypeSpecificProperties)

/// For file types that support enabled and disabled tracks, such as QuickTime Movie files, specifies whether the track corresponding to the receiver should be enabled by default for playback and processing. The default value is YES.
/// 
/// When an input group is added to an AVAssetWriter (see -[AVAssetWriter addInputGroup:]), the value of marksOutputTrackAsEnabled will automatically be set to YES for the default input and set to NO for all of the other inputs in the group. In this case, if a new value is set on this property then an exception will be raised.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
/// 
/// This property throws an exception if a value is set on an asset writer input that is contained in an input group.
@property (nonatomic) BOOL marksOutputTrackAsEnabled API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// For file types that support media time scales, such as QuickTime Movie files, specifies the media time scale to be used.
/// 
/// The default value is 0, which indicates that the receiver should choose a convenient value, if applicable. It is an error to set a value other than 0 if the receiver has media type AVMediaTypeAudio.
/// 
/// This property cannot be set after writing has started.
/// 
/// This property throws an exception if a value is set on an asset writer input with media type AVMediaTypeAudio.
@property (nonatomic) CMTimeScale mediaTimeScale API_AVAILABLE(macos(10.7), ios(4.3), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// For file types that support media chunk duration, such as QuickTime Movie files, specifies the duration to be used for each chunk of sample data in the output file.
/// 
/// Chunk duration can influence the granularity of the I/O performed when reading a media file, e.g. during playback. A larger chunk duration can result in fewer reads from disk, at the potential expense of a higher memory footprint.
/// 
/// A "chunk" contains one or more samples. The total duration of the samples in a chunk is no greater than this preferred chunk duration, or the duration of a single sample if the sample's duration is greater than this preferred chunk duration.
/// 
/// The default value is kCMTimeInvalid, which means that the receiver will choose an appropriate default value.
/// 
/// This property cannot be set after -startWriting has been called on the receiver.
/// 
/// This property throws an exception if a duration is set which is non-numeric or non-positive (see CMTIME_IS_NUMERIC).
@property (nonatomic) CMTime preferredMediaChunkDuration API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// For file types that support media chunk alignment, such as QuickTime Movie files, specifies the boundary for media chunk alignment in bytes (e.g. 512).
/// 
/// The default value is 0, which means that the receiver will choose an appropriate default value. A value of 1 implies that no padding should be used to achieve a particular chunk alignment. It is an error to set a negative value for chunk alignment.
/// 
/// This property cannot be set after -startWriting has been called on the receiver.
@property (nonatomic) NSInteger preferredMediaChunkAlignment API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// For file types that support writing sample references, such as QuickTime Movie files, specifies the base URL sample references are relative to.
/// 
/// If the value of this property can be resolved as an absolute URL, the sample locations written to the file when appending sample references will be relative to this URL. The URL must point to a location that is in a directory that is a parent of the sample reference location. 
/// 
/// Usage example:
/// 
/// Setting the sampleReferenceBaseURL property to "file:///User/johnappleseed/Movies/" and appending sample buffers with the kCMSampleBufferAttachmentKey_SampleReferenceURL attachment set to "file:///User/johnappleseed/Movies/data/movie1.mov" will cause the sample reference "data/movie1.mov" to be written to the movie.
/// 
/// If the value of the property cannot be resolved as an absolute URL or if it points to a location that is not in a parent directory of the sample reference location, the location referenced in the sample buffer will be written unmodified.
/// 
/// The default value is nil, which means that the location referenced in the sample buffer will be written unmodified.
/// 
/// This property cannot be set after -startWriting has been called on the receiver.
@property (nonatomic, copy, nullable) NSURL *sampleReferenceBaseURL API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

typedef NSString *AVAssetWriterInputMediaDataLocation NS_STRING_ENUM API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates that the media data should be interleaved with all other media data with this constant.
AVF_EXPORT AVAssetWriterInputMediaDataLocation const AVAssetWriterInputMediaDataLocationInterleavedWithMainMediaData API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates that the media data should be laid out before all the media data with AVAssetWriterInputMediaDataLocationInterleavedWithMainMediaData and not be interleaved.
AVF_EXPORT AVAssetWriterInputMediaDataLocation const AVAssetWriterInputMediaDataLocationBeforeMainMediaDataNotInterleaved API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates that there may be large segments of time without any media data from this track. When mediaDataLocation is set to this value, AVAssetWriter will interleave the media data, but will not wait for media data from this track to achieve tight interleaving with other tracks.
AVF_EXPORT AVAssetWriterInputMediaDataLocation const AVAssetWriterInputMediaDataLocationSparselyInterleavedWithMainMediaData API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

/// Specifies where the media data will be laid out and whether the media data will be interleaved as the main media data.
/// 
/// If this value is set to AVAssetWriterInputMediaDataLocationBeforeMainMediaDataNotInterleaved, AVAssetWriter tries to write the media data for this track before all the media data for AVAssetWriterInputs with this property set to AVAssetWriterInputMediaDataLocationInterleavedWithMainMediaData.
/// 
/// Use of this property is recommended for optimizing tracks that contain a small amount of data that is needed all at once, independent of playback time, such as chapter name tracks and chapter image tracks.
/// Keep it set to AVAssetWriterInputMediaDataLocationInterleavedWithMainMediaData for tracks whose media data that's needed only as its presentation time is approaching and, when multiple inputs are present that supply media data that will be played concurrently, should be interleaved for optimal access.
/// 
/// For file types that support preloading media data such as QuickTime movie file, if this value is set to AVAssetWriterInputMediaDataLocationBeforeMainMediaDataNotInterleaved, AVAssetWriter will write an indication such as 'load' atom that the whole media data should be preloaded.
/// 
/// The default value is AVAssetWriterInputMediaDataLocationInterleavedWithMainMediaData, which means that the receiver will not write the indication and that the media data will be interleaved.
/// 
/// This property cannot be set after -startWriting has been called on the receiver.
@property (nonatomic, copy) AVAssetWriterInputMediaDataLocation mediaDataLocation API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end

API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVAssetWriterInput (AVAssetWriterInputTrackAssociations)

/// Tests whether an association between the tracks corresponding to a pair of inputs is valid.
/// 
/// If the type of association requires tracks of specific media types that don't match the media types of the inputs, or if the output file type does not support track associations, -canAddTrackAssociationWithTrackOfInput:type: will return NO.
/// 
/// - Parameter input: The instance of AVAssetWriterInput with a corresponding track to associate with track corresponding with the receiver.
/// - Parameter trackAssociationType: The type of track association to test. Common track association types, such as AVTrackAssociationTypeTimecode, are defined in AVAssetTrack.h.
- (BOOL)canAddTrackAssociationWithTrackOfInput:(AVAssetWriterInput *)input type:(NSString *)trackAssociationType API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Associates the track corresponding to the specified input with the track corresponding with the receiver.
/// 
/// If the type of association requires tracks of specific media types that don't match the media types of the inputs, or if the output file type does not support track associations, an NSInvalidArgumentException is raised.
/// 
/// Track associations cannot be added after writing on the receiver's AVAssetWriter has started.
/// 
/// This method throws an exception if the input and track association type cannot be added (see -canAddTrackAssociationWithTrackOfInput:type:).
/// 
/// - Parameter input: The instance of AVAssetWriterInput with a corresponding track to associate with track corresponding to the receiver.
/// - Parameter trackAssociationType: The type of track association to add. Common track association types, such as AVTrackAssociationTypeTimecode, are defined in AVAssetTrack.h.
- (void)addTrackAssociationWithTrackOfInput:(AVAssetWriterInput *)input type:(NSString *)trackAssociationType API_AVAILABLE(macos(10.9), ios(7.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end


@class AVAssetWriterInputPassDescription;

API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVAssetWriterInput (AVAssetWriterInputMultiPass)

/// Indicates whether the input should attempt to encode the source media data using multiple passes.
/// 
/// The input may be able to achieve higher quality and/or lower data rate by performing multiple passes over the source media. It does this by analyzing the media data that has been appended and re-encoding certain segments with different parameters. In order to do this re-encoding, the media data for these segments must be appended again. See -markCurrentPassAsFinished and the property currentPassDescription for the mechanism by which the input nominates segments for re-appending.
/// 
/// When the value of this property is YES, the value of readyForMoreMediaData for other inputs attached to the same AVAssetWriter may be NO more often and/or for longer periods of time. In particular, the value of readyForMoreMediaData for inputs that do not (or cannot) perform multiple passes may start out as NO after -[AVAssetWriter startWriting] has been called and may not change to YES until after all multi-pass inputs have completed their final pass.
/// 
/// When the value of this property is YES, the input may store data in one or more temporary files before writing compressed samples to the output file. Use the AVAssetWriter property directoryForTemporaryFiles if you need to control the location of temporary file writing.
/// 
/// The default value is NO, meaning that no additional analysis will occur and no segments will be re-encoded. Not all asset writer input configurations (for example, inputs configured with certain media types or to use certain encoders) can benefit from performing multiple passes over the source media. To determine whether the selected encoder can perform multiple passes, query the value of canPerformMultiplePasses after calling -startWriting.
/// 
/// For best results, do not set both this property and expectsMediaDataInRealTime to YES.
/// 
/// This property cannot be set after writing on the receiver's AVAssetWriter has started.
@property (nonatomic) BOOL performsMultiPassEncodingIfSupported API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Indicates whether the input might perform multiple passes over appended media data.
/// 
/// When the value for this property is YES, your source for media data should be configured for random access. After appending all of the media data for the current pass (as specified by the currentPassDescription property), call -markCurrentPassAsFinished to start the process of determining whether additional passes are needed. Note that it is still possible in this case for the input to perform only the initial pass, if it determines that there will be no benefit to performing multiple passes.
/// 
/// When the value for this property is NO, your source for media data only needs to support sequential access. In this case, append all of the source media once and call -markAsFinished.
/// 
/// In the default configuration of AVAssetWriterInput, the value for this property will be NO. Currently the only way for this property to become YES is when performsMultiPassEncodingIfSupported has been set to YES. The final value will be available after -startWriting is called, when a specific encoder has been choosen.
/// 
/// This property is key-value observable.
@property (nonatomic, readonly) BOOL canPerformMultiplePasses API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Provides an object that describes the requirements, such as source time ranges to append or re-append, for the current pass.
/// 
/// If the value of this property is nil, it means there is no request to be fulfilled and -markAsFinished should be called on the asset writer input.
/// 
/// During the first pass, the request will contain a single time range from zero to positive infinity, indicating that all media from the source should be appended. This will also be true when canPerformMultiplePasses is NO, in which case only one pass will be performed.
/// 
/// The value of this property will be nil before -startWriting is called on the attached asset writer. It will transition to an initial non-nil value during the call to -startWriting. After that, the value of this property will change only after a call to -markCurrentPassAsFinished. For an easy way to be notified at the beginning of each pass, see -respondToEachPassDescriptionOnQueue:usingBlock:.
/// 
/// This property is key-value observable. Observers should not assume that they will be notified of changes on a specific thread.
@property (readonly, nullable) AVAssetWriterInputPassDescription *currentPassDescription API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Instructs the receiver to invoke a client-supplied block whenever a new pass has begun.
/// 
/// A typical block passed to this method will perform the following steps:
/// 
/// 1. Query the value of the receiver's currentPassDescription property and reconfigure the source of media data (e.g. AVAssetReader) accordingly
/// 2. Call -requestMediaDataWhenReadyOnQueue:usingBlock: to begin appending data for the current pass
/// 3. Exit
/// 
/// When all media data has been appended for the current request, call -markCurrentPassAsFinished to begin the process of determining whether an additional pass is warranted. If an additional pass is warranted, the block passed to this method will be invoked to begin the next pass. If no additional passes are needed, the block passed to this method will be invoked one final time so the client can invoke -markAsFinished in response to the value of currentPassDescription becoming nil.
/// 
/// Before calling this method, you must ensure that the receiver is attached to an AVAssetWriter via a prior call to -addInput: and that -startWriting has been called on the asset writer.
/// 
/// This method throws an exception if called more than once.
/// 
/// - Parameter queue: The queue on which the block should be invoked.
/// - Parameter block: A block the receiver should invoke whenever a new pass has begun.
- (void)respondToEachPassDescriptionOnQueue:(dispatch_queue_t)queue usingBlock:(dispatch_block_t NS_SWIFT_SENDABLE)block API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

/// Instructs the receiver to analyze the media data that has been appended and determine whether the results could be improved by re-encoding certain segments.
/// 
/// When the value of canPerformMultiplePasses is YES, call this method after you have appended all of your media data. After the receiver analyzes whether an additional pass is warranted, the value of currentPassDescription will change (usually asynchronously) to describe how to set up for the next pass. Although it is possible to use key-value observing to determine when the value of currentPassDescription has changed, it is typically more convenient to invoke -respondToEachPassDescriptionOnQueue:usingBlock: in order to start the work for each pass.
/// 
/// After re-appending the media data for all of the time ranges of the new pass, call this method again to determine whether additional segments should be re-appended in another pass.
/// 
/// Calling this method effectively cancels any previous invocation of -requestMediaDataWhenReadyOnQueue:usingBlock:, meaning that -requestMediaDataWhenReadyOnQueue:usingBlock: can be invoked again for each new pass. -respondToEachPassDescriptionOnQueue:usingBlock: provides a convenient way to consolidate these invocations in your code.
/// 
/// After each pass, you have the option of keeping the most recent results by calling -markAsFinished instead of this method. If the value of currentPassDescription is nil at the beginning of a pass, call -markAsFinished to tell the receiver to not expect any further media data.
/// 
/// If the value of canPerformMultiplePasses is NO, the value of currentPassDescription will immediately become nil after calling this method.
/// 
/// Before calling this method, you must ensure that the receiver is attached to an AVAssetWriter via a prior call to -addInput: and that -startWriting has been called on the asset writer.
- (void)markCurrentPassAsFinished API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos);

@end


@class AVAssetWriterInputPassDescriptionInternal;

/// Defines an interface for querying information about the requirements of the current pass, such as the time ranges of media data to append.
/// 
/// Subclasses of this type that are used from Swift must fulfill the requirements of a Sendable type.
NS_SWIFT_SENDABLE
API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
@interface AVAssetWriterInputPassDescription : NSObject
{
@private
	AVAssetWriterInputPassDescriptionInternal *_internal;
}
AV_INIT_UNAVAILABLE

/// An NSArray of NSValue objects wrapping CMTimeRange structures, each representing one source time range.
/// 
/// The value of this property is suitable for using as a parameter for -[AVAssetReaderOutput resetForReadingTimeRanges:].
@property (nonatomic, readonly) NSArray<NSValue *> *sourceTimeRanges;

@end


@class AVAssetWriterInputPixelBufferAdaptorInternal;

/// Defines an interface for appending video samples packaged as CVPixelBuffer objects to a single AVAssetWriterInput object.
/// 
/// Instances of AVAssetWriterInputPixelBufferAdaptor provide a CVPixelBufferPool that can be used to allocate pixel buffers for writing to the output file. Using the provided pixel buffer pool for buffer allocation is typically more efficient than appending pixel buffers allocated using a separate pool.
#if __swift__
API_DEPRECATED("Use AVAssetWriter.inputPixelBufferReceiver(for:pixelBufferAttributes:) instead", macos(10.7, API_TO_BE_DEPRECATED), ios(4.1, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED))
API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.7), ios(4.1), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
@interface AVAssetWriterInputPixelBufferAdaptor : NSObject
{
@private
	AVAssetWriterInputPixelBufferAdaptorInternal	*_internal;
}
AV_INIT_UNAVAILABLE

/// Creates a new pixel buffer adaptor to receive pixel buffers for writing to the output file.
/// 
/// In order to take advantage of the improved efficiency of appending buffers created from the adaptor's pixel buffer pool, clients should specify pixel buffer attributes that most closely accommodate the source format of the video frames being appended.
/// 
/// Pixel buffer attributes keys for the pixel buffer pool are defined in <CoreVideo/CVPixelBuffer.h>. To specify the pixel format type, the pixelBufferAttributes dictionary should contain a value for kCVPixelBufferPixelFormatTypeKey. For example, use [NSNumber numberWithInt:kCVPixelFormatType_32BGRA] for 8-bit-per-channel BGRA. See the discussion under appendPixelBuffer:withPresentationTime: for advice on choosing a pixel format.
/// 
/// Clients that do not need a pixel buffer pool for allocating buffers should set sourcePixelBufferAttributes to nil.
/// 
/// This method throws an exception if the input is already attached to another asset writer input pixel buffer adaptor or if the input has already started writing (the asset writer has progressed beyond AVAssetWriterStatusUnknown).
/// 
/// - Parameter input: An instance of AVAssetWriterInput to which the receiver should append pixel buffers. Currently, only asset writer inputs that accept media data of type AVMediaTypeVideo can be used to initialize a pixel buffer adaptor.
/// - Parameter sourcePixelBufferAttributes: Specifies the attributes of pixel buffers that will be vended by the input's CVPixelBufferPool.
/// 
/// - Returns: An instance of AVAssetWriterInputPixelBufferAdaptor.
+ (instancetype)assetWriterInputPixelBufferAdaptorWithAssetWriterInput:(AVAssetWriterInput *)input sourcePixelBufferAttributes:(nullable NSDictionary<NSString *, id> *)sourcePixelBufferAttributes;

/// Creates a new pixel buffer adaptor to receive pixel buffers for writing to the output file.
/// 
/// In order to take advantage of the improved efficiency of appending buffers created from the adaptor's pixel buffer pool, clients should specify pixel buffer attributes that most closely accommodate the source format of the video frames being appended.
/// 
/// Pixel buffer attributes keys for the pixel buffer pool are defined in <CoreVideo/CVPixelBuffer.h>. To specify the pixel format type, the pixelBufferAttributes dictionary should contain a value for kCVPixelBufferPixelFormatTypeKey. For example, use [NSNumber numberWithInt:kCVPixelFormatType_32BGRA] for 8-bit-per-channel BGRA. See the discussion under appendPixelBuffer:withPresentationTime: for advice on choosing a pixel format.
/// 
/// Clients that do not need a pixel buffer pool for allocating buffers should set sourcePixelBufferAttributes to nil.
/// 
/// This method throws an exception if the input is already attached to another asset writer input pixel buffer adaptor or if the input has already started writing (the asset writer has progressed beyond AVAssetWriterStatusUnknown).
/// 
/// - Parameter input: An instance of AVAssetWriterInput to which the receiver should append pixel buffers. Currently, only asset writer inputs that accept media data of type AVMediaTypeVideo can be used to initialize a pixel buffer adaptor.
/// - Parameter sourcePixelBufferAttributes: Specifies the attributes of pixel buffers that will be vended by the input's CVPixelBufferPool.
/// 
/// - Returns: An instance of AVAssetWriterInputPixelBufferAdaptor.
- (instancetype)initWithAssetWriterInput:(AVAssetWriterInput *)input sourcePixelBufferAttributes:(nullable NSDictionary<NSString *, id> *)sourcePixelBufferAttributes NS_DESIGNATED_INITIALIZER;

/// The asset writer input to which the receiver should append pixel buffers.
@property (nonatomic, readonly) AVAssetWriterInput *assetWriterInput;

/// The pixel buffer attributes of pixel buffers that will be vended by the receiver's CVPixelBufferPool.
/// 
/// The value of this property is a dictionary containing pixel buffer attributes keys defined in <CoreVideo/CVPixelBuffer.h>.
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE sourcePixelBufferAttributes;

/// A pixel buffer pool that will vend and efficiently recycle CVPixelBuffer objects that can be appended to the receiver.
/// 
/// For maximum efficiency, clients should create CVPixelBuffer objects for appendPixelBuffer:withPresentationTime: by using this pool with the CVPixelBufferPoolCreatePixelBuffer() function.
/// 
/// The value of this property will be NULL before -[AVAssetWriter startWriting] is called on the associated AVAssetWriter object.
/// 
/// This property is key value observable.
/// 
/// This property throws an exception if a pixel buffer pool cannot be created with this asset writer input pixel buffer adaptor's source pixel buffer attributes (must specify width, height, and either pixel format or pixel format description).
@property (nonatomic, readonly, nullable) CVPixelBufferPoolRef pixelBufferPool;

/// Appends a pixel buffer to the receiver.
/// 
/// The receiver will retain the CVPixelBuffer until it is done with it, and then release it. Do not modify a CVPixelBuffer or its contents after you have passed it to this method.
/// 
/// For optimal performance the format of the pixel buffer should match one of the native formats supported by the selected video encoder. Below are some recommendations:
/// 
/// The H.264 and HEVC encoders natively support kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange and kCVPixelFormatType_420YpCbCr8BiPlanarFullRange, which should be used with 8-bit 4:2:0 video and full range input respectively; other related pixel formats in CoreVideo/CVPixelBuffer.h are ideal for 4:2:2 and 4:4:4 (and for HEVC, 10-bit). The JPEG encoder on iOS and Apple Silicon macOS natively supports kCVPixelFormatType_422YpCbCr8FullRange. If you need to work in the RGB domain then kCVPixelFormatType_32BGRA is recommended on iOS and macOS.
/// 
/// Pixel buffers not in a natively supported format will be converted internally prior to encoding when possible. Pixel format conversions within the same range (video or full) are generally faster than conversions between different ranges.
/// 
/// The ProRes encoders can preserve high bit depth sources, supporting up to 12bits/ch. ProRes 4444 can contain a mathematically lossless alpha channel and it doesn't do any chroma subsampling. This makes ProRes 4444 ideal for quality critical applications. If you are working with 8bit sources ProRes is also a good format to use due to its high image quality. Use either of the recommended pixel formats above. Note that RGB pixel formats by definition have 4:4:4 chroma sampling.
/// 
/// If you are working with high bit depth sources the following yuv pixel formats are recommended when encoding to ProRes: kCVPixelFormatType_4444AYpCbCr16, kCVPixelFormatType_422YpCbCr16, and kCVPixelFormatType_422YpCbCr10. When working in the RGB domain kCVPixelFormatType_64ARGB is recommended. Scaling and color matching are not currently supported when using AVAssetWriter with any of these high bit depth pixel formats. Please make sure that your track's output settings dictionary specifies the same width and height as the buffers you will be appending. Do not include AVVideoScalingModeKey or AVVideoColorPropertiesKey.
/// 
/// Before calling this method, you must ensure that the input that underlies the receiver is attached to an AVAssetWriter via a prior call to -addInput: and that -startWriting has been called on the asset writer. It is an error to invoke this method before starting a session (via -[AVAssetWriter startSessionAtSourceTime:]) or after ending a session (via -[AVAssetWriter endSessionAtSourceTime:]).
/// 
/// This method throws an exception if the presentation time is is non-numeric (see CMTIME_IS_NUMERIC) or if "readyForMoreMediaData" is NO.
/// 
/// - Parameter pixelBuffer: The CVPixelBuffer to be appended.
/// - Parameter presentationTime: The presentation time for the pixel buffer to be appended. This time will be considered relative to the time passed to -[AVAssetWriter startSessionAtSourceTime:] to determine the timing of the frame in the output file.
/// 
/// - Returns: A BOOL value indicating success of appending the pixel buffer. If a result of NO is returned, clients can check the value of AVAssetWriter.status to determine whether the writing operation completed, failed, or was cancelled.  If the status is AVAssetWriterStatusFailed, AVAsset.error will contain an instance of NSError that describes the failure.
- (BOOL)appendPixelBuffer:(CVPixelBufferRef)pixelBuffer withPresentationTime:(CMTime)presentationTime;

@end

/// Defines an interface for appending tagged buffer groups packaged as CMTaggedBufferGroupRef objects to a single AVAssetWriterInput object.
/// 
/// Instances of AVAssetWriterInputTaggedPixelBufferGroupAdaptor provide a CVPixelBufferPool that can be used to allocate the pixel buffers of tagged buffer groups for writing to the output file. Using the provided pixel buffer pool for buffer allocation is typically more efficient than appending pixel buffers allocated using a separate pool.
#if __swift__
API_DEPRECATED("Use AVAssetWriter.inputTaggedPixelBufferGroupReceiver(for:pixelBufferAttributes:) instead", macos(14.0, API_TO_BE_DEPRECATED), ios(17.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED))
API_UNAVAILABLE(tvos, watchos)
#else
API_AVAILABLE(macos(14.0), ios(17.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos)
#endif
@interface AVAssetWriterInputTaggedPixelBufferGroupAdaptor : NSObject
AV_INIT_UNAVAILABLE

/// Creates a new tagged buffer adaptor to receive tagged buffer groups for writing to the output file.
/// 
/// In order to take advantage of the improved efficiency of appending buffers created from the adaptor's pixel buffer pool, clients should specify pixel buffer attributes that most closely accommodate the source format of the video frames being appended.
/// 
/// Pixel buffer attributes keys for the pixel buffer pool are defined in <CoreVideo/CVPixelBuffer.h>. To specify the pixel format type, the pixelBufferAttributes dictionary should contain a value for kCVPixelBufferPixelFormatTypeKey. For example, use [NSNumber numberWithInt:kCVPixelFormatType_32BGRA] for 8-bit-per-channel BGRA. See the discussion under appendPixelBuffer:withPresentationTime: for advice on choosing a pixel format.
/// 
/// Clients that do not need a pixel buffer pool for allocating buffers should set sourcePixelBufferAttributes to nil.
/// 
/// This method throws an exception if the input is already attached to another asset writer input tagged buffer group adaptor or if the input has already started writing (the asset writer has progressed beyond AVAssetWriterStatusUnknown).
/// 
/// - Parameter input: An instance of AVAssetWriterInput to which the receiver should append tagged buffer groups. Currently, only asset writer inputs that accept media data of type AVMediaTypeVideo can be used to initialize a tagged buffer adaptor.
/// - Parameter sourcePixelBufferAttributes: Specifies the attributes of pixel buffers of tagged buffer groups that will be vended by the input's CVPixelBufferPool.
/// 
/// - Returns: An instance of AVAssetWriterInputTaggedPixelBufferGroupAdaptor.
+ (instancetype)assetWriterInputTaggedPixelBufferGroupAdaptorWithAssetWriterInput:(AVAssetWriterInput *)input sourcePixelBufferAttributes:(nullable NSDictionary<NSString *, id> *)sourcePixelBufferAttributes;

/// Creates a new tagged buffer group adaptor to receive tagged buffer groups for writing to the output file.
/// 
/// In order to take advantage of the improved efficiency of appending buffers created from the adaptor's pixel buffer pool, clients should specify pixel buffer attributes that most closely accommodate the source format of the video frames of tagged buffer groups being appended.
/// 
/// Pixel buffer attributes keys for the pixel buffer pool are defined in <CoreVideo/CVPixelBuffer.h>. To specify the pixel format type, the pixelBufferAttributes dictionary should contain a value for kCVPixelBufferPixelFormatTypeKey. For example, use [NSNumber numberWithInt:kCVPixelFormatType_32BGRA] for 8-bit-per-channel BGRA. See the discussion under appendPixelBuffer:withPresentationTime: in AVAssetWriterInputPixelBufferAdaptor for advice on choosing a pixel format.
/// 
/// Clients that do not need a pixel buffer pool for allocating buffers should set sourcePixelBufferAttributes to nil.
/// 
/// It is an error to initialize an instance of AVAssetWriterInputTaggedPixelBufferGroupAdaptor with an asset writer input that is already attached to another instance of AVAssetWriterInputTaggedPixelBufferGroupAdaptor. It is also an error to initialize an instance of AVAssetWriterInputTaggedPixelBufferGroupAdaptor with an asset writer input whose asset writer has progressed beyond AVAssetWriterStatusUnknown.
/// 
/// - Parameter input: An instance of AVAssetWriterInput to which the receiver should append tagged buffer groups. In addition to the pixel buffer adaptor, asset writer inputs with media data of type AVMediaTypeVideo can be used to initialize a tagged buffer group adaptor.
/// - Parameter sourcePixelBufferAttributes: Specifies the attributes of pixel buffers of tagged buffer groups that will be vended by the input's CVPixelBufferPool.
/// 
/// - Returns: An instance of AVAssetWriterInputTaggedPixelBufferGroupAdaptor.
- (instancetype)initWithAssetWriterInput:(AVAssetWriterInput *)input sourcePixelBufferAttributes:(nullable NSDictionary<NSString *, id> *)sourcePixelBufferAttributes NS_DESIGNATED_INITIALIZER;

/// The asset writer input to which the receiver should append tagged buffer groups.
@property (nonatomic, readonly) AVAssetWriterInput *assetWriterInput;

/// The pixel buffer attributes of pixel buffers that will be vended by the receiver's CVPixelBufferPool.
/// 
/// The value of this property is a dictionary containing pixel buffer attributes keys defined in <CoreVideo/CVPixelBuffer.h>.
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE sourcePixelBufferAttributes;

/// A pixel buffer pool that will vend and efficiently recycle CVPixelBuffer objects of tagged buffer groups that can be appended to the receiver.
/// 
/// For maximum efficiency, clients should create CVPixelBuffer objects of tagged buffer groups for appendTaggedPixelBufferGroup:withPresentationTime: by using this pool with the CVPixelBufferPoolCreatePixelBuffer() function.
/// 
/// The value of this property will be NULL before -[AVAssetWriter startWriting] is called on the associated AVAssetWriter object. Clients should read this property after -[AVAssetWriter startWriting] calling to get a non-NULL value.
/// 
/// This property is not key value observable.
@property (nonatomic, readonly, nullable) CVPixelBufferPoolRef pixelBufferPool;

/// Appends a tagged buffer group to the receiver.
/// 
/// The receiver will retain the CMTaggedBufferGroup until it is done with it, and then release it. Do not modify a CMTaggedBufferGroup or its contents after you have passed it to this method.
/// 
/// Before calling this method, you must ensure that the input that underlies the receiver is attached to an AVAssetWriter via a prior call to -addInput: and that -startWriting has been called on the asset writer. It is an error to invoke this method before starting a session (via -[AVAssetWriter startSessionAtSourceTime:]) or after ending a session (via -[AVAssetWriter endSessionAtSourceTime:]).
/// 
/// In an AVAssetWriterInput instance creation with AVMediaTypeVideo, kVTCompressionPropertyKey_MVHEVCVideoLayerIDs key must be specified as part of the dictionary given for AVVideoCompressionPropertiesKey. It sets video layer IDs to a target multi-image video encoder. This method checks the values for kCMTagCategory_VideoLayerID tag in tag collections of taggedPixelBufferGroup over the array values for kVTCompressionPropertyKey_MVHEVCVideoLayerIDs key. An NSInvalidArgumentException will be raised if the video layer IDs mismatch between the value of kVTCompressionPropertyKey_MVHEVCVideoLayerIDs in the AVVideoCompressionPropertiesKey sub-dictionary of the input's outputSettings property and tag collections of taggedPixelBufferGroup.
/// 
/// Below is a sample code sketch focusing on data flow that illustrates how you might append a taggedPixelBufferGroup instance.
/// ```objc
/// // Set up an AVAssetWriterInput and AVAssetWriterInputTaggedPixelBufferGroupAdaptor instance
/// AVAssetWriterInput *assetWriterInput = [[AVAssetWriterInput alloc] initWithMediaType:AVMediaTypeVideo outputSettings:@{
/// ..,
/// AVVideoCompressionPropertiesKey: @{ (NSString *)kVTCompressionPropertyKey_MVHEVCVideoLayerIDs : .. }}];
/// 
/// AVAssetWriterInputTaggedPixelBufferGroupAdaptor *assetWriterInputAdaptor = [[AVAssetWriterInputTaggedPixelBufferGroupAdaptor alloc] initWithAssetWriterInput:assetWriterInput ..];
/// ```
/// Later, when the writer input is ready for more media data, create and append a tagged buffer group containing one or more pixel buffers and the exact tag values associated with kCMTagCategory_VideoLayerID being specified via kVTCompressionPropertyKey_MVHEVCVideoLayerIDs.
/// ```objc
/// // Set up tag collection buffers
/// CMTag tags[] = CMTagMakeWithSInt64Value(kCMTagCategory_VideoLayerID, ..);
/// CMItemCount tagCount = sizeof(tags) / sizeof(tags[0]);
/// CMTagCollectionCreate(.., tags, tagCount, &tagCollection);
/// CFArrayAppendValue(tagCollectionArray, tagCollection);
/// 
/// // Set up pixel buffers
/// CVPixelBufferPoolCreatePixelBuffer(.., &pixelBuffer);
/// CFArrayAppendValue(pixelBufferArray, pixelBuffer);
/// 
/// // Append a CMTaggedBufferGroupRef instance to asset writer input
/// CMTaggedBufferGroupCreate(.., tagCollectionArray, pixelBufferArray, &taggedBufferGroup);
/// [assetWriterInputAdaptor appendTaggedPixelBufferGroup:taggedBufferGroup ..];
/// ```
/// - Parameter taggedPixelBufferGroup: The CMTaggedBufferGroup to be appended. All of the buffers in taggedPixelBufferGroup should be CVPixelBuffers, and they should correspond to tag collections that contain kCMTagCategory_VideoLayerID values matching the list set using kVTCompressionPropertyKey_MVHEVCVideoLayerIDs. The pixel buffers should be IOSurface-backed.
/// - Parameter presentationTime: The presentation time for the tagged buffer group to be appended. This time will be considered relative to the time passed to -[AVAssetWriter startSessionAtSourceTime:] to determine the timing of the frame in the output file.
/// 
/// - Returns: A BOOL value indicating success of appending the tagged buffer group. If a result of NO is returned, clients can check the value of AVAssetWriter.status to determine whether the writing operation completed, failed, or was cancelled. If the status is AVAssetWriterStatusFailed, AVAssetWriter.error will contain an instance of NSError that describes the failure.
- (BOOL)appendTaggedPixelBufferGroup:(CMTaggedBufferGroupRef)taggedPixelBufferGroup withPresentationTime:(CMTime)presentationTime;
@end

@class AVTimedMetadataGroup;
@class AVAssetWriterInputMetadataAdaptorInternal;

/// Defines an interface for writing metadata, packaged as instances of AVTimedMetadataGroup, to a single AVAssetWriterInput object.
#if __swift__
API_DEPRECATED("Use AVAssetWriter.inputMetadataReceiver(for:) instead", macos(10.10, API_TO_BE_DEPRECATED), ios(8.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED), visionos(1.0, API_TO_BE_DEPRECATED))
API_UNAVAILABLE(watchos)
#else
API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0), visionos(1.0)) API_UNAVAILABLE(watchos)
#endif
@interface AVAssetWriterInputMetadataAdaptor : NSObject {
    AVAssetWriterInputMetadataAdaptorInternal	*_internal;
}
AV_INIT_UNAVAILABLE

/// Creates a new timed metadata group adaptor to receive instances of AVTimedMetadataGroup for writing to the output file.
/// 
/// The instance of AVAssetWriterInput passed in to this method must have been created with a format hint indicating all possible combinations of identifier (or, alternatively, key and keySpace), dataType, and extendedLanguageTag that will be appended to the metadata adaptor. It is an error to append metadata items not represented in the input's format hint.
/// 
/// This method throws an exception for any of the following reasons:
/// - input is already attached to another instance of AVAssetWriterInputMetadataAdaptor
/// - input's asset writer has already started writing (progressed beyond AVAssetWriterStatusUnknown)
/// - input's asset writer does not carry a source format hint
/// - input's source format hint media subtype is not kCMMetadataFormatType_Boxed
/// 
/// - Parameter input: An instance of AVAssetWriterInput to which the receiver should append groups of timed metadata. Only asset writer inputs that accept media data of type AVMediaTypeMetadata can be used to initialize a timed metadata group adaptor.
/// 
/// - Returns: An instance of AVAssetWriterInputMetadataAdaptor.
+ (instancetype)assetWriterInputMetadataAdaptorWithAssetWriterInput:(AVAssetWriterInput *)input;

/// Creates a new timed metadator group adaptor to receive instances of AVTimedMetadataGroup for writing to the output file.
/// 
/// The instance of AVAssetWriterInput passed in to this method must have been created with a format hint indicating all possible combinations of identifier (or, alternatively, key and keySpace), dataType, and extendedLanguageTag that will be appended to the metadata adaptor. It is an error to append metadata items not represented in the input's format hint. For help creating a suitable format hint, see -[AVTimedMetadataGroup copyFormatDescription].
/// 
/// This method throws an exception for any of the following reasons:
/// - input is already attached to another instance of AVAssetWriterInputMetadataAdaptor
/// - input's asset writer has already started writing (progressed beyond AVAssetWriterStatusUnknown)
/// - input's asset writer does not carry a source format hint
/// - input's source format hint media subtype is not kCMMetadataFormatType_Boxed
/// 
/// - Parameter input: An instance of AVAssetWriterInput to which the receiver should append groups of timed metadata. Only asset writer inputs that accept media data of type AVMediaTypeMetadata can be used to initialize a timed metadata group adaptor.
/// 
/// - Returns: An instance of AVAssetWriterInputMetadataAdaptor.
- (instancetype)initWithAssetWriterInput:(AVAssetWriterInput *)input NS_DESIGNATED_INITIALIZER;

/// The asset writer input to which the receiver should append timed metadata groups.
@property (nonatomic, readonly) AVAssetWriterInput *assetWriterInput;

/// Appends a timed metadata group to the receiver.
/// 
/// The receiver will retain the AVTimedMetadataGroup until it is done with it, and then release it.
/// 
/// The timing of the metadata items in the output asset will correspond to the timeRange of the AVTimedMetadataGroup, regardless of the values of the time and duration properties of the individual items.
/// 
/// Before calling this method, you must ensure that the input that underlies the receiver is attached to an AVAssetWriter via a prior call to -addInput: and that -startWriting has been called on the asset writer. It is an error to invoke this method before starting a session (via -[AVAssetWriter startSessionAtSourceTime:]) or after ending a session (via -[AVAssetWriter endSessionAtSourceTime:]).
/// 
/// This method throws an exception if the attached asset writer input has not been added to an asset writer or -startWriting has not been called on that asset writer.
/// 
/// - Parameter timedMetadataGroup: The AVTimedMetadataGroup to be appended.
/// 
/// - Returns: A BOOL value indicating success of appending the timed metadata group.  If a result of NO is returned, AVAssetWriter.error will contain more information about why apending the timed metadata group failed.
- (BOOL)appendTimedMetadataGroup:(AVTimedMetadataGroup *)timedMetadataGroup;

@end

/// An adaptor class for appending instances of AVCaption to an asset writer input. -[AVAssetWriterInput -appendSampleBuffer:] will throw an exception if used when this adaptor is attached.
#if __swift__
API_DEPRECATED("Use AVAssetWriter.inputCaptionReceiver(for:) instead", macos(12.0, API_TO_BE_DEPRECATED), ios(18.0, API_TO_BE_DEPRECATED), macCatalyst(15.0, API_TO_BE_DEPRECATED))
API_UNAVAILABLE(tvos, watchos, visionos)
#else
API_AVAILABLE(macos(12.0), ios(18.0), macCatalyst(15.0)) API_UNAVAILABLE(tvos, watchos, visionos)
#endif
@interface AVAssetWriterInputCaptionAdaptor : NSObject
{
@private
	AVAssetWriterInputCaptionAdaptorInternal *_internal;
}
AV_INIT_UNAVAILABLE

/// Creates a new caption adaptor for writing to the specified asset writer input.
+ (instancetype)assetWriterInputCaptionAdaptorWithAssetWriterInput:(AVAssetWriterInput *)input;

/// Creates a new caption adaptor for writing to the specified asset writer input.
/// 
/// This method thows an exception for any of the following reasons:
/// - input is nil
/// - the input's media type is not supported (should use text or closed caption)
/// - the input is already attached to an asset writer caption adaptor
/// - the input has already started writing
- (instancetype)initWithAssetWriterInput:(AVAssetWriterInput *)input;

/// The asset writer input that was used to initialize the receiver.
@property (nonatomic, readonly) AVAssetWriterInput *assetWriterInput;

/// Append a single caption to be written.
/// 
/// If this method returns NO, check the value of AVAssetWriter.status on the attached asset writer to determine why appending failed.
/// 
/// The start time of each caption's timeRange property must be numeric (see CMTIME_IS_NUMERIC) and must be at least as large as the start time of any previous caption (including any captions present in a group appended via -appendCaptionGroup:). In other words, the sequence of captions appended using this method must have monotonically increasing start times.
/// 
/// The duration of each caption's timeRange property must be numeric.
/// 
/// - Parameter caption: The caption to append.
/// 
/// - Returns: Returns YES if the operation succeeded, NO if it failed.
- (BOOL)appendCaption:(AVCaption *)caption;

/// Append a group of captions to be written.
/// 
/// If this method returns NO, check the value of AVAssetWriter.status on the attached asset writer to determine why appending failed.
/// When appending a sequence of captions groups, the start time of each group must be equal to or greater than the end time of any previous group. The easiest way to achieve this is to create the group using a caption whose duration is kCMTimeInvalid, in which case the duration will be determined by subtracting the start time of the group from the start time of the next appended group.
/// When mixing calls to -appendCaptionGroup: and -appendCaption:, the start time of each group must be equal to or greater than the end time of any previous captions.
/// To mark a time range containing no captions, append a group containing an empty caption array.
/// 
/// - Parameter captionGroup:
/// 
/// - Returns: Returns YES if the operation succeeded, NO if it failed.
- (BOOL)appendCaptionGroup:(AVCaptionGroup *)captionGroup;

@end

NS_ASSUME_NONNULL_END

#else
#import <AVFCore/AVAssetWriterInput.h>
#endif
