#if __has_include(<XCTestCore/XCTMetric.h>)
#import <XCTestCore/XCTMetric.h>
#else

//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <XCTest/XCTestDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, XCTPerformanceMeasurementPolarity) {
    /// Represents measurements where smaller values are considered "better".
    XCTPerformanceMeasurementPolarityPrefersSmaller = -1L,

    /// Represents measurements which do not have a meaningful polarity. Suitable for situations where neither smaller nor larger values are considered "better".
    XCTPerformanceMeasurementPolarityUnspecified,

    /// Represents measurements where larger values are considered "better".
    XCTPerformanceMeasurementPolarityPrefersLarger,
};

/*!
 * @class XCTPerformanceMeasurementTimestamp
 * Encapsulates timestamps at various levels
 */
@interface XCTPerformanceMeasurementTimestamp : NSObject

/*!
 * @property absoluteTime
 * The timestamp recorded using mach_absolute_time().
 */
@property (readonly) uint64_t absoluteTime;

/*!
 * @property absoluteTimeNanoSeconds
 * Nanoseconds since an arbitrary point, does not increment while the system is asleep.
 */
@property (readonly) uint64_t absoluteTimeNanoSeconds;

/*!
 * @property date
 * The timestamp recorded using an NSDate.
 */
@property (readonly, copy) NSDate *date;

/*!
 * @method -initWithAbsoluteTime:date:
 * Initializes an object with the given mach absolute time and NSDate instance.
 */
- (instancetype)initWithAbsoluteTime:(uint64_t)absoluteTime date:(NSDate *)date NS_DESIGNATED_INITIALIZER;

/*!
 * @method -init
 * Initializes an object which represents a timestamp at the current time.
 */
- (instancetype)init;

@end

/*!
 * @class XCTPerformanceMeasurement
 * Contains the data acquired from a single metric being measured for an individual iteration.
 */
@interface XCTPerformanceMeasurement : NSObject

/*!
 * @property identifier
 * A unique identifier for this measurement such as "com.apple.XCTPerformanceMetric_WallClockTime".
 */
@property (readonly, copy) NSString *identifier;

/*!
 * @property displayName
 * The human-readable name for this measurement, such as "Wall Clock Time".
 */
@property (readonly, copy) NSString *displayName;

/*!
 * @property value
 * The value of the measurement.
 */
@property (readonly, copy) NSMeasurement *value API_AVAILABLE(ios(10.0), tvos(10.0), watchos(3.0));

/*!
 * @property doubleValue
 * The double value of the measurement.
 */
@property (readonly) double doubleValue;

/*!
 * @property unitSymbol
 * A string describing the unit the value is in.
 */
@property (readonly, copy) NSString *unitSymbol;

/*!
 * @property polarity
 * An enum value representing in which direction measurements should be compared against their baselines.
 */
@property (readonly) XCTPerformanceMeasurementPolarity polarity;

/*!
 * @method -initWithIdentifier:displayName:value:
 * Initializes an object which encapsulates the measurement for a metric during a single iteration.
 *
 * @param identifier A unique identifier for this measurement such as "com.apple.XCTPerformanceMetric_WallClockTime".
 * @param displayName A human-readable name for this measurement, such as "Wall Clock Time".
 * @param value The value of the measurement.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier displayName:(NSString *)displayName value:(NSMeasurement *)value API_AVAILABLE(ios(10.0), tvos(10.0), watchos(3.0));

/*!
 * @method -initWithIdentifier:displayName:doubleValue:unitSymbol:
 * Initializes an object which encapsulates the measurement for a metric during a single iteration.
 *
 * @param identifier A unique identifier for this measurement such as "com.apple.XCTPerformanceMetric_WallClockTime".
 * @param displayName A human-readable name for this measurement, such as "Wall Clock Time".
 * @param doubleValue The double value of the measurement.
 * @param unitSymbol A string describing the unit the value is in.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier displayName:(NSString *)displayName doubleValue:(double)doubleValue unitSymbol:(NSString *)unitSymbol NS_DESIGNATED_INITIALIZER;

/*!
 * @method -initWithIdentifier:displayName:value:
 * Initializes an object which encapsulates the measurement for a metric during a single iteration.
 *
 * @param identifier A unique identifier for this measurement such as "com.apple.XCTPerformanceMetric_WallClockTime".
 * @param displayName A human-readable name for this measurement, such as "Wall Clock Time".
 * @param value The value of the measurement.
 * @param polarity An enum value representing in which direction measurements should be compared against their baselines.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier displayName:(NSString *)displayName value:(NSMeasurement *)value polarity:(XCTPerformanceMeasurementPolarity)polarity API_AVAILABLE(ios(10.0), tvos(10.0));

/*!
 * @method -initWithIdentifier:displayName:doubleValue:unitSymbol:
 * Initializes an object which encapsulates the measurement for a metric during a single iteration.
 *
 * @param identifier A unique identifier for this measurement such as "com.apple.XCTPerformanceMetric_WallClockTime".
 * @param displayName A human-readable name for this measurement, such as "Wall Clock Time".
 * @param doubleValue The double value of the measurement.
 * @param unitSymbol A string describing the unit the value is in.
 * @param polarity An enum value representing in which direction measurements should be compared against their baselines.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier displayName:(NSString *)displayName doubleValue:(double)doubleValue unitSymbol:(NSString *)unitSymbol polarity:(XCTPerformanceMeasurementPolarity)polarity;

- (instancetype)init XCT_UNAVAILABLE("Default initializer not available. Use -initWithIdentifier:displayName:doubleValue:unitSymbol: instead.");

+ (instancetype)new XCT_UNAVAILABLE("Default initializer not available. Use -initWithIdentifier:displayName:doubleValue:unitSymbol: instead.");

@end

/*!
 * @protocol XCTMetric
 * Defines a protocol which may be used with the -measureWithMetrics* methods on XCTestCase.
 *
 * @discussion
 * Classes conforming to XCTMetric must also adopt NSCopying, as a unique metric instance is copied for each iteration.
 */
