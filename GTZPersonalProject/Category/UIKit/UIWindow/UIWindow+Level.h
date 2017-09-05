//
//  UIWindow+Level.h
//  GTZPersonalProject
//  ViewController的层级关系
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIWindow (Level)

/**
 获取最上层的控制器

 @return topMostController
 */
- (UIViewController*)topMostController;

/*
 获取当前控制器
 @return Returns the topViewController in stack of topMostController.
 */
- (UIViewController*)currentViewController;
@end
