//
//  SWRemoveParticipantAlertController.h
//  SWRemoveParticipantAlertController
//
//  Copyright (c) 2022 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SharedWithYouCore/SWDefines.h>

@class SWCollaborationHighlight;
@class _SWPerson;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(16.0), tvos(16.0)) API_UNAVAILABLE(watchos, macos)
SW_EXTERN @interface SWRemoveParticipantAlertController : UIViewController

+ (instancetype)alertControllerWithParticipant:(_SWPerson *)participant highlight:(SWCollaborationHighlight *)highlight;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
