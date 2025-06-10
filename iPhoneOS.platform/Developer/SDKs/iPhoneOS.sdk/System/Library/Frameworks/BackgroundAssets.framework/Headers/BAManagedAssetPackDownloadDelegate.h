//
//  BAManagedAssetPackDownloadDelegate.h
//  Background Assets
//
//  Created by Gabriel Jacoby-Cooper on 3/10/25.
//

#import <BackgroundAssets/BAAssetPack.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/// A type that can receive notifications about events that occur as an asset pack is downloaded.
API_AVAILABLE(ios(26.0), macos(26.0), tvos(26.0), visionos(26.0))
API_UNAVAILABLE(watchos)
NS_SWIFT_SENDABLE
NS_REFINED_FOR_SWIFT
@protocol BAManagedAssetPackDownloadDelegate <NSObject>

@optional

/// Notifies the receiver that an asset pack began or resumed being downloaded.
/// - Parameter assetPack: The asset pack.
- (void)downloadOfAssetPackBegan:(BAAssetPack*)assetPack;

/// Notifies the receiver that an asset pack is currently being downloaded.
/// - Parameters:
///   - assetPack: The asset pack.
///   - progress: The download progress.
- (void)downloadOfAssetPack:(BAAssetPack*)assetPack
                hasProgress:(NSProgress*)progress;

/// Notifies the receiver that an asset pack paused being downloaded.
/// - Parameter assetPack: The asset pack.
- (void)downloadOfAssetPackPaused:(BAAssetPack*)assetPack;

/// Notifies the receiver that an asset pack is now available locally.
/// - Parameter assetPack: The asset pack.
- (void)downloadOfAssetPackFinished:(BAAssetPack*)assetPack;

/// Notifies the receiver that an asset pack failed to be downloaded.
/// - Parameters:
///   - assetPack: The asset pack.
///   - error: The error that occured.
- (void)downloadOfAssetPack:(BAAssetPack*)assetPack
            failedWithError:(NSError*)error;

@end

NS_HEADER_AUDIT_END(nullability, sendability)
