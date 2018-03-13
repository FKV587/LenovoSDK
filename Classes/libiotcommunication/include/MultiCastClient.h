//
//  MultiCastClient.h
//  BroadCast
//
//  Created by pennycharles on 16/3/10.
//  Copyright © 2016年 lenovo. All rights reserved.
//
/*****************************************************************************
 *  1,Client send multicast message:
 *      {
 *          "msg_type" :  0xe1
 *      }
 *  2,Client recv multicast ack
 *      {
 *          "msg_type" :  0xe1,
 *          "macadd"  : "aq:ee:ff:ff:ee:12",
 *          "hubstatus": 1      // 0:Hub正常工作, 1:Hub未绑定, 2: Hub状态未知
 *      }
 *  3,client send hubid to hub,
 *      {
 *          "msg_type" :  0xe2
 *          "hubid"     : "xxxxxxxxxxxxxxxxxxxx"
 *      }
 *  4,client recv ack of  item 3, 如果hubid和hub本身id一样，hub则通过udp告诉客户端websocket的ip和port
 *      {
 *          "msg_type" :    0xe2,
 *          "ipaddr"    :   "192.168.1.2",
 *          "port"      :   12345
 *      }
 *  5,client recv ack of item 3，否则通知匹配失败
 *      {
 *          "msg_type" :    0xe3
 *      }
 *
 *注意：在3，4，5中一定要用单播，不能用广播，否则如果任意一个用户hubid正确，所有的用户都能收到websocket的
 *端口号和ip地址
 *
 * ***************************************************************************/
#import <Foundation/Foundation.h>

typedef void(^StopBlock)();

typedef void(^ResponseBlock)(NSDictionary *responseObj, BOOL state);

typedef enum{
    MAC = 0xe1,
    ADDR = 0xe2,
    ERROR = 0xe3
}MSGTYPE;

typedef enum {
    NORMAL = 0,
    UNBINDED = 1,
    UNKNOW = 2,
}HUBSTATUS;

@interface MultiCastClient : NSObject
@property (assign ,readonly) BOOL isRunning;
@property (nonatomic ,copy) StopBlock stopBlock;
@property (nonatomic ,assign) BOOL isAmazon;
@property (nonatomic ,copy) NSString *hubid;
@property (nonatomic ,assign) BOOL isStop;

//必须是单例，否则同时端口会绑定失败
+(MultiCastClient*)sharedInstance;
- (void)initSocket;
- (BOOL)start;
- (void)stop;

- (void)stopNoBlock;

/**
 * 开始扫描，扫描到所需的设备之后，需要调用stop方法
 * @return responseObj: 扫描到的数据
 */
- (void)scanWithResponse:(ResponseBlock)response;

@end
