#if __has_include(<XCUIAutomation/XCUIDeviceButton.h>)
#import <XCUIAutomation/XCUIDeviceButton.h>
#else

//
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#import <XCTest/XCTestDefines.h>

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_IPHONE && !TARGET_OS_MACCATALYST

/*!
 * @enum XCUIDeviceButton
 *
 * Represents a physical button on a device.
 *
 * @note Some buttons are not available in the Simulator, and should not be used in your tests.
 * You can use a block like this:
 *
 *     #if !TARGET_OS_SIMULATOR
 *     // test code that depends on buttons not available in the Simulator
 *     #endif
 *
 * in your test code to ensure it does not call unavailable APIs.
 */
typedef NS_ENUM(NSInteger, XCUIDeviceButton) {
    XCUIDeviceButtonHome = 1,
    XCUIDeviceButtonVolumeUp XCTEST_SIMULATOR_UNAVAILABLE("This API is not available in the Simulator, see the XCUIDeviceButton documentation for details.") = 2,
    XCUIDeviceButtonVolumeDown XCTEST_SIMULATOR_UNAVAILABLE("This API is not available in the Simulator, see the XCUIDeviceButton documentation for details.") = 3,
#if TARGET_OS_WATCH
    XCUIDeviceButtonAction = 4,
#endif
};

#endif

NS_ASSUME_NONNULL_END

#endif
