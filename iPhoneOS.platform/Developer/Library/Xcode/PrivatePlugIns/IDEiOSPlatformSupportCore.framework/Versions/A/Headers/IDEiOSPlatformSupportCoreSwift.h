//
//  IDEiOSPlatformSupportCoreSwift.h
//  DVTiOSFrameworks
//
//  Created by Jonathan Hess on 12/20/21.
//  Copyright © 2021 Apple Inc. All rights reserved.
//

// Accept that we're not supposed to add new clients of `SWIFT_INSTALL_OBJC_HEADER = YES`, and manually author our objective-c interface

#import <Foundation/Foundation.h>

@class DVTFilePath;
NS_ASSUME_NONNULL_BEGIN

@interface DistributionArchiveReformatterAppClipSupport: NSObject
+ (nullable DVTFilePath *)appClipsDirectoryPathWithProductsDirectoryPath:(DVTFilePath *)path;
@end

NS_ASSUME_NONNULL_END
