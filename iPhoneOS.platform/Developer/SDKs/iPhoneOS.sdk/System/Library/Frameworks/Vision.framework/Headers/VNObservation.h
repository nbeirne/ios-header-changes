//
//  VNObservation.h
//  Vision
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <CoreML/CoreML.h>
#import <CoreMedia/CoreMedia.h>
#import <simd/simd.h>

#import <Vision/VNTypes.h>
#import <Vision/VNGeometry.h>
#import <Vision/VNDetectedPoint.h>
#import <Vision/VNRequestRevisionProviding.h>

/*!
 @header VNObservation VNObservations describe the results of performing a VNRequest. The type of request determines the type of observations.
 */


NS_ASSUME_NONNULL_BEGIN


@class CIBarcodeDescriptor;
@class MLFeatureValue;
@class VNFaceLandmarks2D;
@class VNPixelBufferObservation;
@class VNImageRequestHandler;
@class VNRecognizedPoint3D;
@class VNHumanBodyRecognizedPoint3D;


/*!
 @class VNObservation
 @brief VNObservation describes the results of performing a VNRequest. The result has a confidence score. The different types of requests will create different subclasses of VNObservation to return their results in properties of those subclasses.
 
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNObservation : NSObject < NSCopying, NSSecureCoding, VNRequestRevisionProviding >

/*!
   @brief The unique identifier assigned to an observation.
 */
@property (readonly, nonatomic, strong) NSUUID *uuid;

/*!
 * @brief The level of confidence normalized to [0, 1] where 1 is most confident. The only exception is results coming from VNCoreMLRequest, where confidence values are forwarded as is from relevant CoreML models
 * @discussion Confidence can always be returned as 1.0 if confidence is not supported or has no meaning
 */
@property (readonly, nonatomic, assign) VNConfidence confidence;

/*!
 * @brief The duration of the observation reporting when first detected and how long it is valid.
 * @discussion The duration of the observation when used with a sequence of buffers. If a request does not support a timeRange or the timeRange is not known, the start time and duration will be set to 0.
 */
@property (readonly, nonatomic, assign) CMTimeRange timeRange API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));

@end


/*!
    @class VNDetectedObjectObservation
    @superclass VNObservation
    @brief VNDetectedObjectObservation is VNObservation in an image that has a location and/or dimension. Further attributes depend on the specific detected object.
    @discussion All result objects (faces, scene objects, shapes etc) must extend from this class.
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNDetectedObjectObservation : VNObservation

/*!
 @brief create a new VNDetectedObjectObservation with a normalized bounding box and a confidence of 1.0.
 */
+ (instancetype)observationWithBoundingBox:(CGRect)boundingBox;

+ (instancetype)observationWithRequestRevision:(NSUInteger)requestRevision boundingBox:(CGRect)boundingBox API_AVAILABLE(macos(10.14), ios(12.0), tvos(12.0));

/*!
    @brief The bounding box of the detected object. The coordinates are normalized to the dimensions of the processed image, with the origin at the image's lower-left corner.
 */
@property (readonly, nonatomic, assign) CGRect boundingBox;

/*!
 @brief The resulting CVPixelBuffer from requests that generate a segmentation mask for the entire image.
 */
@property (readonly, nonatomic, nullable) VNPixelBufferObservation * globalSegmentationMask API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));

@end


/*!
 @class VNFaceObservation
 @superclass VNDetectedObjectObservation
 @brief VNFaceObservation is the result of a face detection request or derivatives like a face landmark request.
 @discussion The properties filled in this obervation depend on the request being performed. For instance, if just a VNDetectFaceRectanglesRequest was performed the landmarks will not be populated. VNFaceObservation are also used as inputs to other request as defined by the VNFaceObservationAccepting protocol. An example would be the VNDetectFaceLandmarksRequest. This can be helpful for instance if the face rectangles in an image are not derived from a VNDetectFaceRectanglesRequest but instead come from other sources like EXIF or other face detectors. In that case the client of the API creates a VNFaceObservation with the boundingBox (in normalized coordinates) that were based on those detected faces.
 
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNFaceObservation: VNDetectedObjectObservation

/*!
 @brief Create a new VNFaceObservation with a normalized bounding box, roll and yaw.
 @param requestRevision The revision of the VNDetectFaceRectanglesRequest that provided the bounding box.  If this observation is being created with data that did not originate from a Vision request, this parameter should be VNRequestRevisionUnspecified.
 @param roll The roll angle of the face, reported in radians.  A positive angle corresponds to counterclockwise direction, range [-Pi, Pi). If no roll information is available, this parameter should be nil.
 @param yaw The yaw angle of the face, reported in radians.  A positive angle corresponds to counterclockwise direction, range [-Pi/2, Pi/2). If no yaw information is available, this parameter should be nil.
 @param pitch The pitch angle of the face, reported in radians.  A positive angle corresponds to nodding head down direction, range [-Pi/2, Pi/2]. If no pitch information is available, this parameter should be nil.
 */
