/*
	File:  VTFrameProcessor_SuperResolutionScaler.h
 
	Framework:  VideoToolbox
 
	Copyright 2023-2024 Apple Inc. All rights reserved.
 
*/

#ifndef VTFRAMEPROCESSOR_SUPERRESOLUTION_H
#define VTFRAMEPROCESSOR_SUPERRESOLUTION_H

#include <CoreMedia/CMBase.h>

#if ! TARGET_OS_SIMULATOR
#ifdef __OBJC__

#import <VideoToolbox/VTFrameProcessorConfiguration.h>
#import <VideoToolbox/VTFrameProcessorParameters.h>
#import <VideoToolbox/VTFrameProcessorFrame.h>

/*!
    @brief Interfaces for creating and using a SuperResolution processor

    @details The VTSuperResolutionScaler processor Configuration and Parameters objects are used with the VTFrameProcessor interface defined in VTFrameProcessor.h.
 */

/*!
 @brief Quality prioritization levels to favor quality or performance.
*/
API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(tvos, visionos, watchos)
typedef NS_ENUM(NSInteger, VTSuperResolutionScalerConfigurationQualityPrioritization) {
	VTSuperResolutionScalerConfigurationQualityPrioritizationNormal = 1,
} NS_SWIFT_NAME(VTSuperResolutionScalerConfiguration.QualityPrioritization);

/*!
 @brief List of existing algorithm revisions with the highest being the latest. Clients can read defaultRevision property to find the default revision.
 */
API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(tvos, visionos, watchos)
typedef NS_ENUM(NSInteger, VTSuperResolutionScalerConfigurationRevision) {
	VTSuperResolutionScalerConfigurationRevision1           = 1,    // revision 1
} NS_SWIFT_NAME(VTSuperResolutionScalerConfiguration.Revision);

/*!
@brief List of SuperResolution  input types.
*/
API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(tvos, visionos, watchos)
typedef NS_ENUM(NSInteger, VTSuperResolutionScalerConfigurationInputType) {
	VTSuperResolutionScalerConfigurationInputTypeVideo		= 1,
	VTSuperResolutionScalerConfigurationInputTypeImage		= 2,
} NS_SWIFT_NAME(VTSuperResolutionScalerConfiguration.InputType);

/*!
@brief List of SuperResolution  input types.
*/
API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(tvos, visionos, watchos)
typedef NS_ENUM(NSInteger, VTSuperResolutionScalerConfigurationModelStatus) {
	VTSuperResolutionScalerConfigurationModelStatusDownloadRequired	= 0,
	VTSuperResolutionScalerConfigurationModelStatusDownloading		= 1,
	VTSuperResolutionScalerConfigurationModelStatusReady				= 2,
} NS_SWIFT_NAME(VTSuperResolutionScalerConfiguration.ModelStatus);

/*!
 @brief Hint to let the processor know whether frames are being submitted in presenatation sequence, allowing performance optimizations based on previous processing requests
 */
API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(tvos, visionos, watchos)
typedef NS_ENUM(NSInteger, VTSuperResolutionScalerParametersSubmissionMode) {
	VTSuperResolutionScalerParametersSubmissionModeRandom             = 1,    // Frames are submitted in non-sequential order
	VTSuperResolutionScalerParametersSubmissionModeSequential         = 2,    // Frames are submitted sequentially following presentation time order
} NS_SWIFT_NAME(VTSuperResolutionScalerParameters.SubmissionMode);


NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/*!
 @class VTSuperResolutionScalerConfiguration
 @abstract Configuration that is used to set up the SuperResolution Processor.

 @discussion This configuration enables the SuperResolution on a VTFrameProcessing session.  IMPORTANT: The VTSuperResolutionScaler processor may require ML models which need to be downloaded by the framework in order to operate.  Before using calling startSessionWithConfiguration with a VTSuperResolutionScalerConfiguration, it is important that you verify that the necessary models are present by checking the configurationModelStatus on the configuration object.  If models are not available, model download can be triggered using the downloadConfigurationModelWithCompletionHandler method on the configuration object.  Best practice is to confirm availability of models and drive download with user awareness and interaction before engaging workflows where the processor is needed.
*/

API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(tvos, visionos, watchos)
NS_SWIFT_SENDABLE
@interface VTSuperResolutionScalerConfiguration : NSObject <VTFrameProcessorConfiguration>

