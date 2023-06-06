#if __has_include(<XCUIAutomation/XCUISystem.h>)
#import <XCUIAutomation/XCUISystem.h>
#else

//
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#import <XCTest/XCTestDefines.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @class XCUISystem
 * Represents a device's base system, providing an interface for performing OS-specific actions like opening universal links.
 */
@interface XCUISystem : NSObject

+ (instancetype)new XCT_UNAVAILABLE("Access XCUISystem through the system property on XCUIDevice.");
- (instancetype)init XCT_UNAVAILABLE("Access XCUISystem through the system property on XCUIDevice.");

/*!
 * Open a URL on the system using the default application for it.
 */
- (void)openURL:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END

#endif
