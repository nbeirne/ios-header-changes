//
//  TCRegionCollider.h
//  TouchControls
//

#import <Foundation/Foundation.h>

#import <TouchControls/TCCollider.h>
#import <TouchControls/TCTransform.h>

@class TCTouchController;

NS_ASSUME_NONNULL_BEGIN

/// Defines the region of the touch controller that the `TCRegionCollider` represents.
typedef NS_ENUM(NSInteger, TCRegionColliderRegion) {
    /// The left side of the touch controller.
    TCRegionColliderRegionLeftSide,
    /// The right side of the touch controller.
    TCRegionColliderRegionRightSide,
};

/// A collider that covers a specific region of the touch controller.
@interface TCRegionCollider : NSObject<TCCollider>

/// Creates a new region collider with the specified region and touch controller.
///
/// - Parameters:
///   - region: The region of the screen to cover.
///   - touchController: The touch controller to use for determining the screen size.
/// - Returns: A new `TCRegionCollider` instance.
- (instancetype)initWithRegion:(TCRegionColliderRegion)region TouchController:(TCTouchController *)touchController;

@end


NS_ASSUME_NONNULL_END
