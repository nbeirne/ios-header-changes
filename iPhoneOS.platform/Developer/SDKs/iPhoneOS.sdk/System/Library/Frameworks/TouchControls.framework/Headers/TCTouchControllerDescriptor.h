//
//  TCTouchControllerDescriptor.h
//  TouchControls
//

#import <Foundation/Foundation.h>

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

/// A descriptor for configuring a touch controller.
@interface TCTouchControllerDescriptor : NSObject

/// The Metal device to use for rendering.
@property (nonatomic, readwrite, strong) id<MTLDevice> device;

/// The width of the screen in points.
@property (nonatomic, readwrite, assign) CGFloat screenWidth;

/// The height of the screen in points.
@property (nonatomic, readwrite, assign) CGFloat screenHeight;

/// The scale factor of the screen.
///
/// For example, 2.0 or 3.0 for Retina displays.
@property (nonatomic, readwrite, assign) CGFloat scaleFactor;

/// The pixel format for the drawable texture.
@property (nonatomic, readwrite, assign) MTLPixelFormat colorPixelFormat;

/// The pixel format for the depth attachment.
@property (nonatomic, readwrite, assign) MTLPixelFormat depthAttachmentPixelFormat;

/// The pixel format for the stencil attachment.
@property (nonatomic, readwrite, assign) MTLPixelFormat stencilAttachmentPixelFormat;

/// The number of samples per pixel for multisampling.
@property (nonatomic, readwrite, assign) NSUInteger sampleCount;

@end


NS_ASSUME_NONNULL_END
