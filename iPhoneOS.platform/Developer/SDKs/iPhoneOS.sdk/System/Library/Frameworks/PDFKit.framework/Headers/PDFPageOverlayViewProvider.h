//
//  PDFPageOverlayViewProvider.h
//  PDFKit
//
//  Copyright © 2022 Apple. All rights reserved.
//

#import <PDFKit/PDFKitPlatform.h>

NS_ASSUME_NONNULL_BEGIN

@class PDFPage, PDFView;

/* PDFPageOverlayViewProvider allows a client to provide views that will be overlaid onto each PDFPage.
*/

@protocol PDFPageOverlayViewProvider <NSObject>

@required

// Return a "prepared" overlay view
- (nullable PDFKitPlatformView*)overlayViewForPage:(PDFPage*)page;

// Perform teardown of the overlay view
- (void)relinquishOverlayViewForPage:(PDFPage*)page;

@optional

// Called when the overlay view has been added to its superview, and constraints have been applied
- (void)overlayViewWasInstalledForPage:(PDFPage*)page;

// Called before the overlay view is removed from its superview
- (void)overlayViewWillBeUninstalledForPage:(PDFPage*)page;

@end

NS_ASSUME_NONNULL_END
