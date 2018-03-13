//
//  SpeakerVoiceManager.h
//  libiot
//
//  Created by leno on 16/11/15.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const failed_reasonKey;

@interface SpeakerVoice: NSObject

@property (nonatomic ,strong) NSString *text;

@property (nonatomic ,assign) BOOL isPerson;

@property (nonatomic ,strong) NSString *date_time;

@property (nonatomic ,assign) double timeStamp;

@property (nonatomic ,strong) NSString *voiceId;

@property (nonatomic ,strong) NSString *score;

@property (nonatomic ,strong) NSString *actor;


@end

@interface PairUserInfo : NSObject

@property (nonatomic ,strong) NSString *user_id;
@property (nonatomic ,strong) NSString *user_name;
@property (nonatomic ,strong) NSString *nick_name;
@property (nonatomic ,strong) NSString *img_url;

@end

@interface PersonVoice : PairUserInfo

@property (nonatomic ,copy) NSString *paired_user_id;

@property (nonatomic ,copy) NSString *time_created; //时间戳

@property (nonatomic ,copy) NSString *dataTime; //格式: yyyymmddhhmmss

@property (nonatomic ,copy) NSString *read; //是否已读，如果最新的消息是对方发过来的，且未读则该标志为0

@property (nonatomic ,assign) BOOL isSelf; //是否本人,不是本人为NO,否则为YES

@property (nonatomic ,copy) NSString *from_user_id;

@property (nonatomic ,copy) NSString *to_user_id;

@property (nonatomic ,copy) NSString *msg_url; //文本链接

@property (nonatomic ,copy) NSString *msg_txt; //文本内容

@property (nonatomic ,assign) BOOL is_client_listen; //消息是否收听过,没听过为NO,否则为YES

@property (nonatomic ,assign) NSInteger msg_duration; //时长

@end

@interface ForbidInfo : NSObject

@property (nonatomic ,assign) BOOL flag; //开关, 开为YES,关为NO

@property (nonatomic ,strong) NSString *start_hm; //开始时间

@property (nonatomic ,strong) NSString *stop_hm;  //结束时间

@end

@interface Dialogue : NSObject

@property (nonatomic ,assign) NSInteger dialogueType; // 0：问天气, 1：聊天, 2：计算, 3：日历

@property (nonatomic ,strong) NSArray *dialogueArray;//由SpeakerVoice组成的数组

@end

typedef void(^CompletionHandler)(BOOL state, NSArray *resultArray, NSInteger code ,NSError *error);

typedef void(^RequestPairCompletionHandler)(BOOL state, NSString *certify_code, NSInteger code ,NSError *error);

typedef void(^AcceptPairCompletionHandler)(BOOL state,  PairUserInfo*userInfo, NSInteger code ,NSError *error);

typedef void(^DelPairCompletionHandler)(BOOL state,  NSInteger code ,NSError *error);

typedef void(^DelCertifyCodeCompletionHandler)(BOOL state,  NSInteger code ,NSError *error);

typedef void(^ForbidTimeCompletionHandler)(BOOL state,  NSInteger code ,NSError *error);

typedef void(^ForbidInfoCompletionHandler)(BOOL state,  ForbidInfo *info, NSInteger code ,NSError *error);

typedef void(^SetForbidStatusHandler)(BOOL state,  ForbidInfo *info, NSInteger code ,NSError *error);


@interface SpeakerVoiceManager : NSObject

@property (nonatomic ,copy) CompletionHandler completionHandler;

@property (nonatomic ,copy) RequestPairCompletionHandler requestPairCompletionHandler;

@property (nonatomic ,copy) AcceptPairCompletionHandler  acceptPairCompletionHandler;

@property (nonatomic ,copy) DelPairCompletionHandler  delPairCompletionHandler;

@property (nonatomic ,copy) DelCertifyCodeCompletionHandler  delCertifyCodeCompletionHandler;

@property (nonatomic ,copy) ForbidTimeCompletionHandler forbidTimeCompletionHandler;

@property (nonatomic ,copy) ForbidInfoCompletionHandler forbidInfoCompletionHandler;

@property (nonatomic ,copy) SetForbidStatusHandler setForbidStatusHandler;

/** 超时时间. 如果不设置，则用默认值，只有设置大于0，才用该值 */
@property (nonatomic ,assign) NSTimeInterval timeout;


/**
 * 查询语音纪录
 * @description
 * @param count:每页的条数
 * @param begin_date: 开始时间
 * @param end_date: 结束时间
 */
- (void)getVoiceRecord:(NSString *)speakerID count:(NSString *)count begin_date:(NSString *)begin_date end_date:(NSString *)end_date completionHandler:(CompletionHandler)handler;