@protocol XCTMetric <NSCopying, NSObject>

/*!
 * @method -reportMeasurementsFromStartTime:toEndTime:error:
 * Report measurements for the iteration that started and ended at the specified times.
 *
 * @discussion
 * Called after -didStopMeasuring has been invoked and when XCTest is ready to gather
 * the measurements that were collected. You can truncate the data accumulated to be as
 * accurate as possible with the start and end times.
 */
- (nullable NSArray<XCTPerformanceMeasurement *> *)reportMeasurementsFromStartTime:(XCTPerformanceMeasurementTimestamp *)startTime toEndTime:(XCTPerformanceMeasurementTimestamp *)endTime error:(NSError **)error;

@optional

/*!
 * @method -willBeginMeasuring
 * Called every iteration just before the measure block is about to be invoked.
 * You should begin measuring when this is called.
 */
- (void)willBeginMeasuring;

/*!
 * @method -didStopMeasuring
 * Called after the measure block's invocation. You should stop measuring when
 * this is called.
 */
- (void)didStopMeasuring;

@end

/*!
 * @class XCTClockMetric
 * A metric which gathers monotonic time data.
 */
XCT_METRIC_API_AVAILABLE
@interface XCTClockMetric : NSObject <XCTMetric>

/*!
 * @method init
 * Initializes a metric which is recommended for measuring time.
 *
 * @return A new instance of a metric which will measure time.
 *
 */
- (instancetype)init;

@end

/*!
 * @class XCTOSSignpostMetric
 * A metric which measures timestamp data gathered from os_signposts.
 * If the interval being measured is an animation os_signpost interval then the following
 * data will also be gathered:
 * - frame rate (fps)
 * - frame count
 * - number of hitches
 * - hitch total time duration (ms)
 * - hitch time ratio (ms per s)
 */
XCT_METRIC_API_AVAILABLE
@interface XCTOSSignpostMetric : NSObject <XCTMetric>

/*!
 * @method -initWithSubsystem:category:name
 * Initializes a metric which describes a custom signpost.
 *
 * @param subsystem The subsystem of the target signpost.
 * @param category The category of the target signpost.
 * @param name The name of the target signpost.
 * @return A signpost metric describing the target signpost.
 */
- (instancetype)initWithSubsystem:(NSString *)subsystem category:(NSString *)category name:(NSString *)name;

- (instancetype)init XCT_UNAVAILABLE("Default initializer not available. Use -initWithSubsystem:category:name: instead.");

+ (instancetype)new XCT_UNAVAILABLE("Default initializer not available. Use -initWithSubsystem:category:name: instead.");

@end

/*!
 * Interface extension describing OS Signposts that are instrumented by the OS.
 */
XCT_METRIC_API_AVAILABLE
@interface XCTOSSignpostMetric (XCTBuiltinOSSignposts)

/*!
 * @property applicationLaunchMetric
 * The XCTOSSignpostMetric object covering application launch
*/
@property (readonly, class) XCTOSSignpostMetric *applicationLaunchMetric API_DEPRECATED("Use XCTApplicationLaunchMetric instead", macos(10.15, 11.0), ios(13.0, 14.0), tvos(13.0, 14.0)) API_UNAVAILABLE(watchos);

