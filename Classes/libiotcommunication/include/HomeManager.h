//
//  HomeManager.h
//  libiot
//
//  Created by pennycharles on 15/4/21.
//  Copyright (c) 2015年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ResultBlock)(BOOL state, NSInteger code);

//@class OctopusHome;

@interface HomeManager : NSObject

//@property(readonly,copy,nonatomic) OctopusHome* primaryHome;

@property (nonatomic ,copy) ResultBlock resultBlock;

/**
 * 获取所有的家庭列表,本地获取
 */
+ (NSArray *)getHomeList;

/**
 * 创建home
 */
- (void)addHomeWithName:(NSString *)homeName resultBlock:(ResultBlock)block;

/**
 * 修改home
 */
- (void)modifyHomeWithHomeid:(NSString *)home_id home_name:(NSString *)home_name resultBlock:(ResultBlock)block;

/** 
 * 删除home
 */
- (void)deleteHomeWithHomeid:(NSString *)home_id resultBlock:(ResultBlock)block;

//此接口废弃
////查询home
//- (void)queryHome:(ResultBlock)block;

/**
 * 查询home,room
 */
- (void)updateHomeAndRoomList:(ResultBlock)block;

@end
