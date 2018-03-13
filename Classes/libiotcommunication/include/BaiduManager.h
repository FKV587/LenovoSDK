//
//  BaiduManager.h
//  libiot
//
//  Created by leno on 17/3/27.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^CompletionHandler)(BOOL state, NSArray *resultArray, NSInteger code ,NSError *error);

@interface BaiduInfo : NSObject

@property (nonatomic ,copy) NSString *dumi_token;
@property (nonatomic ,strong) NSArray *device_idArr; //由device_id组成的数组
@property (nonatomic ,copy) NSString *expires_in;
@property (nonatomic ,copy) NSString *access_token;
@property (nonatomic ,copy) NSString *baidu_id;

@end

@interface BaiduManager : NSObject

@property (nonatomic ,copy) CompletionHandler completionHandler;

/**
 * 获取百度账号信息
 * @param userid: 传nil表示获取本人当前账号下的百度账号信息
 * @return resultArray: 由BaiduInfo组成的数组
 */
- (void)getBaiduAccountInfoWithUserid:(NSString *)userid completionHandler:(CompletionHandler)completionHandler;

/**
 * 获取百度帐号信息，目前是从内存获取
 * @return 由BaiduInfo组成的数组
 */
+ (NSArray *)getBaiduInfos;

@end
