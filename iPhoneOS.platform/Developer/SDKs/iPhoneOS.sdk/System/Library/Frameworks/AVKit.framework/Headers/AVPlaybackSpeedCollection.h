//
//  AVPlaybackSpeedCollection.h
//  AVKit
//
//  Created by adesjarlais on 11/13/21.
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_OSX || TARGET_OS_MACCATALYST
#import <AVKitCore/AVKitDefines.h>
#import <AVKitCore/AVPlaybackSpeed.h>
#else
#import <AVKit/AVKitDefines.h>
#import <AVKit/AVPlaybackSpeed.h>
#endif // #TARGET_OS_OSX || TARGET_OS_MACCATALYST


NS_ASSUME_NONNULL_BEGIN

// MARK: -

/*!
 @class         AVPlaybackSpeedCollection
 @abstract      A class representing a collection of user selectable playback speeds in a playback UI.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0)) API_UNAVAILABLE(watchos)
@interface AVPlaybackSpeedCollection : NSObject

AVKIT_INIT_UNAVAILABLE

/*!
 @method      	defaultSpeedFromList
 @param         speeds
				The playback speeds to select from
 @abstract      Returns the playback speed that should be used by default from the given list.
 */
+ (AVPlaybackSpeed *)defaultSpeedFromList:(NSArray<AVPlaybackSpeed *> *)speeds;


/*!
 @method        collectionWithSpeeds:
 @param         playbackSpeeds
				A list of playback speeds to be used for this collection.
 @abstract      Creates a new instance of an AVPlaybackSpeedCollection with the given playback speeds.
 */
+ (instancetype)collectionWithSpeeds:(NSArray<AVPlaybackSpeed *> *)playbackSpeeds;


/*!
 @property      speeds
 @abstract      The list of playback speeds in this collection.
 */
@property (nonatomic, readonly) NSArray<AVPlaybackSpeed *> *speeds;

/*!
 @property      selectedSpeed
 @abstract      The currently selected playback speed in this collection.
 @discussion    Changes to the associated AVPlayer's defaultRate will be reflected in this property and vice versa. If the associated AVPlayer's defaultRate is set to a value that does not match a speed in the collection, the selected speed will be set to nil.
 */
@property (nonatomic, readonly, nullable) AVPlaybackSpeed *selectedSpeed;


/*!
 @method      selectSpeed
 @param         speed
				The playback speed to select.
 @abstract      Selects the input AVPlaybackSpeed on this collection.
 @discussion    Calls to selectSpeed: with AVPlaybackSpeeds not contained within this collection will be ignored.
 */
- (void)selectSpeed:(AVPlaybackSpeed *)speed;

@end

NS_ASSUME_NONNULL_END
