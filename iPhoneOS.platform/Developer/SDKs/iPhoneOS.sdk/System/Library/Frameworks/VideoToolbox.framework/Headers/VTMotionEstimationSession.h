/*
	File:  VTMotionEstimationSession.h
	
	Framework:  VideoToolbox
 
	Copyright 2022-2023 Apple Inc. All rights reserved.
  
	Video Toolbox client API for generating motion vectors from CVPixelBuffers.
*/

#ifndef VTMotionEstimationSession_h
#define VTMotionEstimationSession_h

#include <CoreFoundation/CoreFoundation.h>
#include <CoreVideo/CoreVideo.h>
#include <CoreMedia/CMBase.h>
#include <VideoToolbox/VTBase.h>
#include <VideoToolbox/VTSession.h>

#if defined(__cplusplus)
extern "C"
{
#endif
	
#pragma pack(push)
#pragma pack()

#if __BLOCKS__

CF_IMPLICIT_BRIDGING_ENABLED

/*!
	@enum		VTMotionEstimationFrameFlags
	@abstract	Directives for the motion estimation session and the motion estimation processor passed from the client into
				motionEstimationFrameFlags parameter of VTMotionEstimationSessionEstimateMotionVectors.

	@constant	kVTMotionEstimationFrameFlags_CurrentBufferWillBeNextReferenceBuffer
		A hint to the motion estimation session that the client will reuse the currentBuffer as referenceBuffer in the next call
		to VTMotionEstimationSessionEstimateMotionVectors. Using this flag allows the motion estimation processor to make some
		optimizations. 
*/
typedef CF_OPTIONS(uint32_t, VTMotionEstimationFrameFlags) {
	kVTMotionEstimationFrameFlags_CurrentBufferWillBeNextReferenceBuffer = 1<<0,
} CF_REFINED_FOR_SWIFT;

/*!
	@enum		VTMotionEstimationInfoFlags
	@abstract	Directives for the client passed into the VTMotionEstimationOutputHandler from the
				motion estimation session or the motion estimation processor.
*/
typedef CF_OPTIONS(uint32_t, VTMotionEstimationInfoFlags) {
	kVTMotionEstimationInfoFlags_Reserved0 = 1<<0,
} CF_REFINED_FOR_SWIFT;

/*!
	@typedef	VTMotionEstimationSessionRef
	@abstract	A reference to a Video Toolbox Motion Estimation Session.
	@discussion
		A motion estimation session supports two CVPixelBuffers of the same size and type,
		and returns motion vectors in the form of a CVPixelBuffer. The session is a
		reference-counted CF object. To create a motion estimation session, call
		VTMotionEstimationSessionCreate; then you can optionally configure the session using
		VTSessionSetProperty; then to create motion estimations, call
		VTMotionEstimationSessionCreateMotionEstimation. When you are done with the session,
		you should call VTMotionEstimationSessionInvalidate to tear it down and CFRelease to
		release your object reference.
 */
typedef struct CM_BRIDGED_TYPE(id) OpaqueVTMotionEstimationSession*  VTMotionEstimationSessionRef CF_REFINED_FOR_SWIFT
	API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

/*!
	@function	VTMotionEstimationSessionGetTypeID
	@abstract	Get the CFTypeID for a VTMotionEstimationSession.
	@discussion
		Get the CFTypeID for a VTMotionEstimationSession.
*/
VT_EXPORT CFTypeID VTMotionEstimationSessionGetTypeID( void ) CF_REFINED_FOR_SWIFT
	API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

/*!
	@function	VTMotionEstimationSessionCreate
	@abstract	Creates a session for creating CVPixelBuffer of motion vectors from two CVPixelBuffers.
	@discussion
		The function creates a session for transferring images between CVPixelBuffers.
	@param	allocator
		An allocator for the session.  Pass NULL to use the default allocator.
	@param	motionVectorProcessorSelectionOptions
		Available creation Options:
			kVTMotionEstimationSessionCreationOption_MotionVectorSize CFNumber 16 or 4.
				The size of the block of pixels 16x16 or 4x4. Default is 16x16.
			kVTMotionEstimationSessionCreationOption_UseMultiPassSearch can be supplied with kCFBooleanTrue to provide higher quality motion estimation.
				True motion achieves higher quality by running the motion estimator in multiple passes. The default is kCFBooleanFalse.
			kVTMotionEstimationSessionCreationOption_Label CFString
				This option assigns a label for logging and resource tracking.
	@param	width
		The width of frames, in pixels.
	@param	height
		The height of frames in pixels.
	@param	motionEstimationSessionOut
		Points to a variable to receive the new pixel transfer session.
	
*/
VT_EXPORT OSStatus
VTMotionEstimationSessionCreate(
		CM_NULLABLE CFAllocatorRef	 allocator,
		CM_NULLABLE CFDictionaryRef	 motionVectorProcessorSelectionOptions,
		uint32_t					 width,
		uint32_t					 height,
		CM_RETURNS_RETAINED_PARAMETER CM_NULLABLE VTMotionEstimationSessionRef * CM_NONNULL motionEstimationSessionOut) CF_REFINED_FOR_SWIFT
		API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

/*!
	@function	VTMotionEstimationSessionCopySourcePixelBufferAttributes
	@abstract	Copy the expected attributes for source pixel buffers
	@discussion
		The function provides a cf dictionary of attributes that must be released. This is
		routine is for clients to query the VTMotionEstimationSession for the native source
		attributes. If a client provides an input  CVPixelBuffer that is not compatible with the
		the attributes returned by this function, VTMotionEstimationSession will automatically
		convert the input pixel buffer into a compatible pixel buffer for processing.
	@param	session
		The motion estimation session.
	@param	attributesOut
		Points to a variable to receive the attributes dictionary.
	
*/
VT_EXPORT OSStatus
VTMotionEstimationSessionCopySourcePixelBufferAttributes(
		CM_NONNULL VTMotionEstimationSessionRef	 motionEstimationSession,
		CM_RETURNS_RETAINED_PARAMETER CM_NULLABLE CFDictionaryRef * CM_NONNULL attributesOut) CF_REFINED_FOR_SWIFT
		API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

/*!
	@function	VTMotionEstimationSessionInvalidate
	@abstract	Tears down a motion estimation session.
    @discussion
    	When you are done with a motion estimation session you created, call VTMotionEstimationSessionInvalidate
    	to tear it down and then CFRelease to release your object reference. When a motion estimation session's
		retain count reaches zero, it is automatically invalidated, but since sessions may be retained by multiple
		parties, it can be hard to predict when this will happen. Calling VTMotionEstimationSessionInvalidate
		ensures a deterministic, orderly teardown.
*/
VT_EXPORT void
VTMotionEstimationSessionInvalidate(
		CM_NONNULL VTMotionEstimationSessionRef session ) CF_REFINED_FOR_SWIFT
		API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

/*!
	@typedef	VTMotionEstimationOutputHandler
	@abstract	Block invoked when frame processing is complete.
	@discussion
		When the client requests a motion estimation, the client passes in a callback block to be called
		for that result of that request. If the VTMotionEstimationSessionCreateMotionEstimation call returns
		an error, the block will not be called.
	@param	status
		noErr if processing request was successful; an error code if motion estimation was not successful.
	@param	infoFlags
		A bit field containing information about the processing operation.
	@param	additionalInfo
		Additional processing information about the processing operation that can not fit in infoFlags.
		Currently, this is expected to be NULL.
	@param	motionVectorPixelBuffer
		A CVPixelBuffer containing the motion vector information, if processing request was successful;
		otherwise, NULL.
 */
typedef void (^VTMotionEstimationOutputHandler)(
		OSStatus status,
		VTMotionEstimationInfoFlags infoFlags,
		CM_NULLABLE CFDictionaryRef additionalInfo,
		CM_NULLABLE CVPixelBufferRef motionVectors);

/*!
	@function	VTMotionEstimationSessionEstimateMotionVectors
	@abstract	Given two CVPixelBuffers, creates a CVPixelBuffer representing the motion estimate.
	@discussion
		The motion estimation session will compare the reference frame to the current frame, and
		generate motion vectors in the form of a CVPixelBuffer.
	@param	session
		The motion estimation session.
	@param	referenceImage
		The reference image.
	@param	currentImage
		The current image.
	@param	motionEstimationFrameFlags
		A bit field with per-frame options.  See kVTMotionEstimationFrameFlags_CurrentBufferWillBeNextReferenceBuffer.
	@param	additionalFrameOptions
		A way to pass additional information that will not fit in motionEstimationFrameFlags; currently expected to be NULL.
	@param	outputHandler
		The block to be called when the processing request is completed.  If the
		VTMotionEstimationSessionCreateMotionEstimation call returns an error, the block will not
		be called.
	@result
		If the call was successful, noErr; otherwise an error code, such as kVTMotionEstimationNotSupportedErr.
*/
VT_EXPORT OSStatus
VTMotionEstimationSessionEstimateMotionVectors(
		CM_NONNULL VTMotionEstimationSessionRef    session,
		CM_NONNULL CVPixelBufferRef                referenceImage,
		CM_NONNULL CVPixelBufferRef                currentImage,
		VTMotionEstimationFrameFlags			   motionEstimationFrameFlags,
		CM_NULLABLE CFDictionaryRef			   	   additionalFrameOptions,
		CM_NONNULL VTMotionEstimationOutputHandler outputHandler ) CF_REFINED_FOR_SWIFT
		API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

/*!
	@function VTMotionEstimationSessionCompleteFrames
	@abstract Directs the motion estimation session to emit all pending frames and waits for completion.
	@discussion
		Directs the motion estimation session to emit all pending frames, then waits for all outstanding
		requests to complete, then returns.
*/
VT_EXPORT OSStatus
VTMotionEstimationSessionCompleteFrames(
		CM_NONNULL VTMotionEstimationSessionRef		session) CF_REFINED_FOR_SWIFT
		API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos);

CF_IMPLICIT_BRIDGING_DISABLED

// See VTSession.h for property access APIs on VTMotionEstimationSession.
// See VTMotionEstimationSessionProperties.h for standard property keys and values for pixel transfer sessions.

#endif // __BLOCKS__

#pragma pack(pop)

#if defined(__cplusplus)
}
#endif

#endif /* VTMotionEstimationSession_h */
