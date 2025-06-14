//
//  MKTypes.h
//  MapKit
//
//  Copyright (c) 2009-2014, Apple Inc. All rights reserved.
//

#import <MapKit/MKFoundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MKMapType) {
    MKMapTypeStandard = 0,
    MKMapTypeSatellite,
    MKMapTypeHybrid,
    MKMapTypeSatelliteFlyover NS_ENUM_AVAILABLE(10_11, 9_0),
    MKMapTypeHybridFlyover NS_ENUM_AVAILABLE(10_11, 9_0),
    MKMapTypeMutedStandard NS_ENUM_AVAILABLE(10_13, 11_0) __TVOS_AVAILABLE(11_0),
} NS_ENUM_AVAILABLE(10_9, 3_0) __TVOS_AVAILABLE(9_2) API_UNAVAILABLE(watchos);

MK_EXTERN NSString *MKErrorDomain __TVOS_AVAILABLE(9_2);

typedef NS_ENUM(NSUInteger, MKErrorCode) {
    MKErrorUnknown = 1,
    MKErrorServerFailure,
    MKErrorLoadingThrottled,
    MKErrorPlacemarkNotFound,
    MKErrorDirectionsNotFound NS_ENUM_AVAILABLE(10_9, 7_0),
    MKErrorDecodingFailed API_AVAILABLE(ios(13.0), tvos(13.0), macos(10.15), watchos(6.0)),
} API_AVAILABLE(macos(10.9), ios(3.0), tvos(9.2), watchos(1.0));

typedef NS_ENUM(NSInteger, MKFeatureVisibility) {
    MKFeatureVisibilityAdaptive,
    MKFeatureVisibilityHidden,
    MKFeatureVisibilityVisible
} API_AVAILABLE(ios(11.0), tvos(11.0), macos(11.0)) API_UNAVAILABLE(watchos);

typedef NS_ENUM(NSInteger, MKLocalSearchRegionPriority) {
    MKLocalSearchRegionPriorityDefault = 0,
    MKLocalSearchRegionPriorityRequired
} API_AVAILABLE(ios(18.0), visionos(2.0), tvos(18.0), macos(15.0), watchos(11.0));

NS_ASSUME_NONNULL_END
