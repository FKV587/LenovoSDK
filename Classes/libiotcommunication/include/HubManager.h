//
//  HubManger.h
//  libiot
//
//  Created by pennycharles on 15/4/21.
//  Copyright (c) 2015年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>



@class OctopusHub;

typedef void(^ResultBlock)(BOOL state, NSInteger code);

typedef void(^CheckVersion)(BOOL state, NSInteger code, NSString *version);

typedef void(^GetHubIPCompletionHandler)(BOOL state, NSArray *resultArray, NSInteger code ,NSError *error);

typedef void(^GetAmazonHubCompletionHandler)(BOOL state, OctopusHub *hub, NSInteger code ,NSError *error);


@interface HubManager : NSObject


@property (nonatomic ,copy) ResultBlock resultBlock;

@property (nonatomic ,copy) GetHubIPCompletionHandler getHubIPCompletionHandler;

@property (nonatomic ,copy) GetAmazonHubCompletionHandler getAmazonHubCompletionHandler;

@property (nonatomic ,assign) BOOL bindhubState; //控制是否重试绑定hub

/**
 * 读取当前的本地的hub列表
 */
+ (NSArray *)getHubList;

/**
 * 根据hub_id获取本地hub信息
 */
+ (OctopusHub *)getHubInfoWithId:(NSString *)hub_id;

/**
 * 根据mac获取本地hub信息
 */
+ (OctopusHub *)getHubInfoWithMac:(NSString *)mac;

/**
 * 扫描hub
 * UI在调用前判断是不是wifi模式，如果不是命令是不会被执行的
 */
+ (BOOL)startScanHub;

/**
 * 判断是否有hub
 */
+ (BOOL)hasHub;

//判断是否有支持当前连接类型的hub
+ (BOOL)hasHub:(NSString *)connectType;

/**
 * 绑定hub
 */
- (void)bindHub:(NSString*)hubVendor
         hubMac:(NSString *)macAddr
        hubName:(NSString*)name
completionHandler:(ResultBlock)resultBlock;

/**
 * 根据hub id查询对应hub信息
 */
- (void)getHubWithId:(NSString*)hubId resultBlock:(ResultBlock)resultBlock;

/*
 * 时间戳归零，根据hub id查询对应hub信息
 */
- (void)getNewHubWithId:(NSString*)hubId resultBlock:(ResultBlock)resultBlock;

/**
 * 解除hub绑定
 */
- (void)unbindHub:(NSString *)hubId completionHandler:(ResultBlock)resultBlock;

/**
 * 更新hub列表
 */
- (void)updateHubList:(ResultBlock)resultBlock;


/** 
 * 修改hub信息接口暂时没实现
 */
- (void)setHubWithId:(NSString *)hubId hub_info:(NSString *)hub_info hub_name:(NSString *)hub_name room_id:(NSString *)room_id hoom_id:(NSString *)hoom_id resultBlock:(ResultBlock)resultBlock;

/**
 * 获取hub的在线状态
 */
- (void)getHubStatus:(ResultBlock)resultBlock;

/**
 获取处于小循环状态的hubs的id和ip,返回数组由OctopusHub组成
 */
+ (NSArray *)getHubsIDAndIP;

/** 异步获取处于小循环状态的hubs的id和ip,返回数组由OctopusHub组成 */
- (void)getAsyHubsIDAndIP:(GetHubIPCompletionHandler)handler;

/** 亚马逊异步获取处于小循环状态的hubs的id和ip,返回数组由OctopusHub组成 */
- (void)getAmazonAsyHubsIDAndIP:(GetHubIPCompletionHandler)handler;

/**
 * 检测当前版本是不是最新
 * @return version:版本号；如果state为yes, code为0,说明当前版本不是最新,再取version；如果state为yes,code为304，说明当前版本是最新,此时version为空
 */
- (void)checkHubVersion:(NSString *)hubid resultBlock:(void(^)(BOOL state, NSInteger code, NSString *version))resultBlock;

/**
 * 设置hub升级模式
 * @param mode: 升级模式，1为自动升级，0为手动升级
 * @return code: 为42004说明hubid不存在
 */
- (void)setHubUpdateMode:(NSString *)hub_id mode:(NSString *)mode completionHandler:(ResultBlock)resultBlock;

/**
 * 设置hub升级
 * @param status: 升级与否，1为升级，0为不升级
 * @return code: 为42004说明hubid不存在
 */
- (void)setHubUpdate:(NSString *)hub_id status:(NSString *)status completionHandler:(ResultBlock)resultBlock;

/**
 * 比较设备的ssid等信息和手机当前wifi的信息是不是一致
 */
- (void)compareSSID:(NSString *)gadgetetID resultBlock:(ResultBlock)resultBlock;

/**
 * softap
 * @param pwd: ssid对应的密码
 * @param utc: 手机客户端的UTC时间
 * @return time_zone: 手机客户端的时区
 */
- (void)softAPNew:(NSString *)ssid pwd:(NSString *)pwd uri:(NSString *)uri localserver:(NSString *)localserver serverlevel:(NSString *)serverlevel pre_code:(NSString *)pre_code utc:(NSString *)utc time_zone:(NSString *)time_zone resultBlock:(void(^)(BOOL state, NSInteger code, NSString *hubtype, NSString *macaddr, NSString *localserver,NSString *serverlevel,NSString *version, NSString *code_challenge))resultBlock;

/**
 * 存储ssid和pwd到本地
 */
- (BOOL)saveSSIDInfo:(NSString *)ssid pwd:(NSString *)pwd;

/**
 * 从本地获取ssid和pwd
 * @return 如果从本地获取失败，则state为NO
 */
- (void)getSSIDInfo:(void(^)(BOOL state, NSString *ssid, NSString *pwd))resultBlock;

/*
 * 判断是否为5g wifi,
 * @return 暂时写死为NO
 */
- (BOOL)wifi5gState;

/**
 * @param gadget_type_id:必传
 * @param model:不必传
 * @return version:版本号
 */
- (void)checkAircleanerVersion:(NSString *)model gadget_type_id:(NSString *)gadget_type_id resultBlock:(void (^)(BOOL state, NSInteger code, NSString *version, NSString *os_version, NSString *image_version))resultBlock;

@end
