/*
 Copyright (C) 2015 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Basic demonstration of how to use the SystemConfiguration Reachablity APIs.
 */

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <netinet/in.h>

typedef enum : NSInteger {
	NotReachable = 0,
	ReachableViaWiFi,
	ReachableViaWWAN,//移动数据，包括2G,3G,4G
    ReachableVia2G,
    ReachableVia3G,
    ReachableVia4G
    
} NetworkStatus;

/**
 kReachabilityChangedNotification：监听网络状态变化的通知名称
 只能用Reachability的全局的实例变量调用startNotifier方法开始通知。例如：
 
    //添加通知,当监测到网络状态发生变化时，会调用reachabilityChanged:方法
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(reachabilityChanged:) name:kReachabilityChangedNotification object:nil];
 
    //新建Reachability的全局的实例变量
    self.internetReachability = [Reachability reachabilityForInternetConnection];
    //用全局的实例变量调用startNotifier方法，开始通知
    [self.internetReachability startNotifier];
 
 */
extern NSString *kReachabilityChangedNotification_le;


@interface Reachability : NSObject

/*!
 * Use to check the reachability of a given host name.
 */
+ (instancetype)reachabilityWithHostName:(NSString *)hostName;

/*!
 * Use to check the reachability of a given IP address.
 */
+ (instancetype)reachabilityWithAddress:(const struct sockaddr *)hostAddress;

/*!
 * Checks whether the default route is available. Should be used by applications that do not connect to a particular host.
 */
+ (instancetype)reachabilityForInternetConnection;

/*!
 * Checks whether a local WiFi connection is available.
 */
//+ (instancetype)reachabilityForLocalWiFi;

/*!
 * Start listening for reachability notifications on the current run loop.
 */
- (BOOL)startNotifier;
- (void)stopNotifier;

/**
 目前返回NotReachable，ReachableViaWiFi，ReachableVia2G，ReachableVia3G，ReachableVia4G 这5种状态之一。如果不需要区分2g,3g,4g,请不要用这个方法，请用currentReachabilityStatus_WWAN
 */
- (NetworkStatus)currentReachabilityStatus;

/*!
 * WWAN may be available, but not active until a connection has been established. WiFi may require a connection for VPN on Demand.
 */
- (BOOL)connectionRequired;

/**
 add,检测网络状态; 返回YES,则网络正常
 */
+ (BOOL)internetConnectionStatus;

/**
 add,判断网络状态，不区分2g，3g, 4g。 返回NotReachable，ReachableViaWiFi，ReachableViaWWAN 三种状态之一。如果不需要区分2g,3g,4g，请用这个方法
 */
- (NetworkStatus)currentReachabilityStatus_WWAN;

@end


