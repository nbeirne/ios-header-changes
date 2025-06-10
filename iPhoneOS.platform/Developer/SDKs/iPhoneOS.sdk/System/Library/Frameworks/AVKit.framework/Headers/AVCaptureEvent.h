/*
	File:  AVCaptureEvent.h
	
	Framework:  AVKit
	
	Copyright © 2022-2023 Apple Inc. All rights reserved.
	
	To report bugs, go to:  http://developer.apple.com/bugreporter/

 */


#import <Foundation/Foundation.h>

#if TARGET_OS_MACCATALYST
#import <AVKitCore/AVKitDefines.h>
#else
#import <AVKit/AVKitDefines.h>
#endif // TARGET_OS_MACCATALYST

#import <AVKit/AVCaptureEventSound.h>

NS_ASSUME_NONNULL_BEGIN

@class AVCaptureEvent;


// MARK: -

/// An enum describing the phase of a capture event.
typedef NS_ENUM(NSUInteger, AVCaptureEventPhase) {
	/// A phase sent at the beginning of a capture event.
	AVCaptureEventPhaseBegan,
	/// A phase sent at the end of a capture event.
	AVCaptureEventPhaseEnded,
	/// A phase sent when a capture event is cancelled.
	AVCaptureEventPhaseCancelled,
} API_AVAILABLE(ios(17.2)) API_UNAVAILABLE(visionos) API_UNAVAILABLE(macos, tvos, watchos);


// MARK: -

/// An object describing a system capture event.
API_AVAILABLE(ios(17.2)) API_UNAVAILABLE(visionos) API_UNAVAILABLE(macos, tvos, watchos)
@interface AVCaptureEvent : NSObject

AVKIT_INIT_UNAVAILABLE


/// The current phase of this capture event.
@property (nonatomic, readonly) AVCaptureEventPhase phase;

/*!
 *	Plays the given capture sound through AirPods.
 *
 *	This method has no effect if `shouldPlaySound` is `NO` or if the event object's lifetime exceeds 15 seconds.
 *
 * - Parameter sound: The capture sound to play for this event.
 * - Returns: A BOOL indicating whether a sound was played or not.
 */
- (BOOL)playSound:(AVCaptureEventSound *)sound API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(visionos, macCatalyst) API_UNAVAILABLE(macos, tvos, watchos);

/*!
 *	Indicates whether a sound must be played manually using the `playSound` method.
 *
 *	This property is `YES` only when both of the following conditions are true:
 *	1. The event was triggered by an AirPod stem click.
 *	2. The default capture sound is disabled.
 *
 *	If `shouldPlaySound ` is `NO`, calling `playSound` will have no effect. Omitting the sound when expected can significantly impact the user experience.
 */
@property (nonatomic, readonly) BOOL shouldPlaySound API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(visionos, macCatalyst) API_UNAVAILABLE(macos, tvos, watchos);

@end

NS_ASSUME_NONNULL_END
