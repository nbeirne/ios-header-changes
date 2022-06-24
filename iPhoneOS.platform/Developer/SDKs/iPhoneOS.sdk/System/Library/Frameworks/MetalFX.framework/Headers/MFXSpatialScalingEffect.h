//
//  MFXSpatialScalingEffect.h
//  MetalFX
//
//  Copyright (c) 2021 Apple Inc. All rights reserved.
//

#import <Metal/Metal.h>

#define MFXSpatialScalingEffectVersionStart (0x10000)

typedef NS_ENUM(NSUInteger, MFXSpatialScalingEffectVersion) {
    MFXSpatialScalingEffectVersion_1 = MFXSpatialScalingEffectVersionStart,
} API_AVAILABLE(macos(13.0), ios(16.0));

typedef NS_ENUM(NSUInteger, MFXSpatialScalingColorProcessingMode) {
    MFXSpatialScalingColorProcessingMode_Perceptual = 0,      /* This should be used when the input and output textures are already in an sRGB or otherwise perceptual 0-1 encoding. */
    MFXSpatialScalingColorProcessingMode_Linear = 1,    /* This should be used when the input and output textures will contain light linear data in the 0-1 range. */
    MFXSpatialScalingColorProcessingMode_HDR = 2,       /* This should be used when the input and output texture will contain light linear data outside the 0-1 range.  In
                                                       this case a reversible tonemapping operation will be done internally to convert to a 0-1 range. */
} API_AVAILABLE(macos(13.0), ios(16.0));

// Forward declaration.
@protocol MFXSpatialScalingEffect;

API_AVAILABLE(macos(13.0), ios(16.0))
@interface MFXSpatialScalingEffectDescriptor : NSObject

// These properties must be set to the respective Metal pixel formats for each texture that will be used with the scaling effect encoder.
@property MTLPixelFormat colorTextureFormat;
@property MTLPixelFormat outputTextureFormat;
@property NSUInteger inputWidth;
@property NSUInteger inputHeight;
@property NSUInteger outputWidth;
@property NSUInteger outputHeight;

/* The default for colorProcessingMode is MFXSpatialScalingColorProcessingMode_Perceptual */
@property (nonatomic) MFXSpatialScalingColorProcessingMode colorProcessingMode;

@property enum MFXSpatialScalingEffectVersion version;

// The following method is used to instantiate the effect encoder for a given
// Metal device.
- (id <MFXSpatialScalingEffect>)newSpatialScalingEffectWithDevice:(id<MTLDevice>)device;

@end

// This is the object that gets created from the descriptor
API_AVAILABLE(macos(13.0), ios(16.0))
@protocol MFXSpatialScalingEffect <NSObject>

// Properties return the minimum required MTLTextureUsage bits required
@property (nonatomic, readonly) MTLTextureUsage colorTextureUsage;
@property (nonatomic, readonly) MTLTextureUsage outputTextureUsage;

// Dynamic resolution property
@property (nonatomic) NSUInteger inputContentWidth;
@property (nonatomic) NSUInteger inputContentHeight;

// These would be all of the "state" needed that is allowed to change on a frame by
// frame basis.   We don't care about the textures assigned except that they must
// match the required MTLTextureUsage flags.
@property (nonatomic, retain) id<MTLTexture> colorTexture;
@property (nonatomic, retain) id<MTLTexture> outputTexture;

// Read-only immutable properties of effect
@property (nonatomic, readonly) MTLPixelFormat colorTextureFormat;
@property (nonatomic, readonly) MTLPixelFormat outputTextureFormat;
@property (nonatomic, readonly) NSUInteger inputWidth;
@property (nonatomic, readonly) NSUInteger inputHeight;
@property (nonatomic, readonly) NSUInteger outputWidth;
@property (nonatomic, readonly) NSUInteger outputHeight;
@property (nonatomic, readonly) MFXSpatialScalingColorProcessingMode colorProcessingMode;

// Property for synchronization when using untracked resources
@property (nonatomic, retain) id<MTLFence> fence;

// Method to encode the effect to a command buffer
- (void)encodeToCommandBuffer:(id<MTLCommandBuffer>)commandBuffer;

@end

