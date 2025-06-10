//
//  BEHostingHandle.h
//  BrowserEngineKit
//
//  Copyright © 2023 Apple Inc. All rights reserved.
//

#import <BrowserEngineKit/BEMacros.h>
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


API_AVAILABLE(ios(17.4))
API_UNAVAILABLE(macos, watchos, tvos, visionos)
BROWSERENGINE_EXPORT
BROWSERENGINE_FINAL
NS_SWIFT_SENDABLE
NS_SWIFT_NAME(LayerHierarchyHandle)
@interface BELayerHierarchyHandle : NSObject <NSSecureCoding>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

#if BROWSERENGINEKIT_HAS_LIBXPC
+ (nullable BELayerHierarchyHandle *)handleWithXPCRepresentation:(nullable xpc_object_t)xpcRepresentation error:(NSError **)error NS_SWIFT_NAME(init(xpcRepresentation:));
- (xpc_object_t)createXPCRepresentation NS_SWIFT_NAME(createXPCRepresentation());
#endif

/// takes ownership of the port right (even if it returns nil).
+ (nullable BELayerHierarchyHandle *)handleWithPort:(mach_port_t)port
                                               data:(NSData *)data
                                              error:(NSError **)error NS_SWIFT_NAME(init(port:data:)) API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(macos, watchos, tvos, visionos);

/// passes a copy of the send right or `MACH_PORT_NULL` if inert.
/// the receiver is responsible for disposing of `copiedPort`.
/// the port and data should be consumed together and _only_ once by `init(port:data:)`.
- (void)encodeWithBlock:(void(^ NS_NOESCAPE)(mach_port_t copiedPort, NSData *data))block NS_SWIFT_NAME(encode(_:)) API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(macos, watchos, tvos, visionos);

@end

NS_ASSUME_NONNULL_END
