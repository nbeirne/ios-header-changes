/*
	File:  VTMotionEstimationSessionProperties.h
 
	Framework:  VideoToolbox
 
	Copyright 2022 Apple Inc. All rights reserved.
 
*/

#ifndef _VT_MOTION_ESTIMATION_SESSION_PROPERTIES_H_
#define _VT_MOTION_ESTIMATION_SESSION_PROPERTIES_H_

#include <CoreMedia/CMBase.h>
#include <CoreFoundation/CoreFoundation.h>

#if defined(__cplusplus)
extern "C"
{
#endif

#pragma pack(push)
#pragma pack()

#pragma mark Creation Options

/*!
	@header
	@abstract
		Video Toolbox motion estimation session creation options

	@discussion
		These keys may be used in the motionVectorProcessorSelectionOptions parameter to 
		VTMotionEstimationSessionCreate to configure the created session.
*/

/*!
	@constant	kVTMotionEstimationSessionCreationOption_MotionVectorSize
	@abstract
		The size of the search blocks used in VTMotionEstimationSession.
	@discussion
		VTMotionEstimationSessionCreate takes a dictionary of creation options, motionVectorProcessorSelectionOptions.
		kVTMotionEstimationSessionCreationOption_MotionVectorSize can be supplied with CFNumber to override the default search block size.
		Currently supported motion vector size is 4 or 16, meaning 4x4 or 16x16 respectively. 16x16 is the default if this key is not provided.
*/
VT_EXPORT const CFStringRef kVTMotionEstimationSessionCreationOption_MotionVectorSize API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos); // Read/write, CFNumber

/*!
	@constant	kVTMotionEstimationSessionCreationOption_UseMultiPassSearch
	@abstract
		An option used for higher quality motion estimation
	@discussion
		VTMotionEstimationSessionCreate takes a dictionary of creation options, motionVectorProcessorSelectionOptions.
		kVTMotionEstimationSessionCreationOption_UseMultiPassSearch can be supplied with kCFBooleanTrue to provide higher quality motion estimation.
		True motion achieves higher quality by running the motion estimator in multiple passes. The default is kCFBooleanFalse.
*/
VT_EXPORT const CFStringRef kVTMotionEstimationSessionCreationOption_UseMultiPassSearch API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos); // Read/write, CFBoolean

/*!
	@constant	kVTMotionEstimationSessionCreationOption_DetectTrueMotion
	@abstract
		Renamed to kVTMotionEstimationSessionCreationOption_UseMultiPassSearch
*/
VT_EXPORT const CFStringRef kVTMotionEstimationSessionCreationOption_DetectTrueMotion API_UNAVAILABLE(macos, ios, tvos, visionos, watchos); // Read/write, CFBoolean DEPRECATED

/*!
	@constant	kVTMotionEstimationSessionCreationOption_Label
	@abstract
		A label used for logging and resource tracking.
	@discussion
		VTMotionEstimationSessionCreate takes a dictionary of creation options, motionVectorProcessorSelectionOptions.
		kVTMotionEstimationSessionCreationOption_Label can be supplied with CFString to specify a label used in logging and
		resource tracking.
*/
VT_EXPORT const CFStringRef kVTMotionEstimationSessionCreationOption_Label API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos); // Read/write, CFString

#pragma mark Properties

/*!
	@header
	@abstract
		Video Toolbox motion estimation session properties

	@discussion
		This file defines private properties used to configure motion estimation sessions after creation.  

		Clients can query supported properties by calling VTSessionCopySupportedPropertyDictionary,
		and use VTSessionSetProperty and VTSessionCopyProperty.
*/

// there are none yet

#pragma pack(pop)

#if defined(__cplusplus)
}
#endif

#endif // _VT_MOTION_ESTIMATION_SESSION_PROPERTIES_H_
