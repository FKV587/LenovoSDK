//
//  ShoppingProtocol.h
//  libiot
//
//  Created by leno on 2017/10/25.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ShoppingProtocol : NSObject

@property (nonatomic ,assign) NSInteger code; //404表示没有更新的数据

@property (nonatomic ,strong) NSString *data_ver;

@property (nonatomic ,strong) NSString *protocol_ver;

@property (nonatomic ,strong) NSString *start_time;

@property (nonatomic ,strong) NSString *end_time;

@property (nonatomic ,strong) NSArray *urlArray; //由ShoppingProtocolUrl组成的数组

@property (nonatomic ,strong) NSString *userid;//目前暂不区分userid


@end


@interface ShoppingProtocolUrl : NSObject

@property (nonatomic ,strong) NSString *imgUrl;//图片url

@property (nonatomic ,strong) NSString *clickUrl;//点击跳转url

@property (nonatomic ,strong) NSString *open; //h5/browse

@property (nonatomic ,strong) NSString *auth; //Y/N

@property (nonatomic ,strong) NSString *realm; //Y/N

@end
