#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIWindowSceneMacGeometryPreferences.h>)
//
//  UIWindowSceneMacGeometryPreferences.h
//  UIKit
//
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIWindowSceneGeometryPreferences.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

UIKIT_EXTERN API_AVAILABLE(macCatalyst(16.0))
@interface UIWindowSceneMacGeometryPreferences : UIWindowSceneGeometryPreferences

- (instancetype)initWithSystemFrame:(CGRect)systemFrame NS_DESIGNATED_INITIALIZER;

@property (nonatomic, assign) CGRect systemFrame;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UIWindowSceneMacGeometryPreferences.h>
#endif
