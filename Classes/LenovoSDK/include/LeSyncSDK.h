//
//  LeSyncSDK.h
//  LeSyncSDK
//
//  Created by winter on 16/3/28.
//  Copyright © 2016年 winter. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^infoBlock)(BOOL isLogin,NSString *st,NSString *userID);
typedef void(^bindInfo)(BOOL isBind,NSString *assistAccount);
typedef void(^userInfo)(NSDictionary *userInfo);
@protocol LenovoIDDelegate <NSObject>

@optional

- (void)didFinishLoginWithLoginStatus:(BOOL)isLogin;

@end

@interface LeSyncSDK : NSObject

@property (nonatomic, copy) infoBlock infoBlock;
@property (nonatomic, copy) bindInfo bindInfo;

@property (nonatomic, weak) id<LenovoIDDelegate> delegate ;
/**
 *  创建实例
 */
+ (instancetype)shareInstance;

/**
 *  初始化
 *
 *  @param realm app的唯一标示（授权令牌）
 */
- (void)LenovoSDKApiInit:(NSString *)realm;

/**
 *  获取登录状态方法，加载登陆界面
 *
 *  @return 登录界面Controller
 */
+ (void)LenovoSDKloginWithRootViewController:(UIViewController *)viewController;

/**
 *  获取登录状态，手机短信快速登录页面
 *
 *  @param viewController 登录界面Controller
 */
+ (void)LenovoSDKLoginBySMSWithViewController:(UIViewController *)viewController;

/**
 *  获取LenovoST
 */
- (void)obtainLenovoSDKStData:(infoBlock)infoBlock;

/**
 *  获取登陆状态
 *
 *  @return YES 已登录  NO未登录
 */
- (BOOL)obtainLenovoSDKLoginStatus;

/**
 *  获取登陆名
 *
 *  @return 登陆帐号名
 */
- (NSString *)obtainLenovoSDKUserName;

/**
 *  用户登出
 */
- (void)LenovoSDKLogout;

/**
 *  设置
 */
+ (void)showLenovoSDKAccountWithRootViewController:(UIViewController *)viewController;

/**
 *  绑定邮箱、手机号
 *
 *  @param viewController 未绑定时加载的页面
 *  @param info           如果绑定返回相应信息（辅助帐号，是否绑定）
 */
- (void)isBindAssistAccountWithViewController:(UIViewController *)viewController info:(bindInfo)info;

/**
 *  当前账号是否绑定了邮箱或手机号
 *
 *  warning:此接口需账号登录成功可用
 *  @param info           如果绑定返回相应信息（辅助帐号，是否绑定）
 *  @param reason         返回请求失败结果
 */
- (void)isBindAccount:(bindInfo)info fail:(void(^)(NSString *reason))reason;

/**
 *  发送绑定账号短信或邮件
 *
 *  @param accountName 设置的绑定邮箱或手机号
 *  @param result  返回发送结果
 */
- (void)sendBindingMessageWithBindingName:(NSString *)bindingName result:(void(^)(NSString *result))result;

/**
 *  解除绑定账号
 *
 *  @param bindingName 已绑定账号
 *  @param result      解除绑定结果
 */
- (void)removeBindingWithBindingName:(NSString *)bindingName result:(void(^)(NSString *result))result;

/**
 *  验证码验证绑定账号
 *
 *  @param message     验证码
 *  @param bindingName 绑定账号
 *  @param result      绑定结果
 */
- (void)verifyBindingMessageWithMessage:(NSString *)message bindingName:(NSString *)bindingName result:(void(^)(NSString *result))result;


/**
 *  获取用户个人信息
 *
 *  @param userInfo 用户信息回调
 */
- (void)obtainLenovoUserInfo:(userInfo)userInfo;


@end

