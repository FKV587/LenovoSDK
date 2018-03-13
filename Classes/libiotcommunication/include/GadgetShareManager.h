//
//  GadgetShareManager.h
//  libiot
//
//  Created by guangchaopeng on 16/4/5.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef  void(^ShareResult)(BOOL state,int code);
@interface GadgetShareManager : NSObject
+(GadgetShareManager*)shareGadgetShareManager;
-(void)getShareCodeForGadgets:(NSArray*)gadgetIds callback:(ShareResult)result;
@end
