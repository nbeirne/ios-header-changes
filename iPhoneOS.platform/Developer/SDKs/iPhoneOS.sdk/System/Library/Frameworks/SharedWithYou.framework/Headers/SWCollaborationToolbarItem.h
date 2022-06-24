//
//  SWCollaborationToolbarItem.h
//  SharedWithYouMac
//
//  Copyright (c) 2022 Apple. All rights reserved.
//

#import <SharedWithYouCore/SWDefines.h>

#if TARGET_OS_OSX
#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN
//@available(macOS 13, *)
//@available(iOS, unavailable)
//@available(watchOS, unavailable)
//@available(tvOS, unavailable)
@interface _SWCollaborationToolbarItem : NSToolbarItem

@property (nonatomic, strong) NSItemProvider *itemProvider;
@property (nonatomic, assign) NSUInteger activeParticipantCount;
@property (nonatomic, assign) BOOL isContentShared;

- (instancetype)initWithItemProvider:(NSItemProvider *)itemProvider;

- (void)dismissPopoverAnimated:(BOOL)animated completion:(void (^_Nullable)(void))completion;

- (void)setDetailViewListContent:(NSView *)detailViewListContentView;
@end

NS_ASSUME_NONNULL_END
#endif
