//
//  GadgetManger.h
//  libiot
//
//  Created by guangchaopeng on 16/1/22.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class Gadget;
@class GadgetTypeDescription;

@interface GadgetFunction : NSObject

@property (nonatomic ,copy) NSString *gadget_id;
//@property (nonatomic ,strong) NSMutableArray *gadgetFunctionArr; //由GadgetFunctionInfo组成的数组
@property (nonatomic ,copy) NSString *gadget_function_id;
@property (nonatomic ,copy) NSString *start_time;
@property (nonatomic ,copy) NSString *end_time;
@property (nonatomic ,copy) NSString *status; //true , false
@property (nonatomic ,strong) NSDictionary *ext;

@end

/** 回调的block */
typedef void(^ResultBlock)(BOOL state, NSInteger code);

/** 在线获取首页数据的回调block */
typedef void(^DashboardResultBlock)(BOOL state, NSInteger code);

typedef void(^HistoryRecordResultBlock)(BOOL state, NSInteger code);

typedef void(^GetGadgetFunctionResultBlock)(BOOL state, NSArray *resultArray, NSInteger code ,NSError *error);

/** 设备管理页 */
@interface GadgetManager : NSObject

@property (nonatomic ,copy) ResultBlock resultBlock;
@property (nonatomic ,copy) DashboardResultBlock dashboardResultBlock;
@property (nonatomic ,copy) HistoryRecordResultBlock historyRecordResultBlock;
@property (nonatomic ,copy) GetGadgetFunctionResultBlock getGadgetFunctionResultBlock;

/** 
 * 获取支持的设备型号列表,本地获取。 数组结构：二维数组，第一维度是按照classid分组，第二维是相同classid的GadgetTypeDescription
 * @return 支持的设备型号列表, 数据类型：数组，数组的元素是GadgetTypeDescription
 */
+ (NSArray *)getGadgetTypeList;

/** 
 * 通过单个的gadgetTypeId获取一个类型描述
 * @param gadgetTypeId  设备类型id
 * @return GadgetTypeDescription  包含设备描述信息的model
 */
+ (GadgetTypeDescription *)GadgetTypeDescriptionWithTypeId:(NSString *)gadgetTypeId;
/**
 * 通过单个的classsId获取一个类型描述
 * @param gadgetTypeId  设备类型
 * @return GadgetTypeDescription  包含设备描述信息的model
 */
+ (GadgetTypeDescription *)GadgetTypeDescriptionWithClassId:(NSString *)classId;
/**
 * 读取所有的gadget列表, 本地获取
 * @return 设备列表， 数据类型：数组， 数组的元素是Gadget model
 */
+ (NSArray *)getGadgets;
/**
 * 读取所有的属于自己的设备gadget列表, 本地获取
 * @return 设备列表， 数据类型：数组， 数组的元素是Gadget model
 */
+(NSArray*)getMyOwnGadgets;

/** 
 * 根据gadget_id获取gadget信息,本地获取
 * @param gadget_id 设备id
 * @return 包含设备信息的Gadget model
 */
+ (Gadget *)getGagdgetInfoWithId:(NSString *)gadget_id;

/**
 * 获取所有gadget的消息记录，本地获取，一级
 * @return 数组类型，数组为两层结构，一级为不同日期的数组集合，二级为相同日期的historyRecord model集合
 */
+ (NSArray *)getRecordGadgetList;

/**
 * 获取单个gadget的历史记录详情
 * source_id: gadgetid
 * @return 数组类型，数组为两层结构，一级为不同日期的数组集合，二级为相同日期的historyRecord model集合
 */
+ (NSArray *)getGadgetHistoryDetDataWithId:(NSString *)source_id;

/** 
 * 获取曲线图属性纪录,本地获取
 */
+ (NSArray *)getGadgetLogList;

/** 
 * 获取历史纪录，一级，全部。本地获取
 */
+ (NSArray *)getEventsAllLogs;

/*
 * 获取属于某个hubId下的所有设备
 */
+ (NSArray*)getGAdgetsWithHubId:(NSString *)hubId;

/**
 * 主页更新的接口，更新内容包括gadget列表信息，hub列表信息，home，room列表信息。超时的情况下，返回code是-1
 * @param timeoutInterval 超时时间
 */
- (void)updateDashboardWithTimeInterval:(double)timeoutInterval resultBlock:(ResultBlock)callback;

/**
 * 强制刷新接口
 * @param timeoutInterval 超时时间
 */
- (void)forceUpdateDashboardWithTimeInterval:(double)timeoutInterval resultBlock:(ResultBlock)callback;

/**
 * 停止设备扫描
 */
+ (void)stopScanGadgets;

/**
 * 启动设备扫描,gadgetTypeId为nil时是全扫描
 */
+ (void)startScanGadgetWithTypeId:(NSString *)gadgetTypeId;

/**
 * 请求设备列表，包括了动态属性，静态信息和在线状态
 */
- (void)updateGadgetListWithResultBlock:(ResultBlock)block;

/**
 * 根据gadgetId请求gadget信息
 */
