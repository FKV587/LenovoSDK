//
//  LePreferenceForUI.h
//  LeSyncSDK
//
//  Created by winter on 16/4/13.
//  Copyright © 2016年 winter. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,titleIndentifier){
    //设置
    SettingTitleIndentifier = 0,
    //登录
    LoginTitleIndentifier,
    //注册
    RegisterTitleIndentifier,
    //修改密码
    ModifyPasswordTitleIndentifier,
    //找回密码
    RetrievePasswordTitleIndentifier,
    //重置密码
    ResetPasswordTitleIndentifier,
};

@interface LePreferenceForUI : NSObject

@property (nonatomic, strong) UIColor *navigationColor;//导航栏文字颜色，默认black
@property (nonatomic, strong) UIFont *navigationFont;//导航栏字体大小，默认system20
@property (nonatomic, strong) UIColor *navigationBackgroundColor;//导航栏背景色
@property (nonatomic, strong) UIColor *backgroundColor;//背景色

+ (LePreferenceForUI *)singleton;

/**
 *  设置导航栏文字
 *
 *  @param title       导航栏文字
 *  @param indentifier SDK内的界面标示
 */
- (void)configNavigationTitle:(NSString *)title withIndentifier:(titleIndentifier)indentifier;


@end
