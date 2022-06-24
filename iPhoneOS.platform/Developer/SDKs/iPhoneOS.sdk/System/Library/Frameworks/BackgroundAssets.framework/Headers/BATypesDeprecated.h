//
//  BATypesDeprecated.h
//  BackgroundAssets
//
//  Copyright (c) 2022, Apple Inc.
//  All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BackgroundAssets/BackgroundAssets.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *kBADownloaderInfoDictionaryApplicationIdentifierKey
API_DEPRECATED_WITH_REPLACEMENT("BADownloaderExtensionMetadataKeyApplicationIdentifier", macos(13.0, 13.0), ios(16.0, 16.0))
API_UNAVAILABLE(tvos, watchos);

FOUNDATION_EXPORT NSString *kBADownloaderInfoDictionaryLocalizedApplicationNameKey
API_DEPRECATED_WITH_REPLACEMENT("BADownloaderExtensionMetadataKeyLocalizedApplicationName", macos(13.0, 13.0), ios(16.0, 16.0))
API_UNAVAILABLE(tvos, watchos);

FOUNDATION_EXPORT NSString *kBADownloaderInfoDictionaryApplicationCacheLocationURLKey
API_DEPRECATED_WITH_REPLACEMENT("BADownloaderExtensionMetadataKeyApplicationCacheLocationURL", macos(13.0, 13.0), ios(16.0, 16.0))
API_UNAVAILABLE(tvos, watchos);

FOUNDATION_EXPORT NSString *kBADownloaderInfoDictionaryApplicationLocationURLKey
API_DEPRECATED_WITH_REPLACEMENT("BADownloaderExtensionMetadataKeyApplicationLocationURL", macos(13.0, 13.0), ios(16.0, 16.0))
API_UNAVAILABLE(tvos, watchos);

NS_ASSUME_NONNULL_END
