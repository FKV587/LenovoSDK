//
//  TimeToolsCom.h
//  libiot
//
//  Created by leno on 16/7/7.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TimeToolsCom : NSObject

+ (NSString *)timeStampToDateTimeStr:(NSTimeInterval)timeStamp;

+ (NSString *)timeStampToDateStr:(NSTimeInterval)timeStamp;

+ (NSTimeInterval)dateStrToTimeStamp:(NSString *)dateStr;

+ (NSTimeInterval)dateTimeStrToTimeStamp:(NSString *)dateStr;

+ (NSTimeInterval)cuurentDateStrToTimeStamp:(NSString *)dateStr;

/** 
 * 秒数转化为分钟，比如28800转为08:00
 * @param seconds 秒数
 * @return HH:mm 格式的时间
 */
+ (NSString *)timeSecondsToDateStr:(NSInteger)seconds;

@end
