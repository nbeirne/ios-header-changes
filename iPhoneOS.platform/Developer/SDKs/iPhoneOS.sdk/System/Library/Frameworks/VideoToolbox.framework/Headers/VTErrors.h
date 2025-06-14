/*
	File:  VTErrors.h
	
	Framework:  VideoToolbox
 
    Copyright 2006-2022 Apple Inc. All rights reserved.
  
*/

#ifndef VTERRORS_H
#define VTERRORS_H

#include <CoreMedia/CMBase.h>

#if defined(__cplusplus)
extern "C"
{
#endif
    
#pragma pack(push, 4)

// Error codes
#if COREMEDIA_USE_DERIVED_ENUMS_FOR_CONSTANTS
enum : OSStatus
#else
enum
#endif // COREMEDIA_USE_DERIVED_ENUMS_FOR_CONSTANTS
{
	kVTPropertyNotSupportedErr				= -12900,
	kVTPropertyReadOnlyErr					= -12901,
	kVTParameterErr							= -12902,
	kVTInvalidSessionErr					= -12903,
	kVTAllocationFailedErr					= -12904,
	kVTPixelTransferNotSupportedErr			= -12905, // c.f. -8961
	kVTCouldNotFindVideoDecoderErr			= -12906,
	kVTCouldNotCreateInstanceErr			= -12907,
	kVTCouldNotFindVideoEncoderErr			= -12908,
	kVTVideoDecoderBadDataErr				= -12909, // c.f. -8969
	kVTVideoDecoderUnsupportedDataFormatErr	= -12910, // c.f. -8970
	kVTVideoDecoderMalfunctionErr			= -12911, // c.f. -8960
	kVTVideoEncoderMalfunctionErr			= -12912,
	kVTVideoDecoderNotAvailableNowErr		= -12913,
	kVTImageRotationNotSupportedErr			= -12914, // deprecated
	kVTPixelRotationNotSupportedErr			= -12914,
	kVTVideoEncoderNotAvailableNowErr		= -12915,
	kVTFormatDescriptionChangeNotSupportedErr	= -12916,
	kVTInsufficientSourceColorDataErr		= -12917,
	kVTCouldNotCreateColorCorrectionDataErr	= -12918,
	kVTColorSyncTransformConvertFailedErr	= -12919,
	kVTVideoDecoderAuthorizationErr			= -12210,
	kVTVideoEncoderAuthorizationErr			= -12211,
	kVTColorCorrectionPixelTransferFailedErr	= -12212,
	kVTMultiPassStorageIdentifierMismatchErr	= -12213,
	kVTMultiPassStorageInvalidErr			= -12214,
	kVTFrameSiloInvalidTimeStampErr			= -12215,
	kVTFrameSiloInvalidTimeRangeErr			= -12216,
	kVTCouldNotFindTemporalFilterErr		= -12217,
	kVTPixelTransferNotPermittedErr			= -12218,
	kVTColorCorrectionImageRotationFailedErr	= -12219,
	kVTVideoDecoderRemovedErr				= -17690,
	kVTSessionMalfunctionErr				= -17691,
	kVTVideoDecoderNeedsRosettaErr			= -17692,
	kVTVideoEncoderNeedsRosettaErr			= -17693,
	kVTVideoDecoderReferenceMissingErr		= -17694,
	kVTVideoDecoderCallbackMessagingErr		= -17695,
	kVTVideoDecoderUnknownErr				= -17696,
	kVTExtensionDisabledErr 				= -17697,
    kVTVideoEncoderMVHEVCVideoLayerIDsMismatchErr = -17698,
	kVTCouldNotOutputTaggedBufferGroupErr	= -17699,
	kVTCouldNotFindExtensionErr				= -19510,
	kVTExtensionConflictErr					= -19511,
};

/*!
	@enum		VTDecodeFrameFlags
	@abstract	Directives for the decompression session and the video decoder, passed into
				decodeFlags parameter of VTDecompressionSessionDecodeFrame.

	@constant	kVTDecodeFrame_EnableAsynchronousDecompression
		With the kVTDecodeFrame_EnableAsynchronousDecompression bit clear, the video decoder 
		is compelled to emit every frame before it returns.  With the bit set, the decoder may 
		process frames asynchronously, but it is not compelled to do so.  
	@constant	kVTDecodeFrame_DoNotOutputFrame
		A hint to the decompression session and video decoder that a CVImageBuffer should not
		be emitted for this frame.  NULL will be returned instead. 
	@constant	kVTDecodeFrame_1xRealTimePlayback
		A hint to the video decoder that it would be OK to use a low-power mode that can not decode faster than 1x realtime.
	@constant	kVTDecodeFrame_EnableTemporalProcessing
		With the kVTDecodeFrame_EnableTemporalProcessing bit clear, the video decoder should emit 
		every frame once that frame's decoding is done -- frames may not be delayed indefinitely.  With 
		the bit set, it is legal for the decoder to delay frames indefinitely -- at least 
		until VTDecompressionSessionFinishDelayedFrames or VTDecompressionSessionInvalidate is called.
*/
typedef CF_OPTIONS(uint32_t, VTDecodeFrameFlags) {
	kVTDecodeFrame_EnableAsynchronousDecompression = 1<<0,
	kVTDecodeFrame_DoNotOutputFrame = 1<<1,
	kVTDecodeFrame_1xRealTimePlayback = 1<<2, 
	kVTDecodeFrame_EnableTemporalProcessing = 1<<3,
};

/*!
	@enum		VTDecodeInfoFlags
	@abstract	Informational status for decoding -- non-error flags

	@constant	kVTDecodeInfo_Asynchronous
		The kVTDecodeInfo_Asynchronous bit may be set if the decode ran asynchronously.
	@constant	kVTDecodeInfo_FrameDropped
		The kVTDecodeInfo_FrameDropped bit may be set if the frame was dropped.
	@constant	kVTDecodeInfo_ImageBufferModifiable
		If the kVTDecodeInfo_ImageBufferModifiable bit is set, it is safe for the client to modify the imageBuffer.
	@constant	kVTDecodeInfo_SkippedLeadingFrameDropped
		The kVTDecodeInfo_SkippedLeadingFrameDropped may be set if a leading frame after a sync frame is dropped.
		This can happen when a seek to a sync frame is initiated and, due to frame reordering, there are leading
		frames following the sync frame that cannot be decoded due to missing references.  Dropping these frames 
		has no impact to playback since the non-decodeable frames will not be rendered.
		If kVTDecodeInfo_SkippedLeadingFrameDropped is set, kVTDecodeInfo_FrameDropped will also be set.
	@constant kVTDecodeInfo_FrameInterrupted
		The kVTDecodeInfo_FrameInterrupted bit may be set if the frame was decoded successfully but the decoded
		content was not provided in the output callback. When this bit is set, the imageBuffer provided to the output
		handler may either be NULL or contain only black pixels.
*/
typedef CF_OPTIONS(UInt32, VTDecodeInfoFlags) {
	kVTDecodeInfo_Asynchronous = 1UL << 0,
	kVTDecodeInfo_FrameDropped = 1UL << 1,
	kVTDecodeInfo_ImageBufferModifiable = 1UL << 2,
	kVTDecodeInfo_SkippedLeadingFrameDropped = 1UL << 3,
	kVTDecodeInfo_FrameInterrupted = 1UL << 4,
};

// Informational status for encoding -- non-error flags 
typedef CF_OPTIONS(UInt32, VTEncodeInfoFlags) {
	kVTEncodeInfo_Asynchronous = 1UL << 0,
	kVTEncodeInfo_FrameDropped = 1UL << 1,
};

#pragma pack(pop)

#if defined(__cplusplus)
}
#endif

#endif // VTERRORS_H
