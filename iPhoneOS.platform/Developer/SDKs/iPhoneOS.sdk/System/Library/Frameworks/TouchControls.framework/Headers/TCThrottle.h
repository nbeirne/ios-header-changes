//
//  TCThrottle.h
//  TouchControls
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Metal/Metal.h>
#import <simd/simd.h>

#import <TouchControls/TCTransform.h>
#import <TouchControls/TCCollider.h>
#import <TouchControls/TCControl.h>
#import <TouchControls/TCControlVisuals.h>

@class TCTouchController;

NS_ASSUME_NONNULL_BEGIN

/// Defines the orientation of the throttle.
typedef NS_ENUM(NSInteger, TCThrottleOrientation) {
    /// A vertical throttle.
    TCThrottleOrientationVertical,
    /// A horizontal throttle.
    TCThrottleOrientationHorizontal,
};

/// Represents a single on-screen throttle - a one axis input.
///
/// This is mirrored by a `GCControllerButtonInput` on the associated `GCController` instance.
@interface TCThrottle : NSObject<TCControl, TCTransform>

/// The touch controller that manages this throttle.
@property (nonatomic, strong, readonly) TCTouchController *touchController;

/// The visuals for the background of the throttle.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *backgroundVisuals;
/// The visuals for the indicator of the throttle.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *indicatorVisuals;

/// The position of the throttle in points, with the origin at the top left corner of the screen.
@property (nonatomic, assign, readonly) CGPoint position;

/// The anchor point that the throttle's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;

/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;

/// The layer of the throttle, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The orientation of the throttle.
@property (nonatomic, assign, readonly) TCThrottleOrientation orientation;

/// A Boolean value that indicates whether the control reverts to it's base value.
///
/// If `YES`, the control's value will revert to its base value when no longer pressed.
@property (nonatomic, assign) BOOL snapToBaseValue;

/// The initial value of this control.
@property (nonatomic, assign) CGFloat baseValue;

/// The size (width, height) of the throttle in points.
@property (nonatomic, assign) CGSize size;

/// The size (width, height) of the indicator itself in points.
@property (nonatomic, assign) CGSize indicatorSize;

/// The size (width, height) of the throttle itself, providing boundaries for the indicator, in points.
@property (nonatomic, assign) CGSize throttleSize;

/// The collider for the throttle.
@property (nonatomic, strong) id<TCCollider> collider;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// Not available. Create the control via a `TCTouchController`.
- (instancetype)init NS_UNAVAILABLE;

@end



/// A descriptor for configuring a throttle.
@interface TCThrottleDescriptor : NSObject

/// The label associated with the throttle.
@property (nonatomic, strong) TCControlLabel *label;

/// The visuals for the background of the throttle.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *backgroundVisuals;
/// The visuals for the indicator of the throttle.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *indicatorVisuals;

/// The size (width, height) of the throttle in points.
@property (nonatomic, assign) CGSize size;
/// The size (width, height) of the indicator itself in points.
@property (nonatomic, assign) CGSize indicatorSize;
/// The size (width, height) of the throttle itself, providing boundaries for the indicator, in points.
@property (nonatomic, assign) CGSize throttleSize;

/// The orientation of the throttle.
@property (nonatomic, assign) TCThrottleOrientation orientation;
/// A Boolean value that indicates whether the control reverts to it's base value.
///
/// If `YES`, the control's value will revert to its base value when no longer pressed.
@property (nonatomic, assign) BOOL snapToBaseValue;
/// The initial value of this control.
@property (nonatomic, assign) CGFloat baseValue;

/// The anchor point that the throttle's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;
/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;
/// The layer of the throttle, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The type of collider to use for the throttle.
@property (nonatomic, assign) TCColliderType colliderType;
/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// Creates a new throttle descriptor with default values.
- (instancetype)init;

@end


NS_ASSUME_NONNULL_END
