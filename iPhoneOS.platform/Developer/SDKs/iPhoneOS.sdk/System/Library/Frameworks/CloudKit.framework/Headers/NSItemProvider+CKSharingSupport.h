//
//  NSItemProvider+CKSharingSupport.h
//  CloudKit
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CloudKit/CKDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class CKShare, CKContainer, CKAllowedSharingOptions;

typedef void (^CKSharePreparationCompletionHandler)(CKShare * _Nullable, NSError * _Nullable) NS_SWIFT_UNAVAILABLE("Use the async throwing preparationHandler instead.");
typedef void (^CKSharePreparationHandler)(CKSharePreparationCompletionHandler) NS_SWIFT_UNAVAILABLE("Use the async throwing preparationHandler instead.");

@interface NSItemProvider (CKSharingSupport)

/*!
 Use this method when you want to share a collection of @c CKRecords but don't currently have a @c CKShare. When the @c preparationHandler is called, you should create a new @c CKShare with the appropriate root @c CKRecord or @c CKRecordZoneID. After ensuring the share and all records have been saved to the server, invoke the @c preparationCompletionHandler with either the resulting @c CKShare, or an @c NSError if saving failed. Invoking the share sheet with a @c CKShare registered with this method will prompt the user to start sharing.
 */
- (void)registerCKShareWithContainer:(CKContainer *)container allowedSharingOptions:(CKAllowedSharingOptions *)allowedOptions preparationHandler:(CKSharePreparationHandler)preparationHandler API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(watchos, tvos) NS_REFINED_FOR_SWIFT;

/*!
 Use this method when you have a @c CKShare that is already saved to the server. Invoking the share sheet with a @c CKShare registered with this method will allow the owner to make modifications to the share settings, or will allow a participant to view the share settings.
 */
- (void)registerCKShare:(CKShare *)share container:(CKContainer *)container allowedSharingOptions:(CKAllowedSharingOptions *)allowedOptions API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(watchos, tvos) NS_REFINED_FOR_SWIFT;

@end

#pragma mark - Deprecated API

// Will be deprecated soon. Please use CKAllowedSharingOptions.
typedef NS_OPTIONS(NSUInteger, CKSharingOptions) {
    /*! Allow the user to configure the share with the standard set of options. */
    CKSharingOptionsStandard = 0,

    /*! If specified, the system UI will allow the user to share publicly i.e. anyone with the link has access. */
    CKSharingOptionsAllowPublic = 1 << 0,

    /*! If specified, the system UI will allow the user to share privately to specified recipients. */
    CKSharingOptionsAllowPrivate = 1 << 1,

    /*! If specified, the system UI will allow the user to grant participants read-only permissions. */
    CKSharingOptionsAllowReadOnly = 1 << 4,

    /*! If specified, the system UI will allow the user to grant participants read/write permissions. */
    CKSharingOptionsAllowReadWrite = 1 << 5,
} API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(watchos, tvos);

@interface NSItemProvider (Deprecated_CKSharingSupport)

// Will be deprecated soon. Please use -[NSItemProvider registerCKShareWithContainer:allowedSharingOptions:preparationHandler:]
- (void)registerCKShareWithContainer:(CKContainer *)container sharingOptions:(CKSharingOptions)sharingOptions preparationHandler:(CKSharePreparationHandler)preparationHandler API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(watchos, tvos) NS_REFINED_FOR_SWIFT;

// Will be deprecated soon. Please use -[NSItemProvider registerCKShare:container:allowedSharingOptions:]
- (void)registerCKShare:(CKShare *)share container:(CKContainer *)container sharingOptions:(CKSharingOptions)sharingOptions API_AVAILABLE(macos(13.0), ios(16.0)) API_UNAVAILABLE(watchos, tvos) NS_REFINED_FOR_SWIFT;
@end

NS_ASSUME_NONNULL_END

