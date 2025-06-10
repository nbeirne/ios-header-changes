//
//  MeshNetFramework.h
//  MeshNetFramework
//
//  Created by Ria Paul on 4/9/25.
//

// In this header, you should import all the public headers of your framework using statements like #import
// <MeshNetFramework/PublicHeader.h>

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Declare the functions exposed by the Swift framework
int32_t connectToPeerNative(const char * host);
int32_t listenForConnectionNative();

#ifdef __cplusplus
}
#endif
