//
//  CKShareAccessRequester.h
//  CloudKit
//
//  Copyright © 2025 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


#define CK_SHARE_ACCESS_REQUESTER_AVAILABILITY API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), watchos(26.0), visionos(26.0))


@class CKUserIdentity, CKUserIdentityLookupInfo, CNContact;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

CK_SHARE_ACCESS_REQUESTER_AVAILABILITY
NS_SWIFT_NAME(CKShare.AccessRequester)
CK_SUBCLASSING_RESTRICTED // should not be subclassed, or Sendable may no longer apply
NS_SWIFT_SENDABLE
@interface CKShareAccessRequester : NSObject <NSSecureCoding, NSCopying>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// The user identity this share access requester represents.
@property (readonly, copy) CKUserIdentity *userIdentity;

/// Convenience method to get the requester's lookup info.
/// This lookup info can be used in ``CKFetchShareParticipantsOperation`` to approve the requester by fetching the corresponding participant and adding the participant to the share.
@property (nonatomic, readonly, copy) CKUserIdentityLookupInfo *participantLookupInfo;

#if !TARGET_OS_TV

/// Returns a displayable `CNContact` for the requester, or a new `CNContact` if none exists in the user's contacts.
/// Provides a standardized format for the requester's underlying lookup info in the user identity.
/// Use when displaying the requester information to other participants and approvers in application UI.
@property (nonatomic, readonly, copy) CNContact *contact;

#endif

@end

NS_HEADER_AUDIT_END(nullability, sendability)