+ (instancetype)faceObservationWithRequestRevision:(NSUInteger)requestRevision boundingBox:(CGRect)boundingBox roll:(nullable NSNumber *)roll yaw:(nullable NSNumber *)yaw API_DEPRECATED_WITH_REPLACEMENT("-faceObservationWithRequestRevision:boundingBox:roll:yaw:", macos(10.14, 12.0), ios(12.0, 15.0), tvos(12.0, 15.0));
+ (instancetype)faceObservationWithRequestRevision:(NSUInteger)requestRevision boundingBox:(CGRect)boundingBox roll:(nullable NSNumber *)roll yaw:(nullable NSNumber *)yaw pitch:(nullable NSNumber *)pitch API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));
/*!
 @brief The face landmarks populated by the VNDetectFaceLandmarksRequest. This is set to nil if only a VNDetectFaceRectanglesRequest was performed.
 */
@property (readonly, nonatomic, strong, nullable)  VNFaceLandmarks2D *landmarks;

/*!
 @brief The capture quality of the face as a normalized value between 0.0 and 1.0 that can be used to compare the quality of the face in terms of it capture attributes (lighting, blur, position). This score can be used to compare the capture quality of a face against other captures of the same face in a given set.
 */
@property (readonly, nonatomic, strong, nullable) NSNumber *faceCaptureQuality API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0));

/*!
 @brief Face roll angle populated by VNDetectFaceRectanglesRequest. The roll is reported in radians, positive angle corresponds to counterclockwise direction, range [-Pi, Pi). nil value indicates that the roll angle hasn't been computed
 */
@property (readonly, nonatomic, strong, nullable) NSNumber *roll API_AVAILABLE(macos(10.14), ios(12.0), tvos(12.0));

/*!
 @brief Face yaw angle populated by VNDetectFaceRectanglesRequest. The yaw is reported in radians, positive angle corresponds to counterclockwise direction, range [-Pi/2, Pi/2]. nil value indicates that the yaw angle hasn't been computed
 */
@property (readonly, nonatomic, strong, nullable) NSNumber *yaw API_AVAILABLE(macos(10.14), ios(12.0), tvos(12.0));

/*!
 @brief Face pitch angle populated by VNDetectFaceRectanglesRequest. The pitch is reported in radians, positive angle corresponds to nodding head down direction, range [-Pi/2, Pi/2]. nil value indicates that the pitch angle hasn't been computed
 */
@property (readonly, nonatomic, strong, nullable) NSNumber *pitch API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));


@end

/*!
 @class VNClassificationObservation
 @superclass VNObservation
 @brief VNClassificationObservation returns the classifcation in form of a string.
 @discussion VNClassificationObservation is the observation returned by VNCoreMLRequests that using a model that is a classifier. A classifier produces an arrary (this can be a single entry) of classifications which are labels (identifiers) and confidence scores.
 
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNClassificationObservation : VNObservation

/*!
 @brief The is the label or identifier of a classification request. An example classification could be a string like 'cat' or 'hotdog'. The string is defined in the model that was used for the classification. Usually these are technical labels that are not localized and not meant to be used directly to be presented to an end user in the UI.
 */
@property (readonly, nonatomic, copy) NSString *identifier;

@end


/*!
 @discussion VNClassificationObservation mave have precision/recall curves which can be used to decide on an "optimal" operation point.
             Precision is a value in the range of [0..1] which represents the fraction of relevant instances among the retrieved instances.
             Recall is a value in the range of [0..1] which represents the fraction of relevant instances that have been retrieved over the total amount of relevant instances.
*/
API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0))
@interface VNClassificationObservation (PrecisionRecallAdditions)

/*!
	@brief	Determine whether or not precision/recall curves are available with the observation.
	@discussion	If this property is YES, then all other precision/recall related methods in this addition can be called.
*/
@property (readonly, nonatomic, assign) BOOL hasPrecisionRecallCurve;

/*!
	@brief	Determine whether or not the observation's operation point for a specific precision has a minimum recall value.
 
	@param minimumRecall	The minimum recall desired for an operation point.
 
	@param precision		The precision value used to select the operation point.
 
	@return YES if the recall value for the operation point specified by a precision value has the minimum value; otherwise, NO.
*/
- (BOOL) hasMinimumRecall:(float)minimumRecall forPrecision:(float)precision;

/*!
	@brief	Determine whether or not the observation's operation point for a specific recall has a minimum precision value.

	@param minimumPrecision	The minimum precision desired for an operation point.
 
	@param recall		The recall value used to select the operation point.
 
	@return YES if the precision value for the operation point specified by a recall value has the minimum value; otherwise, NO.
*/
- (BOOL) hasMinimumPrecision:(float)minimumPrecision forRecall:(float)recall;

@end



/*!
 @class VNRecognizedObjectObservation
 @superclass VNDetectedObjectObservation
 @brief VNRecognizedObjectObservation is a VNDetectedObjectObservation with an array of classifications that classify the recognized object. The confidence of the classifications sum up to 1.0. It is common practice to multiply the classification confidence with the confidence of this observation.
 */
API_AVAILABLE(macos(10.14), ios(12.0), tvos(12.0))
@interface VNRecognizedObjectObservation : VNDetectedObjectObservation

