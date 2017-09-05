//
//  UIControl+GTZActionBlocks.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef void (^UIControlJKActionBlock)(id weakSender);


@interface UIControlJKActionBlockWrapper : NSObject
@property (nonatomic, copy) UIControlJKActionBlock gtz_actionBlock;
@property (nonatomic, assign) UIControlEvents gtz_controlEvents;
- (void)gtz_invokeBlock:(id)sender;
@end

@interface UIControl (GTZActionBlocks)
- (void)gtz_handleControlEvents:(UIControlEvents)controlEvents withBlock:(UIControlJKActionBlock)actionBlock;
- (void)gtz_removeActionBlocksForControlEvents:(UIControlEvents)controlEvents;
@end
