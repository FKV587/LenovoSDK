//
//  GadgetShareManger.h
//  libiot
//
//  Created by guangchaopeng on 16/4/5.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GadgetShareManger : NSObject
+(GadgetShareManger*)shareGadgetShareManger;

//获取分享码
-(void)getShareCodeForGadgets:(NSArray*)gadgetIds callback:(void(^)(BOOL state, NSInteger code))result;
//本地获取分享码
- (NSString *)getShareCode:(void(^)(NSString *share_code_ttl,NSArray *gadget_ids))block;
//获取分享的成员,本地获取
- (NSMutableArray *)getUserArrayWithCopy;

//删除分享码
-(void)delShareCode:(NSString *)code callback:(void(^)(BOOL state,NSInteger code))result;
//通过分享码分享设备
-(void)shareGadgetsWithShareCode:(NSString *)code callback:(void(^)(BOOL state,NSInteger code))result;

//管理员删除分享者
-(void)delShareMember:(NSString*)userId gadgets:(NSArray*)gadgetIds callback:(void(^)(BOOL state,NSInteger code))result;

//用户主动退出分享
-(void)quitShare:(NSArray*)gadgetIds callback:(void(^)(BOOL state,NSInteger code))result;
//请求分享得到的设备
-(void)getSharedGadgets:(void(^)(BOOL state,NSInteger code))result;
//所有设备列表(创建和来自分享)
-(void)getAllGadgets:(void(^)(BOOL state,NSInteger code))result;
//查询用户所有设备列表及成员
- (void)getAllGadgetsWithUsers:(void(^)(BOOL state, NSInteger code , NSMutableArray *gadgetsArray))result;

//获取所有 Gadget动态可变属性信息
-(void)getAllGadgetsAttr:(void(^)(BOOL state,NSInteger code))result;

//根据设备查询设备成员
-(void)getMembersForGadget:(NSString*)gadgetId callback:(void(^)(BOOL state,NSInteger code))result;

//获取创建的设备列表
- (void)getCreateGadgets:(void(^)(BOOL state,NSInteger code))result;

//管理员删除多个成员
- (void)delShareMembers:(NSArray *)user_ids gadget_id:(NSString *)gadget_id callback:(void(^)(BOOL state,NSInteger code))result;

@end
