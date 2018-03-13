//
//  PlugModel.h
//  libiot
//
//  Created by leno on 2017/12/13.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PlugModel : NSObject

@property (nonatomic ,strong) NSString *gadget_type_id;

@property (nonatomic ,strong) NSString *app_version; //app版本号

@property (nonatomic ,strong) NSString *current_plug_version;//当前插件版本

@property (nonatomic ,strong) NSString *down_url;//插件下载地址,只在数据返回时用

@property (nonatomic ,strong) NSString *update_plug_version_name;//能够更新的插件版本名称,只在数据返回时用

@property (nonatomic ,strong) NSString *update_plug_version; //能够更新的插件版本,只在数据返回时用


@property (nonatomic ,strong) NSString *localUrl;

@property (nonatomic ,strong) NSString *plug_type;//H5，RN，REPLUGIN


@end
