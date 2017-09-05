//
//  UIImage+GTZHardware.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (GTZHardware)
+ (NSString *)gtz_platform;
+ (NSString *)gtz_platformString;


+ (NSString *)gtz_macAddress;

//Return the current device CPU frequency
+ (NSUInteger)gtz_cpuFrequency;
// Return the current device BUS frequency
+ (NSUInteger)gtz_busFrequency;
//current device RAM size
+ (NSUInteger)gtz_ramSize;
//Return the current device CPU number
+ (NSUInteger)gtz_cpuNumber;
//Return the current device total memory

/// 获取iOS系统的版本号
+ (NSString *)gtz_systemVersion;
/// 判断当前系统是否有摄像头
+ (BOOL)gtz_hasCamera;
/// 获取手机内存总量, 返回的是字节数
+ (NSUInteger)gtz_totalMemoryBytes;
/// 获取手机可用内存, 返回的是字节数
+ (NSUInteger)gtz_freeMemoryBytes;

/// 获取手机硬盘空闲空间, 返回的是字节数
+ (long long)gtz_freeDiskSpaceBytes;
/// 获取手机硬盘总空间, 返回的是字节数
+ (long long)gtz_totalDiskSpaceBytes;
@end
