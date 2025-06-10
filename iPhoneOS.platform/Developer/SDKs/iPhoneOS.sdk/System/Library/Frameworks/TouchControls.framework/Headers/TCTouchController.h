//
//  TCTouchController.h
//  TouchControls
//

#import <Foundation/Foundation.h>

#import <simd/simd.h>
#import <Metal/Metal.h>
#import <GameController/GameController.h>

#import <TouchControls/TCControl.h>

@class TCButton;
@class TCButtonDescriptor;

@class TCThumbstick;
@class TCThumbstickDescriptor;

@class TCDirectionPad;
@class TCDirectionPadDescriptor;

@class TCTouchpad;
@class TCTouchpadDescriptor;

@class TCThrottle;
@class TCThrottleDescriptor;

@class TCTouchControllerDescriptor;

NS_ASSUME_NONNULL_BEGIN

/// An object that allows you to create and customize on-screen touch controls for a game that uses Metal.
///
/// The controller exposes controls through a <doc://com.apple.documentation/documentation/gamecontroller/gccontroller>
/// instance, and enables seamless integration with the <doc://com.apple.documentation/documentation/gamecontroller>
/// framework.
///
/// This class manages the lifecycle of touch controls, handles user interaction, renders the controls using Metal,
/// and provides a `GCController` instance that reflects the state of the on-screen controls.
@interface TCTouchController : NSObject

/// The Metal device the touch control uses for rendering the touch controls.
@property (nonatomic, readonly) id<MTLDevice> device;

/// An array containing all the touch controls managed by this controller.
@property (nonatomic, readonly) NSArray<id<TCControl>> *controls;

/// An array containing all the button controls managed by this controller.
@property (nonatomic, readonly) NSArray<TCButton *> *buttons;

/// An array containing all the thumbstick controls managed by this controller.
@property (nonatomic, readonly) NSArray<TCThumbstick *> *thumbsticks;

/// An array containing all the direction pad controls managed by this controller.
@property (nonatomic, readonly) NSArray<TCDirectionPad *> *directionPads;

/// An array containing all the throttle controls managed by this controller.
@property (nonatomic, readonly) NSArray<TCThrottle *> *throttles;

/// An array containing all the touchpad controls managed by this controller.
@property (nonatomic, readonly) NSArray<TCTouchpad *> *touchpads;

/// The width of the screen in points.
@property (nonatomic, readonly) CGFloat screenWidth;

/// The height of the screen in points.
@property (nonatomic, readonly) CGFloat screenHeight;

/// The scale factor of the screen.
///
/// For example, 2.0 or 3.0 for Retina displays.
@property (nonatomic, readonly) CGFloat scaleFactor;

/// Creates a new instance with the provided descriptor.
///
/// - Parameters:
///   - descriptor: The `TCTouchControllerDescriptor` containing the configuration for the touch controller.
/// - Returns: A new `TCTouchController` instance.
- (instancetype)initWithDescriptor:(TCTouchControllerDescriptor *)descriptor;

/// Sets up a default layout for the provided control labels.
///
/// This is used to automatically position control labels based on a predefined layout.
///
/// - Parameters:
///   - labels: An array of `TCControlLabel` objects to be laid out.
- (void)setupDefaultLayoutForLabels:(NSArray<TCControlLabel *> *)labels;

// MARK: Layout

/// Creates a new button control with the provided descriptor.
///
/// - Parameters:
///   - descriptor: The `TCButtonDescriptor` containing the configuration for the button.
/// - Returns: A new `TCButton` instance.
- (TCButton *)buttonWithDescriptor:(TCButtonDescriptor *)descriptor;

/// Adds a button to the touch controller.
///
/// - Parameters:
///   - button: The `TCButton` to add.
- (void)addButton:(TCButton *)button;

/// Removes a button from the touch controller.
///
/// - Parameters:
///   - button: The `TCButton` to remove.
- (void)removeButton:(TCButton *)button;

/// Removes all buttons from the touch controller.
- (void)removeAllButtons;

/// Creates a new thumbstick control with the provided descriptor.
///
/// - Parameters:
///   - descriptor: The `TCThumbstickDescriptor` containing the configuration for the thumbstick.
/// - Returns: A new `TCThumbstick` instance.
- (TCThumbstick *)thumbstickWithDescriptor:(TCThumbstickDescriptor *)descriptor;

/// Adds a thumbstick to the touch controller.
///
/// - Parameters:
///   - button: The `TCThumbstick` to add.
- (void)addThumbstick:(TCThumbstick *)button;

/// Removes a thumbstick from the touch controller.
///
/// - Parameters:
///   - button: The `TCThumbstick` to remove.
- (void)removeThumbstick:(TCThumbstick *)button;

/// Removes all thumbsticks from the touch controller.
- (void)removeAllThumbsticks;

