//
//  AppStatics.h
//  libiot
//
//  Created by guangchaopeng on 17/1/21.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppStatics : NSObject

/** 数据采集开关，默认为YES,自定义采集事件接口打开； 如果设为NO, 则会关闭自定义采集事件analyticeEventWithCategory: */
@property (nonatomic, assign) BOOL analyticeFlag;

+ (instancetype)shareInstance;
//自定义采集事件, 当analyticeFlag为NO时，该接口失效
- (void)analyticeEventWithCategory:(NSString *)category action:(NSString *)action label:(NSString *)label value:(NSInteger)value pairs:(NSDictionary *)pairs;

/**
 * 新自定义采集事件,新增hccDic,gadgetId,appVersion参数,修改value参数类型。当analyticeFlag为NO时，该接口失效
 * @param appVersion:app版本
 */
- (void)analyticeEventWithCategoryNew:(NSString *)category action:(NSString *)action label:(NSString *)label value:(NSString *)value pairs:(NSDictionary *)pairs hccDic:(NSDictionary *)hccDic gadgetId:(NSString *)gadgetId appVersion:(NSString *)appVersion;
@end

@interface DurationCalc:NSObject

+(long long) secondsFrome1970;
+(void)start;  
+(int)stop;
+(int)countDurationFromStart;
@end
