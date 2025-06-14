//
//  INSearchForMessagesIntentResponse.h
//  Intents
//
//  Copyright (c) 2016-2025 Apple Inc. All rights reserved.
//

#import <Intents/INIntentResponse.h>

@class INMessage;

typedef NS_ENUM(NSInteger, INSearchForMessagesIntentResponseCode) {
    INSearchForMessagesIntentResponseCodeUnspecified = 0,
    INSearchForMessagesIntentResponseCodeReady,
    INSearchForMessagesIntentResponseCodeInProgress,
    INSearchForMessagesIntentResponseCodeSuccess,
    INSearchForMessagesIntentResponseCodeFailure,
    INSearchForMessagesIntentResponseCodeFailureRequiringAppLaunch,
    INSearchForMessagesIntentResponseCodeFailureMessageServiceNotAvailable,
    INSearchForMessagesIntentResponseCodeFailureMessageTooManyResults,
    INSearchForMessagesIntentResponseCodeFailureRequiringInAppAuthentication API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0)) API_UNAVAILABLE(tvos),
} API_AVAILABLE(ios(10.0), watchos(3.2)) API_UNAVAILABLE(macos, tvos);

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(10.0), watchos(3.2))
API_UNAVAILABLE(macos, tvos)
@interface INSearchForMessagesIntentResponse : INIntentResponse

- (id)init NS_UNAVAILABLE;

// The app extension has the option of capturing its private state as an NSUserActivity and returning it as the 'currentActivity'.
// If the the app is launched, an NSUserActivity will be passed in with the private state.  The NSUserActivity may also be used to query the app's UI extension (if provided) for a view controller representing the current intent handling state.
// In the case of app launch, the NSUserActivity will have its activityType set to the name of the intent. This intent object will also be available in the NSUserActivity.interaction property.
- (instancetype)initWithCode:(INSearchForMessagesIntentResponseCode)code userActivity:(nullable NSUserActivity *)userActivity NS_DESIGNATED_INITIALIZER;

@property (readonly, NS_NONATOMIC_IOSONLY) INSearchForMessagesIntentResponseCode code;

@property (readwrite, copy, nullable, NS_NONATOMIC_IOSONLY) NSArray<INMessage *> *messages;

@end

NS_ASSUME_NONNULL_END
