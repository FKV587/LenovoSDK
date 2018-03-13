//
//  ResourceManager.h
//  libiot
//
//  Created by pennycharles on 16/3/1.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClientUpdateInfo.h"

#import "ChoicenessItem.h"

#import "PlugModel.h"

@class ShoppingProtocol;

typedef void(^ResultBlock)(BOOL state, NSInteger code);

/**  获取意见回调block */
typedef void(^GetFeedBlock)(BOOL state, NSInteger code, NSArray *feedList);

typedef void(^AppVersionCheckBlock)(BOOL state, ClientUpdateInfo *info);

@class Weather;

/** 广告等接口 */
@interface ResourceManager : NSObject

@property (nonatomic ,copy) ResultBlock resultBlock;

@property (nonatomic ,copy) GetFeedBlock getFeedBlock;

@property (nonatomic ,copy) AppVersionCheckBlock versionCheckBlock;

/** 从本地获取版本更新信息 */
+ (ClientUpdateInfo *)getUpdateInfo;

/**
 * 新 版本更新
 * @param currentVersion:当前版本号
 * @param timeout:超时时间
 */
- (void)appVersionCheck:(NSString *)currentVersion timeout:(int)timeout versionCheckHandler:(AppVersionCheckBlock)handler;

/**
 * 获取当前城市的天气，本地获取
 */
+ (Weather*)getCurrentWether;

/**
 * 请求当前城市的天气
 * @param longitude:经度
 * @param latitude:纬度
 * @param locale:多语言项，默认是zh
 * @param resultBlock:结果， 如果根据经纬度获取城市失败，则state为NO, code为-1
 */
- (void)requestCurrentWetherWithLongitude:(double)longitude latitude:(double)latitude locale:(NSString *)locale resultBlock:(ResultBlock)resultBlock;

/**
 * 请求广告页
 */
- (void)updateAdvertisingList:(ResultBlock)resultBlock;

/** 
 * 获取广告页数据，本地获取
 * @return 广告页数据，数据类型：数组， 数组的元素是AdvertisingModel
 */
+ (NSArray *)getAdvertisingList;

/**
 * 获取意见
 */
- (void)getFeedList:(GetFeedBlock)resultBlock;

/**
 * 提交意见
 * @param opinions:用户的意见
 * @param commit_items:用户选中的item
 */
- (void)sendFeedWithOpinions:(NSString *)opinions commit_items:(NSString *)commit_items resultBlock:(ResultBlock)block;

/**
 * 获取和云端的连接状态
 */
+ (BOOL)webSocketStatus;

/**
 * 将apnstoken发给云端
 */
+ (void)postApnsTokenToCloud:(NSString*)apnsToken;

/**
 * 删除token
 */
+ (void)delApnsToken;

/**
 * 上传PC二维码数据
 * @param send_code:扫描到的PC二维码字符串
 */
- (void)sendQRcode:(NSString *)send_code completionHandler:(void (^)(BOOL state, NSInteger code))handler;

/**
 * APP异常日志上传
 */
- (void)uploadAppEexception:(NSString *)message completionHandler:(void (^)(BOOL state, NSInteger code))handler;

/**
 * 查询shopping轮播图、精选、首页图片、shopping设备 url
 * @param type: shopping、chosen(精选)、first_page(首页)、shopping_device(设备)
 */
- (void)queryShoppingProtocol:(NSString *)data_ver protocol_ver:(NSString *)protocol_ver type:(NSString *)type handler:(void (^)(BOOL state, ShoppingProtocol *model, NSInteger code))handler;

/**
 * 根据type获取保存的相应的model
 */
+ (ShoppingProtocol *)getSavedShoppingImgUrl:(NSString *)type;

/**
 * 根据type移除保存的相应的model
 */
+ (BOOL)removeSavedShoppingImgUrl:(NSString *)type;

- (void)uploadAnalyticeDidFinishLaunching;

- (void)uploadAnalyticeBackground;

- (void)requestChoiceXmlyDataWithUserID:(NSString *)userid completionHandler:(void (^)(BOOL state, NSInteger code, ChoicenessItem *item))handler;

+ (ChoicenessItem *)getSavedChoicenessDataWithUserid:(NSString *)userid;

- (void)checkPlugInfo:(NSArray *)plugModels completionHandler:(void (^)(BOOL state, NSInteger code, NSArray *plugsResultArr))handler;

- (NSArray *)getSavedPlugModels;

/**
 * 获取空气质量
 @param start_time、end_time、interval单位为秒
 */
- (void)requestAirPM:(NSString *)start_time end_time:(NSString *)end_time interval:(NSString *)interval completionHandler:(void (^)(BOOL state, NSInteger code, NSArray *pmArr))handler;

@end
