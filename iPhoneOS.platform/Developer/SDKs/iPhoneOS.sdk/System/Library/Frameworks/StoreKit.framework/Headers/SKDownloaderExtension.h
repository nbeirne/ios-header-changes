//
//  SKDownloaderExtension.h
//  StoreKit
//
//  Created by Gabriel Jacoby-Cooper on 3/20/25.
//  Copyright © 2025 Apple Inc. All rights reserved.
//

#if __has_include(<BackgroundAssets/BackgroundAssets.h>)
#import <BackgroundAssets/BackgroundAssets.h>

/// A protocol to which a downloader extension for Apple-Hosted Background Assets must conform.
///
/// The protocol provides default implementations for all of the inherited `BADownloaderExtension` requirements. You can optionally implement the inherited `BAManagedDownloaderExtension` requirements. For more information, see <doc://com.apple.documentation/documentation/backgroundassets>.
/// - Warning: Don’t implement any of the inherited `BADownloaderExtension` requirements.
API_AVAILABLE(ios(26.0), macos(26.0), tvos(26.0), visionos(26.0))
API_UNAVAILABLE(watchos)
NS_REFINED_FOR_SWIFT
@protocol SKDownloaderExtension <BAManagedDownloaderExtension>

@end
#endif
