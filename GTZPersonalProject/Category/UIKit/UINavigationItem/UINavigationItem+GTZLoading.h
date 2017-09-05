//
//  UINavigationItem+GTZLoading.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  位置指示器显示活动视图导航栏
 */
typedef NS_ENUM(NSUInteger, ANNavBarLoaderPosition){
    /**
     *  在视图的标题显示
     */
    ANNavBarLoaderPositionCenter = 0,
    /**
     *  左侧
     */
    ANNavBarLoaderPositionLeft,
    /**
     *  右侧
     */
    ANNavBarLoaderPositionRight
};
@interface UINavigationItem (GTZLoading)
- (void)startAnimatingAt:(ANNavBarLoaderPosition)position;


- (void)stopAnimating;
@end
