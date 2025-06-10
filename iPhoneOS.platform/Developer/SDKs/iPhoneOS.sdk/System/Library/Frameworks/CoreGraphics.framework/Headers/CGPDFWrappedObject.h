//
//  CGPDFWrappedObject.h
//  CoreGraphics
//
//  Copyright © 2024 Apple. All rights reserved.
//

#ifndef CGPDFWRAPPEDOBJECT_H_
#define CGPDFWRAPPEDOBJECT_H_

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFAvailability.h>
#include <CoreGraphics/CGPDFObject.h>
#include <CoreGraphics/CGPDFString.h>
#include <CoreGraphics/CGPDFArray.h>
#include <CoreGraphics/CGPDFDictionary.h>
#include <CoreGraphics/CGPDFStream.h>

/// CGPDFWrappedObject is used to add a PDF object to a CGPDFArray or CGPDFDictionary.

typedef struct CF_BRIDGED_TYPE(id) CGPDFWrappedObject *CGPDFWrappedObjectRef;

CF_IMPLICIT_BRIDGING_ENABLED

CF_ASSUME_NONNULL_BEGIN

CG_EXTERN CGPDFWrappedObjectRef CGPDFWrappedObjectCreateWithBoolean(CGPDFBoolean value);
CG_EXTERN CGPDFWrappedObjectRef CGPDFWrappedObjectCreateWithInteger(CGPDFInteger value);
CG_EXTERN CGPDFWrappedObjectRef CGPDFWrappedObjectCreateWithReal(CGPDFReal value);
CG_EXTERN CGPDFWrappedObjectRef CGPDFWrappedObjectCreateWithName(const char *value);
CG_EXTERN CGPDFWrappedObjectRef CGPDFWrappedObjectCreateWithString(CGPDFStringRef value);
CG_EXTERN CGPDFWrappedObjectRef CGPDFWrappedObjectCreateWithArray(CGPDFArrayRef value);
CG_EXTERN CGPDFWrappedObjectRef CGPDFWrappedObjectCreateWithDictionary(CGPDFDictionaryRef value);
CG_EXTERN CGPDFWrappedObjectRef CGPDFWrappedObjectCreateWithStream(CGPDFStreamRef value);

CF_ASSUME_NONNULL_END

CF_IMPLICIT_BRIDGING_DISABLED

#endif /* CGPDFWRAPPEDOBJECT_H_ */