#pragma mark --- init function(s).
/*!
 @abstract Creates a new VTSuperResolutionScalerConfiguration with specified flow width and height.
 @discussion init will return nil if dimensions are out of range or revision is unsupported.
 @param frameWidth    Width of source frame in pixels. Maximum value is 8192 for macOS, and 4096 for iOS.
 @param frameHeight   Height of source frame in pixels. Maximum value is 4320 for macOS, and 2160 for iOS.
 @param scaleFactor Indicates the scale factor between input and output.
 @param inputType  Indicates the type of input (video / image ).
 @param usePrecomputedFlow  Boolean value to indicate that Optical Flow will be provided by the user, if false this configuration will compute the optical flow on the fly.
 @param qualityPrioritization Used to control quality and performance levels. See VTSuperResolutionScalerConfigurationQualityPrioritization for more info.
 @param revision The specific algorithm or configuration revision that is to be used to perform the request.
*/
- (nullable instancetype)initWithFrameWidth:(NSInteger)frameWidth
								frameHeight:(NSInteger)frameHeight
								scaleFactor:(NSInteger)scaleFactor
								  inputType:(VTSuperResolutionScalerConfigurationInputType)inputType
						 usePrecomputedFlow:(BOOL)usePrecomputedFlow
					  qualityPrioritization:(VTSuperResolutionScalerConfigurationQualityPrioritization)qualityPrioritization
								   revision:(VTSuperResolutionScalerConfigurationRevision)revision;

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
 * @property inputType
 * @abstract Indicates the type of input.
*/
@property (nonatomic, readonly) VTSuperResolutionScalerConfigurationInputType inputType;

/**
 * @property precomputedFlow
 * @abstract Indicates that caller will provide optical flow.
*/
@property (nonatomic, readonly, getter=usesPrecomputedFlow) BOOL precomputedFlow;

/**
 * @property scaleFactor
 * @abstract Indicates the scale factor between input and output.
*/
@property (nonatomic, readonly) NSInteger scaleFactor;

/**
 * @property qualityPrioritization
 * @abstract parameter used to control quality and performance levels. See VTSuperResolutionScalerConfigurationQualityPrioritization for more info.
*/
@property (nonatomic, readonly) VTSuperResolutionScalerConfigurationQualityPrioritization qualityPrioritization;

/*!
 @property revision
 @abstract The specific algorithm or configuration revision that is to be used to perform the request.
 */
@property (nonatomic, readonly) VTSuperResolutionScalerConfigurationRevision revision;

/*!
 @property supportedRevisions
 @abstract Provides the collection of currently-supported algorithm or configuration revisions for the class of configuration.
 @discussion This property allows clients to introspect at runtime what revisions are available for each configuration.
 */
@property (class, nonatomic, readonly) NSIndexSet* supportedRevisions;

/*!
 @property defaultRevision
 @abstract Provides the default revision of a particular algorithm or configuration.
 */
@property (class, nonatomic, readonly) VTSuperResolutionScalerConfigurationRevision defaultRevision;

/**
 * @property frameSupportedPixelFormats
 * @abstract list of source frame supported pixel formats for current configuration
 */
@property (nonatomic, readonly) NSArray<NSNumber *> * frameSupportedPixelFormats NS_REFINED_FOR_SWIFT;

/**
 * @property sourcePixelBufferAttributes
 * @abstract returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as source frames and reference frames.
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE sourcePixelBufferAttributes;

/**
 * @property destinationPixelBufferAttributes
 * @abstract returns a pixelBufferAttributes dictionary describing requirements for pixelBuffers used as destination frames.
*/
@property (nonatomic, readonly) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE destinationPixelBufferAttributes;

/*!
	@property configurationModelStatus
	@abstract reports the download status of models required to use VTSuperResolutionScaler for the current configuration.
*/
@property (nonatomic, readonly) VTSuperResolutionScalerConfigurationModelStatus configurationModelStatus;

/*!
 @abstract This interface requests that models associated with the VTSuperResolutionScalerConfiguration be downloaded.

 @discussion This interface can be used to download model assets required for the current VTSuperResolutionScalerConfiguration if the state is currently VTSuperResolutionScalerConfigurationModelStatusDownloadRequired.  The processorModelStatus class property can be queried to see if models are all already present.  If a download has been initiated, processorModelPercentageAvailable can be queried to determine what percentage of the model models are avialable.
 If the download fails, the completion handler will return an NSError, and the status will go back to VTSuperResolutionScalerConfigurationModelStatusDownloadRequired.  If the download succeeds, the NSError return value will be nil.
*/
- (void)downloadConfigurationModelWithCompletionHandler:(void (^)( NSError * _Nullable error))completionHandler;

