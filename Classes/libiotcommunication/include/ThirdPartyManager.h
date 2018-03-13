//
//  ThirdPartyManager.h
//  libiot
//
//  Created by leno on 16/7/8.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger ,CloudType){
    CloudTypeSamsung = 0,  //三星
    CloudTypeHaier, //海尔
    CloudTypeXiMaLaYa //喜马拉雅
};

@interface ThirtyParty : NSObject

@property (nonatomic ,assign) CloudType cloudType;

/**
 喜马拉雅用户信息
 key:  avatar_url(头像url); nickname(昵称)
 */
@property (nonatomic ,strong) NSDictionary *extDic;

@end

typedef void(^ThirdPartyResultBlock)(BOOL state, id model , NSInteger code);

@interface ThirdPartyManager : NSObject

@property (nonatomic ,copy) ThirdPartyResultBlock resultBlock;

/** 
 * 三星绑定
 * @param lenovo_user_id:lenovo的userid,默认传nil即可,内部实现会进行判断
 * @param thirdparty_user_id: 三方的user_id
 *
 */
- (void)bindingThirdParty:(NSString *)lenovo_user_id thirdparty_user_id:(NSString *)thirdparty_user_id access_token:(NSString *)access_token token_type:(NSString *)token_type refresh_token:(NSString *)refresh_token expand:(id)expand resultBlock:(ThirdPartyResultBlock)block;

/**
 * 三星解绑
 * @param lenovo_user_id:lenovo的userid,默认传nil即可,内部实现会进行判断
 * @param thirdparty_user_id: 三方的user_id
 *
 */
- (void)unbindingThirdParty:(NSString *)lenovo_user_id thirdparty_user_id:(NSString *)thirdparty_user_id access_token:(NSString *)access_token token_type:(NSString *)token_type refresh_token:(NSString *)refresh_token expand:(id)expand resultBlock:(ThirdPartyResultBlock)block;

/** 
 * 根据第三方绑定
 * @param cloudType: 第三方类型，枚举
 * @param lenovo_user_id:lenovo的userid,默认传nil即可,内部实现会进行判断
 * @param thirdparty_user_id: 三方的user_id
 */
- (void)bindingThirdPartyWithType:(CloudType)cloudType lenovo_user_id:(NSString *)lenovo_user_id thirdparty_user_id:(NSString *)thirdparty_user_id access_token:(NSString *)access_token token_type:(NSString *)token_type refresh_token:(NSString *)refresh_token expand:(id)expand resultBlock:(ThirdPartyResultBlock)block;

/**
 * 根据第三方解绑
 * @param cloudType: 第三方类型，枚举
 * @param lenovo_user_id:lenovo的userid,默认传nil即可,内部实现会进行判断
 * @param thirdparty_user_id: 三方的user_id
 *
 */
- (void)unbindingThirdPartyWithType:(CloudType)cloudType lenovo_user_id:(NSString *)lenovo_user_id thirdparty_user_id:(NSString *)thirdparty_user_id access_token:(NSString *)access_token token_type:(NSString *)token_type refresh_token:(NSString *)refresh_token expand:(id)expand resultBlock:(ThirdPartyResultBlock)block;

/**
 * 获取已绑定三方用户列表
 * @param userid:传nil表示本人
 * @return cloudType: 第三方类型，枚举
 */
- (void)getBindedThirdParty:(NSString *)userid resultBlock:(void(^)(BOOL state,  NSArray *thirdPartys, NSInteger code))block;

/**
 * 登录第三方
 * @param lenovo_user_id:传nil表示本人的userid
 * @param vendor:海尔和三星目前可以传nil
 * @param loginId:第三方用户名
 * @param password:第三方密码
 * @param 保留字段，目前没有用到
 */
- (void)loginThirdPartyWithType:(CloudType)cloudType lenovo_user_id:(NSString *)lenovo_user_id vendor:(NSString *)vendor loginId:(NSString *)loginId password:(NSString *)password expand:(id)expand resultBlock:(ThirdPartyResultBlock)block;

@end
