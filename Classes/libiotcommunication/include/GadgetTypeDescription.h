//
//  GadgetTypeDescription.h
//  libiot
//
//  Created by pennycharles on 16/3/8.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
@class GadgetTypeAction;
@class GadgetTypeAttribute;
typedef enum  {
    OCTDATATYPE_INTEGER = 0,       //integer data type, such as int, long
    OCTDATATYPE_FLOAT   = 1,       //float data type, such as float, double
    OCTDATATYPE_STRING  = 2,       //string data type, such as char*
    OCTDATATYPE_ARRAY_INTEGER = 3, //array values
    OCTDATATYPE_ARRAY_FLOAT   = 4  //array values
}GadgetAttrValueType;

@interface GadgetTypeDescription : NSObject
@property (strong,nonatomic) NSString* gadgetTypeid; //表示设备的类型，全局唯一
@property (strong,nonatomic) NSString*  classId; //表示设备属于哪一类的设备
@property (strong,nonatomic) NSString*  vendor; //设备厂商
@property (strong,nonatomic) NSString*  name; //设备的名字
@property (strong,nonatomic) NSString*  model; //型号
@property (strong,nonatomic) NSString*  connectType; //设备连接形式，Wifi，upnp等
@property (strong,nonatomic) NSString*  client_res_url; //对应资源的下载链接
@property (strong,nonatomic) NSString*  tag;            //	设备标签描述，
@property BOOL  ifttt_action;              //是否可以作为联动规则action
@property BOOL  ifttt_attr;                //是否可以作为联动规则condiction
@property BOOL  push_msg_flag;                       //设备是否能设置消息推送标志
@property BOOL  needHub;                   //是否需要hub
@property int   disCoveryType;              //发现流程
@property (strong,nonatomic) NSString* ttl;
@property (strong,nonatomic) NSArray* attributes;
@property (strong,nonatomic) NSArray* actions;
@property (nonatomic ,strong) NSArray *hub_capability;
@property (nonatomic ,strong) NSString *display;
@property (nonatomic ,strong) NSString *discovery;

//根据action id获取一个action的具体描述
-(GadgetTypeAction*)getActionWithActionId:(NSString*)actionId;
-(GadgetTypeAttribute*)getAttrTypeWithAttrId:(NSString *)attrId;
//根据一个attributeId和atrribute value获取一个描述
//-(NSString*)getAttributeDescription:(NSString*)attrId value:(NSString*)attrValue;
//获取Attribute描述
-(NSString*)getAttributesDescription:(NSString *)attrId value:(NSArray *)attrValues;
//获取action 描述
-(NSString*)getActionDescriptionForValue:(NSString *)actionId value:(NSArray *)attrValues;

//获取一个classid的描述，返回dic ：{“classId”：“灯泡”，“descript”:"灯泡打开"}；
+(NSDictionary*)getAtrributeDescriptionForClassId:(NSString*)classId attrId:(NSString*)attrId value:(NSArray *)attrValues;
+(NSDictionary*)getActionDescriptionForClassId:(NSString*)classId actionId:(NSString*)actionId value:(NSArray *)actionValues;
@end


@interface GadgetTypeAction:NSObject
@property(nonatomic,strong)NSString* action_id;
@property(nonatomic,strong)NSString* action_view_title;
@property(nonatomic,strong)NSString*  aDescription;
@property(nonatomic,assign)BOOL ifttt_action;
@property(nonatomic,assign)BOOL push_msg_flag;
@property(nonatomic,assign)BOOL isRange;
@property(nonatomic,assign)GadgetAttrValueType value_type;
@property(nonatomic,strong)NSArray* value;
@property(nonatomic,strong)NSArray* value_description;

@end

@interface GadgetTypeAttribute:NSObject
@property(nonatomic,strong)NSString* attribute_id;
@property(nonatomic,strong)NSString* attribute_view_title;
@property(nonatomic,strong)NSString*  aDescription;
@property(nonatomic,assign)BOOL ifttt_attr;
@property(nonatomic,assign)BOOL push_msg_flag;
@property(nonatomic,assign)BOOL isRange;
@property(nonatomic,assign)GadgetAttrValueType value_type;
@property(nonatomic,strong)NSArray* value;
@property(nonatomic,strong)NSArray* value_description;
@end

