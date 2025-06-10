//
//  TCThumbstick.h
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

/// Represents a single on-screen thumbstick.
///
/// This is mirrored by a `GCControllerDirectionPad` on the associated `GCController` instance.
@interface TCThumbstick : NSObject<TCControl, TCTransform>

/// The touch controller that manages this thumbstick.
@property (nonatomic, strong, readonly) TCTouchController *touchController;

/// The visuals for the background of the thumbstick.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *backgroundVisuals;

/// The visuals for the thumbstick itself.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *stickVisuals;

/// A Boolean value that indicates whether to hide the thumbstick when it is not being pressed.
@property (nonatomic, assign) BOOL hideWhenNotPressed;

/// The position of the thumbstick in points, with the origin at the top left corner of the screen.
@property (nonatomic, assign, readonly) CGPoint position;

/// The anchor point that the thumbstick's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;

/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;

/// The layer of the thumbstick, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The size (width, height) of the thumbstick in points.
@property (nonatomic, assign) CGSize size;

/// The size (width, height) of the thumbstick stick itself in points.
@property (nonatomic, assign) CGSize stickSize;

/// The collider for the thumbstick.
@property (nonatomic, strong) id<TCCollider> collider;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// Not available. Create the control via a `TCTouchController`.
- (instancetype)init NS_UNAVAILABLE;

@end



/// A descriptor for configuring a thumbstick.
@interface TCThumbstickDescriptor : NSObject

/// The label associated with the thumbstick.
@property (nonatomic, strong) TCControlLabel *label;

/// The visuals for the background of the thumbstick.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *backgroundVisuals;

/// The visuals for the thumbstick itself.
///
/// May be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *stickVisuals;

/// Whether to hide the thumbstick when it is not being pressed.
@property (nonatomic, assign) BOOL hideWhenNotPressed;

/// The size (width, height) of the thumbstick stick itself in points.
@property (nonatomic, assign) CGSize stickSize;
/// The size (width, height) of the thumbstick in points.
@property (nonatomic, assign) CGSize size;

/// The anchor point that the thumbstick's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;
/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;
/// The layer of the thumbstick, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The type of collider to use for the thumbstick.
@property (nonatomic, assign) TCColliderType colliderType;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// Creates a new thumbstick descriptor with default values.
- (instancetype)init;

@end


NS_ASSUME_NONNULL_END
