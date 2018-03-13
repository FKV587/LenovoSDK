//
//  Gadget.h
//  libiot
//
//  Created by pennycharles on 15/4/21.
//  Copyright (c) 2015年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum {
    MYOWN = 0, //自己的设备，而且没有分享
    FROMSHARED=1, //来自分享
    SHAREDTOOTHER = 2,//分享给别人
}MemberAttr;
@class GadgetTypeAction;
@interface Gadget : NSObject

@property (nonatomic,strong) NSString *client_data; //对应的插口设备
@property (nonatomic,strong) NSString *gadget_id; //设备的id，全网唯一
@property (nonatomic,strong) NSString *gadget_name; //设备名称，默认名称是什么？
@property (nonatomic,strong) NSString *gadget_type_id; //产品的类型id
@property (nonatomic,strong) NSString *gadget_classId;
@property (nonatomic,strong) NSString *hub_id;  //所属的hub
//@property (nonatomic,strong) NSString *info;    //目前没有用到
@property (nonatomic,strong) NSString *push_msg_flag; //是否推送消息标志，true是，false否
@property (nonatomic,strong) NSString *room_id; //所在的房间id
//@property (nonatomic,strong) NSString *time_created;
@property (nonatomic,strong) NSString *user_id;
@property (nonatomic,strong) NSArray *attributes;//设备属性列表
@property (nonatomic ,strong) NSArray *attributesOld;//设备属性列表，当从云端获取的service属性无效时，此数组不会更新，还是旧的数据
//@property (nonatomic,strong) NSString *location;
//@property (nonatomic,strong) NSString *gadget_info;
@property (nonatomic,strong) NSString *status; //在线041
@property (nonatomic,assign) MemberAttr memAttr;
@property (nonatomic,strong) NSArray* members; //显示当前设备的分享成员,用于设备列表和对应的分享成员页面

@property (nonatomic ,strong) NSString *member; //判断是否为管理员, 管理员为1.  普通成员为0

@property (nonatomic,assign) BOOL isInDirectMode;//是否处于小循环模式

@property (nonatomic ,strong) NSString *default_name;//监听到创建设备通知的时候，noti obj有值

//通过一个attrid获取一个attribute
- (NSDictionary *)getAttrByAttrId:(NSString *)attrId;

//通过一个attrid从attributesOld中获取一个attribute
- (NSDictionary *)getAttrFromOldByAttrId:(NSString*)attrId;

/**
 * 根据属性id去相应的value
 */
- (NSArray *)getAttrValueWithId:(NSString *)attrId;

/**
 * 根据属性id去相应的value,从attributesOld中取
 */
- (NSArray *)getAttrValueFromOldWithId:(NSString*)attrId;

/**
 * 执行action动作
 */
- (void)excuteAction:(NSString *)actionId param:(NSArray *)values;

- (GadgetTypeAction *)getSwitchActionDescription;

/** 
 * 获取属性描述
 */
- (NSString *)getAttrDiscriptionByAttrId:(NSString *)attrId;

/**
 * 获取动作描述
 */
- (NSString *)getActionDescriptionForValues:(NSString *)actionId value:(NSArray *)values;

// 获取一个属性值的百分比值，必须是range的，否则返回nil
- (NSString *)getPercentValueForAttribute:(NSString *)attrId;

@end
