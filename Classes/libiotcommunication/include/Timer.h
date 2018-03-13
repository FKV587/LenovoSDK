//
//  Time.h
//  libiot
//
//  Created by leno on 16/2/16.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Timer : NSObject

@property (nonatomic ,strong) NSString *begin_time; //	定时启动时间
@property (nonatomic ,strong) NSDictionary *begin_action;//对应begin_time 动作
//@property (nonatomic ,strong) NSString *week;//1:周一,2:周二...7:周日 空list[]时表示当天，执行周期
@property (nonatomic ,strong) NSArray *week;
@property (nonatomic ,strong) NSString *gadget_id;//所属的gadget id
@property (nonatomic ,strong) NSString *name;//定时器名称
@property (nonatomic ,strong) NSString *status;//状态：启用0，禁用1
@property (nonatomic ,strong) NSString *time_id;//timer的唯一标识
//当week为空时用于判断是不是今天发生的
@property (nonatomic,assign) BOOL isToday;
//用于表示下一个显示的是星期几
@property (nonatomic,strong) NSNumber* weekDay;
//获取最近即将生效的时间
-(long long)getLatestValidTime;
//获取action的描述
-(NSString*)begin_actionDescription;

@end
