//___FILEHEADER___

#import <FileProvider/FileProvider.h>

@interface ___FILEBASENAME___ : NSObject <NSFileProviderEnumerator>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithEnumeratedItemIdentifier:(NSFileProviderItemIdentifier)enumeratedItemIdentifier;

@property (nonatomic, readonly, strong) NSFileProviderItemIdentifier enumeratedItemIdentifier;

@end
