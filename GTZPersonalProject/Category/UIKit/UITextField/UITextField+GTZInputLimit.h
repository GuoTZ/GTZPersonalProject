//
//  UIView+GTZInputLimit.h
//  GTZPersonalProject
//  限制汉子不是太好用
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (GTZInputLimit)
@property (assign, nonatomic)  NSInteger gtz_maxLength;//if <=0, no limit
@end
