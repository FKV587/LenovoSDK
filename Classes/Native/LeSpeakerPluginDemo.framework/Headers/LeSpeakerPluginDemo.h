//
//  LeSpeakerPluginDemo.h
//  LeSpeakerPluginDemo
//
//  Created by Edward on 2018/1/4.
//  Copyright © 2018年 coolpeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//! Project version number for LeSpeakerPluginDemo.
FOUNDATION_EXPORT double LeSpeakerPluginDemoVersionNumber;

//! Project version string for LeSpeakerPluginDemo.
FOUNDATION_EXPORT const unsigned char LeSpeakerPluginDemoVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <LeSpeakerPluginDemo/PublicHeader.h>

@interface LeSpeakerPluginDemo : NSObject

+ (void)startPluginWithGadgetID:(NSString *)gadget_id fromViewController:(UIViewController *)viewController;

@end

