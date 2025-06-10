//___FILEHEADER___

#import <DeviceDiscoveryExtension/DeviceDiscoveryExtension.h>

NS_ASSUME_NONNULL_BEGIN

@interface ___FILEBASENAME:identifier___ : NSObject

/// Start searching for devices using locators.
- (void)startDiscoveryWithSession:(DDDiscoverySession *)session;

/// Stop searching for devices using locators.
- (void)stopDiscoveryWithSession:(DDDiscoverySession *)session;

@end

/// A DeviceLocator knows how to scan for devices and encapsulates the details about how it does so.
@protocol DeviceLocator <NSObject>

/// Start scanning for devices.
- (void)startScanning;

/// Stop scanning for devices.
- (void)stopScanning;

/// When a device changes state, the DeviceLocator will invoke this handler. The extension can then pass the given event back to its session.
@property (readwrite, copy, nullable, nonatomic) DDEventHandler eventHandler;

@end

NS_ASSUME_NONNULL_END
