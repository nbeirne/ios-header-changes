//
//  MKLocalSearch.h
//  MapKit
//
//  Copyright (c) 2012-2014, Apple Inc. All rights reserved.
//

#import <MapKit/MKFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MKLocalPointsOfInterestRequest;
@class MKLocalSearchRequest;
@class MKLocalSearchResponse;

typedef void (^MKLocalSearchCompletionHandler)(MKLocalSearchResponse * __nullable response, NSError * __nullable error);

API_AVAILABLE(macos(10.9), ios(6.1), tvos(9.2), watchos(1.0))
@interface MKLocalSearch : NSObject

// The request will be copied during initialization, so any changes made to the request
// after this method returns do not affect the request used in -startWithCompletionHandler:
- (instancetype)initWithRequest:(MKLocalSearchRequest *)request NS_DESIGNATED_INITIALIZER;

// The request will be copied during initialization, so any changes made to the request
// after this method returns do not affect the request used in -startWithCompletionHandler:
- (instancetype)initWithPointsOfInterestRequest:(MKLocalPointsOfInterestRequest *)request NS_DESIGNATED_INITIALIZER API_AVAILABLE(ios(14.0), macos(11.0), tvos(14.0), watchos(7.0));

// Any calls to -startWithCompletionHandler: while -[MKLocalSearch isSearching] will fail.
// completionHandler will be called on the main queue
- (void)startWithCompletionHandler:(NS_SWIFT_UI_ACTOR MKLocalSearchCompletionHandler)completionHandler;
- (void)cancel;

@property (nonatomic, readonly, getter=isSearching) BOOL searching;

@end

NS_ASSUME_NONNULL_END
