//
//  MTL4BinaryFunction.h
//  Metal
//
//  Copyright © 2024 Apple, Inc. All rights reserved.
//

#ifndef MTL4BinaryFunction_h
#define MTL4BinaryFunction_h

#import <Metal/MTLDefines.h>

#import <Foundation/Foundation.h>
#import <Metal/MTLTypes.h>
#import <Metal/MTLLibrary.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents reflection information for a binary function.
MTL_EXPORT
API_AVAILABLE(macos(26.0), ios(26.0))
@interface MTL4BinaryFunctionReflection : NSObject
@end

/// Represents a binary function.
///
/// A binary function is a shader that you precompile from Metal IR to GPU machine code.
API_AVAILABLE(macos(26.0), ios(26.0)) NS_SWIFT_SENDABLE
@protocol MTL4BinaryFunction <NSObject>

/// Obtains the optional name of this binary function.
@property (nullable, readonly) NSString* name;

/// Obtains reflection information for this binary function.
@property (nullable, readonly) MTL4BinaryFunctionReflection* reflection;

/// Describes the type of this binary function.
@property (readonly) MTLFunctionType functionType;

@end

NS_ASSUME_NONNULL_END
#endif // MTL4BinaryFunction_h