@property (readonly, nonatomic, copy) NSArray<VNClassificationObservation *> *labels;

@end

/*!
 @class VNCoreMLFeatureValueObservation
 @superclass VNObservation
 @brief VNCoreMLFeatureValueObservation returns the prediction of a model as an MLFeatureValue.
 @discussion This is the returned observations for models that are not classifiers and that do not return an image as a prediction. The confidence for these observations is always 1.0.
 
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNCoreMLFeatureValueObservation : VNObservation

/*!
 @brief The result VNCoreMLRequest where the model produces an MLFeatureValue that is neither a classification or image. Refer to the Core ML documentation and the model itself for the handling of the content of the featureValue.
 
 */
@property (readonly, nonatomic, copy) MLFeatureValue *featureValue;

/*!
 @brief The name used in the model description of the CoreML model that produced this observation allowing to correlate the observation back to the output of the model.
 
 */
@property (readonly, nonatomic, copy) NSString *featureName API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0));

@end

/*!
 @class VNPixelBufferObservation
 @superclass VNObservation
 @brief VNPixelBufferObservation returns the prediction of a model as a CVPixelBufferRef.
 @discussion This is the returned observations for models that are not classifiers and return an image as a prediction. The confidence for these observations is always 1.0.
 
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNPixelBufferObservation : VNObservation

/*!
 @brief The resulting image from a request like VNCoreMLRequest where the model produces an image as an output.
 
 */
@property (readonly, nonatomic) CVPixelBufferRef pixelBuffer CF_RETURNS_NOT_RETAINED;

/*!
 @brief The name used in the model description of the CoreML model that produced this observation allowing to correlate the observation back to the output of the model. This can be nil if the observation is not the result of a VNCoreMLRequest operation.
 
 */
@property (readonly, nonatomic, copy, nullable) NSString *featureName API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0));

@end


/*!
 @class VNRectangleObservation
 @superclass VNDetectedObjectObservation
 @brief VNRectangleObservation is the result of a rectangle detector
 @discussion The VNRectangleObservation has a bounding box that encompasses the rectangle found in the image. The rectangle itself is defined by the four corner point properties. The rectangle can be rotated in or even out of plane. A common use case is to use the CIPerspectiveTransform filter to correct a detected rectangle to its 'flat upright' representation. All coordinates are normalized and the coordinates can be outside the image.

 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNRectangleObservation : VNDetectedObjectObservation

/*!
	@brief Create a synthesized `VNRectangleObservation`.
	@note The clockwise parameter ordered `+[VNRectangleObservation rectangleObservationWithRequestRevision:topLeft:topRight:bottomRight:bottomLeft:]` is the preferred initializer.
	
	@param requestRevision The revision of the VNDetectRectanglesRequest that the observation is to be treated as originating from.
	@param topLeft The top-left corner of the rectangle in normalized coordinate space.
	@param bottomLeft The bottom-left corner of the rectangle in normalized coordinate space.
	@param bottomRight The bottom-right corner of the rectangle in normalized coordinate space.
	@param topRight The top-right corner of the rectangle in normalized coordinate space.
*/
+ (instancetype) rectangleObservationWithRequestRevision:(NSUInteger)requestRevision
												 topLeft:(CGPoint)topLeft
											  bottomLeft:(CGPoint)bottomLeft
											 bottomRight:(CGPoint)bottomRight
												topRight:(CGPoint)topRight API_DEPRECATED_WITH_REPLACEMENT("rectangleObservationWithRequestRevision:topLeft:topRight:bottomRight:bottomLeft:", macos(10.15, 14.0), ios(13.0, 17.0), tvos(13.0, 17.0));

/*!
	@brief Create a synthesized `VNRectangleObservation`.
	
	@param requestRevision The revision of the VNDetectRectanglesRequest that the observation is to be treated as originating from.
	@param topLeft The top-left corner of the rectangle in normalized coordinate space.
	@param topRight The top-right corner of the rectangle in normalized coordinate space.
	@param bottomRight The bottom-right corner of the rectangle in normalized coordinate space.
	@param bottomLeft The bottom-left corner of the rectangle in normalized coordinate space.
*/
+ (instancetype) rectangleObservationWithRequestRevision:(NSUInteger)requestRevision
												 topLeft:(CGPoint)topLeft
												topRight:(CGPoint)topRight
											 bottomRight:(CGPoint)bottomRight
											  bottomLeft:(CGPoint)bottomLeft API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));

@property (readonly, nonatomic, assign) CGPoint topLeft;
@property (readonly, nonatomic, assign) CGPoint topRight;
@property (readonly, nonatomic, assign) CGPoint bottomLeft;
@property (readonly, nonatomic, assign) CGPoint bottomRight;

@end


/*!
 @class VNTrajectoryObservation
 @superclass VNObservation
 @brief The VNTrajectoryObservation describes a detected trajectory with the points on the trajectory and the equation describing the trajectory. The observation also reprorts the duration describing when the trajectory was first detected (which will be in the past).
 */
API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0))
@interface VNTrajectoryObservation : VNObservation