- (void)findGadgetById:(NSString *)gadgetId resultBlock:(ResultBlock)block;

/**
 * 根据gadgetId请求gadget 动态信息
 */
- (void)getGadgetDynamicById:(NSString *)gadgetId resultBlock:(ResultBlock)block;

/**
 * 获取所有gadget的在线状态
 */
- (void)getGadgetListState:(ResultBlock)block;

/**
 * 设置gadget信息
 * @param gadget_id和gadget_name是必传，其他不是必传,不传写nil
 */
- (void)setGadgetInfoWithId:(NSString *)gadget_id gadget_name:(NSString *)gadget_name  room_id:(NSString *)room_id gadget_info:(NSString *)gadget_info client_data:(NSString *)client_data push_msg_flag:(NSString *)push_msg_flag resultBlock:(ResultBlock)block;

/**
 * 删除gadget
 */
- (void)deleteGadget:(NSString *)gadget_id resultBlock:(ResultBlock)block;

/**
 * 查询历史纪录，一级
 */
- (void)queryHistoryRecord:(ResultBlock)block;

/**
 * 查询历史纪录最新消息，一级
 */
- (void)queryLastHistoryRecord:(ResultBlock)block;

/** 本地获取历史纪录最新消息，一级 */
+ (NSDictionary *)getAllLastLogsDic;

/**
 * 查询历史纪录，二级
 * @param source_id:来自消息一级
 * @param attributed_id不是必传，其他参数都是必传。start_time,end_time,num 如果分别传@"",则后台分别取默认值
 */
- (void)queryDetHistoryRecordWithSource_id:(NSString *)source_id start_time:(NSString *)start_time end_time:(NSString *)end_time num:(NSString *)num attributed_id:(NSString *)attributed_id resultBlock:(ResultBlock)block;

/**
 * 新查询历史纪录，二级
 * @param source_id:来自消息一级
 * @param attributed_id 不是必传，其他参数都是必传。start_time,end_time,num 如果分别传@"",则后台分别取默认值
 */
- (void)getDetHistoryRecordWithSource_id:(NSString *)source_id start_time:(NSString *)start_time end_time:(NSString *)end_time num:(NSString *)num attributed_id:(NSString *)attributed_id resultBlock:(void(^)(BOOL state, NSString* data))result;

/** 
 * 查询历史记录,一级，全部
 * @param start_time:开始时间，格式:20100102132035,此参数为空 则默认当前时间
 * @param end_time:开始时间，格式:20100102132035,此参数为空 则默认1970年
 * @param num:条数
 */
- (void)queryEventsAllLogsWithStartTime:(NSString *)start_time end_time:(NSString *)end_time num:(NSString *)num resultBlock:(ResultBlock)block;

/** 
 * 获取支持型号列表
 */
- (void)getGadgetTypeList:(ResultBlock)block;

/** 
 * 查询新系统消息， 二级
 * @param source_id:来自消息一级
 * @param start_time:开始时间，格式：20100121105522
 * @param end_time:结束时间，格式：20100110000000
 * @param attributed_id:不是必传
 */
- (void)querySystemDetHistoryRecordWithSource_id:(NSString *)source_id start_time:(NSString *)start_time end_time:(NSString *)end_time num:(NSString *)num attributed_id:(NSString *)attributed_id event_type:(NSString *)event_type resultBlock:(ResultBlock)block;

/** 
 * 是否有新消息
 * @return status: yes表示有新消息，否则表示没有新消息
 */
- (void)queryHistoryRecordStatus:(void(^)(BOOL state, NSInteger code , BOOL status))block;

/** 移除消息记录 */ 
- (void)removeHistoryRecordWithType:(NSString *)event_source_type event_type:(NSString *)event_type source_id:(NSString *)source_id resultBlock:(ResultBlock)block;

/**
 * 本地获取消息二级页面数据
 */
+ (NSArray *)getSystemHistoryDetDataWithId:(NSString *)source_id;

/**
 * 设置设备免打扰模式
 * @param function_key: 免打扰传 0x10000001
 * @param start_time:开始时间，如11:00
 * @param end_time:结束时间，如12:00
 * @param gadget_function_id: 传nil表示创建一条记录
 * @param status: 是否启用， true 启用，false 禁用
 * @param ext:预留字段，暂时没用
 */
- (void)setGadgetFunction:(NSString *)function_key gadgetId:(NSString *)gadgetId start_time:(NSString *)start_time end_time:(NSString *)end_time gadget_function_id:(NSString *)gadget_function_id status:(NSString *)status ext:(id)ext resultBlock:(ResultBlock)block;

/**
 * 获取设备免打扰模式
 * @param function_key: 免打扰传 0x10000001
 * @param gadget_id: 传nil表示获取Hub下的所有Gadget的勿扰设置
 * @param hub_id: 可以不传
 * @return resultArray:由GadgetFunction组成的数组
 */
- (void)getGadgetFunction:(NSString *)function_key gadget_id:(NSString *)gadget_id hub_id:(NSString *)hub_id resultBlock:(GetGadgetFunctionResultBlock)block;

@end



