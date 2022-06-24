#if !__has_include(<PassKitCore/PKIdentityRequest.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKIdentityRequest.h
//  PassKit
//
//  Copyright © 2022 Apple, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <PassKit/PKIdentityDocumentDescriptor.h>

#ifndef PKIdentityRequest_h
#define PKIdentityRequest_h

NS_ASSUME_NONNULL_BEGIN

/// Request for information from an identity document stored as a Wallet pass.
API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface PKIdentityRequest: NSObject

/// A descriptor describing the identity document to request.
@property (readwrite, strong, nullable) id<PKIdentityDocumentDescriptor> descriptor;

/// A caller-specified nonce that will be included in the signed response payload.
/// This is treated as opaque by the PKIdentityAuthorizationController, and has a
/// maximum allowed size of 64 bytes.
@property (readwrite, copy, nullable) NSData *nonce;

/// Identifies the merchant making the request, as previously agreed with Apple.
/// This must match one of the merchant identifiers in the application's entitlement.
/// This property must be set when requestDocument is invoked.
@property (readwrite, copy, nullable) NSString *merchantIdentifier;

@end

NS_ASSUME_NONNULL_END

#endif /* PKIdentityRequest_h */


#else
#import <PassKitCore/PKIdentityRequest.h>
#endif
