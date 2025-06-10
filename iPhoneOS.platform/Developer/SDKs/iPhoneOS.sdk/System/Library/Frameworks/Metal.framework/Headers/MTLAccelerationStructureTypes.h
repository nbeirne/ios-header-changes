#ifdef __METAL_VERSION__
#import <metal_stdlib>

typedef metal::packed_float3 MTLPackedFloat3;
typedef metal::packed_float4 MTLPackedFloatQuaternion;
#else
#include <math.h>
#include <stdint.h>
#import <Metal/MTLDefines.h>

typedef struct _MTLPackedFloat3 {
    union {
        struct {
            float x;
            float y;
            float z;
        };
        float elements[3];
    };

#ifdef __cplusplus
    _MTLPackedFloat3()
        : x(0.0f), y(0.0f), z(0.0f)
    {
    }

    _MTLPackedFloat3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    float & operator[](int idx) {
        return elements[idx];
    }

    const float & operator[](int idx) const {
        return elements[idx];
    }
#endif
} MTLPackedFloat3;

MTL_INLINE MTLPackedFloat3 MTLPackedFloat3Make(float x, float y, float z)
{
    MTLPackedFloat3 packedFloat3;
    packedFloat3.x = x;
    packedFloat3.y = y;
    packedFloat3.z = z;
    return packedFloat3;
}

typedef struct MTLPackedFloatQuaternion {
    float x;
    float y;
    float z;
    float w;

#ifdef __cplusplus
    MTLPackedFloatQuaternion()
        : x(0.0f), y(0.0f), z(0.0f), w(1.0f)
    {
    }

    MTLPackedFloatQuaternion(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w)
    {
    }

    float & operator[](int idx) {
        float *elements = &x;

        return elements[idx];
    }

    const float & operator[](int idx) const {
        const float *elements = &x;

        return elements[idx];
    }
#endif
} MTLPackedFloatQuaternion;

MTL_INLINE MTLPackedFloatQuaternion MTLPackedFloatQuaternionMake(float x, float y, float z, float w)
{
    MTLPackedFloatQuaternion packedQuaternion;
    packedQuaternion.x = x;
    packedQuaternion.y = y;
    packedQuaternion.z = z;
    packedQuaternion.w = w;
    return packedQuaternion;
}

#endif

typedef struct _MTLPackedFloat4x3 {
    MTLPackedFloat3 columns[4];

#ifdef __cplusplus
    _MTLPackedFloat4x3() {
        columns[0] = MTLPackedFloat3(0.0f, 0.0f, 0.0f);
        columns[1] = MTLPackedFloat3(0.0f, 0.0f, 0.0f);
        columns[2] = MTLPackedFloat3(0.0f, 0.0f, 0.0f);
        columns[3] = MTLPackedFloat3(0.0f, 0.0f, 0.0f);
    }
    
    _MTLPackedFloat4x3(MTLPackedFloat3 column0, MTLPackedFloat3 column1, MTLPackedFloat3 column2, MTLPackedFloat3 column3) {
        columns[0] = column0;
        columns[1] = column1;
        columns[2] = column2;
        columns[3] = column3;
    }
    
#ifndef __METAL_VERSION__
    MTLPackedFloat3 & operator[](int idx) {
        return columns[idx];
    }

    const MTLPackedFloat3 & operator[](int idx) const {
        return columns[idx];
    }
#else
    thread MTLPackedFloat3 & operator[](int idx) thread {
        return columns[idx];
    }

    const thread MTLPackedFloat3 & operator[](int idx) const thread {
        return columns[idx];
    }

    device MTLPackedFloat3 & operator[](int idx) device {
        return columns[idx];
    }

    const device MTLPackedFloat3 & operator[](int idx) const device {
        return columns[idx];
    }

    const constant MTLPackedFloat3 & operator[](int idx) const constant {
        return columns[idx];
    }
#endif
#endif
} MTLPackedFloat4x3;

/**
 * @brief An axis aligned bounding box with a min and max point
 */
typedef struct _MTLAxisAlignedBoundingBox {
    /**
     * @brief Minimum point
     */
    MTLPackedFloat3 min;

    /**
     * @brief Maximum point
     */
    MTLPackedFloat3 max;

#ifdef __cplusplus
    _MTLAxisAlignedBoundingBox()
        : min(INFINITY, INFINITY, INFINITY),
          max(-INFINITY, -INFINITY, -INFINITY)
    {
    }
    
#ifdef __METAL_VERSION__
    _MTLAxisAlignedBoundingBox() threadgroup = default;
#endif
    

    _MTLAxisAlignedBoundingBox(MTLPackedFloat3 p)
        : min(p),
          max(p)
    {
    }

    _MTLAxisAlignedBoundingBox(MTLPackedFloat3 min, MTLPackedFloat3 max)
        : min(min),
          max(max)
    {
    }
#endif
} MTLAxisAlignedBoundingBox;

/**
 * @brief A transformation represented by individual components such as translation and
 * rotation. The rotation is represented by a quaternion, allowing for correct motion
 * interpolation.
 */
typedef struct {
    /**
     * @brief The scale of the instance applied before rotation alongside shear and pivot
     */
    MTLPackedFloat3 scale;
    
    /**
     * @brief The shear of the instance applied before rotation alongside scale and pivot
     */
    MTLPackedFloat3 shear;
    
    /**
     * @brief Translation applied before rotation alongside scale and shear. Allows
     * rotation to pivot around a point.
     */
    MTLPackedFloat3 pivot;
    
    /**
     * @brief The rotation of the instance as a normalized quaternion. Applied after scale,
     * shear, and pivot and before translation
     */
    MTLPackedFloatQuaternion rotation;

    /**
     * @brief The translation of the instance. Applied after rotation. Typically contains
     * the composition of object translation and the inverse of the pivot translation.
     */
    MTLPackedFloat3 translation;
} MTLComponentTransform;

/**
 * @brief A struct representing a range of a Metal buffer. The offset into the buffer is included in the address.
 * The length is generally optional, which a value of (uint64_t)-1 representing the range from the given address to
 * the end of the buffer. However, providing the length can enable more accurate API validation, especially when
 * sub-allocating ranges of a buffer.
 */
typedef struct MTL4BufferRange {
    /**
     * @brief Buffer address returned by the gpuAddress property of an MTLBuffer plus any offset into the buffer
     */
    uint64_t bufferAddress;

    /**
     * @brief Length of the region which begins at the given address. If the length is not known, a value of
     * (uint64_t)-1 represents the range from the given address to the end of the buffer.
     */
    uint64_t length;

#ifdef __cplusplus
    MTL4BufferRange()
        : bufferAddress(0),
          length(0)
    {
    }

    MTL4BufferRange(uint64_t bufferAddress)
        : bufferAddress(bufferAddress),
          length((uint64_t)-1)
    {
    }

    MTL4BufferRange(uint64_t bufferAddress, uint64_t length)
        : bufferAddress(bufferAddress),
          length(length)
    {
    }
#endif
} MTL4BufferRange;

#ifndef __METAL_VERSION__
/**
 * @brief Create a buffer range from a buffer's GPU address (given by the gpuAddress property) and length. A length of
 * (uint64_t)-1 represents the the range from the given address to the end of the buffer.
 */
MTL_INLINE MTL4BufferRange MTL4BufferRangeMake(uint64_t bufferAddress, uint64_t length) {
    MTL4BufferRange range;

    range.bufferAddress = bufferAddress;
    range.length = length;
    
    return range;
}
#endif