/** 新查询语音记录 */
- (void)getVoiceRecordNew:(NSString *)speakerID count:(NSString *)count begin_date:(NSString *)begin_date end_date:(NSString *)end_date completionHandler:(CompletionHandler)handler;

/** 
 * 最新查询语音记录
 * @param access_log_id: 从旧往新的查时必传，access_log_id取当前的最新的一条记录的id
 * @param begin_date:从新往旧的查，必传
 * @param end_time:该参数保留，目前暂不使用
 */
- (void)getVoiceRecordNew:(NSString *)speakerID count:(NSString *)count begin_date:(NSString *)begin_date end_date:(NSString *)end_date access_log_id:(NSString *)access_log_id completionHandler:(CompletionHandler)handler;

/** 
 * 语音记录打分，score和voiceId,isPerson必传
 * @return resultArray为nil
 */
- (void)scoreVoice:(SpeakerVoice *)score completionHandler:(CompletionHandler)handler;

/**
 * 根据speakerID获取本地缓存的语音记录，speakerID必传
 */
+ (NSArray *)getSavedVoiceRecord:(NSString *)speakerID;

/**
 * 请求配对
 * @return certify_code:配对码, code:为41006时，表示未绑定hub
 */
- (void)requestPair:(RequestPairCompletionHandler)handler;

/**
 * 接受配对
 * @param certify_code:配对码
 * @return code说明：41006用户未绑定hub，41007certify_code过未找到，41008certify_code的输入者和生成者是同一人，41009certify_code过期， 41010用户已经配对
 */
- (void)acceptPair:(NSString *)certify_code completionHandler:(AcceptPairCompletionHandler)handler;

/**
 * 删除配对
 * @param paired_user_id: 需要删除的用户id
 */
- (void)delPair:(NSString *)paired_user_id completionHandler:(DelPairCompletionHandler)handler;

/**
 * 获取配对用户信息列表
 * @return resultArray: 数组元素是PairUserInfo
 */
- (void)queryPairUsers:(CompletionHandler)handler;

/**
 * 修改用户昵称
 * @param users: 由PairUserInfo组成的数组
 * @return  由字典组成的数组, 字典构成例如:"failed_reason" = notfound; "user_id" = 2c70e47e56edd09afbc96fbac94012eb;
 */
- (void)modifyUserNickName:(NSArray *)users completionHandler:(CompletionHandler)handler;

/** 销毁验证码 */
- (void)deleteCertifyCode:(DelCertifyCodeCompletionHandler)handler;

/** 
 * 设置勿扰时间 
 * @param forbid_start_h: 小时 24小时制
 * @param forbid_start_m: 分钟
 * @param forbid_stop_h:  小时  24小时制
 * @param forbid_stop_m: 分钟
 */
- (void)setForbidTime:(NSString *)forbid_start_h forbid_start_m:(NSString *)forbid_start_m forbid_stop_h:(NSString *)forbid_stop_h forbid_stop_m:(NSString *)forbid_stop_m completionHandler:(ForbidTimeCompletionHandler)handler;

/**
 * 获取最新的留言列表
 * @return 返回数组由PersonVoice组成, PersonVoice有6个属性值：paired_user_id，time_created，isSelf,user_name,nick_name,img_url
 */
- (void)getNearestVoiceList:(CompletionHandler)handler;

/**
 * 获取和单个人的留言记录
 * @param time:第一次发送填空，后续填返回的列表中，时间最小的数值
 * @param paired_user_id: 对方的userid
 * @param number: 条数，默认为10 
 * @return resultArray: 由PersonVoice组成的数组，PersonVoice有8个属性值：isSelf，time_created，dataTime，from_user_id，to_user_id，msg_url，msg_txt，is_client_listen
 */
- (void)getPersonVoiceList:(NSString *)time paired_user_id:(NSString *)paired_user_id number:(NSString *)number handler:(CompletionHandler)handler;

/**
 * 查询家庭成员
 */
- (NSArray *)queryHomeMember;

/**
 * 增加家庭成员
 */
- (BOOL)addHomeMember:(NSString *)member;

/**
 * 获取勿扰信息
 * @return  ForbidInfo， 为nil时表示未设置过勿扰信息
 */
- (void)getForbidInfo:(ForbidInfoCompletionHandler)handler;

/**
 * 设置勿扰功能打开或关闭
 * @param status为YES表示打开， 否则表示关闭
 */
- (void)setForbidStatus:(BOOL)status handler:(SetForbidStatusHandler)handler;

/** 
 * 查询多轮对话记录
 * @return 返回由Dialogue组成的数组
 */
- (void)getDialogueRecord:(NSString *)speakerID handler:(CompletionHandler)handler;

@end
