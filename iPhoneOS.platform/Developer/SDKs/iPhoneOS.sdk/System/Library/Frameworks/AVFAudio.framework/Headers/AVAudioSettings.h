/*
	File:  AVAudioSettings.h
	
	Framework:  AVFoundation
	
	Copyright 2008-2013 Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Availability.h>

/* This file's methods are available with iPhone 3.0 or later */

/* property keys - values for all keys defined below are NSNumbers */

/* keys for all formats */
extern NSString *const AVFormatIDKey								API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0));  /* value is an integer (format ID) from CoreAudioTypes.h */
extern NSString *const AVSampleRateKey				    			API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0));  /* value is floating point in Hertz */
extern NSString *const AVNumberOfChannelsKey 		    			API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0));  /* value is an integer */

/* linear PCM keys */
extern NSString *const AVLinearPCMBitDepthKey		    			API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0));  /* value is an integer, one of: 8, 16, 24, 32 */
extern NSString *const AVLinearPCMIsBigEndianKey 	    			API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0));  /* value is a BOOL */
extern NSString *const AVLinearPCMIsFloatKey		    			API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0));  /* value is a BOOL */

extern NSString *const AVLinearPCMIsNonInterleaved                  API_AVAILABLE(macos(10.7), ios(4.0), watchos(2.0), tvos(9.0));   /* value is a BOOL */
#define AVLinearPCMIsNonInterleavedKey AVLinearPCMIsNonInterleaved

/* audio file type key */
extern NSString *const AVAudioFileTypeKey                           API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0)); /* value is an integer (audio file type) from AudioFile.h */

/* encoder property keys */
extern NSString *const AVEncoderAudioQualityKey					    API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0)); /* value is an integer from enum AVAudioQuality */
extern NSString *const AVEncoderAudioQualityForVBRKey               API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)); /* value is an integer from enum AVAudioQuality. only relevant for AVAudioBitRateStrategy_Variable */

	/* only one of AVEncoderBitRateKey and AVEncoderBitRatePerChannelKey should be provided. */
extern NSString *const AVEncoderBitRateKey                 			API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0)); /* value is an integer. */
extern NSString *const AVEncoderBitRatePerChannelKey                API_AVAILABLE(macos(10.7), ios(4.0), watchos(2.0), tvos(9.0)); /* value is an integer */
extern NSString *const AVEncoderBitRateStrategyKey                  API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)); /* value is an AVAudioBitRateStrategy constant. see below. */
extern NSString *const AVEncoderBitDepthHintKey					    API_AVAILABLE(macos(10.7), ios(3.0), watchos(3.0), tvos(9.0)); /* value is an integer from 8 to 32 */

/* DRC/loudness encoder property keys */
extern NSString *const AVEncoderDynamicRangeControlConfigurationKey        API_AVAILABLE(macos(26.0), ios(26.0), watchos(26.0), tvos(26.0)); /* value is an AVAudioDynamicRangeControlConfiguration constant - see below. */
extern NSString *const AVEncoderContentSourceKey                    API_AVAILABLE(macos(26.0), ios(26.0), watchos(26.0), tvos(26.0)); /* value is an AVAudioContentSource constant - see below. */

/* Audio Synchronization Packet encoder property keys */
extern NSString *const AVEncoderASPFrequencyKey                     API_AVAILABLE(macos(26.0), ios(26.0), watchos(26.0), tvos(26.0)); /* value is an integer larger than 2. Recommended value is 75 */

/* sample rate converter property keys */
extern NSString *const AVSampleRateConverterAlgorithmKey            API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)); /* value is an AVSampleRateConverterAlgorithm constant. see below. */
extern NSString *const AVSampleRateConverterAudioQualityKey 		API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)); /* value is an integer from enum AVAudioQuality */

/* channel layout */
extern NSString *const AVChannelLayoutKey                           API_AVAILABLE(macos(10.7), ios(4.0), watchos(2.0), tvos(9.0));	/* value is an NSData containing an AudioChannelLayout */


/* property values */

