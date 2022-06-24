//___FILEHEADER___

#import <AudioToolbox/AudioToolbox.h>
#import "___PACKAGENAMEASIDENTIFIER___DSPKernelAdapter.h"

// Define parameter addresses.
extern const AudioUnitParameterID myParam1;

@interface ___PACKAGENAMEASIDENTIFIER___AudioUnit : AUAudioUnit

@property (nonatomic, readonly) ___PACKAGENAMEASIDENTIFIER___DSPKernelAdapter *kernelAdapter;
- (void)setupAudioBuses;
- (void)setupParameterTree;
- (void)setupParameterCallbacks;
@end
