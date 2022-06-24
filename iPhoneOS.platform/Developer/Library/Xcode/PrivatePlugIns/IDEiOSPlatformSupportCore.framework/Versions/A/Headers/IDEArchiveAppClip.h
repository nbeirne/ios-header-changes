//
//  IDEArchiveAppClip.h
//  IDEiOSPlatformSupportCore
//
//  Created by Chris D'Angelo on 2/2/20.
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#import <IDEFoundation/IDEArchive.h>

NS_ASSUME_NONNULL_BEGIN

@class DVTFilePath;

@interface IDEArchiveAppClip : IDEArchive

+ (nullable instancetype)appClipArchiveWithArchivePath:(DVTFilePath *)archivePath;

@end

NS_ASSUME_NONNULL_END
