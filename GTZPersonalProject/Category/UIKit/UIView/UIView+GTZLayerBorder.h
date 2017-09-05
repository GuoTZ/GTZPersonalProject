//
//  UIView+GTZLayerBorder.h
//  GTZPersonalProject
//  加边框
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GTZ. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef NS_OPTIONS(NSUInteger, ExcludePoint) {
    ExcludeStartPoint = 1 << 0,
    ExcludeEndPoint = 1 << 1,
    ExcludeAllPoint = ~0UL
};
@interface UIView (GTZLayerBorder)

/**
 上图上边加边框

 @param color 边框颜色
 @param borderWidth 边框宽度
 */
- (void)addTopBorderWithColor:(UIColor *)color width:(CGFloat) borderWidth;
/**
 上图左边加边框
 
 @param color 边框颜色
 @param borderWidth 边框宽度
 */
- (void)addLeftBorderWithColor: (UIColor *) color width:(CGFloat) borderWidth;
/**
 上图下边加边框
 
 @param color 边框颜色
 @param borderWidth 边框宽度
 */
- (void)addBottomBorderWithColor:(UIColor *)color width:(CGFloat) borderWidth;
/**
 上图有边加边框
 
 @param color 边框颜色
 @param borderWidth 边框宽度
 */
- (void)addRightBorderWithColor:(UIColor *)color width:(CGFloat) borderWidth;

/**
 移除边框
 */
- (void)removeTopBorder;
- (void)removeLeftBorder;
- (void)removeBottomBorder;
- (void)removeRightBorder;


- (void)addTopBorderWithColor:(UIColor *)color width:(CGFloat) borderWidth excludePoint:(CGFloat)point edgeType:(ExcludePoint)edge;
- (void)addLeftBorderWithColor: (UIColor *) color width:(CGFloat) borderWidth excludePoint:(CGFloat)point edgeType:(ExcludePoint)edge;
- (void)addBottomBorderWithColor:(UIColor *)color width:(CGFloat) borderWidth excludePoint:(CGFloat)point edgeType:(ExcludePoint)edge;
- (void)addRightBorderWithColor:(UIColor *)color width:(CGFloat) borderWidth excludePoint:(CGFloat)point edgeType:(ExcludePoint)edge;


@end
