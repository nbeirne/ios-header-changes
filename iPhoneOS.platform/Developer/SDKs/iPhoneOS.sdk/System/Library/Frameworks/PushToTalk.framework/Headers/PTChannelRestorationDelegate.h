//
//  PTChannelRestorationDelegate.h
//  PushToTalk
//
//  Copyright © 2022 Apple. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <PushToTalk/PTChannelDescriptor.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PTChannelRestorationDelegate <NSObject>

/// If the system had been tracking a channel previously, this method will be called.
- (PTChannelDescriptor *)channelDescriptorForRestoredChannelUUID:(NSUUID *)channelUUID NS_SWIFT_NAME(channelDescriptor(restoredChannelUUID:));

@end

NS_ASSUME_NONNULL_END


