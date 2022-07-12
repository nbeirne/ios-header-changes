//___FILEHEADER___

#import <CryptoTokenKit/CryptoTokenKit.h>

@interface TokenDriver : TKSmartCardTokenDriver<TKSmartCardTokenDriverDelegate>

@end

@interface TokenSession : TKSmartCardTokenSession<TKTokenSessionDelegate>

@end

@interface Token : TKSmartCardToken<TKTokenDelegate>

- (instancetype)initWithSmartCard:(TKSmartCard *)smartCard AID:(NSData *)AID tokenDriver:(TokenDriver *)tokenDriver error:(NSError **)error;

@end