/*!
@brief The centroids of the contour being detected along the trajectory.
@details These are the unprocessed centroid points of the detected contour that is tracked on the trajectory. The points may be slightly off the ideal trajectory as these are the measured points that fall within the allowed tolerance. The maximum number or past points is limited by the maximum trajectory length set in the request.
*/
@property (readonly, nonatomic, copy) NSArray<VNPoint *> *detectedPoints;

/*!
@brief The centroids of  the calculated trajectory from the detected points.
@details These are the calculated centroid points along the ideal trajectory described by the parabolic equation. The equation and the projected points of the detected trajectory get refined over time. The maximum number of cached points is limited by the maximum points needed to describe the trajectory together with the parabolic equation.
*/
@property (readonly, nonatomic, copy) NSArray<VNPoint *> *projectedPoints;

/*!
@brief The coefficients of the parabolic equation y = a*x^2 + b*x + c.
@details This equation describes the parabola on which the detected contour is traveling. The equation and the projected points get refined over time of the detected trajectory.
*/
@property (readonly, nonatomic) simd_float3 equationCoefficients;

/*!
@brief The moving average radius of the object being tracked.
@details This is the radius of the object at each detected point (used to determine the trajectory) averaged.
*/
@property (readonly, nonatomic, assign) CGFloat movingAverageRadius API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));


@end


/*!
 @class VNTextObservation
 @superclass VNRectangleObservation
 @brief VNTextObservation Describes a text area detected by the VNRequestNameDetectTextRectangles request.
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNTextObservation : VNRectangleObservation

/*!
	@brief		Array of individual character bounding boxes found within the observation's boundingBox.
	@discussion	If the associated request indicated that it is interested in character boxes by setting the VNDetectTextRectanglesRequest reportCharacterBoxes property to @YES, this property will be non-nil (but may still be empty, depending on the detection results).
*/
@property (readonly, nonatomic, copy, nullable) NSArray<VNRectangleObservation *> *characterBoxes;

@end

/*!
 @class VNRecognizedText
 @brief VNRecognizedText A block of recognized text. There can be multiple VNRecognizedText objects returned in a VNRecognizedTextObservation - one for each candidate.
 */
API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0))
@interface VNRecognizedText : NSObject < NSCopying, NSSecureCoding, VNRequestRevisionProviding>

/*!
 @brief        Field that contains recognized text.
 @discussion   This is the top candidate of the recognized text.
 */
@property (readonly, nonatomic, copy) NSString *string;

/*!
 * @brief The level of confidence normalized to [0.0, 1.0] where 1.0 is most confident
 */
@property (readonly, nonatomic, assign) VNConfidence confidence;

/*!
 * @brief Calculate the bounding box around the characters in the range of the string.
 * @discussion The bounding boxes are not guaranteed to be an exact fit around the characters and are purely meant for UI purposes and not for image processing.
 */
- (nullable VNRectangleObservation *)boundingBoxForRange:(NSRange)range error:(NSError**)error;

@end

/*!
 @class VNRecognizedTextObservation
 @superclass VNRectangleObservation
 @brief VNRecognizedTextObservation Describes a text area detected and recognized by the VNRecognizeTextRequest request.
 */
API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0))
@interface VNRecognizedTextObservation : VNRectangleObservation


/*!
 * @brief Returns the top N candidates sorted by decreasing confidence score
 * @discussion This will return no more than N but can be less than N candidates. The maximum number of candidates returned cannot exceed 10 candidates.
 */
- (NSArray<VNRecognizedText*>*) topCandidates:(NSUInteger)maxCandidateCount;


@end


/*!
 @class VNBarcodeObservation
 @superclass VNRectangleObservation
 @brief VNBarcodeObservation Describes an area containing a barcode detected by the VNRequestNameDetectBarcodes request.
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNBarcodeObservation : VNRectangleObservation

/*!
	@brief The symbology of the detected barcode.
*/
@property (readonly, nonatomic, copy) VNBarcodeSymbology symbology;


/*!
	@brief An object that provides symbology-specific data for the barcode.
*/
@property (readonly, nonatomic, strong, nullable) CIBarcodeDescriptor* barcodeDescriptor;


/*!
	@brief The string representation of the barcode's payload.  Depending on the symbology of the barcode and/or the payload data itself, a string representation of the payload may not be available.
*/
@property (readonly, nonatomic, copy, nullable) NSString* payloadStringValue;


/*!
    @brief The raw data representation of the barcode's payload if available.
 */
@property (readonly, nonatomic, copy, nullable) NSData* payloadData API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));


/*!
    @brief Boolean indicating if the barcode carries any GS1 application specific data
 */
@property (readonly, nonatomic) BOOL isGS1DataCarrier API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));


/*!
    @brief A boolean indicating if the barcode is color inverted
 */
@property (readonly, nonatomic) BOOL isColorInverted API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));


/*!
    @brief Represents the supplemental composite type. Currently, this can only refer to the composite flag of the 2D symbology as part of a GS1 composite symbology.
 This attribute only exists when the primary descriptor is the 1D symbology of a GS1 composite symbology, and of which a valid 2D counterpart has been coalesced into.
 */
@property (readonly, nonatomic) VNBarcodeCompositeType supplementalCompositeType API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));


