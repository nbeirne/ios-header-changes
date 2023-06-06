//
//  MPSGraphCore.h
//  MetalPerformanceShadersGraph
//
//  Created on 11/10/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#ifndef MPSGraphCore_h
#define MPSGraphCore_h

#import <Foundation/Foundation.h>
#import <MetalPerformanceShaders/MetalPerformanceShaders.h>

NS_ASSUME_NONNULL_BEGIN

MPS_CLASS_AVAILABLE_STARTING(macos(14.0), ios(17.0), tvos(17.0))
/// Common base class for all MPSGraph objects. You should use one of the child classes.
@interface MPSGraphObject: NSObject
@end

/// Base type class for types on MPSGraph tensors
MPS_CLASS_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))
@interface MPSGraphType: MPSGraphObject<NSCopying>

@end

/// Shaped type class for types on MPSGraph tensors has a shape and a dataType
MPS_CLASS_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))
@interface MPSGraphShapedType: MPSGraphType

/// shape of the shapedType
@property (readwrite, nullable, copy, atomic) MPSShape *shape;

/// dataType of the shapedType
@property (readwrite, atomic) MPSDataType dataType;

/// Initialize an MPSGraphShapedType
///
/// - Parameters:
///   - shape: The MPSShape
///   - dataType: The dataType of the shaped type
/// - Returns: A valid MPSGraphShapedType, or nil if allocation failure.
-(instancetype) initWithShape:(MPSShape * _Nullable) shape
                     dataType:(MPSDataType) dataType;

/// checks if shapes and elementDataType are the same as the input shapedType
///
/// - Parameters:
///   - object: shapedType to compare to
/// - Returns: true if equal, false if unequal
-(BOOL)isEqualTo:(MPSGraphShapedType * _Nullable)object;

@end

/// Tensor Layout
typedef NS_ENUM(NSUInteger, MPSGraphTensorNamedDataLayout)
{
    /// LayoutNCHW
    MPSGraphTensorNamedDataLayoutNCHW       MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0)) MPS_SWIFT_NAME(NCHW)   =  0L,
    /// LayoutNHWC
    MPSGraphTensorNamedDataLayoutNHWC       MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  1L,
    /// LayoutOIHW
    MPSGraphTensorNamedDataLayoutOIHW       MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  2L,
    /// LayoutHWIO
    MPSGraphTensorNamedDataLayoutHWIO       MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  3L,
    /// LayoutCHW
    MPSGraphTensorNamedDataLayoutCHW        MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  4L,
    /// LayoutHWC
    MPSGraphTensorNamedDataLayoutHWC        MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  5L,
    /// LayoutHW
    MPSGraphTensorNamedDataLayoutHW         MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  6L,
    /// LayoutNCDHW
    MPSGraphTensorNamedDataLayoutNCDHW      MPS_ENUM_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))                        =  7L,
    /// LayoutNDHWC
    MPSGraphTensorNamedDataLayoutNDHWC      MPS_ENUM_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))                        =  8L,
    /// LayoutOIDHW
    MPSGraphTensorNamedDataLayoutOIDHW      MPS_ENUM_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))                        =  9L,
    /// LayoutDHWIO
    MPSGraphTensorNamedDataLayoutDHWIO      MPS_ENUM_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))                        =  10L,
};

/// Tensor Layout
typedef NS_ENUM(NSUInteger, MPSGraphPaddingStyle)
{
    /// Explicit
    MPSGraphPaddingStyleExplicit            MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0)) MPS_SWIFT_NAME(explicit)   =  0L,
    /// ONNX_SAME_LOWER
    MPSGraphPaddingStyleTF_VALID            MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                            =  1L,
    /// TF_SAME
    MPSGraphPaddingStyleTF_SAME             MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                            =  2L,
    /// TF_VALID
    MPSGraphPaddingStyleExplicitOffset      MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))                            =  3L,
    /// Explicit offsets
    MPSGraphPaddingStyleONNX_SAME_LOWER     MPS_ENUM_AVAILABLE_STARTING(macos(13.0), ios(16.0), tvos(16.0))                            =  4L,
};

/// Tensor Padding mode
typedef NS_ENUM(NSInteger, MPSGraphPaddingMode)
{
    /// Constant
    MPSGraphPaddingModeConstant          MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0)) MPS_SWIFT_NAME(constant) =  0L,
    /// Reflect
    MPSGraphPaddingModeReflect           MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                          =  1L,
    /// Symmetric
    MPSGraphPaddingModeSymmetric         MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                          =  2L,
    /// ClampToEdge (PyTorch ReplicationPad)
    MPSGraphPaddingModeClampToEdge       MPS_ENUM_AVAILABLE_STARTING(macos(11.1), ios(15.0), tvos(15.0))                          =  3L,
    /// Zero
    MPSGraphPaddingModeZero              MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))                          =  4L,
    /// Periodic `x[-2] -> x[L-3], where L is size of x.`
    MPSGraphPaddingModePeriodic          MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))                          =  5L,
    /// Anti Periodic `x[-2] -> -x[L-3]`
    MPSGraphPaddingModeAntiPeriodic      MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))                          =  6L,
};

/// Reduction Mode
typedef NS_ENUM(NSUInteger, MPSGraphReductionMode)
{
    /// Min
    MPSGraphReductionModeMin             MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))     =  0L,
    /// Max
    MPSGraphReductionModeMax             MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))     =  1L,
    /// Sum
    MPSGraphReductionModeSum             MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))     =  2L,
    /// Product
    MPSGraphReductionModeProduct         MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))     =  3L,
    /// Argument Min
    MPSGraphReductionModeArgumentMin     MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))     =  4L,
    /// Argument Max
    MPSGraphReductionModeArgumentMax     MPS_ENUM_AVAILABLE_STARTING(macos(12.0), ios(15.0), tvos(15.0))     =  5L
};

NS_ASSUME_NONNULL_END

#endif /* MPSGraphCore_h */
