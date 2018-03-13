//
//  PlugDownloadModel.h
//  libiot
//
//  Created by leno on 2017/12/13.
//  Copyright © 2017年 lenovo. All rights reserved.
//

#import <Foundation/Foundation.h>

// 下载状态
typedef NS_ENUM(NSUInteger, PlugDownloadState) {
    PlugDownloadStateNone,        // 未下载
    PlugDownloadStateReadying,    // 等待下载
    PlugDownloadStateRunning,     // 正在下载
    PlugDownloadStateSuspended,   // 下载暂停
    PlugDownloadStateCompleted,   // 下载完成
    PlugDownloadStateFailed       // 下载失败
};

@class PlugDownloadProgress;

// 进度更新block
typedef void (^PlugDownloadProgressBlock)(PlugDownloadProgress *progress);
// 状态更新block
typedef void (^PlugDownloadStateBlock)(PlugDownloadState state,NSString *filePath, NSError *error);

/**
 *  下载模型
 */
@interface PlugDownloadModel : NSObject

// 下载地址
@property (nonatomic, strong, readonly) NSString *downloadURL;

// 下载状态
@property (nonatomic, assign, readonly) PlugDownloadState state;
// 下载任务
@property (nonatomic, strong, readonly) NSURLSessionTask *task;

// 下载进度
@property (nonatomic, strong ,readonly) PlugDownloadProgress *progress;
// 下载路径 如果设置了downloadDirectory，文件下载完成后会移动到这个目录，否则，在manager默认cache目录里
@property (nonatomic, strong, readonly) NSString *filePath;

// 下载进度更新block
@property (nonatomic, copy) PlugDownloadProgressBlock progressBlock;
// 下载状态更新block
@property (nonatomic, copy) PlugDownloadStateBlock stateBlock;


- (instancetype)initWithURLString:(NSString *)URLString;
/**
 *  初始化方法
 *
 *  @param URLString 下载地址
 *  @param filePath  缓存地址 当为nil 默认缓存到cache
 */
- (instancetype)initWithURLString:(NSString *)URLString filePath:(NSString *)filePath;

@end

/**
 *  下载进度
 */
@interface PlugDownloadProgress : NSObject

// 续传大小
@property (nonatomic, assign, readonly) int64_t resumeBytesWritten;
// 这次写入的数量
@property (nonatomic, assign, readonly) int64_t bytesWritten;
// 已下载的数量
@property (nonatomic, assign, readonly) int64_t totalBytesWritten;
// 文件的总大小
@property (nonatomic, assign, readonly) int64_t totalBytesExpectedToWrite;
// 下载进度
@property (nonatomic, assign, readonly) float progress;
// 下载速度
@property (nonatomic, assign, readonly) float speed;
// 下载剩余时间
@property (nonatomic, assign, readonly) int remainingTime;


@end
