//
//  INSearchForMediaIntentResponse.h
//  Intents
//
//  Copyright (c) 2016-2025 Apple Inc. All rights reserved.
//

#import <Intents/INIntentResponse.h>

@class INMediaItem;

typedef NS_ENUM(NSInteger, INSearchForMediaIntentResponseCode) {
    INSearchForMediaIntentResponseCodeUnspecified = 0,
    INSearchForMediaIntentResponseCodeReady,
    INSearchForMediaIntentResponseCodeContinueInApp,
    INSearchForMediaIntentResponseCodeInProgress,
    INSearchForMediaIntentResponseCodeSuccess,
    INSearchForMediaIntentResponseCodeFailure,
    INSearchForMediaIntentResponseCodeFailureRequiringAppLaunch,
} API_AVAILABLE(ios(13.0), watchos(6.0), tvos(14.0)) API_UNAVAILABLE(macos);

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13.0), watchos(6.0), tvos(14.0))
API_UNAVAILABLE(macos)
@interface INSearchForMediaIntentResponse : INIntentResponse

- (id)init NS_UNAVAILABLE;

// The app extension has the option of capturing its private state as an NSUserActivity and returning it as the 'currentActivity'.
// If the the app is launched, an NSUserActivity will be passed in with the private state.  The NSUserActivity may also be used to query the app's UI extension (if provided) for a view controller representing the current intent handling state.
// In the case of app launch, the NSUserActivity will have its activityType set to the name of the intent. This intent object will also be available in the NSUserActivity.interaction property.
- (instancetype)initWithCode:(INSearchForMediaIntentResponseCode)code userActivity:(nullable NSUserActivity *)userActivity NS_DESIGNATED_INITIALIZER;

@property (readonly, NS_NONATOMIC_IOSONLY) INSearchForMediaIntentResponseCode code;

@property (readwrite, copy, nullable, NS_NONATOMIC_IOSONLY) NSArray<INMediaItem *> *mediaItems;

@end

NS_ASSUME_NONNULL_END