/// Creates a new direction pad control with the provided descriptor.
///
/// - Parameters:
///   - descriptor: The `TCDirectionPadDescriptor` containing the configuration for the direction pad.
/// - Returns: A new `TCDirectionPad` instance.
- (TCDirectionPad *)directionPadWithDescriptor:(TCDirectionPadDescriptor *)descriptor;

/// Adds a direction pad to the touch controller.
///
/// - Parameters:
///   - directionPad: The `TCDirectionPad` to add.
- (void)addDirectionPad:(TCDirectionPad *)directionPad;

/// Removes a direction pad from the touch controller.
///
/// - Parameters:
///   - directionPad: The `TCDirectionPad` to remove.
- (void)removeDirectionPad:(TCDirectionPad *)directionPad;

/// Removes all direction pads from the touch controller.
- (void)removeAllDirectionPads;

/// Creates a new throttle control with the provided descriptor.
///
/// - Parameters:
///   - descriptor: The `TCThrottleDescriptor` containing the configuration for the throttle.
/// - Returns: A new `TCThrottle` instance.
- (TCThrottle *)throttleWithDescriptor:(TCThrottleDescriptor *)descriptor;

/// Adds a throttle to the touch controller.
///
/// - Parameters:
///   - throttle: The `TCThrottle` to add.
- (void)addThrottle:(TCThrottle *)throttle;

/// Removes a throttle from the touch controller.
///
/// - Parameters:
///   - throttle: The `TCThrottle` to remove.
- (void)removeThrottle:(TCThrottle *)throttle;

/// Removes all throttles from the touch controller.
- (void)removeAllThrottles;

/// Creates a new touchpad control with the provided descriptor.
///
/// - Parameters:
///   - descriptor: The `TCTouchpadDescriptor` containing the configuration for the touchpad.
/// - Returns: A new `TCTouchpad` instance.
- (TCTouchpad *)touchpadWithDescriptor:(TCTouchpadDescriptor *)descriptor;

/// Adds a touchpad to the touch controller.
///
/// - Parameters:
///   - touchpad: The `TCTouchpad` to add.
- (void)addTouchpad:(TCTouchpad *)touchpad;

/// Removes a touchpad from the touch controller.
///
/// - Parameters:
///   - touchpad: The `TCTouchpad` to remove.
- (void)removeTouchpad:(TCTouchpad *)touchpad;

/// Removes all touchpads from the touch controller.
- (void)removeAllTouchpads;

/// Removes all controls from the touch controller.
- (void)removeAllControls;

// MARK: User Interaction

/// The control at the specified point, if any.
///
/// - Parameters:
///   - point: The point to check for a control.
/// - Returns: The control at the specified point, or `nil` if no control is found.
- (nullable id<TCControl>)controlAtPoint:(CGPoint)point;

/// Handles a touch began event at the specified point.
///
/// - Parameters:
///   - point: The point where the touch began.
///   - index: An NSNumber representing a unique index for the touch
/// - Returns: `YES` if the touch was handled by a control; otherwise `NO`.
- (BOOL)handleTouchBeganAtPoint:(CGPoint)point index:(NSNumber *)index;

/// Handles a touch moved event at the specified point.
///
/// - Parameters:
///   - point: The point where the touch moved to.
///   - index: An NSNumber representing a unique index for the touch
/// - Returns: `YES` if the touch was handled by a control, `NO` otherwise.
- (BOOL)handleTouchMovedAtPoint:(CGPoint)point index:(NSNumber *)index;

/// Handles a touch ended event at the specified point.
///
/// - Parameters:
///   - point: The point where the touch ended.
///   - index: An NSNumber representing a unique index for the touch
/// - Returns: `YES` if the touch was handled by a control, `NO` otherwise.
- (BOOL)handleTouchEndedAtPoint:(CGPoint)point index:(NSNumber *)index;

// MARK: Rendering

/// Renders the touch controls using the provided Metal render command encoder.
///
/// - Parameters:
///   - encoder: The `MTLRenderCommandEncoder` to use for rendering.
- (void)renderWithRenderCommandEncoder:(id<MTLRenderCommandEncoder>)encoder;

/// Called when the drawable size changes.
///
/// - Parameters:
///   - size: The new size of the drawable in points.
///   - scaleFactor: The new scale factor of the screen.
- (void)drawableSizeWillChange:(CGSize)size scaleFactor:(CGFloat)scaleFactor;

// MARK: Game Controller

/// A Boolean value that indicates whether the touch controller is connected to the Game Controller framework.
@property (nonatomic, assign, readonly, getter=isConnected) BOOL connected;

/// Connects the touch controller to the app, allowing its controls to be drawn and an associated `GCController` to be created.
- (void)connect;

/// Disconnects the touch controller from the app, preventing its controls from being drawn.
- (void)disconnect;

/// The game controller instance associated with this touch controller.
///
/// - Returns: The `GCController` instance.
- (GCController *)controller;

@end

NS_ASSUME_NONNULL_END
