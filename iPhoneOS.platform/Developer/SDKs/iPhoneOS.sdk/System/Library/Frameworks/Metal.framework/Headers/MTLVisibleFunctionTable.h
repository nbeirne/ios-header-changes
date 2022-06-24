//
//  MTLVisibleFunctionTable.h
//  Framework
//
//  Copyright © 2020 Apple, Inc. All rights reserved.
//

#import <Metal/MTLDefines.h>

#import <Metal/MTLTypes.h>
#import <Metal/MTLResource.h>
#import <Metal/MTLFunctionHandle.h>

MTL_EXPORT API_AVAILABLE(macos(11.0), ios(14.0))
@interface MTLVisibleFunctionTableDescriptor : NSObject <NSCopying>

/*!
 @method visibleFunctionTableDescriptor
 @abstract Create an autoreleased visible function table descriptor
 */
+ (nonnull MTLVisibleFunctionTableDescriptor *)visibleFunctionTableDescriptor;

/*!
* @property functionCount
* @abstract The number of functions in the table.
*/
@property (nonatomic) NSUInteger functionCount;

@end

API_AVAILABLE(macos(11.0), ios(14.0))
@protocol MTLVisibleFunctionTable <MTLResource>

/*!
 @property gpuHandle
 @abstract accessible by the CPU, and used to get the device handle of a resource/object that could be normally passed to the GPU within an argument buffer
 this will be deleted as the gpuResourceID will replace it
 */
@property (readonly) MTLGPUHandle gpuHandle;
/*!
 @property gpuResourceID
 @abstract Accessible by the CPU, it is used to get the handle of a GPU resource that could be normally passed to the GPU
 */
@property (readonly) MTLResourceID gpuResourceID API_AVAILABLE(macos(13.0), ios(16.0));

- (void)setFunction:(nullable id <MTLFunctionHandle>)function atIndex:(NSUInteger)index;

- (void)setFunctions:(const id <MTLFunctionHandle> __nullable [__nonnull])functions withRange:(NSRange)range;

@end

