#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIPasteControl.h>)
//
//  UIPasteControl.h
//  UIKit
//
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@class NSCoder;
@protocol UIPasteConfigurationSupporting;

typedef NS_ENUM(NSUInteger, UIPasteControlDisplayMode) {
    UIPasteControlDisplayModeIconAndLabel,
    UIPasteControlDisplayModeIconOnly,
    UIPasteControlDisplayModeLabelOnly
} API_AVAILABLE(ios(16.0)) NS_SWIFT_NAME(UIPasteControl.DisplayMode);

typedef NS_ENUM(NSInteger, UIPasteControlCornerStyle) {
    UIPasteControlCornerStyleNone,
    UIPasteControlCornerStyleSmall,
    UIPasteControlCornerStyleMedium,
    UIPasteControlCornerStyleLarge,
    UIPasteControlCornerStyleCapsule
} API_AVAILABLE(ios(16.0)) NS_SWIFT_NAME(UIPasteControl.CornerStyle);

UIKIT_EXTERN API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(tvos, watchos) NS_SWIFT_NAME(UIPasteControl.Configuration) NS_SWIFT_UI_ACTOR
@interface UIPasteControlConfiguration : NSObject <NSSecureCoding>
@property (nonatomic) UIPasteControlDisplayMode displayMode;
@property (nonatomic) UIPasteControlCornerStyle cornerStyle;
@property (nonatomic, nullable) UIColor *baseForegroundColor;
@property (nonatomic, nullable) UIColor *baseBackgroundColor;
@end

UIKIT_EXTERN API_AVAILABLE(ios(16.0)) API_UNAVAILABLE(tvos, watchos) NS_SWIFT_UI_ACTOR
@interface UIPasteControl : UIControl
@property (nonatomic, readonly) UIPasteControlConfiguration *configuration;
@property (nonatomic, nullable, weak) id<UIPasteConfigurationSupporting> target;

- (instancetype)initWithConfiguration:(UIPasteControlConfiguration *)configuration NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UIPasteControl.h>
#endif
