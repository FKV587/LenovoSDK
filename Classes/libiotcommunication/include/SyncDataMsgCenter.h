//
//  SynDataCenter.h
//  aa
//
//  Created by pennycharles on 15/5/21.
//  Copyright (c) 2015年 lipeng. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum DataType:NSInteger{
    HUB,
    GADGET,
    RULE,
    HOME,
    ROOM,
    TIME
    
}SyncDataType;


@protocol SyncDataObserver <NSObject>
-(void)syncData:(SyncDataType)data_type object:(NSDictionary*)request;
@end


@interface SyncDataMsgCenter : NSObject
@property (nonatomic, strong) NSMutableSet *observerCollection;
+(SyncDataMsgCenter*) shareSyncDataMsgCenter;
-(void)addSyncDataMsgListener:(id)listener;
-(void)removeSyncDataMsgListener:(id)listener;
-(void)processSyncData:(NSDictionary*)data;
-(void)onNewGadget:(NSDictionary*)data;
-(void)onResetGadget:(NSDictionary*)data;
//更新gadget属性
- (void)updateAttr:(NSDictionary *)notifiDic;

- (void)executeGadgetAction:(NSDictionary *)requestDic;

- (void)acceptByShareCode:(NSDictionary *)dic;
- (void)deleteShareMember:(NSDictionary *)dic;
- (void)memberQuitShare:(NSDictionary *)dic;
- (void)deleteShareMembers:(NSDictionary *)dic;

@end
