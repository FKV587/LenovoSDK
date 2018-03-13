//
//  SmartRules.h
//  libiot
//
//  Created by guangchaopeng on 16/4/6.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
AND=0,
OR =1,
}ConditionType;

typedef enum {
GREATTHAN = 0,//>
EQUAL = 1, //==
LESSTHAN = 2, // <
NOTGREATTHAN =3 , // =<
NOTLESSTHAN = 4, //>=
}ConditionOption;

@interface SmartRule : NSObject
@property(nonatomic,retain) NSString* ruleId;
@property(nonatomic,retain) NSString* ruleName;
@property(nonatomic,assign)ConditionType conditionType;
@property(nonatomic,retain)NSArray* conditions;//包含的是Condition对象
@property(nonatomic,retain)NSArray* gadgetActions;
@property(nonatomic,assign)BOOL valid;
@property(nonatomic,assign)BOOL pushMsgFlag;
@property (nonatomic ,strong) NSString *rule_desc;//规则描述
@property (nonatomic ,strong) NSArray *start_time;//生效开始时间[22,33] 时分
@property (nonatomic ,strong) NSArray *end_time;//生效结束时间[22,33] 时分

/**
 生效周期[1,2,3,4,5,6,7] 默认[1,2,3,4,5,6,7]
 /1:周一,2:周二...7:周日 空list[]时表示当天
 */
@property (nonatomic ,strong) NSArray *week;

@property (nonatomic ,strong) NSString *icon;

@end

@interface  Condition: NSObject
@property(nonatomic,retain) NSString* attrId;
@property(nonatomic,retain) NSString* classId;
@property(nonatomic,retain) NSString* gadgetId;
@property(nonatomic,assign) ConditionOption option;
@property(nonatomic,retain) NSArray* values;
@property (nonatomic ,strong) NSString *trigger_type;//1:设备属性变化; 2:通用 trigger
@property (nonatomic ,strong) NSString *general; //trigger_type为2，general为0x10001时，手动执行
@property (nonatomic ,strong) NSDictionary *triggerDic;
@property (nonatomic ,strong) NSArray *gadget_type_ids; //推荐设备typeid列表

- (NSString*)getOptionString;

@end

@interface GadgetAction : NSObject
@property(nonatomic,retain) NSString* gadgetId;
@property(nonatomic,retain) NSString* classId;
@property(nonatomic,retain) NSArray* actions;
@property (nonatomic ,strong) NSString *action_type; //1:设备action 2:使能规则 3:使能消息开关 4:延时执行 5:发通知.  
@property (nonatomic ,strong) NSString *cmd; //device和mfa
@property (nonatomic ,strong) NSDictionary *actionDic;
@property (nonatomic ,strong) NSArray *gadget_type_ids;

@end

@interface Action : NSObject
@property(nonatomic,retain) NSString* actionId;
@property(nonatomic,retain) NSArray* param;
@end
