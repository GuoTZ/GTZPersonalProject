//
//  UIImage+GTZAlpha.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (GTZAlpha)
/**
 *  @brief  是否有alpha通道
 *
 *  @return 是否有alpha通道
 */
- (BOOL)hasAlpha;
/**
 *  @brief  如果没有alpha通道 增加alpha通道
 *
 *  @return 如果没有alpha通道 增加alpha通道
 */
- (UIImage *)imageWithAlpha;
/**
 *  @brief  增加透明边框
 *
 *  @param borderSize 边框尺寸
 *
 *  @return 增加透明边框后的图片
 */
- (UIImage *)transparentBorderImage:(NSUInteger)borderSize;


/**
 *  @brief  裁切含透明图片为最小大小
 *
 *  @return 裁切后的图片
 */
- (UIImage *)trimmedBetterSize;
@end
