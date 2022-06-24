#ifndef Spatial_SPPoint3D_h
#define Spatial_SPPoint3D_h

#include <Spatial/Structures.h>

// MARK: - Public API

/*!
 @abstract Creates a point with the specified coordinates.
 
 @param x The x coordinate.
 @param y The y coordinate.
 @param z The z coordinate.
 @returns A new point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DMake(double x, double y, double z)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Creates a point with coordinates specified as a 3-element SIMD vector.
 
 @param xyz The source vector.
 @returns A new point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DMakeWithVector(simd_double3 xyz)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Creates a point with coordinates specified as a dimensions of a size structure.
 
 @param size The source size.
 @returns A new point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DMakeWithSize(SPSize3D size)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point with an origin that is offset from that of the source point.
 
 @param point The source point.
 @param offset A size structure that defines the offset.
 @returns A point that's offset by the @p width, @p height, and @p depth of the size.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DTranslate(SPPoint3D point, SPSize3D offset)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns the position of the entity's origin.
 
 @param point The source point.
 @returns For point structures, this function returns a point that's identical to the source point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DGetOrigin(SPPoint3D point)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns the distance between the origins of two points.
 
 @param point The first point.
 @param other The second point.
 @returns The distance between the two points.
*/
SPATIAL_INLINE
double SPPoint3DDistanceToPoint(SPPoint3D point, SPPoint3D other)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns the rotation around @p (0,0,0)  from the first point to the second point.
 
 @param point The first point.
 @param other The second point.
 @returns A rotation structure that represents the rotation.
*/
SPATIAL_INLINE
SPRotation3D SPPoint3DRotationToPoint(SPPoint3D point, SPPoint3D other)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns the @p x, @p y, and @p z components of the point expressed as a simd vector.
 
 @param point The source point.
 @returns A vector that represents the point.
*/
SPATIAL_INLINE simd_double3 SPPoint3DGetVector(SPPoint3D point)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's transformed by the specified affine transform.
 
 @param point The source point.
 @param transform The affine transform that the function applies to the point.
 @returns The transformed point,
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DApplyAffineTransform(SPPoint3D point,
                                        SPAffineTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's transformed by the specified projective transform.
 
 @param point The source point.
 @param transform The projective transform that the function applies to the point.
 @returns The transformed point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DApplyProjectiveTransform(SPPoint3D point,
                                            SPProjectiveTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's transformed by the inverted affine transform.
 
 @param point The source point.
 @param transform The affine transform that the function unapplies to the point.
 @returns The transformed point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DUnapplyAffineTransform(SPPoint3D point,
                                          SPAffineTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/*!
 @abstract Returns a point that's transformed by the inverted projective transform.
 
 @param point The source point.
 @param transform The projective transform that the function unapplies to the point.
 @returns The transformed point.
*/
SPATIAL_INLINE
SPPoint3D SPPoint3DUnapplyProjectiveTransform(SPPoint3D point,
                                              SPProjectiveTransform3D transform)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

/// Returns @p true if both points are equal.
SPATIAL_INLINE
bool SPPoint3DEqualToPoint(SPPoint3D point1, SPPoint3D point2)
__API_AVAILABLE(macos(13.0), ios(16.0), watchos(9.0), tvos(16.0));

// MARK: - Header inline implementations

SPATIAL_SWIFT_NAME(getter:Point3D.vector(self:))
simd_double3 SPPoint3DGetVector(SPPoint3D point) {
    return point.simd;
}

SPATIAL_REFINED_FOR_SWIFT
SPPoint3D SPPoint3DMake(double x, double y, double z) {
    return (SPPoint3D){ .x = x, .y = y, .z = z };
}

SPATIAL_REFINED_FOR_SWIFT
SPPoint3D SPPoint3DMakeWithVector(simd_double3 xyz) {
    return (SPPoint3D){ .simd = xyz};
}

SPATIAL_REFINED_FOR_SWIFT
SPPoint3D SPPoint3DMakeWithSize(SPSize3D size) {
    return (SPPoint3D){ .simd = size.simd};
}

SPATIAL_SWIFT_NAME(Point3D.translated(self:by:))
SPPoint3D SPPoint3DTranslate(SPPoint3D point, SPSize3D offset) {
    
    return (SPPoint3D) { .simd = point.simd + offset.simd};
}

SPATIAL_SWIFT_NAME(Point3D.rotation(self:to:))
SPRotation3D SPPoint3DRotationToPoint(SPPoint3D point, SPPoint3D other) {
    
    simd_quatd quaternion = simd_quaternion(point.simd, other.simd);

    simd_double3 axis = simd_axis(quaternion);
    
    return (SPRotation3D) {
        (SPRotationAxis3D){ .simd = axis },
        (SPAngle){ simd_angle(quaternion) }
    };
}

SPATIAL_SWIFT_NAME(getter:Point3D.origin(self:))
SPPoint3D SPPoint3DGetOrigin(SPPoint3D point) {
    return point;
}

SPATIAL_SWIFT_NAME(Point3D.distance(self:to:))
double SPPoint3DDistanceToPoint(SPPoint3D point, SPPoint3D other) {
    return simd_distance(point.simd, other.simd);
}

SPATIAL_SWIFT_NAME(Point3D.unapplying(self:_:))
SPPoint3D SPPoint3DUnapplyAffineTransform(SPPoint3D point, SPAffineTransform3D transform) {
    SPAffineTransform3D invertedTransform = SPAffineTransform3DInverted(transform);
    
    return SPPoint3DApplyAffineTransform(point, invertedTransform);
}

SPATIAL_SWIFT_NAME(Point3D.unapplying(self:_:))
SPPoint3D SPPoint3DUnapplyProjectiveTransform(SPPoint3D point, SPProjectiveTransform3D transform) {
    SPProjectiveTransform3D invertedTransform = SPProjectiveTransform3DInverted(transform);
    
    return SPPoint3DApplyProjectiveTransform(point, invertedTransform);
}

SPATIAL_SWIFT_NAME(Point3D.applying(self:_:))
SPPoint3D SPPoint3DApplyAffineTransform(SPPoint3D point, SPAffineTransform3D transform) {
 
    simd_double4 rhs = simd_make_double4(point.simd, 1);
    
    simd_double3 transformed = simd_mul(transform.matrix, rhs).xyz;
    
    return (SPPoint3D){ .simd = transformed };
}

SPATIAL_SWIFT_NAME(Point3D.applying(self:_:))
SPPoint3D SPPoint3DApplyProjectiveTransform(SPPoint3D point, SPProjectiveTransform3D transform) {

    simd_double4 rhs = simd_make_double4(point.simd, 1);
    
    simd_double3 transformed = simd_mul(transform.matrix, rhs).xyz;
    
    return (SPPoint3D){ .simd = transformed };
}

SPATIAL_REFINED_FOR_SWIFT
bool SPPoint3DEqualToPoint(SPPoint3D point1, SPPoint3D point2) {
    return simd_equal(point1.simd, point2.simd);
}

#endif /* Spatial_SPPoint3D_h */
