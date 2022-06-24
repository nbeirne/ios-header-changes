//___FILEHEADER___

#pragma once

#include <AudioToolbox/AUParameters.h>

#ifdef __cplusplus
namespace ___PACKAGENAMEASIDENTIFIER___ParameterAddress {
#endif

typedef NS_ENUM(AUParameterAddress, ___PACKAGENAMEASIDENTIFIER___ParameterAddress) {
    sendNote = 0,
    midiNoteNumber = 1
};

#ifdef __cplusplus
}
#endif
