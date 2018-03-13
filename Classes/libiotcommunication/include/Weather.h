//
//  Weather.h
//  libiot
//
//  Created by pennycharles on 16/3/1.
//  Copyright © 2016年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef  enum{
    hurricane = 1,
    lightrain = 2,
    moderaterain = 3,
    heavyrain = 4,
    thundershowers = 5,
    freezingrain = 6,
    sleet = 7,
    lightsnow = 8,
    moderatesnow = 9,
    heavysnow = 10,
    hail = 11,
    fog = 12,
    haze = 13,
    wind = 14,
    overcast = 15,
    cloudy = 16,
    sunny = 17
}WeatherType;

@interface Weather : NSObject
////温度
//@property(strong,retain) NSString* temperature;
////天气类型
//@property(assign)WeatherType type;
////天气类型描述
//@property(strong,retain)NSString* typeDescription;
////天气城市
//@property(strong,retain) NSString* location;
////天气质量
//@property(strong,retain) NSString* quality;
////天气质量描述
//@property(strong,retain) NSString* qualityDescription;
//天气类型
@property (nonatomic ,assign) WeatherType code;
////天气类型描述
@property (nonatomic ,strong) NSString *text;
////温度
@property (nonatomic ,strong) NSString *temp;
////天气城市
@property (nonatomic ,strong) NSString *city;
////天气质量
@property (nonatomic ,strong) NSString *pm2_5;
////天气质量描述
@property (nonatomic ,strong) NSString *condition;

@end
