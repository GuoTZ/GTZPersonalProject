//
//  UIControl+GTZBlock.m
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import "UIControl+GTZBlock.h"
#import <objc/runtime.h>
#define JK_UICONTROL_EVENT(methodName, eventName)                                \
-(void)methodName : (void (^)(void))eventBlock {                              \
objc_setAssociatedObject(self, @selector(methodName:), eventBlock, OBJC_ASSOCIATION_COPY_NONATOMIC);\
[self addTarget:self                                                        \
action:@selector(methodName##Action:)                                       \
forControlEvents:UIControlEvent##eventName];                                \
}                                                                               \
-(void)methodName##Action:(id)sender {                                        \
void (^block)() = objc_getAssociatedObject(self, @selector(methodName:));  \
if (block) {                                                                \
block();                                                                \
}                                                                           \
}

@interface UIControl ()

@end
@implementation UIControl (GTZBlock)

JK_UICONTROL_EVENT(gtz_touchDown, TouchDown)
JK_UICONTROL_EVENT(gtz_touchDownRepeat, TouchDownRepeat)
JK_UICONTROL_EVENT(gtz_touchDragInside, TouchDragInside)
JK_UICONTROL_EVENT(gtz_touchDragOutside, TouchDragOutside)
JK_UICONTROL_EVENT(gtz_touchDragEnter, TouchDragEnter)
JK_UICONTROL_EVENT(gtz_touchDragExit, TouchDragExit)
JK_UICONTROL_EVENT(gtz_touchUpInside, TouchUpInside)
JK_UICONTROL_EVENT(gtz_touchUpOutside, TouchUpOutside)
JK_UICONTROL_EVENT(gtz_touchCancel, TouchCancel)
JK_UICONTROL_EVENT(gtz_valueChanged, ValueChanged)
JK_UICONTROL_EVENT(gtz_editingDidBegin, EditingDidBegin)
JK_UICONTROL_EVENT(gtz_editingChanged, EditingChanged)
JK_UICONTROL_EVENT(gtz_editingDidEnd, EditingDidEnd)
JK_UICONTROL_EVENT(gtz_editingDidEndOnExit, EditingDidEndOnExit)
@end