/*!
    @brief Decode the supplemental code in the descriptor as a string value. Note: this property might be expensive the first time it is accessed
 When non-NULL, and if the descriptor has supplemental raw payload data, the pointee will be set to the decoded supplemental payload string value.
 */
@property (readonly, nonatomic, copy, nullable) NSString* supplementalPayloadString API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));


/*!
    @brief Decode the supplemental code in the descriptor as a string value. Note: this property might be expensive the first time it is accessed
 When non-NULL, and if the descriptor has supplemental raw payload data, the pointee will be set to the decoded supplemental payload raw data value.
 */
@property (readonly, nonatomic, copy, nullable) NSData* supplementalPayloadData API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0));


@end



/*!
 @class VNHorizonObservation
 @superclass VNObservation
 @brief VNHorizonObservation is the result of a VNDetectHorizonRequest
 @discussion Use the transform or angle to upright the image and make the detected horizon level.
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNHorizonObservation : VNObservation

/*!
 @brief Transform applied to the detected horizon in image coordinates.
 @discussion This is the transform in image coordinates and not a normalized transform.
 */
@property (readonly, nonatomic, assign) CGAffineTransform transform;

/*!
 @brief Angle of the observed horizon.
 */
@property (readonly, nonatomic, assign) CGFloat angle;

/*!
 @brief Creates a transform for the specified width and height.
 */
- (CGAffineTransform) transformForImageWidth:(size_t)width height:(size_t)height API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0));

@end



/*!
 @class VNImageAlignmentObservation
 @superclass VNObservation
 @brief VNImageAlignmentObservation is generated from an image registration. This is an abstract base class. The type of registration request used defines which subclass describes the result.
 */
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNImageAlignmentObservation : VNObservation
@end


/*!
 @class VNImageTranslationAlignmentObservation
 @superclass VNImageAlignmentObservation
 @brief An observation describing the results of performing a translational image alignment.
*/
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNImageTranslationAlignmentObservation : VNImageAlignmentObservation

@property (readonly, nonatomic, assign) CGAffineTransform alignmentTransform;

@end


/*!
 @class VNImageHomographicAlignmentObservation
 @superclass VNImageAlignmentObservation
 @brief An observation describing the results of performing a homographic image alignment.
*/
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
@interface VNImageHomographicAlignmentObservation : VNImageAlignmentObservation

@property (readonly, nonatomic, assign) matrix_float3x3 warpTransform;

@end

/*!
 @class VNSaliencyImageObservation
 @superclass VNPixelBufferObservation
 @brief VNSaliencyImageObservation provides a grayscale "heat" map of important areas of an image.
 @discussion In the revision1, the "heat" map is a OneComponent32Float pixel format CVPixelBuffer.
 
 */
API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0))
@interface VNSaliencyImageObservation : VNPixelBufferObservation

/*!
 @brief An array of bounds of salient objects within the image. Each box represents a distinct mode of the heat map.
*/
@property (readonly, nonatomic, nullable) NSArray<VNRectangleObservation*>* salientObjects;

@end


/*!
*/
API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0))
@interface VNFeaturePrintObservation : VNObservation

/*!
	@brief The type of each element in the data.
*/
@property (readonly, atomic, assign) VNElementType elementType;

/*!
	@brief The total number of elements in the data.
*/
@property (readonly, atomic, assign) NSUInteger elementCount;

/*!
	@brief The feature print data.
*/
@property (readonly, atomic, strong) NSData* data;

/*!
 @brief Computes the distance between two observations.
 @discussion The larger the distance the more dissimlar the feature prints are. In case of an error this method returns false with an error describing the error condition, for instance comparing two non-comparable feature prints.
 */
- (BOOL)computeDistance:(float *)outDistance toFeaturePrintObservation:(VNFeaturePrintObservation *)featurePrint error:(NSError **)error;

@end


#pragma mark - VNContoursObservation

@class VNContour;

/*
 * @brief An observation that provides all of the detected contours in an image.
 * @discussion Contours can be referenced as a flattened array or as a tree of enclosing parent contours to enclosed child contours.
 *
 *      ┌ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─
 *                         ┌───────────────────┐   │
 *      │        Λ         │       ┌─────────┐ │
 *              ╱ ╲        │       │         │ │   │
 *      │      ╱   ╲       │       │         │ │
 *            ╱     ╲      │       │ C       │ │   │
 *      │    ▕   A   ▏     │       └─────────┘ │
 *            ╲     ╱      │                   │   │
 *      │      ╲   ╱       │ B                 │
 *              ╲ ╱        └───────────────────┘   │
 *      │        V
 *                                                 │
 *      └ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─
 *
 *	        Contour A index 0, index path [0].
 *	        Contour B index 1, index path [1].
 *	        Contour C index 2, index path [1, 0].
 */
API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0))
@interface VNContoursObservation : VNObservation

/*!
 @brief The total number of contours detected.
 */
@property (readonly) NSInteger contourCount;

/*!
 @brief Returns the VNContour object at the specified index, irrespective of hierarchy.
 @param contourIndex The index of the contour to request. Valid values are in the range [0..contourCount-1].
 @param error The error returned if the index path is out of range.
 @return The detected VNContour at the specified index without regard to hierarchy.
 */
