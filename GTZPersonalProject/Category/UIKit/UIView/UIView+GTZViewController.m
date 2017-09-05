//
//  UIView+GTZViewController.m
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GTZ. All rights reserved.
//

#import "UIView+GTZViewController.h"

@implementation UIView (GTZViewController)
/**
 *  @brief  找到当前view所在的viewcontroler
 */
- (UIViewController *)gtz_ViewController {
    UIResponder *responder = self.nextResponder;
    do {
        if ([responder isKindOfClass:[UIViewController class]]) {
            return (UIViewController *)responder;
        }
        responder = responder.nextResponder;
    } while (responder);
    return nil;
}
@end
