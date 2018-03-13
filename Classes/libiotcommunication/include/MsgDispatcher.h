//
//  MsgDispatcher.h
//  libiot
//
//  Created by pennycharles on 16/2/29.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* const newGadgetFind; //新设备发现通知,notifi obj为gadget model
extern NSString* const gadgetReseted; //设备充值通知,notifi obj为gadget model
extern NSString *const gadgetAttrUpdate; //设备属性变化通知,notifi obj为gadgetid或者nil

/**
 设备在线状态变化通知，notifi obj为由dic组成的数组:
 [
 {
 "gadget_id": "a8af015dddbbfceb70863c44c7b06e47c64c468b",
 "status": true
 }
 ]
 */
extern NSString *const gadgetStatusUpdate;
extern NSString *const gadgetInfoModify; //设备信息修改通知,notifi obj为gadgetId
extern NSString *const gadgetDelete; //设备删除通知,notifi obj为gadget model

extern NSString *const hubInfoModify; //hub信息修改通知,notifi obj为hubid
extern NSString *const hubBind; //hub绑定通知,notifi obj为hubid
extern NSString *const hubDelete; //hub删除通知,notifi obj为hubid

/*
 * 发现一个未绑定的hub，通知的参数是对应的hub mac地址
 * [[NSNotificationCenter defaultCenter] postNotificationName:anUnbindHubFind object:mac];
 */
extern NSString *const anUnbindHubFind;

extern NSString *const ruleAdd; //rule添加通知,notifi obj为ruleid
extern NSString *const ruleModify; //rule修改通知,notifi obj为ruleid
extern NSString *const ruleDelete; //rule删除通知,notifi obj为ruleid

extern NSString *const homeAdd; //home添加通知,notifi obj为homeid
extern NSString *const homeDelete; //home删除通知,notifi obj为homeid
extern NSString *const homeModify; //home修改通知,notifi obj为homeid

extern NSString *const roomAdd; //room添加通知,notifi obj为roomid
extern NSString *const roomDelete; //room删除通知,notifi obj为roomid
extern NSString *const roomModify; //room修改通知,notifi obj为roomid

extern NSString *const timeAdd; //time添加通知,notifi obj为timeid
extern NSString *const timeDelete; //time删除通知,notifi obj为timeid
extern NSString *const timeModify; //time修改通知,notifi obj为timeid

/*
 * [cent postNotificationName:webSocketStatus object:[NSNumber numberWithBool:YES]];
 */
extern NSString *const webSocketStatus;


//需要重新登录
extern NSString *const loginExpired;
//登录成功
extern NSString *const loginSuccess;
//退出登录
extern NSString *const logoutSuccess;

extern NSString *const acceptByShareCode; //接受者接受分享成功的通知,notifi obj为由gadgetid组成的数组
extern NSString *const deleteShareMember; //删除分享通知
extern NSString *const memberQuitShare;//分享人员退出分享的通知

//消息推送
extern NSString *const pushMessageNotice;

extern NSString *const alarmUpdate; //alarm更新通知
extern NSString *const memoUpdate; //备忘录更新通知

extern NSString *const taxiUpdate; //打车通知

extern NSString *const speaker_accept_pair; //接受配对
extern NSString *const speaker_delete_pair; //删除配对


extern NSString *const gadgetDyncAttrUpdate; //设备动态属性变化通知, 不通知gadgetid
extern NSString *const hubListUpdate; //hub列表变化通知, 不通知hubid
//extern NSString *const ruleInfoUpdate; //rule变化通知, 不通知ruleid
//extern NSString *const homeAndRoomInfoUpdate; //home和room变化通知, 不通知homeid和roomid
//extern NSString *const timelistUpdate; //定时器列表变化通知, 不通知time id
//extern NSString *const websocketConnectGadgSucc; //websocket连接成功，并成功拉取到设备之后的通知, obj为nil

extern NSString *const createGadgetPC;

@interface MsgDispatcher : NSObject

@end
