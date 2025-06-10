//
//  CPListImageRowItemImageGridElement.h
//  CarPlay
//
//  Copyright © 2025 Apple Inc. All rights reserved.
//

#import <CarPlay/CPListImageRowItemElement.h>
#import <CarPlay/CPTemplate.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(tvos) API_UNAVAILABLE(macos, watchos)
/**
 Types of shape used to draw a list item.
 */
typedef NS_ENUM(NSUInteger, CPListImageRowItemImageGridElementShape) {
    /**
     The list item will render a row of elements.
     */
    CPListImageRowItemImageGridElementShapeCircular = 0,
    CPListImageRowItemImageGridShapeCircular = 0,
    /**
     The list item will render a condensed list of rounded rectangle elements.
     */
    CPListImageRowItemImageGridElementShapeRoundedRectangle = 1,
    CPListImageRowItemImageGridShapeRoundedRectangle = 1,
};

API_AVAILABLE(ios(26.0)) API_UNAVAILABLE(tvos) API_UNAVAILABLE(macos, watchos)
CARPLAY_TEMPLATE_UI_ACTOR
@interface CPListImageRowItemImageGridElement: CPListImageRowItemElement

/**
 Initialize an element that is constituted of an image and an image shape.
 
 When providing an image, your app should provide a @c UIImage that is display-ready. If necessary for the image, provide
 light and dark styles by using an asset from your asset catalog, prepared with light and dark styles
 or by using @c UIImageAsset to combine two @c UIImage instances into a single image with
 both styles.
 
 UIImageAsset is used to combine multiple UIImages with different trait collections into a single UIImage.
 
 @note The expected image size is given by +[CPListImageRowItemImageGridElement maximumImageSize]. Images provided will be resized to this size if necessary.
 
 @discussion To properly size your images, your app should size them to the display scale of the car screen.
 See -[CPInterfaceController carTraitCollection].
 
 @param image The image associated to the element.
 @param imageShape The @c CPListImageRowItemImageGridElementShape shape being applied on the image.
 */

- (instancetype)initWithImage:(UIImage *)image
                   imageShape:(CPListImageRowItemImageGridElementShape)imageShape;

/**
 Shape used to draw the image of the element.
 */
@property (nonatomic, assign, readonly) CPListImageRowItemImageGridElementShape imageShape;

@end

NS_ASSUME_NONNULL_END
