//
//  UITextField+GTZNIB.m
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import "UITableViewCell+GTZNIB.h"

@implementation UITableViewCell (GTZNIB)
/**
 *  @brief  加载同类名的nib
 *
 *  @return nib
 */
+(UINib*)nib{
    return  [UINib nibWithNibName:NSStringFromClass([self class]) bundle:nil];
}
@end
