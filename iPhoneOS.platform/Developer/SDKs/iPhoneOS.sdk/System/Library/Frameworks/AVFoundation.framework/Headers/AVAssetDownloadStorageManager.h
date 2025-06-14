#if !__has_include(<AVFCore/AVAssetDownloadStorageManager.h>)
/*
	File:  AVAssetDownloadStorageManager.h
 
	Framework:  AVFoundation
 
	Copyright 2017-2023 Apple Inc. All rights reserved.
 
 */

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AVAssetDownloadStorageManagementPolicy;
// Used by AVAssetDownloadStorageManagementPolicy.

/// These constants represents the eviction priority of downloaded assets.
typedef NSString *AVAssetDownloadedAssetEvictionPriority NS_STRING_ENUM API_AVAILABLE(macos(10.15), ios(11.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos);
/// Used to mark assets with the highest priority. They will be the last to be purged.
AVF_EXPORT AVAssetDownloadedAssetEvictionPriority const AVAssetDownloadedAssetEvictionPriorityImportant				API_AVAILABLE(macos(10.15), ios(11.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos);
/// Used to mark assets have the default priority. They will be the first to be purged.
AVF_EXPORT AVAssetDownloadedAssetEvictionPriority const AVAssetDownloadedAssetEvictionPriorityDefault				API_AVAILABLE(macos(10.15), ios(11.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos);

/// An AVAssetDownloadStorageManager manages the policy for automatic purging of downloaded AVAssets. The policy is vended as AVAssetDownloadStorageManagementPolicy object.
/// 
/// When a storage management policy needs to be set on an asset, sharedDownloadStorageManager singleton needs to be fetched. 
/// The new policy can then be set by using setStorageManagementPolicy and the location of the downloaded asset.
API_AVAILABLE(macos(10.15), ios(11.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos)
@interface AVAssetDownloadStorageManager : NSObject

/// returns singleton instance.
+ (AVAssetDownloadStorageManager *)sharedDownloadStorageManager;

/// Sets the policy for asset with disk backing at downloadStorageURL.
/// 
/// - Parameter downloadStorageURL: The location of downloaded asset.
- (void)setStorageManagementPolicy:(AVAssetDownloadStorageManagementPolicy *)storageManagementPolicy forURL:(NSURL *)downloadStorageURL;

/// Returns the storage management policy for asset downloaded at downloadStorageURL. This may be nil if a storageManagementPolicy was never set on the downloaded asset.
/// 
/// - Parameter downloadStorageURL: The location of downloaded asset.
- (nullable AVAssetDownloadStorageManagementPolicy *)storageManagementPolicyForURL:(NSURL *)downloadStorageURL;

@end


@class AVAssetDownloadStorageManagementPolicyInternal;

/// A class to inform the system of a policy for automatic purging of downloaded AVAssets.
/// 
/// System will put in best-effort to evict all the assets based on expirationDate before evicting based on priority.
API_AVAILABLE(macos(10.15), ios(11.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos)
@interface AVAssetDownloadStorageManagementPolicy : NSObject <NSCopying, NSMutableCopying> {
@private
	AVAssetDownloadStorageManagementPolicyInternal    *_storageManagementPolicy;
}

/// Indicates the eviction priority of downloaded asset.
/// 
/// Assets with default priority will be purged first before assets with higher priorities.
/// In case this is not set, default priority is used.
@property (nonatomic, readonly, copy) AVAssetDownloadedAssetEvictionPriority priority;

/// Returns the expiration date of asset.
@property (nonatomic, readonly, copy) NSDate *expirationDate;

@end

/// A mutable subclass of AVAssetDownloadStorageManagementPolicy.
/// 
/// System will put in best-effort to evict all the assets based on expirationDate before evicting based on priority.
NS_SWIFT_NONSENDABLE
API_AVAILABLE(macos(10.15), ios(11.0), visionos(1.0)) API_UNAVAILABLE(tvos, watchos)
@interface AVMutableAssetDownloadStorageManagementPolicy : AVAssetDownloadStorageManagementPolicy

/// Indicates the eviction priority of downloaded asset.
/// 
/// Assets with default priority will be purged first before assets with higher priorities.
/// In case this is not set, default priority is used.
@property (nonatomic, copy) AVAssetDownloadedAssetEvictionPriority priority;

/// Returns the expiration date of asset.
@property (nonatomic, copy) NSDate *expirationDate;

@end

NS_ASSUME_NONNULL_END

#else
#import <AVFCore/AVAssetDownloadStorageManager.h>
#endif
