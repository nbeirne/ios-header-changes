//
//  TCButton.h
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

/// A control that represents a single on-screen button.
///
/// This is mirrored by a <doc://com.apple.documentation/documentation/gamecontroller/gccontrollerbuttoninput>
/// on the associated <doc://com.apple.documentation/documentation/gamecontroller/gccontroller>.
@interface TCButton : NSObject<TCControl, TCTransform>

/// The touch controller that manages this button.
@property (nonatomic, strong, readonly) TCTouchController *touchController;

/// The visuals for the button in its normal state.
///
/// This value can be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *visuals;

/// The visuals for the button when it is toggled on.
///
/// This value is only used when the button is a toggle, and can be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *toggleVisuals;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// A Boolean value that indicates whether the button is a toggle button.
@property (nonatomic, assign, getter=isToggle) BOOL toggle;

/// A Boolean value that indicates whether the button is currently toggled on.
@property (nonatomic, assign, getter=isToggle, readonly) BOOL toggled;

/// The position of the button in points, with the origin at the top left corner of the screen.
@property (nonatomic, assign, readonly) CGPoint position;

/// The anchor point that the control's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;

/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;

/// The layer of the button, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The size (width, height) of the button in points.
@property (nonatomic, assign) CGSize size;

/// The collider for the button.
@property (nonatomic, strong) id<TCCollider> collider;

/// Not available.  Create the control via a `TCTouchController`.
- (instancetype)init NS_UNAVAILABLE;

@end



/// A descriptor for configuring a button.
@interface TCButtonDescriptor : NSObject

/// The label you associate with the button.
@property (nonatomic, strong) TCControlLabel *label;

/// The visuals for the button in its normal state.
///
/// This value can be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *visuals;

/// The visuals for the button when it is toggled on.
///
/// This value is only used when the button is a toggle, and can be `nil`.
@property (nonatomic, strong, nullable) TCControlVisuals *toggleVisuals;

/// Whether the button is a toggle button.
@property (nonatomic, assign, getter=isToggle) BOOL toggle;

/// The anchor point that the button's offset is relative to.
@property (nonatomic, assign) TCTransformAnchor anchor;

/// The control's offset from the anchor, which determines its position.
@property (nonatomic, assign) CGPoint offset;

/// The layer of the button, used for z-sorting.
@property (nonatomic, assign) simd_int1 layer;

/// The size (width, height) of the button in points.
@property (nonatomic, assign) CGSize size;

/// The type of collider to use for the button.
@property (nonatomic, assign) TCColliderType colliderType;

/// The time it takes for a highlight to fade away, in seconds.
@property (nonatomic, assign) simd_float1 highlightTime;

/// Creates a new button descriptor with default values.
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
