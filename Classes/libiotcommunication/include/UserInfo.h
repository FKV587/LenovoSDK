//
//  UserInfo.h
//  libiot
//
//  Created by guangchaopeng on 15/12/28.
//  Copyright © 2015年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserInfo : NSObject
-(UserInfo*)initWithUserKeyAndId:(NSString*)userKey ID:(NSString*)userId;
@property (nonatomic,assign)  int weight;
@property (nonatomic,retain,readonly)  NSString* userKey;
@property (nonatomic,retain,readonly)  NSString* userId;
@property (nonatomic,assign)  BOOL pushMsgFlag;
@property (nonatomic, strong) NSString* apnsToken;
@property (nonatomic ,strong) NSString *locale;
@property (nonatomic ,strong) NSString *user_info;
@property (nonatomic ,strong) NSString *nick_name;
@property (nonatomic ,strong) NSString *img_url;
@property (nonatomic ,strong) NSString *user_name;

@end
