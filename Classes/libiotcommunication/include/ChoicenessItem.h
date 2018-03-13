//
//  ChoicenessItem.h
//  libiot
//
//  Created by leno on 2017/12/11.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ChoicenessItem : NSObject

@property (nonatomic ,strong) NSArray *items;

@end


@interface Item:NSObject

@property (nonatomic ,strong) NSString *item_type;

@property (nonatomic ,strong) NSString *title;

@property (nonatomic ,strong) NSString *more_act_title;

@property (nonatomic ,strong) NSString *more_act_type;

/**
 * 如果该属性值不包含"|"，则会把原始字符串作为该属性值。如果该属性值包含"|"，会把"|"前面的部分作为该属性的值，同时,数据没问题的情况下会把"|"后面的部分解析为more_act_targetDic属性。
 */
@property (nonatomic ,strong) NSString *more_act_target;

@property (nonatomic ,strong) NSString *more_act_target_original;//从云端拿到的more_act_target未经处理的原始值

@property (nonatomic ,strong) NSDictionary *more_act_targetDic; //该属性可能为空,依赖more_act_target属性

@property (nonatomic ,strong) NSString *splite_line;

@property (nonatomic ,strong) NSArray *subItems;

//转化more_act_target字符串为字典
- (NSDictionary *)parserMoreacttargetWithStr:(NSString *)more_act_target;

@end


@interface SubItem:NSObject

@property (nonatomic ,strong) NSString *title;

@property (nonatomic ,strong) NSString *author;

@property (nonatomic ,assign) NSInteger play_times;

@property (nonatomic ,assign) NSInteger sets;

@property (nonatomic ,strong) NSString *small_image;

@property (nonatomic ,strong) NSString *middle_image;

@property (nonatomic ,strong) NSString *large_image;

@property (nonatomic ,strong) NSString *act_type;

@property (nonatomic ,strong) NSString *act_target;

@property (nonatomic ,strong) NSDictionary *target_param;


@end