- (nullable VNContour *) contourAtIndex:(NSInteger)contourIndex error:(NSError **)error;

/*!
 @brief The total number of top-level contours detected.
 */
@property (readonly) NSInteger topLevelContourCount;

/*!
 @brief An array of the top level contours (i.e. contours that are not enclosed inside another contour),.
 @details This array constitutes the top of the contour hierarchy. Each contour object can be further iterated to determine its children.
 @see VNContour for more information.
 */
@property (readonly) NSArray<VNContour *> * topLevelContours;

/*!
 @brief Returns the VNContour object at the specified index path.
 @details Use the indexPath property from a VNContour instance to pass to this method.
 @param indexPath The index path is the heirarchical path to the contour.
 @param error The error returned if the index path is out of range.
 @return The VNContour object at the specified index path.
*/
- (nullable VNContour *) contourAtIndexPath:(NSIndexPath *)indexPath error:(NSError **)error;

/*!
 @brief Obtain all of the contours represented as a CGPath in normalized coordinates.
 @details The path is owned by the observation and therefore will be alive as long as the the observation is alive.
 */
@property (readonly) CGPathRef normalizedPath CF_RETURNS_NOT_RETAINED;

@end


#pragma mark ---- VNRecognizedPointsObservation ----


VN_EXPORT VNRecognizedPointGroupKey const VNRecognizedPointGroupKeyAll API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));


/*!
 @class VNRecognizedPointsObservation
 @superclass VNObservation
 @brief VNRecognizedPointsObservation is a request result detailing points in an image.
 */
API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0))
@interface VNRecognizedPointsObservation : VNObservation

+ (instancetype) new NS_UNAVAILABLE;
- (instancetype) init NS_UNAVAILABLE;


/*!
 @brief Returns all of the point group keys available in the observation.
 */
@property (readonly, copy) NSArray<VNRecognizedPointKey>* availableKeys;


/*!
 @brief The availableGroupKeys property returns all of the point group labels usable with the observation.
 */
@property (readonly, copy) NSArray<VNRecognizedPointGroupKey>* availableGroupKeys;

/*!
 @brief Obtains a specific normalized recognized point.
 
 @param pointKey The key specifying the desired recognized point.
 
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 
 @return the recognized point, or nil if the specific point is not defined.
*/
- (nullable VNRecognizedPoint*) recognizedPointForKey:(VNRecognizedPointKey)pointKey error:(NSError**)error;

/*!
 @brief Obtains the collection of points associated with an identified grouping.
 
 @discussion The obtained collection is a dictionary that provides the mapping of a recognized point's key to the recognized point.
 
 @param groupKey The key representing a specific grouping of points.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 @return the dictionary of recognized points in the group, or nil if an error was encountered.
*/
- (nullable NSDictionary<VNRecognizedPointKey, VNRecognizedPoint*>*) recognizedPointsForGroupKey:(VNRecognizedPointGroupKey)groupKey error:(NSError**)error;

/*!
 @brief    Returns the recognized points packaged into an MLMultiArray.
 
 @discussion The MLMultiArray will contain the raw data output of (x coordinate, y coordinate, confidence) for specific points in the format expected by CreateML action recognition models.
 The datatype of the elements in the array is double and the dimensions are [1, 3, # of possible points].  If an expected point key is not available in the obeservation, that entry in the MLMultiArray will be populated with 0s.

 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.

 @return the MLMultiArray representation of the points, or nil if an error was encountered.
*/
- (nullable MLMultiArray*) keypointsMultiArrayAndReturnError:(NSError**)error;

@end


/*!
 @class VNHumanObservation
 @superclass VNDetectedObjectObservation
 @brief VNHumanObservation is the result of a Human rectangles detection request
  */
API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0))
@interface VNHumanObservation : VNDetectedObjectObservation

/*!
 @brief Boolean property to specify whether the human upper body or full body detection is recorded in the observation. This setting is propagated from [VNDetectHumanRectanglesRequest -upperBodyOnly]
 */
@property(readonly, nonatomic) BOOL upperBodyOnly API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));

@end


#pragma mark ---- VNInstanceMaskObservation ----


/*!
    @brief An observation resulting from an instance mask generation request. It contains an instance mask that labels instances in the mask that labels per pixel an instance.
*/
API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0))
@interface VNInstanceMaskObservation : VNObservation

/*!
 *@brief The resulting mask represents all instances in a mask image where 0 represents the background and all other values represent the indices of the instances identified.
 Note that a pixel can only correspond to one instance and not multiple instances.
 */
@property (readonly, nonatomic) CVPixelBufferRef instanceMask CF_RETURNS_NOT_RETAINED;


/*!
 *@brief *The IndexSet that encompases all instances except the background
 */
@property (readonly, copy) NSIndexSet* allInstances;

/*!
 @brief The low res mask from the selected instances in the resolution of the performed analysis which is not upscaled to the image resolution.
 @param instances An NSIndexSet of selected instances where 0 is the background. An empty set selects all instances but the background
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 The pixel format of kCVPixelFormatType_OneComponent32Float
 */
