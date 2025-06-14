/* CoreAnimation - CAGradientLayer.h

   Copyright (c) 2008-2025, Apple Inc.
   All rights reserved. */

/* The gradient layer draws a color gradient over its background color,
 * filling the shape of the layer (i.e. including rounded corners). */

#ifdef __OBJC__

#import <QuartzCore/CALayer.h>
#import <QuartzCore/CAMediaTimingFunction.h>
#import <Foundation/NSArray.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

typedef NSString * CAGradientLayerType NS_TYPED_ENUM API_AVAILABLE(macos(10.6), ios(3.0), tvos(9.0)) API_UNAVAILABLE(watchos);

API_AVAILABLE(macos(10.6), ios(3.0), tvos(9.0)) API_UNAVAILABLE(watchos)
@interface CAGradientLayer : CALayer

/* The array of CGColorRef objects defining the color of each gradient
 * stop. Defaults to nil. Animatable. */

@property(nullable, copy) NSArray *colors;

/* An optional array of NSNumber objects defining the location of each
 * gradient stop as a value in the range [0,1]. The values must be
 * monotonically increasing. If a nil array is given, the stops are
 * assumed to spread uniformly across the [0,1] range. When rendered,
 * the colors are mapped to the output colorspace before being
 * interpolated. Defaults to nil. Animatable. */

@property(nullable, copy) NSArray<NSNumber *> *locations;

/* The start and end points of the gradient when drawn into the layer's
 * coordinate space. The start point corresponds to the first gradient
 * stop, the end point to the last gradient stop. Both points are
 * defined in a unit coordinate space that is then mapped to the
 * layer's bounds rectangle when drawn. (I.e. [0,0] is the bottom-left
 * corner of the layer, [1,1] is the top-right corner.) The default values
 * are [.5,0] and [.5,1] respectively. Both are animatable. */

@property CGPoint startPoint;
@property CGPoint endPoint;

/* The kind of gradient that will be drawn. Currently, the only allowed
 * values are `axial' (the default value), `radial', and `conic'. */

@property(copy) CAGradientLayerType type;

@end

/** `type' values. **/

CA_EXTERN CAGradientLayerType const kCAGradientLayerAxial
    API_AVAILABLE(macos(10.6), ios(3.0), tvos(9.0)) API_UNAVAILABLE(watchos);

/* Radial gradient. The gradient is defined as an ellipse with its
 * center at 'startPoint' and its width and height defined by
 * '(endPoint.x - startPoint.x) * 2' and '(endPoint.y - startPoint.y) *
 * 2' respectively. */

CA_EXTERN CAGradientLayerType const kCAGradientLayerRadial
    API_AVAILABLE(macos(10.6), ios(3.2), tvos(9.0)) API_UNAVAILABLE(watchos);

/* Conic gradient. The gradient is centered at 'startPoint' and its 0-degrees
 * direction is defined by a vector spanned between 'startPoint' and
 * 'endPoint'. When 'startPoint' and 'endPoint' overlap the results are
 * undefined. The gradient's angle increases in the direction of rotation of
 * positive x-axis towards positive y-axis. */

CA_EXTERN CAGradientLayerType const kCAGradientLayerConic
    API_AVAILABLE(macos(10.14), ios(12.0), tvos(12.0)) API_UNAVAILABLE(watchos);

NS_HEADER_AUDIT_END(nullability, sendability)

#endif
