//
//  HistoryRecord.h
//  libiot
//
//  Created by leno on 16/3/25.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HistoryRecord : NSObject

@property (nonatomic ,strong) NSString *source_id;
@property (nonatomic ,strong) NSString *source_type_id;
@property (nonatomic ,strong) NSString *source_name;
@property (nonatomic ,strong) NSString *event_type;
@property (nonatomic ,strong) NSArray *event_params;
@property (nonatomic ,strong) NSString *time;
@property (nonatomic ,strong) NSString *event_source_type; //gadget/rule/hub/cloud/user/push_message

@property (nonatomic ,strong) NSString *descriptionStr;

@property (nonatomic ,strong) NSString *valueStr;

@end
