//
//  TCControlLabel.h
//  TouchControls
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Defines the type of control label.
typedef NS_ENUM(NSInteger, TCControlLabelType) {
    /// A label for a button input controller.
    TCControlLabelTypeButton,
    /// A label for a direction pad controller.
    TCControlLabelTypeDirectionPad,
};

/// A label you associate with a touch control and provides a semantic description.
@interface TCControlLabel : NSObject

/// Creates a pre-configured label for the "A" button.
+ (instancetype)buttonA;
/// Creates a pre-configured label for the "B" button.
+ (instancetype)buttonB;
/// Creates a pre-configured label for the "X" button.
+ (instancetype)buttonX;
/// Creates a pre-configured label for the "Y" button.
+ (instancetype)buttonY;
/// Creates a pre-configured label for the "Menu" button.
+ (instancetype)buttonMenu;
/// Creates a pre-configured label for the "Options" button.
+ (instancetype)buttonOptions;
/// Creates a pre-configured label for the left shoulder button.
+ (instancetype)buttonLeftShoulder;
/// Creates a pre-configured label for the left trigger button.
+ (instancetype)buttonLeftTrigger;
/// Creates a pre-configured label for the right shoulder button.
+ (instancetype)buttonRightShoulder;
/// Creates a pre-configured label for the right trigger button.
+ (instancetype)buttonRightTrigger;
/// Creates a pre-configured label for the left thumbstick.
+ (instancetype)leftThumbstick;
/// Creates a pre-configured label for the left thumbstick button.
+ (instancetype)leftThumbstickButton;
/// Creates a pre-configured label for the right thumbstick.
+ (instancetype)rightThumbstick;
/// Creates a pre-configured label for the right thumbstick button.
+ (instancetype)rightThumbstickButton;
/// Creates a pre-configured label for the direction pad.
+ (instancetype)directionPad;

- (instancetype)init NS_UNAVAILABLE;

/// The name of the control label that you use for lookup on a game controller instance.
@property (nonatomic, retain, readonly) NSString *name;
/// The type of the control label.
@property (nonatomic, assign, readonly) TCControlLabelType type;

@end


NS_ASSUME_NONNULL_END