/*!
 * @property navigationTransitionMetric
 * The XCTMetric object covering navigation transitions between views
 */
@property (readonly, class) id<XCTMetric> navigationTransitionMetric API_AVAILABLE(ios(14.0), tvos(14.0), watchos(7.0)) API_UNAVAILABLE(macos);

/*!
 * @property customNavigationTransitionMetric
 * The XCTMetric object covering custom navigation transitions between views
 */
@property (readonly, class) id<XCTMetric> customNavigationTransitionMetric API_AVAILABLE(ios(14.0), tvos(14.0), watchos(7.0)) API_UNAVAILABLE(macos);

/*!
 * @property scrollingAndDecelerationMetric
 * The XCTMetric object covering both the scroll and deceleration animations
 */
@property (readonly, class) id<XCTMetric> scrollingAndDecelerationMetric API_AVAILABLE(macos(11.0), ios(15.0), tvos(15.0), watchos(8.0));

/*!
 * @property scrollDecelerationMetric
 * The XCTMetric object covering scroll deceleration animations
 */
@property (readonly, class) id<XCTMetric> scrollDecelerationMetric API_DEPRECATED_WITH_REPLACEMENT("Use scrollingAndDecelerationMetric instead", ios(14.0, API_TO_BE_DEPRECATED), tvos(14.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(macos);

/*!
 * @property scrollDraggingMetric
 * The XCTMetric object covering scroll dragging animations
 */
@property (readonly, class) id<XCTMetric> scrollDraggingMetric API_DEPRECATED_WITH_REPLACEMENT("Use scrollingAndDecelerationMetric instead", ios(14.0, API_TO_BE_DEPRECATED), tvos(14.0, API_TO_BE_DEPRECATED)) API_UNAVAILABLE(macos);

@end

/*!
 * @class XCTApplicationLaunchMetric
 * A metric which measures application launch durations.
*/
XCT_METRIC_API_AVAILABLE
__attribute__((objc_subclassing_restricted))
@interface XCTApplicationLaunchMetric : NSObject <XCTMetric>

/*!
 * @method -init
 * Initializes an application launch metric that measures the amount of time an
 * application takes to display its first frame to screen.
 */
- (instancetype)init;

/*!
 * @method -initWithWaitUntilResponsive
 * Initializes an application launch metric that measures the amount of time it takes
 * for an application to display its first frame to screen and for its main thread to be
 * ready to accept user input.
 *
 * @param waitUntilResponsive Specifies the end of the application launch
 * interval to be when the application's main thread is responsive to user input.
*/
- (instancetype)initWithWaitUntilResponsive:(BOOL)waitUntilResponsive API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0), watchos(7.0));

@end

/*!
 * @class XCTCPUMetric
 * A metric which measures instructions retired and time utilization of the CPU.
 */
XCT_METRIC_API_AVAILABLE
@interface XCTCPUMetric : NSObject <XCTMetric>

/*!
 * @method initLimitingToCurrentThread:
 * Creates a metric which will observe CPU activity for the thread that executes
 * the block being measured. For single-threaded workloads, this provides greater
 * precision and lower variance than -init.
 *
 * @note The Thread under test is defined as the thread which will perform the execution of the work provided to the -[XCTestCase measure*] API.
 *
 * @returns An initialized metric.
 */
- (instancetype)initLimitingToCurrentThread:(BOOL)limitToCurrentThread;

/*!
 * @method init
 * Creates a metric that will target the current process.
 *
 * @returns An initialized metric.
 */
- (instancetype)init;

@end

/*!
 * @class XCTMemoryMetric
 * A metric which measures utilization of physical memory.
 */
XCT_METRIC_API_AVAILABLE
@interface XCTMemoryMetric : NSObject <XCTMetric>

/*!
 * @method init
 * Creates a metric that will target the current process.
 *
 * @returns An initialized metric.
 */
- (instancetype)init;

@end

/*!
 * @class XCTStorageMetric
 * A metric which measures utilization of the file storage media.
 */
XCT_METRIC_API_AVAILABLE
@interface XCTStorageMetric : NSObject <XCTMetric>

/*!
 * @method init
 * Creates a metric that will target the current process.
 *
 * @returns An initialized metric.
 */
- (instancetype)init;

@end

/*!
 * @class XCTHitchMetric
 * A metric which measures the hitches encountered.
 */
API_AVAILABLE(macos(16.0), ios(19.0), watchos(12.0), tvos(19.0)) API_UNAVAILABLE(visionos)
@interface XCTHitchMetric : NSObject <XCTMetric>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif
