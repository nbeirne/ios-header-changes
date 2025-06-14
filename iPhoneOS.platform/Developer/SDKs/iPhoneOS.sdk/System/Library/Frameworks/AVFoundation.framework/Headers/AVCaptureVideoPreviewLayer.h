#if !__has_include(<AVFCapture/AVCaptureVideoPreviewLayer.h>)
/*
    File:  AVCaptureVideoPreviewLayer.h
 
    Framework:  AVFoundation
 
    Copyright 2010-2022 Apple Inc. All rights reserved.
*/

#import <AVFoundation/AVBase.h>

#if __has_include(<QuartzCore/QuartzCore.h>)
#import <QuartzCore/QuartzCore.h>
#import <AVFoundation/AVCaptureSession.h>
#import <AVFoundation/AVAnimation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark AVCaptureVideoPreviewLayer

@class AVMetadataObject;
@class AVCaptureVideoPreviewLayerInternal;

/*!
 @class AVCaptureVideoPreviewLayer
 @abstract
    A CoreAnimation layer subclass for previewing the visual output of an AVCaptureSession.
 
 @discussion
    An AVCaptureVideoPreviewLayer instance is a subclass of CALayer and is therefore suitable for insertion in a layer hierarchy as part of a graphical interface. One creates an AVCaptureVideoPreviewLayer instance with the capture session to be previewed, using +layerWithSession: or -initWithSession:. Using the @"videoGravity" property, one can influence how content is viewed relative to the layer bounds. On some hardware configurations, the orientation of the layer can be manipulated using @"orientation" and @"mirrored".
 */
