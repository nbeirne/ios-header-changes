//
//  INRequestPaymentPayerResolutionResult.h
//  Intents
//
//  Copyright (c) 2016-2025 Apple Inc. All rights reserved.
//

#import <Intents/INPersonResolutionResult.h>

typedef NS_ENUM(NSInteger, INRequestPaymentPayerUnsupportedReason) {
    INRequestPaymentPayerUnsupportedReasonCredentialsUnverified = 1,
    INRequestPaymentPayerUnsupportedReasonNoAccount,
    INRequestPaymentPayerUnsupportedReasonNoValidHandle API_AVAILABLE(ios(11.1), watchos(4.1)),
} API_AVAILABLE(ios(11.0), watchos(4.0)) API_UNAVAILABLE(macos, tvos);

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(11.0), watchos(4.0))
API_UNAVAILABLE(macos, tvos)
@interface INRequestPaymentPayerResolutionResult : INPersonResolutionResult

+ (instancetype)unsupportedForReason:(INRequestPaymentPayerUnsupportedReason)reason NS_SWIFT_NAME(unsupported(forReason:));

- (instancetype)initWithPersonResolutionResult:(INPersonResolutionResult *)personResolutionResult;

@end

NS_ASSUME_NONNULL_END