- (nullable CVPixelBufferRef) generateMaskForInstances:(NSIndexSet*)instances error:(NSError**)error CF_RETURNS_RETAINED ;


/*!
 *@brief High res image with everything but the selected instances removed to transparent black.
 @param instances An NSIndexSet of selected instances where 0 is the background.
 @param croppedToInstancesExtent Crops the image to the smallest rectangle containg all instances with remaining alpha elements.
 Setting this value to NO does not perform any cropping.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 */
- (nullable CVPixelBufferRef) generateMaskedImageOfInstances:(NSIndexSet*)instances fromRequestHandler:(VNImageRequestHandler*)requestHandler croppedToInstancesExtent:(BOOL)cropResult error:(NSError**)error CF_RETURNS_RETAINED;


/*!
 *@brief High res mask with the selected instances preserved while everything else is removed to transparent black.
 @param forInstances An NSIndexSet of selected instances where 0 is the background.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 */
- (nullable CVPixelBufferRef) generateScaledMaskForImageForInstances:(NSIndexSet*)instances fromRequestHandler:(VNImageRequestHandler*)requestHandler error:(NSError**)error CF_RETURNS_RETAINED;

@end


API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0))
@interface VNAnimalBodyPoseObservation : VNRecognizedPointsObservation

/*!
 @brief All animal joint names available in the observation.
 */
@property (readonly, copy) NSArray<VNAnimalBodyPoseObservationJointName>* availableJointNames;


/*!
 @brief All animal joints group names available in the observation.
 */
@property (readonly, copy) NSArray<VNAnimalBodyPoseObservationJointsGroupName>* availableJointGroupNames;


/*!
 @brief Obtain a specific normalized point for a named animal body joint.
 
 @param jointName The name of the animal body joint.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 @return the recognized point, or nil if the point could not be obtained.
*/
- (nullable VNRecognizedPoint*) recognizedPointForJointName:(VNAnimalBodyPoseObservationJointName)jointName
                                                      error:(NSError**)error NS_SWIFT_NAME(recognizedPoint(_:));

/*!
 @brief Obtains the collection of points associated with a named animal body joints group.
 
 @discussion The obtained collection is a dictionary that provides the mapping of animal join names to the recognized point.
 
 @param jointsGroupName The name of the animal body joints group.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 @return a dictionary of recognized points in the group, or nil if an error was encountered.
*/
- (nullable NSDictionary<VNAnimalBodyPoseObservationJointName, VNRecognizedPoint*>*) recognizedPointsForJointsGroupName:(VNAnimalBodyPoseObservationJointsGroupName)jointsGroupName
                                                                                                                  error:(NSError**)error NS_SWIFT_NAME(recognizedPoints(_:));

@end

#pragma mark ---- VNRecognizedPoints3DObservation ----

VN_EXPORT VNRecognizedPointGroupKey const VNRecognizedPoint3DGroupKeyAll API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));
/*!
 @class VNRecognizedPoints3D
 Observation
 @superclass VNObservation
 @brief VNRecognizedPointsObservation is a request result detailing points in an image.
 */
API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0))
@interface VNRecognizedPoints3DObservation : VNObservation

+ (instancetype) new NS_UNAVAILABLE;
- (instancetype) init NS_UNAVAILABLE;

/*!
 @brief Returns all of the point group keys available in the observation.
 */
@property (readonly, copy) NSArray<VNRecognizedPointKey>* availableKeys;


/*!
 @brief The availableGroupKeys property returns all of the point group labels usable with the observation.
 */
@property (readonly, copy) NSArray<VNRecognizedPointGroupKey>* availableGroupKeys;

/*!
 @brief Obtains a specific normalized recognized point.
 @param pointKey The key specifying the desired recognized point.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 @return the recognized point, or nil if the specific point is not defined.
 */
- (nullable VNRecognizedPoint3D*) recognizedPointForKey:(VNRecognizedPointKey)pointKey error:(NSError**)error;

/*!
 @brief Obtains the collection of points associated with an identified grouping.
 @discussion The obtained collection is a dictionary that provides the mapping of a recognized point's key to the recognized point.
 @param groupKey The key representing a specific grouping of points.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 @return the dictionary of recognized points in the group, or nil if an error was encountered.
 */
- (nullable NSDictionary<VNRecognizedPointKey, VNRecognizedPoint3D*>*) recognizedPointsForGroupKey:(VNRecognizedPointGroupKey)groupKey error:(NSError**)error;

@end

#pragma mark ---- VNHumanBodyPose3DObservation ----

/*!
 @brief     Height estimation technique used in observation based on available metadata
            VNHumanBodyPose3DObservationHeightEstimationReference is the default if no LiDAR depth is present
 @details   reference -   Since no depth was present, a reference height of 1.8 meters is used
            measured -   LiDAR depth was used to measure a more accurate `bodyHeight` in meters
 */
typedef NS_ENUM(NSInteger, VNHumanBodyPose3DObservationHeightEstimation)
{
    VNHumanBodyPose3DObservationHeightEstimationReference = 0,
    VNHumanBodyPose3DObservationHeightEstimationMeasured ,
}  NS_SWIFT_NAME(VNHumanBodyPose3DObservation.HeightEstimation);

