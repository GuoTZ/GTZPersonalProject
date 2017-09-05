//
//  UIImage+GTZBadge.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (GTZBadge)


@property (strong, nonatomic) UILabel *gtz_badge;
@property (nonatomic) NSString *gtz_badgeValue;

@property (nonatomic) UIColor *gtz_badgeBGColor;

@property (nonatomic) UIColor *gtz_badgeTextColor;

@property (nonatomic) UIFont *gtz_badgeFont;

@property (nonatomic) CGFloat gtz_badgePadding;

@property (nonatomic) CGFloat gtz_badgeMinSize;

@property (nonatomic) CGFloat gtz_badgeOriginX;
@property (nonatomic) CGFloat gtz_badgeOriginY;

@property BOOL gtz_shouldHideBadgeAtZero;

@property BOOL gtz_shouldAnimateBadge;
@end
