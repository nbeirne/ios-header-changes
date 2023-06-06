//
//  HKHealthStore+UIKit.h
//  HealthKit
//
//  Created by Srishti Gupta on 1/25/23.
//  Copyright © 2023 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <HealthKit/HealthKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HKHealthStore (UIKit)

/*!
@property      authorizationViewControllerPresenter
@abstract      The view controller from which HealthKit authorization sheets will be presented
@discussion    This property can be set before requesting authorization or running a query like HKDocumentQuery for a better user-experience. Since this property will ensure to infer the correct hosting view controller to show the authorization sheet.
*/
@property (nonatomic, weak, nullable) UIViewController *authorizationViewControllerPresenter API_AVAILABLE(ios(17.0));

@end

NS_ASSUME_NONNULL_END
