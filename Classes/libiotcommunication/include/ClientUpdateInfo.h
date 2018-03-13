//
//  ClientUpdateInfo.h
//  libiot
//
//  Created by pennycharles on 16/5/5.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum{
    ISUPTODATE =0,
    NORMOLUPDATE=1,
    FORCEUPDATE=2,
} ClientUpdateType;
@interface ClientUpdateInfo : NSObject
@property(nonatomic,strong)NSString* theNewVersion;
@property(nonatomic,strong)NSString* theNewVersionUrl;
@property(nonatomic,strong)NSArray* updateReson;
@property(nonatomic,assign)ClientUpdateType updateType;

@end
