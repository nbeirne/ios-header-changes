//
//  MTL4ComputePipeline.h
//  Metal
//
//  Copyright © 2024 Apple, Inc. All rights reserved.
//

#ifndef MTL4ComputePipeline_h
#define MTL4ComputePipeline_h

#import <Metal/MTLDefines.h>

#import <Foundation/Foundation.h>
#import <Metal/MTL4PipelineState.h>
#import <Metal/MTLComputePipeline.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MTL4BinaryFunction;
@protocol MTLDynamicLibrary;
@class MTL4FunctionDescriptor;
@class MTL4LinkedFunctions;
@class MTLComputePipelineReflection;
@class MTL4StaticLinkingDescriptor;

/// Descriptor defining how a compute pipeline state would be created.
MTL_EXPORT
API_AVAILABLE(macos(26.0), ios(26.0))
@interface MTL4ComputePipelineDescriptor : MTL4PipelineDescriptor

/// A function descriptor representing the function that will be executed by the compute pipeline.
@property (nullable, readwrite, nonatomic, copy) MTL4FunctionDescriptor* computeFunctionDescriptor;

/// A boolean value indicating whether each dimension of the threadgroup size is a multiple of its
/// corresponding thread execution width.
@property (readwrite, nonatomic) BOOL threadGroupSizeIsMultipleOfThreadExecutionWidth;

/// The maximum total number of threads that can be executing in a single threadgroup for the
/// compute function.
@property (readwrite, nonatomic) NSUInteger maxTotalThreadsPerThreadgroup;

/// Sets the required threads-per-threadgroup during dispatches. The `threadsPerThreadgroup` argument of any dispatch must match this value if it is set.
/// Optional, unless the pipeline is going to use CooperativeTensors in which case this must be set.
/// Setting this to a size of 0 in every dimension disables this property
@property(readwrite, nonatomic) MTLSize requiredThreadsPerThreadgroup;

/// A boolean value indicating whether the compute pipeline should support adding binary functions.
@property (readwrite, nonatomic) BOOL supportBinaryLinking;

/// An object that contains information about functions that are linked to the compute pipeline
/// during creation.
@property (nullable, copy, nonatomic) MTL4StaticLinkingDescriptor* staticLinkingDescriptor;

/// A value indicating whether the pipeline should support indirect command buffers.
@property (readwrite, nonatomic) MTL4IndirectCommandBufferSupportState supportIndirectCommandBuffers;

/// Resets the descriptor to the default values.
- (void)reset;
@end

NS_ASSUME_NONNULL_END

#endif // MTL4ComputePipeline_h
