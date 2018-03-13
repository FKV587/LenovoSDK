//
//  LibProperty.h
//  libiot
//
//  Created by guangchaopeng on 16/3/22.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LibProperty : NSObject
+(LibProperty*)shareInstance;
+(BOOL)isLogEnable;
-(NSString*)getServerAddr;
@end
