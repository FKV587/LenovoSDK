//
//  UniversalManager.h
//  libiot
//
//  Created by leno on 2017/8/18.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UniversalManager : NSObject

/**
 * 查询用户感兴趣内容
 * @return interestArray:由字符串（兴趣）组的数组
 */
- (void)queryUserInterest:(void(^)(BOOL state, NSArray *interestArray, NSInteger code))result;

/**
 * 查询系统感兴趣内容
 * @return interestArray:由字符串（兴趣）组的数组
 */
- (void)queryDefaultInterest:(void(^)(BOOL state, NSArray *interestArray, NSInteger code))result;

/**
 * 设置用户感兴趣内容
 * @param interestArray:由字符串组成的数组,如["读书","健身","旅游"]
 */
- (void)setUserInterest:(NSArray *)interestArray result:(void (^)(BOOL, NSInteger))result;

@end
