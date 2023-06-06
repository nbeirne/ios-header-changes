#if __has_include(<XCUIAutomation/XCUIDevice.h>)
#import <XCUIAutomation/XCUIDevice.h>
#else

//
//  Copyright (c) 2014-2015 Apple Inc. All rights reserved.
//


#import <XCTest/XCTestDefines.h>
#import <XCTest/XCUISiriService.h>
#import <XCTest/XCUIElement.h>
#import <XCTest/XCUIDeviceButton.h>
#import <XCTest/XCUILocation.h>

@class XCUISiriService;
@class XCUISystem;

#if TARGET_OS_IPHONE && !TARGET_OS_MACCATALYST
#import <UIKit/UIKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/*!
 * @enum XCUIDeviceAppearance
 *
 * Represents the light or dark UI style of a device.
 *
 * @note To maintain alignment with UIUserInterfaceStyle, we use `XCUIDeviceAppearanceUnspecified` to describe
 * UI styles that are unset.
 */
typedef NS_ENUM(NSInteger, XCUIDeviceAppearance) {
    XCUIDeviceAppearanceUnspecified = 0,
    XCUIDeviceAppearanceLight = 1,
    XCUIDeviceAppearanceDark = 2,
};

/*! Represents a device, providing an interface for simulating events involving physical buttons and device state. */
@interface XCUIDevice : NSObject

/*! The current device. */
@property (class, readonly) XCUIDevice *sharedDevice;

+ (instancetype)new XCT_UNAVAILABLE("Access XCUIDevice through +sharedDevice");
- (instancetype)init
    XCT_DEPRECATED_WITH_REPLACEMENT("XCUIDevice.sharedDevice")
    XCT_DEPRECATED_WITH_SWIFT_REPLACEMENT("XCUIDevice.shared");

#if TARGET_OS_IPHONE && !TARGET_OS_MACCATALYST
- (BOOL)hasHardwareButton:(XCUIDeviceButton)button API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0));
#endif

#if TARGET_OS_IOS
/*! The orientation of the device. */
@property (nonatomic) UIDeviceOrientation orientation;
/*!
 * Provides access to an object representing the Siri interface on the device.
 */
@property (readonly) XCUISiriService *siriService NS_AVAILABLE_IOS(10_3);

@property (readonly) BOOL supportsPointerInteraction;
#endif

/*!
 * The location currently being simulated by the device, if any.
 */
@property (nonatomic, strong, nullable) XCUILocation *location API_AVAILABLE(macos(13.3), ios(16.4), tvos(16.4), watchos(9.4));

#if TARGET_OS_IPHONE && !TARGET_OS_MACCATALYST
/*! Simulates the user pressing a physical button. */
- (void)pressButton:(XCUIDeviceButton)button;
#endif

#if TARGET_OS_WATCH || TARGET_OS_XR
/*!
 * Rotate the digital crown by a specified amount.
 *
 * @param rotationalDelta
 * The amount by which to rotate the digital crown. A value of 1.0 represents one full rotation.
 * The value’s sign indicates the rotation’s direction, but the sign is adjusted based on the crown’s orientation.
 * Positive values always indicate an upward scrolling gesture, while negative numbers indicate a downward scrolling gesture.
 *
 */
- (void)rotateDigitalCrownByDelta:(CGFloat)rotationalDelta;

/*!
 * Rotate the digital crown by a specified amount.
 *
 * @param rotationalDelta
 * The amount by which to rotate the digital crown. A value of 1.0 represents one full rotation.
 * The value’s sign indicates the rotation’s direction, but the sign is adjusted based on the crown’s orientation.
 * Positive values always indicate an upward scrolling gesture, while negative numbers indicate a downward scrolling gesture.
 *
 * @param velocity
 * The velocity with which to rotate the digital crown, specified in rotations per second. The sign of the value is ignored.
 *
 */
- (void)rotateDigitalCrownByDelta:(CGFloat)rotationalDelta withVelocity:(XCUIGestureVelocity)velocity;
#endif // TARGET_OS_WATCHOS || TARGET_OS_XR

/*!
 * Get or set the UI style of the device. Uses the `XCUIDeviceAppearance` enum to describe the UI style.
 */
@property (nonatomic) XCUIDeviceAppearance appearance API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0)) API_UNAVAILABLE(watchos);

/*!
 * Access system features of the device, such as its running applications, or the ability to open files on it.
 */
@property (nonatomic, readonly) XCUISystem *system;

@end

NS_ASSUME_NONNULL_END

#endif
