//
//  PushMessage.h
//  libiot
//
//  Created by pennycharles on 16/4/14.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum {
    GADGET_NOTICE, //设备相关的推送
    RULE_NOTICE, //规则相关的推送
    PUSH_MESSAGE_NOTICE, //系统类
    MSG_SYSTEM_NOTICE,//系统通知
    MSG_FUNCTION_NOTICE,//新功能通知
    MSG_ACTIVITY_NOTICE //活动通知
}NoticeType;
@interface PushMessage : NSObject
@property(nonatomic,strong) NSString* noticeText; //显示的内容
@property(nonatomic,strong) NSString* noticeId; //如果是设备相关的推送，此处为gadget id，否则为rule id
@property(nonatomic,assign) NoticeType noticeType;
@property (nonatomic ,strong) NSString *url;
@end
