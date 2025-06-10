/*
	File:  AVCaptureEventSound.h
	
	Framework:  AVKit
	
	Copyright © 2025 Apple Inc. All rights reserved.
	
	To report bugs, go to:  http://developer.apple.com/bugreporter/

 */

#if TARGET_OS_OSX || TARGET_OS_MACCATALYST
#import <AVKitCore/AVKitDefines.h>
#else
#import <AVKit/AVKitDefines.h>
#endif // TARGET_OS_OSX || TARGET_OS_MACCATALYST


// MARK: -

/// A sound object for a capture event.
API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(visionos, macCatalyst) API_UNAVAILABLE(macos, tvos, watchos)
@interface AVCaptureEventSound : NSObject

AVKIT_INIT_UNAVAILABLE

/*!
 * Initializer for an AVCaptureEventSound with a custom sound.
 *
 * - Parameter url: A URL within the app's bundle for a custom capture sound.
 * - Parameter error: A return by-reference error that specifies any error in creating the sound object.
 * - Returns: An AVCaptureEventSound.
 */
- (instancetype)initWithURL:(NSURL *)url error:(NSError **)error;

/// The default sound for photo capture.
@property (class, readonly) AVCaptureEventSound *cameraShutterSound;

/// The default sound for starting a video recording.
@property (class, readonly) AVCaptureEventSound *beginVideoRecordingSound;

/// The default sound for ending a video recording.
@property (class, readonly) AVCaptureEventSound *endVideoRecordingSound;

@end
