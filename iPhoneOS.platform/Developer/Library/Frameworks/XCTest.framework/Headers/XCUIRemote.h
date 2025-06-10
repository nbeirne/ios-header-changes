#if __has_include(<XCUIAutomation/XCUIRemote.h>)
#import <XCUIAutomation/XCUIRemote.h>
#else

//
//  Copyright (c) 2014-2015 Apple Inc. All rights reserved.
//

#import <XCTest/XCTestDefines.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @enum XCUIRemoteButton
 *
 * A button on a physical remote control.
 */
typedef NS_ENUM(NSUInteger, XCUIRemoteButton) {
    XCUIRemoteButtonUp          = 0,
    XCUIRemoteButtonDown        = 1,
    XCUIRemoteButtonLeft        = 2,
    XCUIRemoteButtonRight       = 3,
    
    XCUIRemoteButtonSelect      = 4,
    XCUIRemoteButtonMenu        = 5,
    XCUIRemoteButtonPlayPause   = 6,
    
    XCUIRemoteButtonHome        = 7,

    XCUIRemoteButtonPageUp API_AVAILABLE(tvos(14.3))   = 9,
    XCUIRemoteButtonPageDown API_AVAILABLE(tvos(14.3)) = 10,

    XCUIRemoteButtonGuide API_AVAILABLE(tvos(14.3))    = 11
};

#if TARGET_OS_TV

/*!
 * @class XCUIRemote
 *
 * Simulates interaction with a physical remote control.
 */
XCT_SWIFT_MAIN_ACTOR
@interface XCUIRemote : NSObject

/*!
 * The simulated physical remote control.
 */
@property (class, readonly) XCUIRemote *sharedRemote;

+ (instancetype)new XCT_UNAVAILABLE("Access XCUIRemote through the sharedRemote property.");
- (instancetype)init XCT_UNAVAILABLE("Access XCUIRemote through the sharedRemote property.");

/*!
 * Sends a momentary press of a button on a physical remote control.
 *
 * @param remoteButton
 * The button on the physical remote control for which to synthesize a press.
 */
- (void)pressButton:(XCUIRemoteButton)remoteButton;

/*!
 * Sends a press and hold of a button on a physical remote control, holding for the specified duration.
 *
 * @param remoteButton
 * The button on the physical remote control for which to synthesize a press.
 *
 * @param duration
 * Duration in seconds.
 */
- (void)pressButton:(XCUIRemoteButton)remoteButton forDuration:(NSTimeInterval)duration;

@end

#endif

NS_ASSUME_NONNULL_END

#endif
