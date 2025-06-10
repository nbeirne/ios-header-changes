//
//  TCControlVisuals.h
//  TouchControls
//

#import <Foundation/Foundation.h>

@class TCSpriteRenderer;

NS_ASSUME_NONNULL_BEGIN

/// Represents the visual elements of a touch control.
@interface TCControlVisuals : NSObject

/// Creates a new instance with the specified sprites.
///
/// - Parameters:
///   - sprites: An array of `TCSpriteRenderer` objects to use for the visuals.
/// - Returns: A new `TCControlVisuals` instance.
+ (instancetype)visualsWithSprites:(NSArray<TCSpriteRenderer *> *)sprites;

/// Not available. Use `visualsWithSprites:` to create a `TCControlVisuals`.
- (instancetype)init NS_UNAVAILABLE;

/// The array of objects used to render the control.
@property (nonatomic, strong, readwrite) NSArray<TCSpriteRenderer *> *sprites;

@end

NS_ASSUME_NONNULL_END
