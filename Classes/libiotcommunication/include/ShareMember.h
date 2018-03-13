//
//  ShareMember.h
//  libiot
//
//  Created by leno on 16/4/7.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ShareMember : NSObject

@property (nonatomic ,strong) NSString *user_id;
@property (nonatomic ,strong) NSString *user_name;
@property (nonatomic ,strong) NSString *nick_name;
@property (nonatomic ,strong) NSString *img_url;
@property (nonatomic ,strong) NSString *member; //判断是否为管理员, 管理员为1.  普通成员为0

@end
