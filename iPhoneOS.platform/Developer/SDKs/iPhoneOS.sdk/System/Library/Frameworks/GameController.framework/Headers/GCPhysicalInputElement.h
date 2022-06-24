//  
//  GCPhysicalInputElement.h
//  GameController
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0))
@protocol GCPhysicalInputElement <NSObject>

/**
 The element's SF Symbols name.
 */
@property (readonly, nullable) NSString *sfSymbolsName;

/**
 The element's localized name.
 */
@property (readonly, nullable) NSString *localizedName;

/**
 A set of aliases that can be used to access this element with keyed subscript
 notation.
 */
@property (readonly) NSSet<NSString *> *aliases;

@end

NS_ASSUME_NONNULL_END
