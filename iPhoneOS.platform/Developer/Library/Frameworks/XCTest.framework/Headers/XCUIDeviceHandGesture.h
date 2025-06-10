#if __has_include(<XCUIAutomation/XCUIDeviceHandGesture.h>)
#import <XCUIAutomation/XCUIDeviceHandGesture.h>
#else

//
//  Copyright © 2023 Apple Inc. All rights reserved.
//

#import <XCTest/XCTestDefines.h>

#if TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

/*!
 * @enum XCUIDeviceHandGesture
 *
 * Represents a hand gesture that can be performed while wearing an Apple Watch.
 *
 */
typedef NS_ENUM(NSInteger, XCUIDeviceHandGesture) {
    XCUIDeviceHandGestureDoubleTap = 1,
};

NS_ASSUME_NONNULL_END

#endif // TARGET_OS_WATCH

#endif
