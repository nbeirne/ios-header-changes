//
//  PHContentEditingInput.h
//  Photos
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/PhotosTypes.h>

@class PHAdjustmentData;
@class AVAsset;
@class CLLocation;
@class PHLivePhoto;
@class UTType;
@class UIImage;

NS_ASSUME_NONNULL_BEGIN
API_AVAILABLE_BEGIN(macos(10.11), ios(8), tvos(10))

OS_EXPORT
@interface PHContentEditingInput : NSObject

@property (readonly, assign) PHAssetMediaType mediaType;
@property (readonly, assign) PHAssetMediaSubtype mediaSubtypes;
@property (readonly, copy, nullable) NSDate *creationDate;
@property (readonly, copy, nullable) CLLocation *location;

/// The type of data provided as the asset's content editing input image or video.
@property (readonly, copy, nullable) UTType *contentType API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0));
@property (readonly, copy, nullable) NSString *uniformTypeIdentifier API_DEPRECATED("Use contentType instead", ios(8, API_TO_BE_DEPRECATED), macos(10.11, API_TO_BE_DEPRECATED), tvos(10, API_TO_BE_DEPRECATED), visionos(1, API_TO_BE_DEPRECATED));

// Playback style describes how the content should be presented to the user.  Use this value to choose the type of view and the appropriate APIs on the content editing input to display this content.
// When editing a live photo with a PHAssetPlaybackStyleLoopingVideo, you should provide an updated video that includes the looping video metadata on the PHContentEditingOutput's renderedContentURL.
@property (nonatomic, assign, readonly) PHAssetPlaybackStyle playbackStyle API_AVAILABLE(macos(10.13), ios(11), tvos(11));

// Adjustments to be applied onto the provided input image or video.
@property (readonly, strong, nullable) PHAdjustmentData *adjustmentData;

// Input image:
@property (readonly, strong, nullable) UIImage *displaySizeImage;
@property (readonly, copy, nullable) NSURL *fullSizeImageURL;
@property (readonly, assign) int fullSizeImageOrientation; // EXIF value

// Input video:
@property (readonly, strong, nullable) AVAsset *avAsset API_DEPRECATED_WITH_REPLACEMENT("-audiovisualAsset", ios(8,9)) API_UNAVAILABLE(macos);
@property (readonly, strong, nullable) AVAsset *audiovisualAsset API_AVAILABLE(macos(10.11), ios(9));

// Input Live Photo:
@property (readonly, strong, nullable) PHLivePhoto *livePhoto API_AVAILABLE(macos(10.12), ios(10));

@end

API_AVAILABLE_END
NS_ASSUME_NONNULL_END
