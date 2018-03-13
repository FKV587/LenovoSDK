//
//  TimeManager.h
//  libiot
//
//  Created by leno on 16/2/17.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Timer;

typedef void(^ResultBlock)(BOOL state, NSInteger code);

@interface TimeManager : NSObject

@property (nonatomic ,copy) ResultBlock resultBlock;

/**
 * 获取定时器列表
 */
+ (NSArray *)getTimeList;

/**
 * 根据timeId获取相应的timer model
 */
+ (Timer *)getTimerWithId:(NSString *)timeId;

/**
 * 根据gadget_id获取当前设备下的定时器列表
 */
+ (NSArray *)getTimeListWithGadget_id:(NSString *)gadget_id;

/**
 * 根据gadget_id获取当前设备下的定时器列表,已经按照即将发生的时间排序
 */
+(NSArray *)getSortedTimeListWithGadget_id:(NSString *)gadget_id;

/**
 * 创建定时器
 * param:数组类型，数组元素是NSNumber类型。 比如：[1]
 */
- (void)createTime:(NSString *)begin_time actionid:(NSString *)actionid param:(NSArray *)param week:(NSArray *)week gadget_id:(NSString *)gadget_id name:(NSString *)name status:(NSString *)status resultBlock:(ResultBlock)block;

/**
 * 修改定时器
 */
- (void)modifyTime:(NSString *)time_id begin_time:(NSString *)begin_time actionid:(NSString *)actionid param:(NSArray *)param week:(NSArray *)week gadget_id:(NSString *)gadget_id name:(NSString *)name status:(NSString *)status resultBlock:(ResultBlock)block;

/**
 * 删除定时器
 */
- (void)deleteTimeWithId:(NSString *)time_id resultBlock:(ResultBlock)block;

/**
 * 启用禁用定时器
 */
- (void)setTimeWithId:(NSString *)time_id status:(NSString *)status resultBlock:(ResultBlock)block;

/**
 * 根据gadgetid获取定时器列表
 */
- (void)getTimeListWithGadgetid:(NSString *)gadget_id resultBlock:(ResultBlock)block;

/**
 * 根据gadgetid获取定时器列表字符串
 */
- (void)getTimeStringtWithGadgetid:(NSString *)gadget_id resultBlock:(void(^)(BOOL state, NSString*data))result;


/**
 * 获取定时器列表
 */
- (void)getTimeList:(ResultBlock)block;

@end

