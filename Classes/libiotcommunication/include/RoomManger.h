//
//  RoomManger.h
//  libiot
//
//  Created by guangchaopeng on 15/12/29.
//  Copyright © 2015年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ResultBlock)(BOOL state, NSInteger code);

//@protocol RoomDelegate
//-(void)roomUpdateNotify;
//@end
//@class Room;
@class  OctopusRoom;
@interface RoomManger : NSObject

@property (nonatomic ,copy) ResultBlock resultBlock;

/**
 * 获取所有的房间列表
 */
+ (NSArray *)getRoomList;

/**
 * 根据roomId获取一个房间对象
 */
+ (OctopusRoom *)getRoomWithId:(NSString*)roomId;

/**
 * 获取本地某个home下的房间列表
 */
+ (NSArray *)getRoomsWithHomeid:(NSString *)home_id;

/** 
 * 添加一个room
 */
- (void)addRoomWithName:(NSString *)room_name home_id:(NSString *)home_id resultBlock:(ResultBlock)block;

/**
 * 删除房间
 */
- (void)deleteRoom:(NSString*)room_id resultBlock:(ResultBlock)block;

/**
 * 修改房间信息
 */
- (void)modifyRoomName:(NSString*)room_id room_name:(NSString*)room_name home_id:(NSString *)home_id resultBlock:(ResultBlock)block;

//此接口废弃
////获取房间列表
//- (void)getRoomList:(ResultBlock)block;

/**
 * 查询home,room
 * 此接口和HomeManager里的updateHomeAndRoomList:是完全一样的
 */
- (void)updateHomeAndRoomList:(ResultBlock)block;

@end