API_AVAILABLE(macos(10.7), ios(4.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos) API_UNAVAILABLE(watchos)
@interface AVCaptureVideoPreviewLayer : CALayer
{
@private
    AVCaptureVideoPreviewLayerInternal *_internal;
}

/*!
 @method layerWithSession:
 @abstract
    Creates an AVCaptureVideoPreviewLayer for previewing the visual output of the specified AVCaptureSession.
 
 @param session
    The AVCaptureSession instance to be previewed.
 @result
    A newly initialized AVCaptureVideoPreviewLayer instance.
 */
+ (instancetype)layerWithSession:(AVCaptureSession *)session;

/*!
 @method initWithSession:
 @abstract
    Creates an AVCaptureVideoPreviewLayer for previewing the visual output of the specified AVCaptureSession.
 
 @param session
    The AVCaptureSession instance to be previewed.
 @result
    A newly initialized AVCaptureVideoPreviewLayer instance.
 */
- (instancetype)initWithSession:(AVCaptureSession *)session;

/*!
 @method layerWithSessionWithNoConnection:
 @abstract
    Creates an AVCaptureVideoPreviewLayer for previewing the visual output of the specified AVCaptureSession, but creates no connections to any of the session's eligible video inputs. Only use this initializer if you intend to manually form a connection between a desired AVCaptureInputPort and the receiver using AVCaptureSession's -addConnection: method.
 
 @param session
    The AVCaptureSession instance to be previewed.
 @result
    A newly initialized AVCaptureVideoPreviewLayer instance.
 */
+ (instancetype)layerWithSessionWithNoConnection:(AVCaptureSession *)session API_AVAILABLE(ios(8.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @method initWithSessionWithNoConnection:
 @abstract
    Creates an AVCaptureVideoPreviewLayer for previewing the visual output of the specified AVCaptureSession, but creates no connections to any of the session's eligible video inputs. Only use this initializer if you intend to manually form a connection between a desired AVCaptureInputPort and the receiver using AVCaptureSession's -addConnection: method.
 
 @param session
    The AVCaptureSession instance to be previewed.
 @result
    A newly initialized AVCaptureVideoPreviewLayer instance.
 */
- (instancetype)initWithSessionWithNoConnection:(AVCaptureSession *)session API_AVAILABLE(ios(8.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @property session
 @abstract
    The AVCaptureSession instance being previewed by the receiver.
 
 @discussion
    The session is retained by the preview layer.
 */
@property(nonatomic, retain, nullable) AVCaptureSession *session;

/*!
 method setSessionWithNoConnection:
 @abstract
    Attaches the receiver to a given session without implicitly forming a connection to the first eligible video AVCaptureInputPort. Only use this setter if you intend to manually form a connection between a desired AVCaptureInputPort and the receiver using AVCaptureSession's -addConnection: method.
 
 @discussion
    The session is retained by the preview layer.
 */
- (void)setSessionWithNoConnection:(AVCaptureSession *)session API_AVAILABLE(ios(8.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @property connection
 @abstract
    The AVCaptureConnection instance describing the AVCaptureInputPort to which the receiver is connected.
 
 @discussion
    When calling initWithSession: or setSession: with a valid AVCaptureSession instance, a connection is formed to the first eligible video AVCaptureInput. If the receiver is detached from a session, the connection property becomes nil.
 */
@property(nonatomic, readonly, nullable) AVCaptureConnection *connection API_AVAILABLE(ios(6.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @property videoGravity
 @abstract
    A string defining how the video is displayed within an AVCaptureVideoPreviewLayer bounds rect.
 
 @discussion
    Options are AVLayerVideoGravityResize, AVLayerVideoGravityResizeAspect and AVLayerVideoGravityResizeAspectFill. AVLayerVideoGravityResizeAspect is default. See <AVFoundation/AVAnimation.h> for a description of these options.
 */
@property(copy) AVLayerVideoGravity videoGravity;

/*!
 @property previewing
 @abstract
    A BOOL value indicating whether the receiver is currently rendering video frames from its source.
 
 @discussion
    An AVCaptureVideoPreviewLayer begins previewing when -[AVCaptureSession startRunning] is called. When associated with an AVCaptureMultiCamSession, all video preview layers are guaranteed to be previewing by the time the blocking call to -startRunning or -commitConfiguration returns. While a session is running, you may enable or disable a video preview layer's connection to re-start or stop the flow of video to the layer. Once you've set enabled to YES, you can observe this property changing from NO to YES and synchronize any UI to take place precisely when the video resumes rendering to the video preview layer.
 */
@property(nonatomic, readonly, getter=isPreviewing) BOOL previewing API_AVAILABLE(ios(13.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(macos, visionos) API_UNAVAILABLE(watchos);

/*!
 @method captureDevicePointOfInterestForPoint:
 @abstract
    Converts a point in layer coordinates to a point of interest in the coordinate space of the capture device providing input to the layer.
 
 @param pointInLayer
    A CGPoint in layer coordinates.
 @result
    A CGPoint in the coordinate space of the capture device providing input to the layer.
 
 @discussion
    AVCaptureDevice pointOfInterest is expressed as a CGPoint where {0,0} represents the top left of the picture area, and {1,1} represents the bottom right on an unrotated picture. This convenience method converts a point in the coordinate space of the receiver to a point of interest in the coordinate space of the AVCaptureDevice providing input to the receiver. The conversion takes frameSize and videoGravity into consideration.
 */
- (CGPoint)captureDevicePointOfInterestForPoint:(CGPoint)pointInLayer API_AVAILABLE(macos(10.15), ios(6.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @method pointForCaptureDevicePointOfInterest:
 @abstract
    Converts a point of interest in the coordinate space of the capture device providing input to the layer to a point in layer coordinates.
 
 @param captureDevicePointOfInterest
    A CGPoint in the coordinate space of the capture device providing input to the layer.
 @result
    A CGPoint in layer coordinates.
 
 @discussion
    AVCaptureDevice pointOfInterest is expressed as a CGPoint where {0,0} represents the top left of the picture area, and {1,1} represents the bottom right on an unrotated picture. This convenience method converts a point in the coordinate space of the AVCaptureDevice providing input to the coordinate space of the receiver. The conversion takes frame size and videoGravity into consideration.
 */
- (CGPoint)pointForCaptureDevicePointOfInterest:(CGPoint)captureDevicePointOfInterest API_AVAILABLE(macos(10.15), ios(6.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @method metadataOutputRectOfInterestForRect:
 @abstract
    Converts a rectangle in layer coordinates to a rectangle of interest in the coordinate space of an AVCaptureMetadataOutput whose capture device is providing input to the layer.
 
 @param rectInLayerCoordinates
    A CGRect in layer coordinates.
 @result
    A CGRect in the coordinate space of the metadata output whose capture device is providing input to the layer.
 
 @discussion
    AVCaptureMetadataOutput rectOfInterest is expressed as a CGRect where {0,0} represents the top left of the picture area, and {1,1} represents the bottom right on an unrotated picture. This convenience method converts a rectangle in the coordinate space of the receiver to a rectangle of interest in the coordinate space of an AVCaptureMetadataOutput whose AVCaptureDevice is providing input to the receiver. The conversion takes frame size and videoGravity into consideration.
 */
- (CGRect)metadataOutputRectOfInterestForRect:(CGRect)rectInLayerCoordinates API_AVAILABLE(macos(10.15), ios(7.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @method rectForMetadataOutputRectOfInterest:
 @abstract
    Converts a rectangle of interest in the coordinate space of an AVCaptureMetadataOutput whose capture device is providing input to the layer to a rectangle in layer coordinates.
 
 @param rectInMetadataOutputCoordinates
    A CGRect in the coordinate space of the metadata output whose capture device is providing input to the layer.
 @result
    A CGRect in layer coordinates.
 
 @discussion
    AVCaptureMetadataOutput rectOfInterest is expressed as a CGRect where {0,0} represents the top left of the picture area, and {1,1} represents the bottom right on an unrotated picture. This convenience method converts a rectangle in the coordinate space of an AVCaptureMetadataOutput whose AVCaptureDevice is providing input to the coordinate space of the receiver. The conversion takes frame size and videoGravity into consideration.
 */
- (CGRect)rectForMetadataOutputRectOfInterest:(CGRect)rectInMetadataOutputCoordinates API_AVAILABLE(macos(10.15), ios(7.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @method transformedMetadataObjectForMetadataObject:
 @abstract
    Converts an AVMetadataObject's visual properties to layer coordinates.
 
 @param metadataObject
    An AVMetadataObject originating from the same AVCaptureInput as the preview layer.
 @result
    An AVMetadataObject whose properties are in layer coordinates.
 
 @discussion
    AVMetadataObject bounds may be expressed as a rect where {0,0} represents the top left of the picture area, and {1,1} represents the bottom right on an unrotated picture. Face metadata objects likewise express yaw and roll angles with respect to an unrotated picture. -transformedMetadataObjectForMetadataObject: converts the visual properties in the coordinate space of the supplied AVMetadataObject to the coordinate space of the receiver. The conversion takes orientation, mirroring, layer bounds and videoGravity into consideration. If the provided metadata object originates from an input source other than the preview layer's, nil will be returned.
 */
- (nullable AVMetadataObject *)transformedMetadataObjectForMetadataObject:(AVMetadataObject *)metadataObject API_AVAILABLE(macos(10.15), ios(6.0), macCatalyst(14.0), tvos(17.0)) API_UNAVAILABLE(visionos);

/*!
 @property orientationSupported
 @abstract
    Specifies whether or not the preview layer supports orientation.
 
 @discussion
    Changes in orientation are not supported on all hardware configurations. An application should check the value of @"orientationSupported" before attempting to manipulate the orientation of the receiver. This property is deprecated. Use AVCaptureConnection's -isVideoOrientationSupported instead.
 */
@property(nonatomic, readonly, getter=isOrientationSupported) BOOL orientationSupported API_DEPRECATED("Use AVCaptureConnection's isVideoOrientationSupported instead.", ios(4.0, 6.0)) API_UNAVAILABLE(macos, visionos) API_UNAVAILABLE(tvos);

/*!
 @property orientation
 @abstract
    Specifies the orientation of the preview layer.
 
 @discussion
    AVCaptureVideoOrientation and its constants are defined in AVCaptureSession.h. The value of @"orientationSupported" must be YES in order to set @"orientation". An exception will be raised if this requirement is ignored. This property is deprecated. Use AVCaptureConnection's -videoOrientation instead.
 */
@property(nonatomic) AVCaptureVideoOrientation orientation API_DEPRECATED("Use AVCaptureConnection's videoOrientation instead.", ios(4.0, 6.0)) API_UNAVAILABLE(macos, visionos) API_UNAVAILABLE(tvos);

/*!
 @property mirroringSupported
 @abstract
    Specifies whether or not the preview layer supports mirroring.
 
 @discussion
    Mirroring is not supported on all hardware configurations. An application should check the value of @"mirroringSupported" before attempting to manipulate mirroring on the receiver. This property is deprecated. Use AVCaptureConnection's -isVideoMirroringSupported instead.
 */
@property(nonatomic, readonly, getter=isMirroringSupported) BOOL mirroringSupported API_DEPRECATED("Use AVCaptureConnection's isVideoMirroringSupported instead.", ios(4.0, 6.0)) API_UNAVAILABLE(macos, visionos) API_UNAVAILABLE(tvos);

/*!
 @property automaticallyAdjustsMirroring
 @abstract
    Specifies whether or not the value of @"mirrored" can change based on configuration of the session.
 
 @discussion
    For some session configurations, preview will be mirrored by default. When the value of this property is YES, the value of @"mirrored" may change depending on the configuration of the session, for example after switching to a different AVCaptureDeviceInput. The default value is YES. This property is deprecated. Use AVCaptureConnection's -automaticallyAdjustsVideoMirroring instead.
 */
@property(nonatomic) BOOL automaticallyAdjustsMirroring API_DEPRECATED("Use AVCaptureConnection's automaticallyAdjustsVideoMirroring instead.", ios(4.0, 6.0)) API_UNAVAILABLE(macos, visionos) API_UNAVAILABLE(tvos);

/*!
 @property mirrored
 @abstract
    Specifies whether or not the preview is flipped over a vertical axis.
 
 @discussion
    For most applications, it is unnecessary to manipulate preview mirroring manually if @"automaticallyAdjustsMirroring" is set to YES. The value of @"automaticallyAdjustsMirroring" must be NO in order to set @"mirrored". The value of @"mirroringSupported" must be YES in order to set @"mirrored". An exception will be raised if the value of @"mirrored" is mutated without respecting these requirements. This property is deprecated. Use AVCaptureConnection's -videoMirrored instead.
 */
@property(nonatomic, getter=isMirrored) BOOL mirrored API_DEPRECATED("Use AVCaptureConnection's videoMirrored instead.", ios(4.0, 6.0)) API_UNAVAILABLE(macos, visionos) API_UNAVAILABLE(tvos);

/// A Boolean value that indicates whether the preview layer supports deferred start.
///
/// You can only set the ``deferredStartEnabled`` property to `true` if the preview layer supports deferred start.
@property(nonatomic, readonly, getter=isDeferredStartSupported) BOOL deferredStartSupported API_AVAILABLE(macos(26.0), ios(26.0), macCatalyst(26.0), tvos(26.0)) API_UNAVAILABLE(visionos) API_UNAVAILABLE(watchos);

/// A Boolean value that indicates whether to defer starting this preview layer.
///
/// When this value is `true`, the session doesn't prepare the output's resources until some time after ``startRunning`` returns. You can start the visual parts of your user interface (e.g. preview) prior to other parts (e.g. photo/movie capture, metadata output, etc..) to improve startup performance. Set this value to `false` for outputs that your app needs for startup, and `true` for the ones that it doesn't need immediately.
///
/// By default, this value is `false` for ``AVCaptureVideoPreviewLayer`` objects, since this object is used to display preview. For best session start performance, set ``deferredStartEnabled`` to `false` for preview layers. If your app contains multiple preview layers, you may want to display the main preview layer as soon as possible and allow the remaining layers to display subsequently. In this case, set ``deferredStartEnabled`` to `true` for the remaining layers.
///
/// Setting this property to the same value for all outputs, including ``AVCaptureVideoPreviewLayer`` and ``AVCaptureOutput``, is equivalent to not using deferred start.
///
/// If ``deferredStartSupported`` is `false`, setting this property value to `true` results in the session throwing an invalid argument exception.
///
/// - Note: Set this value before committing the configuration.
@property(nonatomic, getter=isDeferredStartEnabled) BOOL deferredStartEnabled API_AVAILABLE(macos(26.0), ios(26.0), macCatalyst(26.0), tvos(26.0)) API_UNAVAILABLE(visionos) API_UNAVAILABLE(watchos);

@end

NS_ASSUME_NONNULL_END

#endif  // __has_include(<QuartzCore/QuartzCore.h>)

#else
#import <AVFCapture/AVCaptureVideoPreviewLayer.h>
#endif
