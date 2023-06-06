#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UINibLoading.h>)
//
//  UINibLoading.h
//  UIKit
//
//  Copyright (c) 2005-2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

typedef NSString * UINibOptionsKey NS_TYPED_ENUM;

UIKIT_EXTERN UINibOptionsKey const UINibExternalObjects API_AVAILABLE(ios(3.0));

@interface NSBundle(UINibLoadingAdditions)
- (nullable NSArray *)loadNibNamed:(NSString *)name owner:(nullable id)owner options:(nullable NSDictionary<UINibOptionsKey, id> *)options API_DEPRECATED("Loading Interface Builder products will not be supported in a future version of xrOS.", xros(1.0, 1.0));
@end

@interface NSObject(UINibLoadingAdditions)
- (void)awakeFromNib NS_REQUIRES_SUPER API_DEPRECATED("Loading Interface Builder products will not be supported in a future version of xrOS.", xros(1.0, 1.0));
- (void)prepareForInterfaceBuilder API_AVAILABLE(ios(8.0)) API_DEPRECATED("Loading Interface Builder products will not be supported in a future version of xrOS.", xros(1.0, 1.0));
@end

UIKIT_EXTERN NSString * const UINibProxiedObjectsKey API_DEPRECATED("", ios(2.0, 3.0)) API_UNAVAILABLE(xros) API_UNAVAILABLE(tvos);

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UINibLoading.h>
#endif
