//
//  TCCircleCollider.h
//  TouchControls
//

#import <Foundation/Foundation.h>

#import <TouchControls/TCCollider.h>
#import <TouchControls/TCTransform.h>

NS_ASSUME_NONNULL_BEGIN

/// A circular collider.
@interface TCCircleCollider : NSObject<TCCollider>

/// Creates a new circle collider with the specified transform.
///
/// - Parameters:
///   - transform: The transform to use for the collider.
/// - Returns: A new `TCCircleCollider` instance.
- (instancetype)initWithTransform:(id<TCTransform>)transform;

@end

NS_ASSUME_NONNULL_END
