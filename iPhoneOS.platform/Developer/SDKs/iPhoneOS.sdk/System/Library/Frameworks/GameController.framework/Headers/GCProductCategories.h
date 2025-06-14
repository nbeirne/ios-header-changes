//  
//  GCProductCategories.h
//  GameController
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <GameController/GCExtern.h>

/**
 A set of common values of -[GCDevice productCategory]. Check a device's' productCategory against these values to
 set appropriate UI elements based on what type of device is connected.
 
@see GCDevice.h
*/

/// Game Controller Product Categories

GAMECONTROLLER_EXPORT NSString *const GCProductCategoryDualSense API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));
GAMECONTROLLER_EXPORT NSString *const GCProductCategoryDualShock4 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));
GAMECONTROLLER_EXPORT NSString *const GCProductCategoryMFi API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));
GAMECONTROLLER_EXPORT NSString *const GCProductCategoryXboxOne API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));
GAMECONTROLLER_EXPORT NSString *const GCProductCategoryHID API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0));

/** The category for game controller products that support 6DoF tracking on visionOS. */
GAMECONTROLLER_EXPORT NSString *const GCProductCategorySpatialController API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0));


GAMECONTROLLER_EXPORT NSString *const GCProductCategoryArcadeStick API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));



/// Remote Product Categories

/// The Siri Remote (1st generation), or Apple TV Remote (1st generation), was first introduced in 2015. It features a Touch surface for touch navigation, and supports device motion.
GAMECONTROLLER_EXPORT NSString *const GCProductCategorySiriRemote1stGen API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));

/// The Siri Remote (2nd generation), or Apple TV Remote (2nd generation), was first introduced in 2021. It features a touch-enabled clickpad for navigation.
GAMECONTROLLER_EXPORT NSString *const GCProductCategorySiriRemote2ndGen API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));

/// Users can use Apple TV Remote controls in Control Center on an iOS or iPadOS device.
GAMECONTROLLER_EXPORT NSString *const GCProductCategoryControlCenterRemote API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));

/// The Universal Electronics remote is an infrared and Bluetooth Low Energy remote designed to work with the Apple TV.
GAMECONTROLLER_EXPORT NSString *const GCProductCategoryUniversalElectronicsRemote API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));

/**
 If multiple remotes have been combined into one, the device will have the GCProductCategoryCoalescedRemote product category.
 
 @discussion By default, the Game Controller framework will try to coalesce, or combine, the physical Apple TV Remote and the
 virtual Control Center remote and treat them as a single GCDevice instance. By setting GCSupportsMultipleMicroGamepads in your
 app's plist to true, you can disable this behavior.
*/
GAMECONTROLLER_EXPORT NSString *const GCProductCategoryCoalescedRemote API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));



/// Keyboards and Mice Product Categories

GAMECONTROLLER_EXPORT NSString *const GCProductCategoryMouse API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));
GAMECONTROLLER_EXPORT NSString *const GCProductCategoryKeyboard API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));


/// Stylus product categories

/** The category for stylus products that support 6DoF tracking on visionOS. */
GAMECONTROLLER_EXPORT NSString *const GCProductCategorySpatialStylus API_AVAILABLE(visionos(26.0)) API_UNAVAILABLE(macos, ios, tvos);
