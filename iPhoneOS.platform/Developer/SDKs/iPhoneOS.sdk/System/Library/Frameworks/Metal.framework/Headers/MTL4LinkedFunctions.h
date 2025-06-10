//
//  MTL4LinkedFunctions.h
//  Metal
//
//  Copyright © 2024 Apple, Inc. All rights reserved.
//

#ifndef MTL4LinkedFunctions_h
#define MTL4LinkedFunctions_h

#import <Metal/MTLDefines.h>

#import <Metal/MTL4BinaryFunction.h>
#import <Metal/MTL4FunctionDescriptor.h>
#import <Metal/MTLTypes.h>

NS_ASSUME_NONNULL_BEGIN

/// Groups together functions to link.
MTL_EXPORT
API_AVAILABLE(macos(26.0), ios(26.0))
@interface MTL4LinkedFunctions : NSObject<NSCopying>

/// Provides an array of functions to link at the Metal IR level.
@property (readwrite, nonatomic, copy, nullable) NSArray<MTL4FunctionDescriptor*>* functionDescriptors;

/// Provides an array of binary functions to link.
@property (readwrite, nonatomic, copy, nullable) NSArray<id<MTL4BinaryFunction>>* binaryFunctions;

/// Provides an array of private functions to link at the Metal IR level.
///
///
/// You specify private functions to link separately from ``functionDescriptors`` because pipelines don't export private
/// functions as ``MTLFunctionHandle`` instances.
/// - Note: You can link private functions even when your ``MTLDevice`` doesn't support function pointers.
@property (readwrite, nonatomic, copy, nullable) NSArray<MTL4FunctionDescriptor*>* privateFunctionDescriptors;

/// Assigns groups of functions to match call-site attributes in shader code.
///
/// Function groups help the compiler reduce the number of candidate functions it needs to evaluate for shader function
/// calls, potentially increasing runtime performance.
@property (readwrite, nonatomic, copy, nullable) NSDictionary<NSString*, NSArray<MTL4FunctionDescriptor*>*>* groups;
@end

NS_ASSUME_NONNULL_END

#endif // MTL4LinkedFunctions_h
