//
//  SpeakerSetManager.h
//  libiot
//
//  Created by leno on 16/7/15.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Gadget.h"

@interface SpeakerInfo : Gadget

@property (nonatomic ,strong) NSString *firmwareVersion; //固件版本
@property (nonatomic ,strong) NSString *sleep; //自动睡眠
@property (nonatomic ,strong) NSString *model;
@property (nonatomic ,strong) NSString *room;

@end

@interface SpeakerSetManager : NSObject

- (void)querySpeakerInfo:(void(^)(BOOL state, SpeakerInfo *info ,NSInteger code))handler;

@end
