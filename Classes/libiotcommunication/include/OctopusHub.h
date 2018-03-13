//
//  SmartHub.h
//  libiot
//
//  Created by pennycharles on 15/4/21.
//  Copyright (c) 2015年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OctopusHub : NSObject
-(OctopusHub*) initWithMac:(NSString*) mac theHubId:(NSString*) hubId theUserId:(NSString*)userId;
@property(retain,nonatomic) NSString* hub_id; //hub id
@property(retain,nonatomic) NSString* user_id;// user id
//@property(nonatomic,strong)NSMutableArray *info;
@property (nonatomic ,strong) NSString *hub_info;
@property(retain,nonatomic) NSString* model; //hub 型号
@property(retain,nonatomic) NSString* name; //hub名称
@property(retain,nonatomic) NSString* hub_mac; //hub mac地址
@property(retain,nonatomic) NSString* hub_flag; //“1”普通hub，“2”虚拟hub
@property(retain,nonatomic) NSString* hub_vendor; //hub 商家
@property(retain,nonatomic) NSString* firmware_version; //hub的固件版本
@property (nonatomic ,strong) NSString *hub_type; //Hub 类型
@property (nonatomic ,assign)  BOOL activated; //hub是否被激活，理论上client得到的所有hub都是被激活的，所以client端可以不关心该字段
@property (retain,nonatomic) NSString* type_id ;
@property (retain,nonatomic) NSString* class_id;
@property (nonatomic,assign) BOOL status;
@property (nonatomic ,assign) BOOL display; //hub是否显示, NO不显示,YES显示

@property (nonatomic ,strong) NSString *ip; //处于小循环状态的hub的ip

@property (nonatomic ,copy) NSString *updateModel; //升级模式， true为自动升级，false为非自动升级

@property (nonatomic ,strong) NSString *os_version; //系统版本

@end


