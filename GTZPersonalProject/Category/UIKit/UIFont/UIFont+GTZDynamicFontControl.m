//
//  UIImage+GTZDynamicFontControl.m
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import "UIFont+GTZDynamicFontControl.h"

@implementation UIFont (GTZDynamicFontControl)

+(UIFont *)preferredFontForTextStyle:(NSString *)style withFontName:(NSString *)fontName{
    return [UIFont preferredFontForTextStyle:style withFontName:fontName scale:1.0f];
}

+(UIFont *)preferredFontForTextStyle:(NSString *)style withFontName:(NSString *)fontName scale:(CGFloat)scale{
    
    
    UIFont * font = nil;
    if([[UIFont class] resolveClassMethod:@selector(preferredFontForTextStyle:)]){
        font = [UIFont preferredFontForTextStyle:fontName];
    }else{
        font = [UIFont fontWithName:fontName size:14 * scale];
    }
    
    
    return [font adjustFontForTextStyle:style];
    
}

-(UIFont *)adjustFontForTextStyle:(NSString *)style{
    return [self adjustFontForTextStyle:style scale:1.0f];
}

-(UIFont *)adjustFontForTextStyle:(NSString *)style scale:(CGFloat)scale{
    
    UIFontDescriptor * fontDescriptor = nil;
    
    if([[UIFont class] resolveClassMethod:@selector(preferredFontForTextStyle:)]){
        
        fontDescriptor = [UIFontDescriptor preferredFontDescriptorWithTextStyle:style];
        
    }else{
        
        fontDescriptor = self.fontDescriptor;
        
    }
    
    float dynamicSize = [fontDescriptor pointSize] * scale + 3;
    
    return [UIFont fontWithName:self.fontName size:dynamicSize];
    
}

@end
