//
//  BAManagedError.h
//  Background Assets
//
//  Created by Gabriel Jacoby-Cooper on 4/14/25.
//

#import <BackgroundAssets/BackgroundAssets.h>
#import <Foundation/Foundation.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/// The Managed Background Assets error domain.
BA_EXPORT NSErrorDomain const BAManagedErrorDomain API_AVAILABLE(ios(26.0), macos(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos) NS_REFINED_FOR_SWIFT;

/// The `-[NSError userInfo]` key for an asset pack’s identifier.
///
/// This key is relevant when the error code is ``BAManagedErrorCode/assetPackNotFound``.
BA_EXPORT NSErrorUserInfoKey const BAAssetPackIdentifierErrorKey API_AVAILABLE(ios(26.0), macos(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos) NS_REFINED_FOR_SWIFT;

/// A Managed Background Assets error code.
typedef NS_ENUM(NSInteger, BAManagedErrorCode) {
    
    /// An error code that indicates that an asset pack wasn’t found.
    ///
    /// Refer to the value in `-[NSError userInfo]` for the key `BAAssetPackIdentifierErrorKey` for the asset pack’s identifier.
    BAManagedErrorCodeAssetPackNotFound,
    
    /// An error code that indicates that a file wasn’t found.
    ///
    /// Refer to the value in `-[NSError userInfo]` for the key `NSFilePathErrorKey` for the file path.
    BAManagedErrorCodeFileNotFound
} API_AVAILABLE(ios(26.0), macos(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE(watchos) NS_REFINED_FOR_SWIFT;

NS_HEADER_AUDIT_END(nullability, sendability)
