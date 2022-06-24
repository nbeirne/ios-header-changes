//
//  HKGlassesPrescription.h
//  HealthKit
//
//  Copyright © 2022 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HealthKit/HKDefines.h>
#import <HealthKit/HKVisionPrescription.h>

@class HKDevice;
@class HKQuantity;
@class HKGlassesLensSpecification;

NS_ASSUME_NONNULL_BEGIN

/*!
 @class         HKGlassesPrescription
 @abstract      An object subclass representing a glasses prescription
 */
HK_EXTERN API_AVAILABLE(ios(16.0), watchos(9.0), macCatalyst(16.0), macos(13.0))
@interface HKGlassesPrescription : HKVisionPrescription

/*!
 @property      glassesDescription
 @abstract      The description of the type of glasses
 */
@property (nonatomic, copy, readonly) NSString *glassesDescription;

/*!
 @property      rightEye
 @abstract      The right eye lens specification
 */
@property (nonatomic, copy, readonly, nullable) HKGlassesLensSpecification *rightEye;

/*!
 @property      leftEye
 @abstract      The left eye lens specification
 */
@property (nonatomic, copy, readonly, nullable) HKGlassesLensSpecification *leftEye;

/*!
 @method        prescriptionWithRightEyeSpecification:leftEyeSpecification:type:dateIssued:expirationDate:device:metadata

 @param         rightEyeSpecification    The right eye specification
 @param         leftEyeSpecification     The left eye specification
 @param         description              The description of the type of glasses
 @param         dateIssued               The date the prescription was issued
 @param         expirationDate           The date the prescription expires
 @param         device                   The device that generated the sample
 @param         metadata                 The metadata for the sample
 */
+ (instancetype)prescriptionWithRightEyeSpecification:(nullable HKGlassesLensSpecification *)rightEyeSpecification
                                 leftEyeSpecification:(nullable HKGlassesLensSpecification *)leftEyeSpecification
                                          description:(NSString *)description
                                           dateIssued:(NSDate *)dateIssued
                                       expirationDate:(nullable NSDate *)expirationDate
                                               device:(nullable HKDevice *)device
                                             metadata:(nullable NSDictionary<NSString *, id> *)metadata;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
