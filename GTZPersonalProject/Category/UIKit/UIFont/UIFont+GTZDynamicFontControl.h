//
//  UIImage+GTZDynamicFontControl.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIFont (GTZDynamicFontControl)
+(UIFont *)preferredFontForTextStyle:(NSString *)style withFontName:(NSString *)fontName scale:(CGFloat)scale;

+(UIFont *)preferredFontForTextStyle:(NSString *)style withFontName:(NSString *)fontName;



-(UIFont *)adjustFontForTextStyle:(NSString *)style;

-(UIFont *)adjustFontForTextStyle:(NSString *)style scale:(CGFloat)scale;
@end
