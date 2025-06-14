//
//  PHASESoundEvent.h
//  PHASE
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#ifndef PHASESoundEvent_h
#define PHASESoundEvent_h

#import <AVFAudio/AVAudioTime.h>
#import <PHASE/PHASETypes.h>

@class PHASESoundEventNodeAsset;
@class PHASEEngine;
@class PHASEListener;
@class PHASEMixer;
@class PHASESource;
@class PHASEMixerParameters;
@class PHASESoundEventNodeDefinition;
@class PHASEMetaParameter;
@class PHASEPushStreamNode;
@class PHASEPullStreamNode;

NS_ASSUME_NONNULL_BEGIN

/****************************************************************************************************/
/*!
    @interface PHASESoundEvent
    @abstract A PHASESoundEvent is an object that represents a playable sound event in the PHASE system.
 */
OS_EXPORT API_AVAILABLE(macos(12.0), ios(15.0), tvos(17.0)) API_UNAVAILABLE(watchos)
@interface PHASESoundEvent : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/*!
    @method initWithEngine:assetIdentifier:mixerParameters:error
    @abstract Creates a new sound event instance
    @param engine
        The PHASEEngine object that the sound event will be played by.
    @param assetIdentifier
        The identifier registered with the Asset Registry for the particular PHASESoundEventNodeAsset that this sound instance will play.
        If the asset identifier is not registered, this function will fail.
    @param mixerParameters
        A dictionary of PHASEMixerParameters objects with keys that match the identifiers of the spatial mixers in the sound event
    @discussion
        This will look up the asset in the asset registry and create the necessary objects to play the sound event
 */
- (nullable instancetype)initWithEngine:(PHASEEngine*)engine
                        assetIdentifier:(NSString*)assetIdentifier
                        mixerParameters:(PHASEMixerParameters*)mixerParameters
                                  error:(NSError**)error;

/*!
    @method initWithEngine:assetIdentifier:error
    @abstract Creates a new sound event instance
    @param engine
        The PHASEEngine object that the sound event will be played by.
    @param assetIdentifier
        The identifier registered with the Asset Registry for the particular PHASESoundEventNodeAsset that this sound event will play.
        If the asset identifier is not registered, this function will fail.
    @discussion
        This will look up the asset in the asset registry and create the necessary objects to play the sound event
 */
- (nullable instancetype)initWithEngine:(PHASEEngine*)engine
                        assetIdentifier:(NSString*)assetIdentifier
                                  error:(NSError**)error;

/*!
    @method prepareWithCompletion
    @abstract Prepare the sound event
    @param handler
        The block that will be called when the PHASESoundEvent has finished preparing and is ready to start. Pass in nil for no handler.
    @discussion
        This function notifies the engine to begin preparing a sound event, then returns immediately.
        Once the sound event is prepared (or has failed to prepare), you will receive a callback via the completion.
        If you call startWithCompletion() before receiving the callback, the sound event will start as soon as it's prepared.
 */
- (void)prepareWithCompletion:(void (^_Nullable)(PHASESoundEventPrepareHandlerReason reason))handler;

/*!
    @method startWithCompletion
    @abstract Start the sound event
    @param handler
        The block that will be called when the sound event has stopped.
    @discussion
        This function notifies the engine to start the sound event, then returns immediately.
        Once the sound event is playing (or has failed to start), you will receive a callback via the completion.
        Playback will begin immediately if the sound event has been prepared; otherwise, it will start as soon as it is finished preparing.
 */
- (void)startWithCompletion:(void (^_Nullable)(PHASESoundEventStartHandlerReason reason))handler;

/*!
    @method startAtTime:completion
    @abstract Start the sound event
    @param when
        The desired start time based on the engine time retrieved from [PHASEEngine lastRenderTime]
        If the sound event starts immediately with an audible sound, it will begin rendering at this time.  The sound event will otherwise begin operating at this time.
        A nil value will start the sound event immediately
        This time is not scaled by unitsPerSecond.
    @param handler
        The block that will be called when the sound event has stopped.
    @discussion
        This function notifies the engine to start the sound event, then returns immediately.
        Once the sound event is playing (or has failed to start), you will receive a callback via the completion.
        Playback will begin at the requested time if the sound event has finished preparing in time.
        You may wait for preparation to finish with the [PHASESoundEvent prepare:completion] method before calling startAtTime, to ensure that the sound event will start at the desired time.
        However if the desired time is far enough into the future to allow for preparation to happen, you may skip calling prepare entirely and just call startAtTime.
 */
- (void)startAtTime:(nullable AVAudioTime*)when completion:(void (^_Nullable)(PHASESoundEventStartHandlerReason reason))handler
API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE( watchos);

