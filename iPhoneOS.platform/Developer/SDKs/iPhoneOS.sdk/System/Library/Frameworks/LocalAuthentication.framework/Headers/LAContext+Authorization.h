//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LocalAuthentication/LAContext.h>

NS_ASSUME_NONNULL_BEGIN

@class LARight;

/// @brief Extensions on the @c LAContext interface for inter-operability with the Authorization API
API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(watchos, tvos)
@interface LAContext (LARight)

/// @brief Evaluates the given @c LARight using in the current @c LAContext
/// @param right Right to be evaluated.
/// @param localizedReason Localized explanation for the authorization. Appears in the UI presented to the user.
/// @param reply Returns error in case evaluation has failed
- (void)evaluateRight:(LARight *)right localizedReason:(NSString *)localizedReason reply:(void (^)(NSError *_Nullable))reply;

/// @brief Preflights the given @c LARight using in the current @c LAContext
/// @param right Right to be evaluated.
/// @param reply Completion handler. Returns @c nil if the right can be authorized or an error otherwise.
- (void)checkCanEvaluateRight:(LARight *)right reply:(void (^)(NSError *_Nullable))reply;
@end

NS_ASSUME_NONNULL_END
