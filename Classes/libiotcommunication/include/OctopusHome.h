//
//  OctopusHome.h
//  libiot
//
//  Created by pennycharles on 15/4/21.
//  Copyright (c) 2015年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Gadget;

@class OctopusRoom;

//@protocol OctopusHomeDelegate <NSObject>
//- (void)homeDidUpdateName:(OctopusHome *)home;
//- (void)didAddGadget:(OctopusHome *)home  gadget:(Gadget *)gadget;
//- (void)didRemoveGadget:(OctopusHome *)home  gadget:(Gadget *)gadget;
//- (void)didAddRoom:(OctopusHome *)home room:(OctopusRoom*) room;
//- (void)didRemoveRoom:(OctopusHome *)home room:(OctopusRoom*) room;
//@end


@interface OctopusHome : NSObject<NSCopying>
//名字属性，只读，能通过update接口来更新，
@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *homeId;
//@property(readonly, copy, nonatomic) NSArray *gadgets;
//@property(nonatomic, strong) NSMutableArray *rooms;
//当home的状态发生变化时应该及时通知其他模块
//@property(weak, nonatomic) id<OctopusHomeDelegate > delegate;
//
////修改家的名字，error为nil则修改成功，否则是失败
//- (void)updateName:(NSString *)name  completionHandler:(void (^)(NSError *error))completion;
////添加一个gadget到home，此gadget并没有指定房间 error为nil添加成功，否则失败
//- (void)addGadget:(Gadget*)gadget completionHandler:(void (^)(NSError *error))completion;
////添加一个gadget到home中指定的房间，error为nil添加成功，否则失败
//- (void)assignGadget:(Gadget*)gadget toRoom:(OctopusRoom *)room completionHandler:(void (^)(NSError *error))completion;
////删除一个gadget
//- (void)removeGadget:(Gadget*)gadget  completionHandler:(void (^)(NSError *error))completion;
////添加一个room
//- (void)addRoomWithName:(NSString *)roomName completionHandler:(void (^)(OctopusRoom *room,
//                                                                        NSError *error))completion;
////删除一个房间
//- (void)removeRoom:(OctopusRoom *)room completionHandler:(void (^)(NSError *error))completion;

@end