/*!
	@property configurationModelPercentageAvailable
	@abstract Returns a floating point value between 0.0 and 1.0 indicating the percentage of required model assets that have been downloaded.
*/
@property (nonatomic, readonly) float configurationModelPercentageAvailable;


/*!
	@property supported
	@abstract reports whether this processor is supported
*/
@property (class, nonatomic, readonly, getter=isSupported) BOOL supported;

/*!
	@property supportedScaleFactors
	@abstract reports the set of supported scale factors that can be used when initializing a VTSuperResolutionScalerConfiguration.
*/
@property (class, nonatomic, readonly) NSArray<NSNumber*> * supportedScaleFactors NS_REFINED_FOR_SWIFT;

@end


/*!
 @class VTSuperResolutionScalerParameters
 @abstract VTSuperResolutionScalerParameters object contains both input and output parameters needed to run the SuperResolution processor on a frame. This object is used in the processWithParameters call of VTFrameProcessor class. The output parameter for this class is destinationFrame where the output frame is returned (as VTFrameProcessorFrame) back to the caller function once the processWithParameters completes.
 
 @discussion VTSuperResolutionScalerParameters are frame level parameters.
*/

API_AVAILABLE(macos(26.0), ios(26.0)) API_UNAVAILABLE(tvos, visionos, watchos)
@interface VTSuperResolutionScalerParameters : NSObject <VTFrameProcessorParameters>

/*!
 @abstract Creates a new VTSuperResolutionScalerParameters .
 @discussion init will return nil if sourceFrame or destinationFrame is nil, sourceFrame and reference frames  are different pixelFormats.
 @param sourceFrame Current source frame. Must be non nil.
 @param previousFrame  The Previous source frame in presentation time order. For the first frame this can be set to nil.
 @param previousOutputFrame  The Previous output frame in presentation time order. For the first frame this can be set to nil.
 @param opticalFlow Optional VTFrameProcessorOpticalFlow object that contains forward and backward optical flow between sourceFrame and previousFrame frame. Only needed if optical flow is pre-computed.
 @param submissionMode Set to VTSuperResolutionScalerParametersSubmissionModeSequential to indicate that current submission follow presentation time order without jump or skip when compared to previous submission. VTSuperResolutionScalerParametersSubmissionModeSequential will yield better performance. Set to VTSuperResolutionScalerParametersSubmissionModeRandom to indicate a skip or a jump in frame sequence.
@param destinationFrame User allocated pixel buffer that will receive the results.
*/
- (nullable instancetype) initWithSourceFrame:(VTFrameProcessorFrame *)sourceFrame
								previousFrame:(VTFrameProcessorFrame * _Nullable)previousFrame
						  previousOutputFrame:(VTFrameProcessorFrame * _Nullable)previousOutputFrame
								  opticalFlow:(VTFrameProcessorOpticalFlow * _Nullable)opticalFlow
							   submissionMode:(VTSuperResolutionScalerParametersSubmissionMode)submissionMode
							 destinationFrame:(VTFrameProcessorFrame *)destinationFrame;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * @property sourceFrame
 * @abstract sourceFrame Current source frame. Must be non nil
*/

@property(nonatomic, readonly) VTFrameProcessorFrame * sourceFrame;

/**
 * @property previousFrame
 * @abstract Previous source frame in presentation time order. For the first frame this will be nil.
*/

@property(nonatomic, readonly, nullable) VTFrameProcessorFrame * previousFrame;

/**
 * @property previousOutputFrame
 * @abstract Previous output frame in presentation time order. For the first frame this will be nil.
*/

@property(nonatomic, readonly, nullable) VTFrameProcessorFrame * previousOutputFrame;

/**
 * @property opticalFlow
 * @abstract Optional VTFrameProcessorOpticalFlow object that contains forward and backward optical flow with the previous frame. Only needed if optical flow is pre-computed. For the first frame this will be nil.
*/

@property(nonatomic, readonly, nullable) VTFrameProcessorOpticalFlow * opticalFlow;

/**
 * @property submissionMode
 * @abstract A VTSuperResolutionScalerSubmissionMode value describing the processing request in this Parameters object .
*/
@property (nonatomic, readonly) VTSuperResolutionScalerParametersSubmissionMode submissionMode;

/**
 * @property destinationFrame
 * @abstract VTFrameProcessorFrame that contains user allocated pixel buffer that will receive the results.
*/

@property(nonatomic, readonly) VTFrameProcessorFrame * destinationFrame;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // __OBJC__
#endif // ! TARGET_OS_SIMULATOR

#endif // VTFRAMEPROCESSOR_SUPERRESOLUTION_H
