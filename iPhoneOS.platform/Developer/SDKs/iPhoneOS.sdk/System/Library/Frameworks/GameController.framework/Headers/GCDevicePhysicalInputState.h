//  
//  GCDevicePhysicalInputState.h
//  GameController
//
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <GameController/GCPhysicalInputElement.h>
#import <GameController/GCButtonElement.h>
#import <GameController/GCAxisElement.h>
#import <GameController/GCSwitchElement.h>
#import <GameController/GCDirectionPadElement.h>

@protocol GCDevice;

NS_ASSUME_NONNULL_BEGIN

/**
 An object conforming to \c GCDevicePhysicalInputState contains the state of
 a device's physical inputs.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0))
@protocol GCDevicePhysicalInputState <NSObject>

/**
 The device that this profile is mapping input from.
 */
@property (weak, readonly) id<GCDevice> device;

/**
 The internal time stamp of the last event.
 
 This time interval is not relative to any specific point in time.  Your
 application can subtract a previous timestamp from the returned timestamp to
 determine the time (in seconds) between events.  The \c lastEventTimestamp of
 the inputs from two different devices can be compared to determine which event
 occurred first.
 */
@property (readonly) NSTimeInterval lastEventTimestamp;

/**
 The interval (in seconds) between the timestamp of the last event and the
 current time.
 
 This value should be treated as a lower bound of the event latency.  It may
 not include (wired or wireless) transmission latency, or latency accrued on
 the device before the event was transmitted to the host.
 
 @note
 If the system has gone to sleep between when the event occurred and when this
 property is read, the returned value may not reflect the true latency.
 */
@property (readonly) NSTimeInterval lastEventLatency;

/**
 The following properties allow for runtime lookup of any input element on a
 profile, when provided with a valid alias.

 @example input.elements["Button A"] == extendedGamepad.buttonA // YES
 @example input.dpads["Left Thumbstick"] == extendedGamepad.leftThumbstick // YES
 @example input.dpads["Button B"] // returns nil, "Button B" is not a DirectionPad
 */
@property (readonly) NSDictionary<NSString *, id<GCPhysicalInputElement> > *elements;
@property (readonly) NSDictionary<NSString *, id<GCButtonElement> > *buttons;
@property (readonly) NSDictionary<NSString *, id<GCAxisElement> > *axes;
@property (readonly) NSDictionary<NSString *, id<GCSwitchElement> > *switches;
@property (readonly) NSDictionary<NSString *, id<GCDirectionPadElement> > *dpads;

/**
 Profile elements can be accessed using keyed subscript notation, with a valid alias of its inputs.
 
 @example physicalInput["Button A"] == extendedGamepad.buttonA // YES
 @example physicalInput["Button X"] == microGamepad.buttonX // YES
 @note Equivalent to -elements
 */
- (__kindof id<GCPhysicalInputElement> _Nullable)objectForKeyedSubscript:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
