//___FILEHEADER___

#import <FileProvider/FileProvider.h>

@interface FileProviderItem : NSObject<NSFileProviderItem>

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithItemIdentifier:(NSFileProviderItemIdentifier)itemIdentifier NS_DESIGNATED_INITIALIZER;

@end
