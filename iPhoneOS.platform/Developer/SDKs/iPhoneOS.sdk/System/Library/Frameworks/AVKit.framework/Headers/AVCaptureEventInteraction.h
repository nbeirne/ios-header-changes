/*
	File:  AVCaptureEventInteraction.h
	
	Framework:  AVKit
	
	Copyright © 2022-2025 Apple Inc. All rights reserved.
	
	To report bugs, go to:  http://developer.apple.com/bugreporter/

 */


#import <Foundation/Foundation.h>

#if TARGET_OS_MACCATALYST
#import <AVKitCore/AVKitDefines.h>
#else
#import <AVKit/AVKitDefines.h>
#endif // TARGET_OS_MACCATALYST
#import <AVKit/AVCaptureEvent.h>
#import <UIKit/UIInteraction.h>


NS_ASSUME_NONNULL_BEGIN

// MARK: -

/*!
 *	A UIInteraction used to register actions triggered by system capture events.
 *
 *	Events may or may not be sent to applications based on the current system state. Backgrounded applications will not receive events, additionally events will only be sent to applications that are actively using the camera. AVCaptureEventInteraction should be attached to views in the responder chain.
 *
 *	This API is for media capture use cases only.
 */
API_AVAILABLE(ios(17.2)) API_UNAVAILABLE(visionos) API_UNAVAILABLE(macos, tvos, watchos)
@interface AVCaptureEventInteraction : NSObject <UIInteraction>

AVKIT_INIT_UNAVAILABLE

/*!
 *	Initializer for an AVCaptureEventInteraction.
 *
 * - Parameter handler: An event handler called when either the primary or secondary events are triggered.
 * - Returns: An AVCaptureEventInteraction.
 */
- (instancetype)initWithEventHandler:(void (^)(AVCaptureEvent *event))handler NS_SWIFT_NAME(init(handler:));

/*!
 *	Initializer for an AVCaptureEventInteraction.
 *
 * - Parameter primaryHandler: An event handler called when a primary capture event is triggered.
 * - Parameter secondaryHandler: An event handler called when a secondary capture event is triggered.
 * - Returns: An AVCaptureEventInteraction.
 */
- (instancetype)initWithPrimaryEventHandler:(void (^)(AVCaptureEvent *event))primaryHandler secondaryEventHandler:(void (^)(AVCaptureEvent *event))secondaryHandler NS_SWIFT_NAME(init(primary:secondary:));

/*!
 *	A boolean value indicating whether this capture event interaction is active or not.
 *
 *	Set this value to NO when your application cannot or will not respond to the action callbacks to avoid non-interactive buttons or UI elements.
 */
@property (nonatomic, readwrite, getter=isEnabled) BOOL enabled;

/*!
 * 	A boolean value indicating whether or not the default sound is disabled.
 *
 *  If `YES`, sound playback for capture events must be handled manually using the `playSound` method.
 */
@property (class, nonatomic, readwrite) BOOL defaultCaptureSoundDisabled API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(visionos, macCatalyst) API_UNAVAILABLE(macos, tvos, watchos);

@end

NS_ASSUME_NONNULL_END
