//
//  SWCollaborationBarButtonItem.h
//  SocialLayer
//
//  Copyright (c) 2022 Apple. All rights reserved.
//

#import <SharedWithYouCore/SWDefines.h>

#if TARGET_OS_IOS

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
//@available(iOS 16, macOS 13, *)
//@available(watchOS, unavailable)
//@available(tvOS, unavailable)
@interface _SWCollaborationBarButtonItem : UIBarButtonItem

@property (nonatomic, strong) NSItemProvider *itemProvider;
@property (nonatomic, strong) id<UICloudSharingControllerDelegate> cloudSharingControllerDelegate;
@property (nonatomic, assign) NSUInteger activeParticipantCount;
@property (nonatomic, assign) BOOL isContentShared;

- (instancetype)initWithItemProvider:(NSItemProvider *)itemProvider;

- (void)dismissPopoverAnimated:(BOOL)animated completion:(void (^_Nullable)(void))completion;

- (void)setDetailViewListContent:(UIView *)detailViewListContentView;

@end

NS_ASSUME_NONNULL_END

#endif
