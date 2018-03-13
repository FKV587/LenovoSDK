//
//  UserManger.h
//  libiot
//
//  Created by pennycharles on 15/4/20.
//  Copyright (c) 2015年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>


@class UserInfo;
@class ClientUpdateInfo;
typedef void (^userInfoCallback)(UserInfo* userInfo);

extern NSString* const userLanguagePrefer;
//typedef void (^loginResult)(BOOL result ,int code);
//需要增加账户信息修改通知？
@interface AccountManger : NSObject

//@property(nonatomic,copy)  _theResult;

+(AccountManger*) shareAccountManger;
-(void)appVersionCheck:(NSString*)currentVersion callback:(void (^)(BOOL state,ClientUpdateInfo* info))result;

/**
 *退出登录
 **/
-(void)logOut;

- (int) logIn:(NSString *)lenovoId callback:(void (^)(BOOL result ,NSInteger code))blk;
/**
 *判断之前是否已经登录过，如果已经登录过就进行自动登录，不需要调用登录接口。
 **/
-(BOOL)isUserLogIn;

/*
 获取用户个人信息，本地获取
 */
-(void)getUserInfo:(userInfoCallback)blk;

/**
 * 在线获取个人信息
 */
- (void)queryUserInfo:(void (^)(BOOL state, NSInteger code))resultBlock;


- (NSString*)userKey;

- (NSString *)getUserID;

/**
 * 修改用户信息接口，userid必传，user_info暂定必传，其他可传可不传
 */
- (void)modifyUserInfoWithId:(NSString *)userid user_info:(NSString *)user_info push_msg_flag:(NSString *)push_msg_flag locale:(NSString *)locale nick_name:(NSString *)nick_name img_url:(NSString *)img_url resultBlock:(void(^)(BOOL state, NSInteger code))resultBlock;

/***
 自动登录接口:用户上次已经登录了并且没有退出登录，我们不需要用户再输入账号和密码了，自动登录
 */
-(void) autoLogIn:(void(^)(BOOL loginState, NSString *errorCodeStr))loginResult;

/**
 新登录接口,根据token登录
 @param st: 根据登录SDK，登录成功后获取到的st
 @param loginResult: block，包含登录的状态，错误码. 默认在主线程执行
 */
- (void)loginWithSt:(NSString *)st loginResultBlock:(void(^)(BOOL loginState, NSString *errorCodeStr))loginResult;

/**
 新登录接口,根据lenovoid登录
 @param lenovoID: 根据登录SDK，登录成功后获取到的lenovoid
 @param st: token
 @param userName: 用户名
 @param loginResult: block，包含登录的状态，错误码. 默认在主线程执行
 */
- (void)loginWithLenovoID:(NSString *)lenovoID st:(NSString *)st userName:(NSString *)userName resultBlock:(void (^)(BOOL loginState, NSString *errorCodeStr))loginResult;

/**
 登录接口
 @param name:用户名
 @param psw:密码
 @param loginResult: block，包含登录的状态，错误码. 默认在主线程执行
 */
- (void)loginWithName:(NSString *)name psw:(NSString *)psw loginResultBlock:(void(^)(BOOL loginState, NSString *errorCodeStr))loginResult;

/**
 获取图片验证码接口
 @param imgData: block, 包含图片验证码数据. 默认在主线程执行
 */
- (void)getCaptchaImageData:(void(^)(NSData *imgData))imgData;

/**
 注册接口
 @param name:用户名
 @param psw:密码
 @param captcha:图片验证码
 @param registerResult: block, 包含注册的状态，错误信息. 默认在主线程执行
 */
- (void)registerWithName:(NSString *)name psw:(NSString *)psw captcha:(NSString *)captcha registerResultBlock:(void(^)(BOOL registerState, NSString *errorCodeStr))registerResult;

/**
 获取重置密码的验证码(verifyCode)接口
 @param name:用户名
 @param captcha:图片验证码
 @param resetPswInfo: block, 包含返回的状态，错误码. 默认在主线程执行
 */
- (void)getResetPswInfo:(NSString *)name captcha:(NSString *)captcha resetPswInfoBlock:(void(^)(BOOL resetInfoState, NSString *errorCodeStr))resetPswInfo;

/**
 重置密码接口
 @param name:用户名
 @param verifyCode:用户收到的验证码
 @param newPsw:新密码
 @param resetPswResult: block, 包含重置的状态，错误码. 默认在主线程执行
 */
- (void)resetPswWithName:(NSString *)name verifyCode:(NSString *)verifyCode newPsw:(NSString *)newPsw resetPswResultBlock:(void(^)(BOOL resetPswState, NSString *errorCodeStr))resetPswResult;

/**
 修改密码接口
 @param oldPsw:旧密码
 @param newPsw:新密码
 @param modifyPswResultBlock: block, 包含修改的状态，错误码. 默认在主线程执行
 */
- (void)modifyPswWithOldPsw:(NSString *)oldPsw newPsw:(NSString *)newPsw modifyPswResultBlock:(void(^)(BOOL modifyPswState, NSString *errorCodeStr))modifyPswResult;

/**
 注册并自动登录接口
 @param name:用户名
 @param psw:密码
 @param captcha:图片验证码
 @param timeoutInterval:包括注册和登录的超时间隔
 @param registerResult: isLogin-->标识返回结果是否为登录,如果是YES，则为登录, 否则为注册结果(注册目前只有失败时才会回调). state-->登录或注册的结果,成功为YES,失败为NO. errorCodeStr-->失败时的错误码.   默认在主线程执行
 */
- (void)registerAndLoginWithName:(NSString *)name psw:(NSString *)psw captcha:(NSString *)captcha timeoutInterval:(double)timeoutInterval registerOrLoginResult:(void (^)(BOOL isLogin, BOOL state, NSString *errorCodeStr))registerOrLoginResult;

/*获取用户当前的语言设置，zh 中文，en英语*/
-(NSString*)getLanguagePrefer;


@end
