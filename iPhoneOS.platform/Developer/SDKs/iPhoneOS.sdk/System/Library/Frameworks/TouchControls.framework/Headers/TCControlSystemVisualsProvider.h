//
//  TCControlSystemVisualsProvider.h
//  TouchControls
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

#import <TouchControls/TCTouchController.h>
#import <TouchControls/TCControlLabel.h>
#import <TouchControls/TCControlVisuals.h>

NS_ASSUME_NONNULL_BEGIN

/// Defines the visual shape of a button.
typedef NS_ENUM(NSInteger, TCButtonVisualShape) {
    /// A circular button shape.
    TCButtonVisualShapeCircle,
    /// A rectangular button shape.
    TCButtonVisualShapeRect,
};

/// Defines the direction of a direction pad visual.
typedef NS_ENUM(NSInteger, TCDirectionPadVisualDirection) {
    /// The up direction.
    TCDirectionPadVisualDirectionUp,
    /// The down direction.
    TCDirectionPadVisualDirectionDown,
    /// The left direction.
    TCDirectionPadVisualDirectionLeft,
    /// The right direction.
    TCDirectionPadVisualDirectionRight,
};

/// Defines the visual style of a direction pad.
typedef NS_ENUM(NSInteger, TCDirectionPadVisualStyle) {
    /// A circular direction pad style.
    TCDirectionPadVisualStyleCircle,
    /// A pentagon direction pad style.
    TCDirectionPadVisualStylePentagon,
};

/// Provides system-defined visuals for touch controls.
@interface TCControlSystemVisualsProvider : NSObject

/// Not available. Use `initWithTouchController:` to create a `TCControlSystemVisualsProvider`.
- (instancetype)init NS_UNAVAILABLE;

/// Creates a new visuals provider with the specified touch controller.
///
/// - Parameters:
///   - touchController: The touch controller to use for creating the visuals.
/// - Returns: A new `TCControlSystemVisualsProvider` instance.
- (instancetype)initWithTouchController:(TCTouchController *)touchController;

/// The button visuals for the specified label, size, and shape.
///
/// - Parameters:
///   - label: The label for the button.
///   - size: The size of the button in points.
///   - shape: The shape of the button.
/// - Returns: The `TCControlVisuals` for the button.
- (TCControlVisuals *)buttonVisualsForLabel:(TCControlLabel *)label ofSize:(CGSize)size ofShape:(TCButtonVisualShape)shape;

/// The button visuals for the specified system image name, size, and shape.
///
/// - Parameters:
///   - imageName: The name of the system image to use for the button.
///   - size: The size of the button in points.
///   - shape: The shape of the button.
/// - Returns: The `TCControlVisuals` for the button.
- (TCControlVisuals *)buttonVisualsForSystemImageNamed:(NSString *)imageName ofSize:(CGSize)size ofShape:(TCButtonVisualShape)shape;

/// The toggle visuals for the specified label, size, and shape.
///
/// - Parameters:
///   - label: The label for the toggle button.
///   - size: The size of the toggle button in points.
///   - shape: The shape of the toggle button.
/// - Returns: The `TCControlVisuals` for the toggle button.
- (TCControlVisuals *)toggleVisualsForLabel:(TCControlLabel *)label ofSize:(CGSize)size ofShape:(TCButtonVisualShape)shape;

/// The toggle visuals for the specified system image name, size, and shape.
///
/// - Parameters:
///   - imageName: The name of the system image to use for the toggle button.
///   - size: The size of the toggle button in points.
///   - shape: The shape of the toggle button.
/// - Returns: The `TCControlVisuals` for the toggle button.
- (TCControlVisuals *)toggleVisualsForSystemImageNamed:(NSString *)imageName ofSize:(CGSize)size ofShape:(TCButtonVisualShape)shape;

/// The thumbstick stick visuals for the specified label and size.
///
/// - Parameters:
///   - label: The label for the thumbstick.
///   - size: The size of the thumbstick stick in points.
/// - Returns: The `TCControlVisuals` for the thumbstick stick.
- (TCControlVisuals *)thumbstickStickVisualsForLabel:(TCControlLabel *)label ofSize:(CGSize)size;

/// The thumbstick background visuals for the specified label and size.
///
/// - Parameters:
///   - label: The label for the thumbstick.
///   - size: The size of the thumbstick background in points.
/// - Returns: The `TCControlVisuals` for the thumbstick background.
- (TCControlVisuals *)thumbstickBackgroundVisualsForLabel:(TCControlLabel *)label ofSize:(CGSize)size;

/// The throttle indicator visuals for the specified size.
///
/// - Parameters:
///   - size: The size of the throttle indicator in points.
/// - Returns: The `TCControlVisuals` for the throttle indicator.
- (TCControlVisuals *)throttleIndicatorVisualsOfSize:(CGSize)size;

/// The throttle background visuals for the specified size.
///
/// - Parameters:
///   - size: The size of the throttle background in points.
/// - Returns: The `TCControlVisuals` for the throttle background.
- (TCControlVisuals *)throttleBackgroundVisualsOfSize:(CGSize)size;

/// The direction pad visuals for the specified label, size, style, and direction.
///
/// - Parameters:
///   - label: The label for the direction pad.
///   - size: The size of the direction pad in points.
///   - style: The style of the direction pad.
///   - direction: The direction of the direction pad visual.
/// - Returns: The `TCControlVisuals` for the direction pad.
- (TCControlVisuals *)directionPadVisualsForLabel:(TCControlLabel *)label ofSize:(CGSize)size ofStyle:(TCDirectionPadVisualStyle)style withDirection:(TCDirectionPadVisualDirection)direction;

@end


NS_ASSUME_NONNULL_END
