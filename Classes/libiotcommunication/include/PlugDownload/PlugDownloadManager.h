//
//  PlugDownloadManager.h
//  libiot
//
//  Created by leno on 2017/12/21.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlugDownloadModel.h"


@interface PlugDownloadManager : NSObject<NSURLSessionDownloadDelegate>

// 等待中的模型 只读
@property (nonatomic, strong,readonly) NSMutableArray *waitingDownloadModels;

// 下载中的模型 只读
@property (nonatomic, strong,readonly) NSMutableArray *downloadingModels;

// 最大下载数
@property (nonatomic, assign) NSInteger maxDownloadCount;

// 等待下载队列 先进先出 默认YES， 当NO时，先进后出
@property (nonatomic, assign) BOOL resumeDownloadFIFO;

// 全部并发 默认NO, 当YES时，忽略maxDownloadCount
@property (nonatomic, assign) BOOL isBatchDownload;

// 后台session configure
@property (nonatomic, strong) NSString *backgroundConfigure;

@property (nonatomic, copy) void (^backgroundSessionCompletionHandler)();

// 后台下载完成后调用 返回文件保存路径filePath
@property (nonatomic, copy) NSString *(^backgroundSessionDownloadCompleteBlock)(NSString *downloadURL);

// 单例
+ (PlugDownloadManager *)manager;

// 配置后台session
- (void)configureBackroundSession;

// 获取正在下载模型
- (PlugDownloadModel *)downLoadingModelForURLString:(NSString *)URLString;

// 获取后台运行task
- (NSURLSessionDownloadTask *)backgroundSessionTasksWithDownloadModel:(PlugDownloadModel *)downloadModel;

// 是否已经下载
- (BOOL)isDownloadCompletedWithDownloadModel:(PlugDownloadModel *)downloadModel;

// 取消所有完成或失败后台task
- (void)cancleAllBackgroundSessionTasks;

// 开始下载
- (PlugDownloadModel *)startDownloadURLString:(NSString *)URLString toDestinationPath:(NSString *)destinationPath progress:(PlugDownloadProgressBlock)progress state:(PlugDownloadStateBlock)state;

// 开始下载
- (void)startWithDownloadModel:(PlugDownloadModel *)downloadModel;

// 开始下载
- (void)startWithDownloadModel:(PlugDownloadModel *)downloadModel progress:(PlugDownloadProgressBlock)progress state:(PlugDownloadStateBlock)state;

// 恢复下载
- (void)resumeWithDownloadModel:(PlugDownloadModel *)downloadModel;

// 暂停下载
- (void)suspendWithDownloadModel:(PlugDownloadModel *)downloadModel;

// 取消下载
- (void)cancleWithDownloadModel:(PlugDownloadModel *)downloadModel;

// 删除下载
- (void)deleteFileWithDownloadModel:(PlugDownloadModel *)downloadModel;

// 删除下载
- (void)deleteAllFileWithDownloadDirectory:(NSString *)downloadDirectory;

@end
