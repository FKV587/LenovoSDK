//
//  WebsocketRequest.h
//  libiot
//
//  Created by guangchaopeng on 16/1/20.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

/** 回复的block */
typedef void(^CallBackHandler)(NSDictionary *resultDic);

@interface WebsocketRequest : NSObject

@property (nonatomic ,strong) NSString *requestBody; //发送的数据
@property (nonatomic ,assign) BOOL isNeedAck;  //是否需要回复，默认为NO，需要回复时必传YES
@property (nonatomic ,assign) NSTimeInterval timeOut; //超时时间，默认30s
@property (nonatomic ,copy) CallBackHandler callBackHandler;

//对应的请求的sequenceid 生成，具体算法根据云端需求
+ (NSString *)getSequenceId;
+ (NSString *)getVersionValue;
 
/** 拼接数据，目前适用于service相关 */
- (NSString *)getRequestBodyWithType:(NSString *)msg_type ns:(NSString *)ns sequence:(NSString *)sequence qos:(NSInteger)qos version:(NSString *)version requestDic:(NSDictionary *)requestDic;

//发送请求
- (void)sendReuqest;

@end
