//
//  TCDirectionPad.h
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

/// An object that represents a direction pad.
///
/// You can configure this object to behave as either a composite direction pad (mirrored by a
/// `GCControllerDirectionPad` on the associated `GCController` instance) or as four separate
/// buttons.
@interface TCDirectionPad : NSObject<TCControl, TCTransform>

/// The touch controller that manages this direction pad.
@property (nonatomic, strong, readonly) TCTouchController *touchController;

/// A composite control label.
///
/// If set, the control will behave as a `GCControllerDirectionPad`; otherwise, it behaves as separate buttons.
@property (nonatomic, strong, nullable) TCControlLabel *compositeLabel;
/// The label for the up button, if the control isn't a composite direction pad.
@property (nonatomic, strong, nullable) TCControlLabel *upLabel;
/// The label for the down button, if the control isn't a composite direction pad.
@property (nonatomic, strong, nullable) TCControlLabel *downLabel;
/// The label for the left button, if the control isn't a composite direction pad.
@property (nonatomic, strong, nullable) TCControlLabel *leftLabel;
/// The label for the right button, if the control isn't a composite direction pad.
@property (nonatomic, strong, nullable) TCControlLabel *rightLabel;

/// The visuals for the up button.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *upVisuals;

/// The visuals for the down button.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *downVisuals;

/// The visuals for the left button.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *leftVisuals;

/// The visuals for the right button.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *rightVisuals;

/// The position of the direction pad in points, with the origin at the top left corner of the screen.
@property (nonatomic, assign, readonly) CGPoint position;

/// The anchor point that the direction pad's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;

/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;

/// The layer of the direction pad, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The size (width, height) of the direction pad in points.
@property (nonatomic, assign) CGSize size;

/// The collider for the direction pad.
@property (nonatomic, strong) id<TCCollider> collider;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// A Boolean value that indicates whether the control behaves as a swipeable radial button.
///
/// If `YES`, the control behaves as a swipable radial button, rather than a collection of 4 separate buttons.
@property (nonatomic, assign, getter=isRadial) BOOL radial;

/// A Boolean value that indicates whether the control behaves as a digital button.
///
/// If `YES`, dpad buttons will report 1 or 0. Ignored if radial is set, as button presses will always be digital.
@property (nonatomic, assign, getter=isDigital) BOOL digital;

/// A Boolean value that indicates whether the control has mutally exclusive input.
///
/// If `YES`, only one element of the direction pad can be pressed at a time.
@property (nonatomic, assign, getter=hasMutuallyExclusiveInput) BOOL mutuallyExclusiveInput;

/// Not available. Create the control via a `TCTouchController`.
- (instancetype)init NS_UNAVAILABLE;

@end



/// A descriptor for configuring a directional pad.
@interface TCDirectionPadDescriptor : NSObject

/// A composite control label.
///
/// If set, the control will behave as a `GCControllerDirectionPad`. Otherwise, it will behave as separate buttons.
@property (nonatomic, strong, nullable) TCControlLabel *compositeLabel;
/// The label for the up button, if the control isn't a composite direction pad.
@property (nonatomic, strong, nullable) TCControlLabel *upLabel;
/// The label for the down button, if the control is not a composite direction pad.
@property (nonatomic, strong, nullable) TCControlLabel *downLabel;
/// The label for the left button, if the control is not a composite direction pad.
@property (nonatomic, strong, nullable) TCControlLabel *leftLabel;
/// The label for the right button, if the control is not a composite direction pad.
@property (nonatomic, strong, nullable) TCControlLabel *rightLabel;

/// The visuals for the up button.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *upVisuals;
/// The visuals for the down button.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *downVisuals;
/// The visuals for the left button.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *leftVisuals;
/// The visuals for the right button.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *rightVisuals;

/// The anchor point that the direction pad's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;
/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;
/// The layer of the direction pad, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;
/// The size (width, height) of the direction pad in points.
@property (nonatomic, assign) CGSize size;

/// The type of collider to use for the direction pad.
@property (nonatomic, assign) TCColliderType colliderType;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// A Boolean value that indicates whether the control behaves as a swipeable radial button.
///
/// If `YES`, the control behaves as a swipable radial button, rather than a collection of 4 separate buttons.
@property (nonatomic, assign, getter=isRadial) BOOL radial;

/// A Boolean value that indicates whether the control behaves as a digital button.
///
/// If `YES`, dpad buttons will report 1 or 0. Ignored if radial is set, as button presses will always be digital.
@property (nonatomic, assign, getter=isDigital) BOOL digital;

/// A Boolean value that indicates whether the control has mutally exclusive input.
///
/// If `YES`, only one element of the direction pad can be pressed at a time.
@property (nonatomic, assign, getter=hasMutuallyExclusiveInput) BOOL mutuallyExclusiveInput;

/// Creates a new instance with default values.
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
