//
//  SWCollaborationButtonView.h
//  SocialLayer
//
//  Copyright (c) 2022 Apple. All rights reserved.
//

#import <SharedWithYouCore/SWDefines.h>

#if TARGET_OS_OSX
#import <AppKit/AppKit.h>
#else
#import <UIKit/UIKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/*!
 @abstract A view that displays a `SWCollaborationDetailViewController` upon user interaction and attributes active collaborations associated with the given content to a conversation in Messages.
 */
#if TARGET_OS_OSX
@interface _SWCollaborationButtonView : NSView
- (void)setDetailViewListContent:(NSView *)detailViewListContentView;
#else
@interface _SWCollaborationButtonView : UIView
- (void)setDetailViewListContent:(UIView *)detailViewListContentView;
#endif

- (instancetype)initWithItemProvider:(NSItemProvider *)itemProvider;

/*!
     @abstract sets the title of the manage participants button in the collaboration popover to the given string, defaults to "Manage Share"
     @param title localized string to display as the title for the manage participants button in the collaboration popover
*/
- (void)setManageButtonTitle:(NSString *)manageButtonTitle;

/*!
     @abstract whether the collaboration popover should show the default manage participants button in the popover, defaults to YES
     @param showManageButton whether the button should be hidden
*/
- (void)setShowManageButton:(BOOL)showManageButton;

@end

NS_ASSUME_NONNULL_END
