//
//  TCSpriteRenderer.h
//  TouchControls
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

/// A renderer for drawing sprites using Metal.
@interface TCSpriteRenderer : NSObject

/// Not available. Use designated initializer.
- (instancetype)init NS_UNAVAILABLE;

/// Creates a new sprite renderer with the specified texture and size.
///
/// - Parameters:
///   - texture: The Metal texture to use for the sprite.
///   - size: The size of the sprite in points.
/// - Returns: A new `TCSpriteRenderer` instance.
- (instancetype)initWithTexture:(id<MTLTexture>)texture size:(CGSize)size;

/// Creates a new sprite renderer with the specified texture, size, highlight texture, offset, and color tint.
///
/// - Parameters:
///   - texture: The Metal texture to use for the sprite.
///   - size: The size of the sprite in points.
///   - highlightTexture: The Metal texture to use for the sprite when highlighted. May be `nil`.
///   - offset: The offset from the center of the parent control in points.
///   - colorTint: The color tint to apply to the texture. The color ref is retained.
/// - Returns: A new `TCSpriteRenderer` instance.
- (instancetype)initWithTexture:(id<MTLTexture>)texture size:(CGSize)size highlightTexture:(id<MTLTexture> __nullable)highlightTexture offset:(CGPoint)offset colorTint:(CGColorRef)colorTint NS_DESIGNATED_INITIALIZER;

/// The Metal texture to use for the sprite.
@property (nonatomic, strong) id<MTLTexture> texture;
/// The Metal texture to use for the sprite when highlighted. May be `nil`.
@property (nonatomic, strong, nullable) id<MTLTexture> highlightTexture;
/// The size of the sprite in points.
@property (nonatomic, assign) CGSize size;
/// The offset from the center of the parent control in points.
@property (nonatomic, assign) CGPoint offset;
/// The color tint to apply to the texture. The color ref is retained.
@property (nonatomic, assign) CGColorRef colorTint;

@end


NS_ASSUME_NONNULL_END
