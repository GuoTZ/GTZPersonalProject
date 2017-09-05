//
//  UIColor+GTZHex.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/2.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (GTZHex)
// 默认alpha位1
+ (UIColor *)colorWithHexString:(NSString *)color;

//从十六进制字符串获取颜色，
//color:支持@“#123456”、 @“0X123456”、 @“123456”三种格式
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

// 颜色函数
UIColor* getHexColor(NSString * hexString);
@end
