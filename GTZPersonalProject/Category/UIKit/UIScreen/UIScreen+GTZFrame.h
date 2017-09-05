//
//  UITextField+GTZFrame.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIScreen (GTZFrame)

+ (CGSize)size;
+ (CGFloat)width;
+ (CGFloat)height;

+ (CGSize)orientationSize;
+ (CGFloat)orientationWidth;
+ (CGFloat)orientationHeight;
+ (CGSize)DPISize;

@end
