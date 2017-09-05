//
//  UIView+GTZVisuals.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (GTZVisuals)

/*
 *  设置一个角落与半径,中风的大小和颜色
 */
-(void)cornerRadius: (CGFloat)radius
         strokeSize: (CGFloat)size
              color: (UIColor *)color;
/*
 *  设置一个角落
 */
-(void)setRoundedCorners:(UIRectCorner)corners
                  radius:(CGFloat)radius;

/*
 *  画阴影的属性
 */
-(void)shadowWithColor: (UIColor *)color
                offset: (CGSize)offset
               opacity: (CGFloat)opacity
                radius: (CGFloat)radius;

/*
 *  删除父视图与消退
 */
-(void)removeFromSuperviewWithFadeDuration: (NSTimeInterval)duration;

/*
 *  添加子视图与给定的过渡和持续时间
 */
-(void)addSubview: (UIView *)view withTransition: (UIViewAnimationTransition)transition duration: (NSTimeInterval)duration;

/*
 *  删除视图的父视图给转型和持续时间
 */
-(void)removeFromSuperviewWithTransition: (UIViewAnimationTransition)transition duration: (NSTimeInterval)duration;

/*
 *  由给定的角度旋转视图。定时功能可以零和违约。
 */
-(void)rotateByAngle: (CGFloat)angle
            duration: (NSTimeInterval)duration
         autoreverse: (BOOL)autoreverse
         repeatCount: (CGFloat)repeatCount
      timingFunction: (CAMediaTimingFunction *)timingFunction;

/*
 *  移动点。定时功能可以零和违约
 */
-(void)moveToPoint: (CGPoint)newPoint
          duration: (NSTimeInterval)duration
       autoreverse: (BOOL)autoreverse
       repeatCount: (CGFloat)repeatCount
    timingFunction: (CAMediaTimingFunction *)timingFunction;

@end