/*!
    @method seekToTime:completion
    @abstract Seeks all leaf nodes in a PHASESoundEvent to a specified time relative to the start of the sound event.
    @discussion
        This function notifies the engine to seek the sound event, then returns immediately.
        Once the sound event has seeked to the new offset (or has failed to seek), you will receive a callback via the completion.
        If any leaf nodes do not support seeking, those nodes will ignore this command.
        Nodes that have finished playing or have stopped will not seek.
        Nodes that are sleeping will seek, and will resume at the correct time when they wake up.
    @note
        The time is scaled by unitsPerSecond internally, so can be provided at the client's native time scale.
*/
- (void)seekToTime:(double)time completion:(nullable void (^)(PHASESoundEventSeekHandlerReason reason))handler
NS_SWIFT_NAME(seek(to:completion:));

/*!
    @method seekToTime:resumeAtEngineTime:completion
    @abstract Seeks all leaf nodes in a PHASESoundEvent to the specified time, and automatically resumes playback at the specified engine time.
    @param time The desired time position in seconds to seek the nodes to.
    @param engineTime The engine time to resume playback.
    @param handler The completion callback that will be called when seeking is complete.
    @discussion
        This is a low latency convenience method that allows for tight deadlines to be met.  However if the seek fails the node state will not be changed.  You should check the callback and handle the failure appropriately.
        The time parameter will seek the nodes to the equivalent sample position based on the sample rate of the asset.
        The engineTime parameter is the engine timestamp to resume rendering at, based off of [PHASEEngine lastRenderTime].
        If any leaf nodes do not support seeking, those nodes will ignore this command.
        Nodes that have finished playing or have stopped will not seek.
        The time parameter is in seconds and will be scaled by unitsPerSecond.
        The time in the AVAudioTime structure is not scaled by unitsPerSecond.
        The engineTime parameter will use the sample time if valid, if not, then the host time if valid.
*/
- (void)seekToTime:(double)time resumeAtEngineTime:(AVAudioTime*)engineTime completion:(nullable void (^)(PHASESoundEventSeekHandlerReason reason))handler
API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE( watchos)
NS_SWIFT_NAME(seek(to:resumeAt:completion:));

/*!
    @method pause
    @abstract Pause the sound event.
 */
- (void)pause;

/*!
    @method resume
    @abstract Resume the sound event.
 */
- (void)resume;

/*!
    @method resumeAtTime
    @abstract Resume the sound event at a specific time
    @param time The desired start time based on the engine time retrieved from [PHASEEngine lastRenderTime]
    @discussion
        A nil time parameter will resume immediately.
        The device time is not scaled by UnitsPerSecond and is in seconds.
 */
- (void)resumeAtTime:(nullable AVAudioTime*)time
API_AVAILABLE(macos(26.0), ios(26.0), tvos(26.0), visionos(26.0)) API_UNAVAILABLE( watchos)
NS_SWIFT_NAME(resume(at:));

/*!
    @method stopAndInvalidate
    @abstract stop and invalidate the sound event
 */
- (void)stopAndInvalidate;

/*!
    @property renderingState
    @abstract Sound Event's current rendering state
*/
@property(readonly) PHASERenderingState renderingState;

/*!
    @property prepareState
    @abstract Sound Event's current preparation state
*/
@property(readonly) PHASESoundEventPrepareState prepareState;

/*!
    @property metaParameters
    @abstract A Dictionary containing the MetaParameters associated with this sound event
*/
@property(readonly, copy) NSDictionary<NSString*, PHASEMetaParameter*>* metaParameters;

/*!
    @property mixNodes
    @abstract A Dictionary containing the mix nodes associated with this sound event
*/
@property(readonly, copy) NSDictionary<NSString*, PHASEMixer*>* mixers;

/*!
    @property pushStreamNodes
    @abstract A Dictionary containing the push stream nodes associated with this sound event, for pushing buffers to.
*/
@property(readonly, copy) NSDictionary<NSString*, PHASEPushStreamNode*>* pushStreamNodes;

/*!
    @property pullStreamNodes
    @abstract A Dictionary containing the pull stream nodes associated with this sound event, for setting renderBlocks on.
*/
@property(readonly, copy) NSDictionary<NSString*, PHASEPullStreamNode*>* pullStreamNodes
API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), visionos(2.0)) API_UNAVAILABLE(watchos);

/*!
    @property indefinite
    @abstract A boolean that tell if this sound event will run indefinitely, or finish executing on its own
*/
@property(readonly, getter=isIndefinite) BOOL indefinite;

@end

NS_ASSUME_NONNULL_END


#endif /* PHASESoundEvent_h */
