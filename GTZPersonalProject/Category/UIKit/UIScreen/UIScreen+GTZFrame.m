//
//  UITextField+GTZFrame.m
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import "UIScreen+GTZFrame.h"

@implementation UIScreen (GTZFrame)
+ (CGSize)size
{
    return [[UIScreen mainScreen] bounds].size;
}

+ (CGFloat)width
{
    return [[UIScreen mainScreen] bounds].size.width;
}

+ (CGFloat)height
{
    return [[UIScreen mainScreen] bounds].size.height;
}

+ (CGSize)orientationSize
{
    CGFloat systemVersion = [[[UIDevice currentDevice] systemVersion]
                             doubleValue];
    BOOL isLand =   UIInterfaceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation);
    return (systemVersion>8.0 && isLand) ? SizeSWAP([UIScreen size]) : [UIScreen size];
}

+ (CGFloat)orientationWidth
{
    return [UIScreen orientationSize].width;
}

+ (CGFloat)orientationHeight
{
    return [UIScreen orientationSize].height;
}

+ (CGSize)DPISize
{
    CGSize size = [[UIScreen mainScreen] bounds].size;
    CGFloat scale = [[UIScreen mainScreen] scale];
    return CGSizeMake(size.width * scale, size.height * scale);
}


/**
 *  交换高度与宽度
 */
static inline CGSize SizeSWAP(CGSize size) {
    return CGSizeMake(size.height, size.width);
}

@end
