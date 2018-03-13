//
//  AutoLinkManager.h
//  AutoLinkManager
//
//  Created by MPK on 15/11/25.
//  Copyright © 2015年 MPK. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AutoLinkDelegate <NSObject>

@required
//status -1:failed
//      >=0:repeat times
-(void)currentStatus:(int)statuss;
//macArray: device mac array.
-(void)finishResult:(NSDictionary*)macDic;

@optional
//deviceIpArray:deviceIp array
- (void)finishGetIPResult:(NSDictionary *)ipDic;

@end

@interface AutoLinkManager : NSObject

@property(nonatomic,assign) id <AutoLinkDelegate> delegate;
//====================================
//func:    startAutoLink
//input:
//    1. ssid: ssid of wifi
//    2. pwd:  password of wifi
//output:  instance of AutoLinkManger
//desc:    init the instance of AutoLinkManager
//====================================
- (id)initWithSsid:(NSString *)ssid Passwd:(NSString *)pwd delegate:(id)delegate;
//====================================
//func:    startAutoLink
//input:   void
//output:  int, 0 success, -1 failed
//desc:    start auto link function,
//
//====================================
- (int)startAutoLink;
//====================================
//func:    stopAutoLink
//input:   void
//output:  void
//desc:    stop autolink function if started
//====================================
- (void)stopAutoLink;

//====================================
//func:    setAutoLinkCmdInterval
//input:   int interval in millisecond,default is 10ms
//output:  void
//desc:    set the interval of cmds
//====================================
- (void)setAutoLinkCmdInterval:(double)interval;
//====================================
//func:    setAutoLinkTimeout
//input:   int timeout in second, default is 30s
//output:  void
//desc:    set the timeout that send cmds
//         to device
//====================================
- (void)setAutoLinkTimeout:(int)timeout;


/** 获取当前手机ip以及判断当前手机ip状态 */
+ (BOOL)ipStatus;



@end
