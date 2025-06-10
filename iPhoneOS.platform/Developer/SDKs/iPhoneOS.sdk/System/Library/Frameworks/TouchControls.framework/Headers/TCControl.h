//
//  TCControl.h
//  TouchControls
//

#import <Foundation/Foundation.h>

#import <TouchControls/TCCollider.h>
#import <TouchControls/TCTransform.h>
#import <TouchControls/TCControlLabel.h>

NS_ASSUME_NONNULL_BEGIN

/// A protocol that defines the base properties and methods for all touch controls.
@protocol TCControl <NSObject, TCTransform>

@required

/// The label associated with the control.
@property (nonatomic, strong, readonly) TCControlLabel *label;

/// The collider for the control.
@property (nonatomic, strong) id<TCCollider> collider;

/// Indicates whether the control is currently pressed.
@property (nonatomic, assign, readonly) BOOL pressed;

/// A Boolean value that indicates whether the control is enabled.
///
/// If disabled, it won't respond to touches.
@property (nonatomic, assign) BOOL enabled;

/// Handles a touch began event at the specified point.
///
/// - Parameters:
///   - point: The point where the touch began.
- (void)handleTouchBeganAtPoint:(CGPoint)point;

/// Handles a touch moved event at the specified point.
///
/// - Parameters:
///   - point: The point where the touch moved to.
- (void)handleTouchMovedAtPoint:(CGPoint)point;

/// Handles a touch ended event at the specified point.
///
/// - Parameters:
///   - point: The point where the touch ended.
- (void)handleTouchEndedAtPoint:(CGPoint)point;

@optional

/// The factor by which to highlight the control when pressed.
@property (nonatomic, assign) float highlightFactor;
/// The duration of the highlight animation.
@property (nonatomic, assign) simd_float1 highlightTime;

/// Updates the layout of the control.
///
/// You won't need to call this directly, unless you change the layout.
- (void)layoutIfNeeded;

@end

NS_ASSUME_NONNULL_END