API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0))
@interface VNHumanBodyPose3DObservation : VNRecognizedPoints3DObservation

/*!
 @brief Technique used to estimate body height.   `VNHumanBodyPose3DObservationHeightEstimationMeasured`   indicates`bodyHeight` returns measured height in meters more accurate to true world height.
 `VNHumanBodyPose3DObservationHeightEstimationReference` indicates `bodyHeight` returns reference height of 1.8 m
 */
@property(readonly) VNHumanBodyPose3DObservationHeightEstimation heightEstimation;

/*!
 @brief A transform from root (at hip) to Camera as projection center.
 */
@property(nonatomic, readonly) simd_float4x4 cameraOriginMatrix;

/*!
 @brief All of the joints group names available in the observation.
 */
@property (readonly, copy) NSArray<VNHumanBodyPose3DObservationJointsGroupName>* availableJointsGroupNames;

/*!
 @brief All of the joint names available in the observation.
 */
@property (readonly, copy) NSArray<VNHumanBodyPose3DObservationJointName>* availableJointNames;

/*!
 @brief Estimated human height, in meters.
 @note A measured height will be returned in meters if  `heightEstimation` is  `VNHumanBodyPose3DObservationHeightEstimationMeasured`, otherwise reference height of 1.8 meters is returned for `VNHumanBodyPose3DObservationHeightEstimationReference`
 */
@property (nonatomic, readonly) float bodyHeight;

/*!
 @brief Obtains the collection of joints associated with a named human body joints group.
 @discussion The obtained collection is a dictionary that provides the mapping of human joint names to the recognized point.
 @param jointsGroupName The name of the human body joints group.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 @return a dictionary of recognized points in the group, or nil if an error was encountered.
 */
- (nullable NSDictionary<VNHumanBodyPose3DObservationJointName, VNHumanBodyRecognizedPoint3D*>*) recognizedPointsForJointsGroupName:(VNHumanBodyPose3DObservationJointsGroupName)jointsGroupName
                                                                                                            error:(NSError **)error NS_SWIFT_NAME(recognizedPoints(_:));
/*!
 @brief Obtain a specific point for a named human body joint.
    Each returned `VNHumanBodyRecognizedPoint3D` instance contains position relative to the model (`position`) and the parent joint (`localPosition`)
    Model position is relative to root joint (hip) for a named human body joint in meters .
    Local position is relative to parent joint for a named human body joint in meters.
 @param jointName The name of the human body joint.
 @param error The address of a variable that will be populated with the error that describes the failure.  If the caller does not require this information, NULL can be passed.
 @return The recognized point, or nil if the point could not be obtained.
 */

- (nullable VNHumanBodyRecognizedPoint3D*) recognizedPointForJointName:(VNHumanBodyPose3DObservationJointName)jointName
                                                                 error:(NSError**)error NS_SWIFT_NAME(recognizedPoint(_:));

/*!
 @brief Obtain 2D point relative to the input image for named human body joint
 @param jointName The name of the human body joint
 @return A projection of the determined 3D position onto the original 2D image in normalized, lower left origin coordinates
 */
- (nullable VNPoint*) pointInImageForJointName:(VNHumanBodyPose3DObservationJointName)jointName
                                         error:(NSError**)error NS_SWIFT_NAME(pointInImage(_:));

/*!
 @brief Obtain the parent joint of a specified joint
 @param jointName The name of the human body joint
 @return The name of the parent joint
 */
- (nullable VNHumanBodyPose3DObservationJointName) parentJointNameForJointName:(VNHumanBodyPose3DObservationJointName)jointName NS_SWIFT_NAME(parentJointName(_:));

/*!
 @brief Obtain position relative to camera for a named human body joint in meters
 @param modelPositionOut A reference to a simd_float4x4 that will be updated to contain position of a joint relative to the camera if successful
 @param jointName The name of the human body joint
 @return BOOL indicating success of determing position
 */
- (BOOL) getCameraRelativePosition:(simd_float4x4*) modelPositionOut
                        forJointName:(VNHumanBodyPose3DObservationJointName)jointName
                             error:(NSError**)error;

@end

#pragma mark ---- VNImageAestheticsScoresObservation ----

/*!
 @class VNImageAestheticsScoresObservation
 @superclass VNObservation
 @brief VNImageAestheticsScoresObservation provides an overall score of aesthetic attributes for an image.
 */
API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), visionos(2.0))
@interface VNImageAestheticsScoresObservation: VNObservation

-(instancetype) init NS_UNAVAILABLE;

/// A Boolean value that represents images that are not necessarily of poor image quality, but may not have memorable or exciting content.
@property (readonly, nonatomic, assign) BOOL isUtility;

/// A score which incorporates aesthetic score, failure score, and utility labels.
///
/// This returns a value within the range of `-1` and `1`, where `-1` is least desirable and `1` is most desirable.
@property (readonly, nonatomic, assign) float overallScore;

@end

NS_ASSUME_NONNULL_END
