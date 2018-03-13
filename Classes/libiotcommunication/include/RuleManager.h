//
//  RuleManager.h
//  libiot
//
//  Created by leno on 16/2/1.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ResultBlock)(BOOL state, NSInteger code);
@class SmartRule;
@interface RuleManager : NSObject

@property (nonatomic ,copy) ResultBlock resultBlock;

//获取本地rule数据
+ (NSArray *)getRuleList;

+ (SmartRule *)getSmartRuleWithRuleId:(NSString *)ruleid;

/**
 * 获取所有rule的消息记录，本地获取，一级
 * @return 数组类型，数组为两层结构，一级为不同日期的数组集合，二级为相同日期的historyRecord model集合
 */
+ (NSArray *)getRecordRuleList;

/**
 * 获取单个rule的历史记录详情
 * source_id: ruleid
 * @return 数组类型，数组为两层结构，一级为不同日期的数组集合，二级为相同日期的historyRecord model集合
 */
+ (NSArray *)getRuleHistoryDetDataWithId:(NSString *)source_id;

/**
 * 根据source_id获取相应的events的json字符串
 */
+ (NSString *)getRuletHistoryDetEventsWithId:(NSString *)source_id;

/**
 * 创建规则
 */

-(void)createRule:(SmartRule*)rule resultBlock:(ResultBlock)block;

/**
 * 查询规则
 */
- (void)queryRuleList:(ResultBlock)block;

/** 
 * 删除规则
 */
- (void)deleteRule:(NSString *)rule_id resultBlock:(ResultBlock)block;

/** 
 * 修改规则
 */

-(void)modifyRuleWithId:(SmartRule*)rule  ruleId:(NSString*)ruleId resultBlock:(ResultBlock)block;
/**
 * 查询历史纪录，一级
 */
- (void)queryHistoryRecord:(ResultBlock)block;

/**
 * 查询历史纪录，二级
 * attributed_id不是必传，其他都是必传。start_time,end_time,num 如果分别传@"",则后台分别取默认值
 */
- (void)queryDetHistoryRecordWithSource_id:(NSString *)source_id start_time:(NSString *)start_time end_time:(NSString *)end_time num:(NSString *)num attributed_id:(NSString *)attributed_id resultBlock:(ResultBlock)block;

///**
// * 新查询历史纪录，二级
// * attributed_id不是必传，其他都是必传。start_time,end_time,num 如果分别传@"",则后台分别取默认值
// */
//- (void)queryDetHistoryRecordWithSource_id:(NSString *)source_id start_time:(NSString *)start_time end_time:(NSString *)end_time num:(NSString *)num attributed_id:(NSString *)attributed_id event_type:(NSString *)event_type resultBlock:(ResultBlock)block;

@end
