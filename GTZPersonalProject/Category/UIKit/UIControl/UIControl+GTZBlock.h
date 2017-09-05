//
//  UIControl+GTZBlock.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIControl (GTZBlock)
- (void)gtz_touchDown:(void (^)(void))eventBlock;
- (void)gtz_touchDownRepeat:(void (^)(void))eventBlock;
- (void)gtz_touchDragInside:(void (^)(void))eventBlock;
- (void)gtz_touchDragOutside:(void (^)(void))eventBlock;
- (void)gtz_touchDragEnter:(void (^)(void))eventBlock;
- (void)gtz_touchDragExit:(void (^)(void))eventBlock;
- (void)gtz_touchUpInside:(void (^)(void))eventBlock;
- (void)gtz_touchUpOutside:(void (^)(void))eventBlock;
- (void)gtz_touchCancel:(void (^)(void))eventBlock;
- (void)gtz_valueChanged:(void (^)(void))eventBlock;
- (void)gtz_editingDidBegin:(void (^)(void))eventBlock;
- (void)gtz_editingChanged:(void (^)(void))eventBlock;
- (void)gtz_editingDidEnd:(void (^)(void))eventBlock;
- (void)gtz_editingDidEndOnExit:(void (^)(void))eventBlock;
@end