/* values for AVEncoderBitRateStrategyKey */
extern NSString *const AVAudioBitRateStrategy_Constant              API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0));
extern NSString *const AVAudioBitRateStrategy_LongTermAverage       API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0));
extern NSString *const AVAudioBitRateStrategy_VariableConstrained   API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0));
extern NSString *const AVAudioBitRateStrategy_Variable              API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0));

/* values for AVSampleRateConverterAlgorithmKey */
extern NSString *const AVSampleRateConverterAlgorithm_Normal        API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0));
extern NSString *const AVSampleRateConverterAlgorithm_Mastering     API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0));
extern NSString *const AVSampleRateConverterAlgorithm_MinimumPhase  API_AVAILABLE(macos(10.12), ios(10.0), watchos(3.0), tvos(10.0));

typedef NS_ENUM(NSInteger, AVAudioQuality) {
	AVAudioQualityMin    = 0,
	AVAudioQualityLow    = 0x20,
	AVAudioQualityMedium = 0x40,
	AVAudioQualityHigh   = 0x60,
	AVAudioQualityMax    = 0x7F
};

typedef NS_ENUM(NSInteger, AVAudioDynamicRangeControlConfiguration) {
    AVAudioDynamicRangeControlConfiguration_None    = 0,
    AVAudioDynamicRangeControlConfiguration_Music   = 1,
    AVAudioDynamicRangeControlConfiguration_Speech  = 2,
    AVAudioDynamicRangeControlConfiguration_Movie   = 3,
    AVAudioDynamicRangeControlConfiguration_Capture = 4
};

/*  Constants to be used with AVAudioContentSource to indicate the content type */
typedef NS_ENUM(NSInteger, AVAudioContentSource) {
    AVAudioContentSource_Unspecified                   = -1,
    AVAudioContentSource_Reserved                      = 0,
    AVAudioContentSource_AppleCapture_Traditional      = 1,  /* Traditional Apple device capture */
    AVAudioContentSource_AppleCapture_Spatial          = 2,  /* Spatial Apple device capture */
    AVAudioContentSource_AppleCapture_Spatial_Enhanced = 3,  /* Reserved for Apple use */
    AVAudioContentSource_AppleMusic_Traditional        = 4,  /* Traditional Apple music and music video content such as stereo and multichannel */
    AVAudioContentSource_AppleMusic_Spatial            = 5,  /* Spatial Apple music and music video content */
    AVAudioContentSource_AppleAV_Traditional_Offline   = 6,  /* Traditional Apple professional AV offline encoded content such as stereo and multichannel */
    AVAudioContentSource_AppleAV_Spatial_Offline       = 7,  /* Spatial Apple professional AV offline encoded content */
    AVAudioContentSource_AppleAV_Traditional_Live      = 8,  /* Traditional Apple professional AV live content such as stereo and multichannel */
    AVAudioContentSource_AppleAV_Spatial_Live          = 9,  /* Spatial Apple professional AV live content */
    AVAudioContentSource_ApplePassthrough              = 10, /* Apple passthrough content (use only if source information is not available) */

    AVAudioContentSource_Capture_Traditional           = 33, /* Traditional device capture */
    AVAudioContentSource_Capture_Spatial               = 34, /* Spatial device capture */
    AVAudioContentSource_Capture_Spatial_Enhanced      = 35, /* Reserved for future use */
    AVAudioContentSource_Music_Traditional             = 36, /* Traditional music and music video content such as stereo and multichannel */
    AVAudioContentSource_Music_Spatial                 = 37, /* Spatial music and music video content */
    AVAudioContentSource_AV_Traditional_Offline        = 38, /* Traditional professional AV offline encoded content such as stereo and multichannel */
    AVAudioContentSource_AV_Spatial_Offline            = 39, /* Spatial professional AV offline encoded content */
    AVAudioContentSource_AV_Traditional_Live           = 40, /* Traditional professional AV live content such as stereo and multichannel */
    AVAudioContentSource_AV_Spatial_Live               = 41, /* Spatial professional AV live content */
    AVAudioContentSource_Passthrough                   = 42  /* Passthrough content (use only if source information is not available) */
}   API_AVAILABLE(macos(26.0), ios(26.0), watchos(26.0), tvos(26.0));
