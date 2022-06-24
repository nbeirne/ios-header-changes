#ifndef Spatial_SPRotation3D_h
#define Spatial_SPRotation3D_h

#include <Spatial/Structures.h>

// MARK: - Public API

/*!
 @abstract Returns a rotation over the specified axis with the specified angle.
 
 @param axis The axis of the rotation.
 @param angle The angle of the rotation.
 @returns A new rotation stucture.
*/
SPATIAL_INLINE
SPRotation3D SPRotation3DMake(SPRotationAxis3D axis, SPAngle angle)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract  Returns the rotation represented as a normalized quaternion.
 
 @param rotation The source rotation.
 @returns A quaternion with an axis and angle derived from the source rotation.
*/
SPATIAL_INLINE
simd_quatd SPRotation3DGetQuaternion(SPRotation3D rotation)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a rotation from the specified quaternion.
 
 @param quaternion The source quaternion.
 @returns A new rotation stucture.
*/
SPATIAL_INLINE
SPRotation3D SPRotation3DMakeWithQuaternion(simd_quatd quaternion)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/// Returns @p true if both rotations are equal.
SPATIAL_INLINE
bool SPRotation3DEqualToRotation(SPRotation3D rotation1, SPRotation3D rotation2)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

// MARK: - Header inline implementations

SPATIAL_SWIFT_NAME(Rotation3D.init(quaternion:))
SPRotation3D SPRotation3DMakeWithQuaternion(simd_quatd quaternion) {
  
    simd_double4 vector = quaternion.vector;
    bool hasValidAxis = (vector.x != 0 || vector.y != 0 || vector.z != 0);

    if (!hasValidAxis) {
        return (SPRotation3D) {
            (SPRotationAxis3D){ .simd = { 1, 0, 0 } },
            (SPAngle){ 0 }
        };
    } else {
        return (SPRotation3D) {
            (SPRotationAxis3D){ .simd = simd_axis(quaternion) },
            (SPAngle){ simd_angle(quaternion) }
        };
    }
}

SPATIAL_SWIFT_NAME(Rotation3D.init(axis:angle:))
SPRotation3D SPRotation3DMake(SPRotationAxis3D axis, SPAngle angle) {
    return (SPRotation3D){
        .axis = axis,
        .angle = angle
    };
}

SPATIAL_SWIFT_NAME(getter:Rotation3D.quaternion(self:))
simd_quatd SPRotation3DGetQuaternion(SPRotation3D rotation) {
    return simd_quaternion(rotation.angle.radians,
                           rotation.axis.simd);
}

SPATIAL_REFINED_FOR_SWIFT
bool SPRotation3DEqualToRotation(SPRotation3D rotation1, SPRotation3D rotation2) {
    
    return (SPRotationAxis3DEqualToRotationAxis(rotation1.axis, rotation2.axis) &&
            rotation1.angle.radians == rotation2.angle.radians);
    
}

#endif /* Spatial_SPRotation3D_h */
