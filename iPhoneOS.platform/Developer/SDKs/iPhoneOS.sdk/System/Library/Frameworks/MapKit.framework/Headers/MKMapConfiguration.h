//
//  MKMapConfiguration.h
//  MapKit
//
//  Copyright © 2021 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

// To be removed; please use MKMapElevationStyle.
typedef NS_ENUM(NSInteger, MKMapLandscape) {
    MKMapLandscapeDefault = 0,
    MKMapLandscapeDetailed,
};

API_AVAILABLE(ios(16.0), tvos(16.0), macos(13.0)) API_UNAVAILABLE(watchos)
typedef NS_ENUM(NSInteger, MKMapElevationStyle) {
    MKMapElevationStyleFlat = 0,
    MKMapElevationStyleRealistic,
};

NS_ASSUME_NONNULL_BEGIN

MK_EXTERN
API_AVAILABLE(ios(16.0), macos(13.0), tvos(16.0)) API_UNAVAILABLE(watchos)
@interface MKMapConfiguration : NSObject <NSSecureCoding, NSCopying>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic) MKMapLandscape landscape; // To be removed; please use MKMapElevationStyle.
@property (nonatomic) MKMapElevationStyle elevationStyle;

@end

NS_ASSUME_NONNULL_END

