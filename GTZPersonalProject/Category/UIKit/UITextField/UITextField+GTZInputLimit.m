//
//  UIView+GTZInputLimit.m
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import "UITextField+GTZInputLimit.h"
#import <objc/runtime.h>
static const void *GTZTextFieldInputLimitMaxLength = &GTZTextFieldInputLimitMaxLength;
@implementation UITextField (GTZInputLimit)
- (NSInteger)gtz_maxLength {
    return [objc_getAssociatedObject(self, GTZTextFieldInputLimitMaxLength) integerValue];
}
- (void)setGtz_maxLength:(NSInteger)maxLength {
    objc_setAssociatedObject(self, GTZTextFieldInputLimitMaxLength, @(maxLength), OBJC_ASSOCIATION_ASSIGN);
    [self addTarget:self action:@selector(gtz_textFieldTextDidChange) forControlEvents:UIControlEventEditingChanged];
}
- (void)gtz_textFieldTextDidChange {
    NSString *toBeString = self.text;
    //获取高亮部分
    UITextRange *selectedRange = [self markedTextRange];
    UITextPosition *position = [self positionFromPosition:selectedRange.start offset:0];
    
    //没有高亮选择的字，则对已输入的文字进行字数统计和限制
    //在iOS7下,position对象总是不为nil
    if ( (!position ||!selectedRange) && (self.gtz_maxLength > 0 && toBeString.length > self.gtz_maxLength))
    {
        NSRange rangeIndex = [toBeString rangeOfComposedCharacterSequenceAtIndex:self.gtz_maxLength];
        if (rangeIndex.length == 1)
        {
            self.text = [toBeString substringToIndex:self.gtz_maxLength];
        }
        else
        {
            NSRange rangeRange = [toBeString rangeOfComposedCharacterSequencesForRange:NSMakeRange(0, self.gtz_maxLength)];
            NSInteger tmpLength;
            if (rangeRange.length > self.gtz_maxLength) {
                tmpLength = rangeRange.length - rangeIndex.length;
            }else{
                tmpLength = rangeRange.length;
            }
            self.text = [toBeString substringWithRange:NSMakeRange(0, tmpLength)];
        }
    }
}

@end
