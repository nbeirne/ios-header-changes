//
//  TCTransform.h
//  TouchControls
//

#import <Foundation/Foundation.h>

#import <simd/simd.h>

NS_ASSUME_NONNULL_BEGIN

/// Defines the anchor point for a transform.
typedef NS_ENUM(NSInteger, TCTransformAnchor) {
    /// Anchors to the top-left corner, relative to the screen size.
    TCTransformAnchorTopLeft,
    /// Anchors to the top-center, relative to the screen size.
    TCTransformAnchorTopCenter,
    /// Anchors to the top-right corner, relative to the screen size.
    TCTransformAnchorTopRight,
    /// Anchors to the center-left, relative to the screen size.
    TCTransformAnchorCenterLeft,
    /// Anchors to the center, relative to the screen size.
    TCTransformAnchorCenter,
    /// Anchors to the center-right, relative to the screen size.
    TCTransformAnchorCenterRight,
    /// Anchors to the bottom-left corner, relative to the screen size.
    TCTransformAnchorBottomLeft,
    /// Anchors to the bottom-center, relative to the screen size.
    TCTransformAnchorBottomCenter,
    /// Anchors to the bottom-right corner, relative to the screen size.
    TCTransformAnchorBottomRight,

    /// Anchors to the top-left corner, using absolute coordinates.
    TCTransformAnchorAbsoluteTopLeft,
    /// Anchors to the top-center, using absolute coordinates.
    TCTransformAnchorAbsoluteTopCenter,
    /// Anchors to the top-right corner, using absolute coordinates.
    TCTransformAnchorAbsoluteTopRight,
    /// Anchors to the center-left, using absolute coordinates.
    TCTransformAnchorAbsoluteCenterLeft,
    /// Anchors to the center, using absolute coordinates.
    TCTransformAnchorAbsoluteCenter,
    /// Anchors to the center-right, using absolute coordinates.
    TCTransformAnchorAbsoluteCenterRight,
    /// Anchors to the bottom-left corner, using absolute coordinates.
    TCTransformAnchorAbsoluteBottomLeft,
    /// Anchors to the bottom-center, using absolute coordinates.
    TCTransformAnchorAbsoluteBottomCenter,
    /// Anchors to the bottom-right corner, using absolute coordinates.
    TCTransformAnchorAbsoluteBottomRight,
};

/// A protocol defining the transform properties for a control.
@protocol TCTransform <NSObject>

@required

/// The anchor point of the transform.
@property (nonatomic, assign) TCTransformAnchor anchor;
/// The offset from the anchor point.
@property (nonatomic, assign) CGPoint offset;
/// The layer of the transform, used for z-ordering.
@property (nonatomic, assign) simd_int1 layer;
/// The size of the transform in points.
@property (nonatomic, assign) CGSize size;

/// The calculated position of the transform.
- (CGPoint)position;

@end

NS_ASSUME_NONNULL_END
