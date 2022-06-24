//
//  MTLIOCompression.h
//  Metal
//
//  Copyright © 2022 Apple, Inc. All rights reserved.
//

#import <Metal/MTLDefines.h>
#import <Metal/MTLDevice.h>



typedef NS_ENUM(NSInteger, MTLIOCompressionStatus) {
    MTLIOCompressionStatusComplete = 0,
    MTLIOCompressionStatusError = 1
};

MTL_EXTERN const size_t kMTLIOCompressionContextDefaultChunkSize;

/*
 These methods are expected to be used by offline tools that
 process and generate assets.
 */

/*
 @function MTLIOCreateCompressionContext
 @abstract used to create a context that writes a stream of data to
 a path using a given codec and chunk size.
 */
MTL_EXTERN void* MTLIOCreateCompressionContext(const char* path, MTLIOCompressionMethod type, size_t chunkSize);

/*
 @function MTLIOCompressionContextAppendData
 @abstract append data to a compression context.
 */
MTL_EXTERN void MTLIOCompressionContextAppendData(void* context, const void* data, size_t size);

/*
 @function MTLIOFlushAndDestroyCompressionContext
 @abstract close the compression context and write the pack file.
 */
MTL_EXTERN MTLIOCompressionStatus MTLIOFlushAndDestroyCompressionContext(void* context);


