//
//  TCCollider.h
//  TouchControls
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Defines the type of collider.
typedef NS_ENUM(NSInteger, TCColliderType) {
    /// A circular collider.
    TCColliderTypeCircle,
    /// A rectangular collider.
    TCColliderTypeRect,
    /// A collider representing the left side of the touch controller.
    TCColliderTypeLeftSide,
    /// A collider representing the right side of the touch controller.
    TCColliderTypeRightSide,
};

/// A protocol defining the collider properties for a control.
@protocol TCCollider <NSObject>

@required
/// The type of the collider.
- (TCColliderType)colliderType;

/// Determines whether the collider contains the specified point.
///
/// - Parameters:
///   - point: The point to check.
/// - Returns: `YES` if the collider contains the point; otherwise, `NO`.
- (BOOL)containsPoint:(CGPoint)point;

/// A Boolean value that indicates whether the collider is enabled.
- (BOOL)enabled;

/// Sets whether the collider is enabled.
///
/// - Parameters:
///   - enabled: `YES` to enable the collider, `NO` to disable it.
- (void)setEnabled:(BOOL)enabled;

@end


NS_ASSUME_NONNULL_END
