//
//  INSetProfileInCarIntent.h
//  Intents
//
//  Copyright (c) 2016-2025 Apple Inc. All rights reserved.
//

#import <Intents/INIntent.h>
#import <Intents/INIntentResolutionResult.h>

@class INIntegerResolutionResult;
@class INSpeakableString;
@class INSpeakableStringResolutionResult;
@class INStringResolutionResult;
@class INBooleanResolutionResult;

NS_ASSUME_NONNULL_BEGIN

API_DEPRECATED("INSetProfileInCarIntent is deprecated. There is no replacement.", ios(10.0, 15.0))
API_UNAVAILABLE(macos, watchos, tvos)
@interface INSetProfileInCarIntent : INIntent

- (instancetype)initWithProfileNumber:(nullable NSNumber *)profileNumber
                          profileName:(nullable NSString *)profileName
                       defaultProfile:(nullable NSNumber *)defaultProfile
                              carName:(nullable INSpeakableString *)carName NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT API_AVAILABLE(ios(12.0));

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSNumber *profileNumber NS_REFINED_FOR_SWIFT;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *profileName API_AVAILABLE(ios(10.2));

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSNumber *defaultProfile NS_REFINED_FOR_SWIFT;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INSpeakableString *carName API_AVAILABLE(ios(12.0));

@end

@class INSetProfileInCarIntentResponse;

/*!
 @abstract Protocol to declare support for handling an INSetProfileInCarIntent. By implementing this protocol, a class can provide logic for resolving, confirming and handling the intent.
 @discussion The minimum requirement for an implementing class is that it should be able to handle the intent. The resolution and confirmation methods are optional. The handling method is always called last, after resolving and confirming the intent.
 */

API_DEPRECATED("INSetProfileInCarIntentHandling is deprecated. There is no replacement.", ios(10.0, 15.0))
API_UNAVAILABLE(macos, watchos, tvos)
@protocol INSetProfileInCarIntentHandling <NSObject>

@required

/*!
 @abstract Handling method - Execute the task represented by the INSetProfileInCarIntent that's passed in
 @discussion Called to actually execute the intent. The app must return a response for this intent.

 @param  intent The input intent
 @param  completion The response handling block takes a INSetProfileInCarIntentResponse containing the details of the result of having executed the intent

 @see  INSetProfileInCarIntentResponse
 */

- (void)handleSetProfileInCar:(INSetProfileInCarIntent *)intent
                   completion:(void (^)(INSetProfileInCarIntentResponse *response))completion NS_SWIFT_NAME(handle(intent:completion:));

@optional

/*!
 @abstract Confirmation method - Validate that this intent is ready for the next step (i.e. handling)
 @discussion Called prior to asking the app to handle the intent. The app should return a response object that contains additional information about the intent, which may be relevant for the system to show the user prior to handling. If unimplemented, the system will assume the intent is valid following resolution, and will assume there is no additional information relevant to this intent.

 @param  intent The input intent
 @param  completion The response block contains an INSetProfileInCarIntentResponse containing additional details about the intent that may be relevant for the system to show the user prior to handling.

 @see INSetProfileInCarIntentResponse
 */

- (void)confirmSetProfileInCar:(INSetProfileInCarIntent *)intent
                    completion:(void (^)(INSetProfileInCarIntentResponse *response))completion NS_SWIFT_NAME(confirm(intent:completion:));

/*!
 @abstract Resolution methods - Determine if this intent is ready for the next step (confirmation)
 @discussion Called to make sure the app extension is capable of handling this intent in its current form. This method is for validating if the intent needs any further fleshing out.

 @param  intent The input intent
 @param  completion The response block contains an INIntentResolutionResult for the parameter being resolved

 @see INIntentResolutionResult
 */

- (void)resolveProfileNumberForSetProfileInCar:(INSetProfileInCarIntent *)intent
                                withCompletion:(void (^)(INIntegerResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveProfileNumber(for:with:));

- (void)resolveProfileNameForSetProfileInCar:(INSetProfileInCarIntent *)intent
                              withCompletion:(void (^)(INStringResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveProfileName(for:with:)) API_AVAILABLE(ios(10.2));

- (void)resolveCarNameForSetProfileInCar:(INSetProfileInCarIntent *)intent
                          withCompletion:(void (^)(INSpeakableStringResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveCarName(for:with:)) API_AVAILABLE(ios(12.0));

- (void)resolveDefaultProfileForSetProfileInCar:(INSetProfileInCarIntent *)intent
                                 withCompletion:(void (^)(INBooleanResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveDefaultProfile(forSetProfileInCar:with:)) API_DEPRECATED("The property doesn't need to be resolved", ios(10.0, 11.0));

@end

NS_ASSUME_NONNULL_END
