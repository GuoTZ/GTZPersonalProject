//
//  UIControl+GTZActionBlocks.m
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import "UIControl+GTZActionBlocks.h"
#import <objc/runtime.h>

static const void *UIControlJKActionBlockArray = &UIControlJKActionBlockArray;

@implementation UIControlJKActionBlockWrapper

- (void)gtz_invokeBlock:(id)sender {
    if (self.gtz_actionBlock) {
        self.gtz_actionBlock(sender);
    }
}
@end


@implementation UIControl (GTZActionBlocks)
-(void)gtz_handleControlEvents:(UIControlEvents)controlEvents withBlock:(UIControlJKActionBlock)actionBlock {
    NSMutableArray *actionBlocksArray = [self gtz_actionBlocksArray];
    
    UIControlJKActionBlockWrapper *blockActionWrapper = [[UIControlJKActionBlockWrapper alloc] init];
    blockActionWrapper.gtz_actionBlock = actionBlock;
    blockActionWrapper.gtz_controlEvents = controlEvents;
    [actionBlocksArray addObject:blockActionWrapper];
    
    [self addTarget:blockActionWrapper action:@selector(gtz_invokeBlock:) forControlEvents:controlEvents];
}


- (void)gtz_removeActionBlocksForControlEvents:(UIControlEvents)controlEvents {
    NSMutableArray *actionBlocksArray = [self gtz_actionBlocksArray];
    NSMutableArray *wrappersToRemove = [NSMutableArray arrayWithCapacity:[actionBlocksArray count]];
    
    [actionBlocksArray enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        UIControlJKActionBlockWrapper *wrapperTmp = obj;
        if (wrapperTmp.gtz_controlEvents == controlEvents) {
            [wrappersToRemove addObject:wrapperTmp];
            [self removeTarget:wrapperTmp action:@selector(gtz_invokeBlock:) forControlEvents:controlEvents];
        }
    }];
    
    [actionBlocksArray removeObjectsInArray:wrappersToRemove];
}


- (NSMutableArray *)gtz_actionBlocksArray {
    NSMutableArray *actionBlocksArray = objc_getAssociatedObject(self, UIControlJKActionBlockArray);
    if (!actionBlocksArray) {
        actionBlocksArray = [NSMutableArray array];
        objc_setAssociatedObject(self, UIControlJKActionBlockArray, actionBlocksArray, OBJC_ASSOCIATION_RETAIN);
    }
    return actionBlocksArray;
}
@end
