/*
 * Copyright (c) 2020-2022, 2025 Apple Inc.
 * All rights reserved.
 */

#ifndef __NE_INDIRECT__
#error "Please import the NetworkExtension module instead of this file directly."
#endif

NS_ASSUME_NONNULL_BEGIN

/*!
 * @file NEAppPushProvider.h
 * @discussion This file declares the NEAppPushProvider API. The NEAppPushProvider API is used to manage the life cycle of the provider.
 * The API also allows provider to report incoming call and handle outgoing call message from the containing app.
*/

/*!
 * @interface NEAppPushProvider
 * @discussion The NEAppPushProvider class declares a programmatic interface to manage a life cycle of app push provider. It also allows the provider to handle outgoing
 * communication message from the containing app, and pass incoming call message to the containing app.
 * NEAppPushProvider is part of NetworkExtension.framework
 */
API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface NEAppPushProvider : NEProvider

/*!
 * @property providerConfiguration
 * @discussion A dictionary containing current vendor-specific configuration parameters. This dictionary is provided by NEAppPushManager. Use KVO to watch for changes.
 */
@property (readonly, nullable) NSDictionary<NSString *, id> *providerConfiguration API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos, tvos);

/*!
 * @method startWithCompletionHandler:completionHandler:
 * @discussion This method is called by the framework when the provider is started. Subclasses must override this method to create a connection with its server.
 * @param completionHandler A block that must be called when the provider establishes a connection with the server. If the providers fails to create a connection,
 * the subclass' implementation of this method must pass a non-nil NSError object to this block. A value of nil passed to the completion handler indicates that the connection
 * was successfully created.
 */
- (void)startWithCompletionHandler:(void (^)(NSError * __nullable error))completionHandler NS_SWIFT_DISABLE_ASYNC API_DEPRECATED_WITH_REPLACEMENT("start", ios(14.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(macos, watchos, tvos);

/*!
 * @method start
 * @discussion This method is called by the framework when the provider is started. Subclasses must override this method to create a connection with its server.
 */
- (void)start API_AVAILABLE(ios(15.0)) API_UNAVAILABLE(macos, watchos, tvos);


/*!
 * @method stopWithReason:reason:completionHandler:
 * @discussion This method is called by the framework when the app push provider needs to be stopped. Subclasses must override this method to perform necessary tasks.
 * @param reason An NEProviderStopReason indicating why the provider was stopped.
 * @param completionHandler A block that must be called when the provider is completely stopped.
 */
- (void)stopWithReason:(NEProviderStopReason)reason completionHandler:(void (^)(void))completionHandler API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos, tvos);

/*!
 * @method reportIncomingCallWithUserInfo:userinfo:
 * @discussion This function is called by the provider when it determines incoming call on the conection.
 * @param userInfo A dictionary of custom information associated with the incoming call. This dictionary is passed to containg app as-is.
*/
- (void)reportIncomingCallWithUserInfo:(NSDictionary * _Nonnull)userInfo API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos, tvos);

/*!
 * @method reportPushToTalkMessageWithUserInfo:userinfo:
 * @discussion This function is called by the provider when it receives a Push to Talk message on the connection.
 * @param userInfo A dictionary of custom information associated with the Push to Talk message, such as the active remote participant. This dictionary is passed to the PTChannelManagerDelegate of the containing app if the user is joined to a Push to Talk channel.
*/
- (void)reportPushToTalkMessageWithUserInfo:(NSDictionary * _Nonnull)userInfo API_AVAILABLE(ios(16.4)) API_UNAVAILABLE(macos, macCatalyst, tvos) __WATCHOS_PROHIBITED;

/*!
 * @method handleTimerEvent
 * @discussion This method is called by the framework periodically after every 60 seconds. Subclasses must override this method to perform necessary tasks.
 */
- (void)handleTimerEvent API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos, tvos);

/*!
 * @method unmatchEthernet
 * @discussion This method is called by the provider when it does not require runtime while the device is connected to the current Ethernet network.
 * This method is applicable only when NEAppPushManager has set matchEthernet property to YES and the provider is running because the device is connected to an
 * Ethernet network.
*/
- (void)unmatchEthernet API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(macos, watchos, tvos, visionos);

@end

NS_ASSUME_NONNULL_END
