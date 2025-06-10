//
//  CKShareRequestAccessOperation.h
//  CloudKit
//
//  Copyright © 2025 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CloudKit/CKDatabaseOperation.h>

@class CKShare;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), watchos(26.0), visionos(26.0))
@interface CKShareRequestAccessOperation : CKOperation

/// - Returns: A new ``CKShareRequestAccessOperation`` instance.
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/// Creates a ``CKShareRequestAccessOperation`` for requesting access to the specified shares.
///
/// - Parameter shareURLs: An array of `NSURL` objects for shares you wish to request access to
/// - Returns: A ``CKShareRequestAccessOperation`` instance configured with the given share URLs.
- (instancetype)initWithShareURLs:(NSArray<NSURL *> *)shareURLs NS_SWIFT_NAME(init(shareURLs:));

/// The share URLs for which access is being requested.
///
/// If requesting access to multiple shares, include multiple `NSURL` objects.
/// The server processes them independently.
@property (nullable, copy, nonatomic) NSArray<NSURL *> *shareURLs;

/// A block that is called once for each share URL processed by the server.
///
/// - Parameters:
///   - shareURL: The URL of the processed share.
///   - shareRequestAccessError: If non-nil, an error describing why the request failed for this share.
///
/// The server does **not** reveal share existence to the requester to protect privacy.
@property (nullable, copy, nonatomic) void (^perShareAccessRequestCompletionBlock)(NSURL *shareURL, NSError * _Nullable shareRequestAccessError) NS_REFINED_FOR_SWIFT;

/// A block that is called when the entire operation completes.
///
/// - Parameter operationError: If non-nil, an error describing why the request failed.
///
/// If operationError is CKErrorPartialFailure, the userInfo dictionary
/// contains per-share errors under ``CKPartialErrorsByItemIDKey``.
@property (nullable, copy, nonatomic) void (^shareRequestAccessCompletionBlock)(NSError * _Nullable operationError) NS_REFINED_FOR_SWIFT;

@end

NS_HEADER_AUDIT_END(nullability, sendability)
