//
//  CKShareBlockedIdentity.h
//  CloudKit
//
//  Copyright © 2025 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


#define CK_SHARE_BLOCKED_IDENTITY_AVAILABILITY API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), watchos(26.0), visionos(26.0))


@class CKUserIdentity, CNContact;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

CK_SHARE_BLOCKED_IDENTITY_AVAILABILITY
NS_SWIFT_NAME(CKShare.BlockedIdentity)
CK_SUBCLASSING_EXTERNALLY_RESTRICTED // should not be subclassed, or Sendable may no longer apply
NS_SWIFT_SENDABLE
@interface CKShareBlockedIdentity : NSObject <NSSecureCoding, NSCopying>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// The user identity this blocked identity represents.
@property (readonly, copy, nonatomic) CKUserIdentity *userIdentity;

#if !TARGET_OS_TV

/// Returns a displayable `CNContact` for the blocked identity, or a new `CNContact` if none exists in the user's contacts.
/// Provides a standardized format for the blocked identity's underlying lookup info in the user identity.
/// Use when displaying the blocked identity information to other participants in application UI.
@property (nonatomic, readonly, copy) CNContact *contact;

#endif

@end

NS_HEADER_AUDIT_END(nullability, sendability)
