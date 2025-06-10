#if !__has_include(<AVFCapture/AVCaptureSpatialAudioMetadataSampleGenerator.h>)
/*
    File:		AVCaptureSpatialAudioMetadataSampleGenerator.h
 
    Framework:  AVFoundation
 
    Copyright 2025 Apple Inc. All rights reserved.
*/

#import <AVFoundation/AVBase.h>

#import <CoreMedia/CMSampleBuffer.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class AVCaptureSpatialAudioMetadataSampleGenerator
 @abstract
	Defines an interface for generating a spatial audio timed metadata sample.
 */

API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(macos, macCatalyst, tvos, visionos) API_UNAVAILABLE(watchos)
@interface AVCaptureSpatialAudioMetadataSampleGenerator : NSObject

/*!
 @property timedMetadataSampleBufferFormatDescription
 @abstract
    Returns the CMFormatDescription that will be specified by the buffer returned from the createTimedMetadataSampleBuffer method.
 
 @discussion
    Clients can use this format description when creating their AVAssetWriter track that will contain the metadata.
*/
@property(readonly, nonatomic) CMFormatDescriptionRef timedMetadataSampleBufferFormatDescription;

/*!
 @method analyzeAudioSample:
 @abstract
    Analyzes the audio sample buffer for its contribution to the spatial audio timed metadata value.
 
 @param sbuf
	An CMSampleBuffer containing spatial audio.
 @result
	Returns noErr if the sample was able to be analyzed.
 
 @discussion
    All of the spatial audio sample buffer that given to an AVAssetWriter need to be analyzed for the generation of the proper spatial audio timed metadata value.
 */
- (OSStatus)analyzeAudioSample:(CMSampleBufferRef)sbuf;

/*!
 @method newTimedMetadataSampleBufferAndResetAnalyzer
 @abstract
    Returns a CMSampleBuffer containing a spatial audio timed metadata sample containing the value computed from all of the prior audio sample buffers passed to analyzeAudioSample:. The analyzer is also reset to its initial state, making it ready for a new run of sample buffers.
 
 @result
	Returns an CMSampleBuffer that contains the spatial audio timed metadata sample. If no value can be computed, NULL will be returned.
 
 @discussion
    This method is to be called after the last audio sample buffer has been passed to the client's AVAssetWriterInput for audio. The returned CMSampleBuffer can be passed directly to the client's AVAssetWriterInput for the audio timed metadata track. Note that it is expected that one and only one sample buffer be present in the timed metadata track.
 */
- (nullable CMSampleBufferRef)newTimedMetadataSampleBufferAndResetAnalyzer;

/*!
 @method resetAnalyzer
 @abstract
    Calling this method will reset the analyzer to its initial state so that a new run of audio sample buffers can be analyzed.
 
 @discussion
    If the client needs to abort generating the audio timed metadata buffer for audio buffers already given to analyzeAudioSample:, calling this method is required to prepare the analyzer for a new run of sample buffers.
 */
- (void)resetAnalyzer;

@end

NS_ASSUME_NONNULL_END

#else
#import <AVFCapture/AVCaptureSpatialAudioMetadataSampleGenerator.h>
#endif
