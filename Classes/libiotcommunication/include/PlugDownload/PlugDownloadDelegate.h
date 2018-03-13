//
//  PlugDownloadDelegate.h
//  libiot
//
//  Created by leno on 2017/12/21.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlugDownloadModel.h"

// 下载代理
@protocol PlugDownloadDelegate <NSObject>

// 更新下载进度
- (void)downloadModel:(PlugDownloadModel *)downloadModel didUpdateProgress:(PlugDownloadProgress *)progress;

// 更新下载状态
- (void)downloadModel:(PlugDownloadModel *)downloadModel didChangeState:(PlugDownloadState)state filePath:(NSString *)filePath error:(NSError *)error;

@end
