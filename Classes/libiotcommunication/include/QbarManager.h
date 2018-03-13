//
//  QbarManager.h
//  QbarDemo
//
//  Created by leno on 2017/9/5.
//  Copyright © 2017年 leno. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//摄像头权限
typedef NS_ENUM(NSInteger, CaAuthorizationStatus) {
    CaAuthorizationStatusNotDetermined = 0, //未确定
    CaAuthorizationStatusRestricted, //受限
    CaAuthorizationStatusDenied, //拒绝
    CaAuthorizationStatusAuthorized //授权
};


@protocol QbarScanManagerDelegate <NSObject>

/**
 * 原生二维码扫描获取数据的回调方法,当AVFoundFlag 大于0时调用,在主线程回调
 */
- (void)qbarScanResultArr:(NSArray *)resultArr;

/**
 * 非原生二维码扫描获取数据的回调方法，,当AVFoundFlag 等于0时调用,在主线程回调
 */
- (void)qbarScanResultStr:(NSString *)resultStr;


@end

@interface QbarManager : NSObject

@property(nonatomic, assign) id<QbarScanManagerDelegate>delegate;

/**
 * 初始化
 * @param view 必传
 * @param scanRect 识别区域
 * @param avFoundFlag:是否采用cpu和内存占用低,但是扫描效率低的方法，为NO是不采用，否则采用， 默认为NO
 */
- (QbarManager *)initWithView:(UIView *)view scanRect:(CGRect)scanRect avFoundFlag:(BOOL)avFoundFlag;

/**
 * 初始化，全屏识别
 * @param view 必传
* @param avFoundFlag:是否采用cpu和内存占用低,但是扫描效率低的方法，为NO是不采用，否则采用， 默认为NO
 */
- (QbarManager *)initWithView:(UIView *)view avFoundFlag:(BOOL)avFoundFlag;

/**
 * 开始扫码
 */
- (void)start;

/**
 * 停止扫码
 */
- (void)stop;

/**
 * 打开关闭闪光灯
 * @param status YES:打开闪光灯,NO:关闭闪光灯
 */
- (void)openTorch:(BOOL)status;

/**
 * 判断摄像头权限
 */
- (CaAuthorizationStatus)getAVAuthorizationStatus;


@end
