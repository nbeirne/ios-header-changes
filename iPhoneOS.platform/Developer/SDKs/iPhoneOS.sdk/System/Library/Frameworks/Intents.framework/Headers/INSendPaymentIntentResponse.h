//
//  INSendPaymentIntentResponse.h
//  Intents
//
//  Copyright (c) 2016-2025 Apple Inc. All rights reserved.
//

#import <Intents/INIntentResponse.h>

@class INPaymentRecord;

typedef NS_ENUM(NSInteger, INSendPaymentIntentResponseCode) {
    INSendPaymentIntentResponseCodeUnspecified = 0,
    INSendPaymentIntentResponseCodeReady,
    INSendPaymentIntentResponseCodeInProgress,
    INSendPaymentIntentResponseCodeSuccess,
    INSendPaymentIntentResponseCodeFailure,
    INSendPaymentIntentResponseCodeFailureRequiringAppLaunch,
    INSendPaymentIntentResponseCodeFailureCredentialsUnverified,
    INSendPaymentIntentResponseCodeFailurePaymentsAmountBelowMinimum,
    INSendPaymentIntentResponseCodeFailurePaymentsAmountAboveMaximum,
    INSendPaymentIntentResponseCodeFailurePaymentsCurrencyUnsupported,
    INSendPaymentIntentResponseCodeFailureInsufficientFunds,
    INSendPaymentIntentResponseCodeFailureNoBankAccount,
    INSendPaymentIntentResponseCodeFailureNotEligible API_AVAILABLE(ios(11.0), watchos(4.0)),
    INSendPaymentIntentResponseCodeFailureTermsAndConditionsAcceptanceRequired API_AVAILABLE(ios(11.1), watchos(4.1)),
} API_AVAILABLE(ios(10.0), watchos(3.2)) API_UNAVAILABLE(macos, tvos);

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(10.0), watchos(3.2))
API_UNAVAILABLE(macos, tvos)
@interface INSendPaymentIntentResponse : INIntentResponse

- (id)init NS_UNAVAILABLE;

// The app extension has the option of capturing its private state as an NSUserActivity and returning it as the 'currentActivity'.
// If the the app is launched, an NSUserActivity will be passed in with the private state.  The NSUserActivity may also be used to query the app's UI extension (if provided) for a view controller representing the current intent handling state.
// In the case of app launch, the NSUserActivity will have its activityType set to the name of the intent. This intent object will also be available in the NSUserActivity.interaction property.
- (instancetype)initWithCode:(INSendPaymentIntentResponseCode)code userActivity:(nullable NSUserActivity *)userActivity NS_DESIGNATED_INITIALIZER;

@property (readonly, NS_NONATOMIC_IOSONLY) INSendPaymentIntentResponseCode code;

@property (readwrite, copy, nullable, NS_NONATOMIC_IOSONLY) INPaymentRecord *paymentRecord;

@end

NS_ASSUME_NONNULL_END
