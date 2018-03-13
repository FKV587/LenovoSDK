//
//  HccOrderManager.h
//  libiot
//
//  Created by leno on 17/5/11.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ShoppingInfoHcc : NSObject

@property (nonatomic ,strong) NSString *product_id;

@property (nonatomic ,strong) NSString *image_url;

@property (nonatomic ,strong) NSString *lager_image_url;

@property (nonatomic ,strong) NSString *product_name;

@property (nonatomic ,strong) NSString *price;

@property (nonatomic ,assign) NSInteger number;

@end


@interface AddressInfoHcc : NSObject

@property (nonatomic ,strong) NSString *receiver;

@property (nonatomic ,strong) NSString *phone;

@property (nonatomic ,strong) NSString *address;

@property (nonatomic ,strong) NSString *email;//邮箱

@property (nonatomic ,strong) NSString *postcode;//邮编

@end

@interface DeliveryInfoHcc : NSObject

@property (nonatomic ,strong) NSString *deliver_time;

@property (nonatomic ,strong) NSString *deliver_fee;

@property (nonatomic ,strong) NSString *deliver_distance;

@property (nonatomic ,strong) NSString *delivery_name;

@property (nonatomic ,strong) NSString *delivery_mobile;

@property (nonatomic ,strong) NSString *delivery_company;

@property (nonatomic ,strong) NSString *waywill_number;


@end


@interface HccOrder : NSObject

@property (nonatomic ,strong) NSString *order_id;

@property (nonatomic ,strong) NSArray *shopping_list; //由ShoppingInfo组成的数组

@property (nonatomic ,strong) AddressInfoHcc *user_address; //由AddressInfo组成的数组

@property (nonatomic ,strong) DeliveryInfoHcc *delivery_info; //由DeliveryInfo组成的数组

@property (nonatomic ,assign) NSInteger order_status;

@property (nonatomic ,strong) NSString *sum_price;

@property (nonatomic ,strong) NSString *discount;

@property (nonatomic ,strong) NSString *vat_fee;

@property (nonatomic ,assign) NSInteger timestamp;

@end

typedef void(^HccOrderCompletionHandler)(BOOL state, NSObject *order, NSInteger code ,NSError *error);

@interface HccOrderManager : NSObject

@property (nonatomic ,copy) HccOrderCompletionHandler completionHandler;

/**
 * hcc上传订单
 * @param verdor: @"youfu"或者@"kite",必传
 * @param orderId:订单id，必传
 * @return 返回数组为nil
 */
- (void)uploadOrder:(NSString *)vendor orderId:(NSString *)orderId completionHandler:(HccOrderCompletionHandler)completionHandler;

/**
 * 查询订单列表
 * @param verdor: @"youfu"或者@"kite",必传
 * @param ts:时间戳，第一页时间戳传0，从第二页开始把上一页最后的一条时间戳上传上来
 * @return 返回数组由HccOrder组成
 */
- (void)queryOrder:(NSString *)vendor ts:(NSInteger)ts completionHandler:(HccOrderCompletionHandler)completionHandler;

@end
