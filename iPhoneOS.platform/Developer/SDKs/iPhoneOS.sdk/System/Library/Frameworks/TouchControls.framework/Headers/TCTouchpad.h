//
//  TCTouchpad.h
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

/// Represents a single on-screen touchpad that reports absolute coordinates or delta movements.
///
/// This is mirrored by a `GCControllerDirectionPad` on the associated `GCController` instance.
@interface TCTouchpad : NSObject<TCControl, TCTransform>

/// The touch controller that manages this touchpad.
@property (nonatomic, strong, readonly) TCTouchController *touchController;

/// The visuals for the touchpad. May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *visuals;

/// The position of the touchpad in points, with the origin at the top left corner of the screen.
@property (nonatomic, assign, readonly) CGPoint position;

/// The anchor point that the touchpad's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;

/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;

/// The layer of the touchpad, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The width and height of the touchpad. in points.
@property (nonatomic, assign) CGSize size;

/// The collider for the touchpad.
@property (nonatomic, strong) id<TCCollider> collider;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// A Boolean value that represents the touchpad reports deltas.
///
/// If `YES`, the touchpad will report delta values as touch moves instead of absolute positions.
@property (nonatomic, assign) BOOL reportsDeltas;

/// Not available. Create the control via a `TCTouchController`.
- (instancetype)init NS_UNAVAILABLE;

@end



/// A descriptor for configuring a touchpad.
@interface TCTouchpadDescriptor : NSObject

/// The label associated with the touchpad.
@property (nonatomic, strong) TCControlLabel *label;

/// The visuals for the touchpad.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *visuals;

/// The anchor point that the touchpad's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;
/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;
/// The layer of the touchpad, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The size (width, height) of the touchpad in points.
@property (nonatomic, assign) CGSize size;

/// The type of collider to use for the touchpad.
@property (nonatomic, assign) TCColliderType colliderType;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// A Boolean value that represents the touchpad reports deltas.
///
/// If `YES`, the touchpad will report delta values as touch moves instead of absolute positions.
@property (nonatomic, assign) BOOL reportsDeltas;

/// Creates a new touchpad descriptor with default values.
- (instancetype)init;

@end


NS_ASSUME_NONNULL_END
