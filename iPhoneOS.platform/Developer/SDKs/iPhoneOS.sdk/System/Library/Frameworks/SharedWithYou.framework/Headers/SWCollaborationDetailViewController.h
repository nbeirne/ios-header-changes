//
//  SWCollaborationDetailViewController.h
//  SharedWithYou
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

#if TARGET_OS_OSX
//@available(macOS 13, *)
//@available(iOS, unavailable)
//@available(watchOS, unavailable)
//@available(tvOS, unavailable)
@interface _SWCollaborationDetailViewController : NSViewController
#else
//@available(iOS 16, *)
//@available(macOS, unavailable)
//@available(watchOS, unavailable)
//@available(tvOS, unavailable)
@interface _SWCollaborationDetailViewController : UIViewController
#endif

@end

NS_ASSUME_NONNULL_END
