//
//  UIImage+GTZBadge.m
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import "UIButton+GTZBadge.h"
#import <objc/runtime.h>
NSString const *gtz_UIButton_badgeKey = @"gtz_UIButton_badgeKey";

NSString const *gtz_UIButton_badgeBGColorKey = @"gtz_UIButton_badgeBGColorKey";
NSString const *gtz_UIButton_badgeTextColorKey = @"gtz_UIButton_badgeTextColorKey";
NSString const *gtz_UIButton_badgeFontKey = @"gtz_UIButton_badgeFontKey";
NSString const *gtz_UIButton_badgePaddingKey = @"gtz_UIButton_badgePaddingKey";
NSString const *gtz_UIButton_badgeMinSizeKey = @"gtz_UIButton_badgeMinSizeKey";
NSString const *gtz_UIButton_badgeOriginXKey = @"gtz_UIButton_badgeOriginXKey";
NSString const *gtz_UIButton_badgeOriginYKey = @"gtz_UIButton_badgeOriginYKey";
NSString const *gtz_UIButton_shouldHideBadgeAtZeroKey = @"gtz_UIButton_shouldHideBadgeAtZeroKey";
NSString const *gtz_UIButton_shouldAnimateBadgeKey = @"gtz_UIButton_shouldAnimateBadgeKey";
NSString const *gtz_UIButton_badgeValueKey = @"gtz_UIButton_badgeValueKey";


@implementation UIButton (GTZBadge)

@dynamic gtz_badgeValue, gtz_badgeBGColor, gtz_badgeTextColor, gtz_badgeFont;
@dynamic gtz_badgePadding, gtz_badgeMinSize, gtz_badgeOriginX, gtz_badgeOriginY;
@dynamic gtz_shouldHideBadgeAtZero, gtz_shouldAnimateBadge;

- (void)gtz_badgeInit
{
    // Default design initialization
    self.gtz_badgeBGColor   = [UIColor redColor];
    self.gtz_badgeTextColor = [UIColor whiteColor];
    self.gtz_badgeFont      = [UIFont systemFontOfSize:12.0];
    self.gtz_badgePadding   = 6;
    self.gtz_badgeMinSize   = 8;
    self.gtz_badgeOriginX   = self.frame.size.width - self.gtz_badge.frame.size.width/2;
    self.gtz_badgeOriginY   = -4;
    self.gtz_shouldHideBadgeAtZero = YES;
    self.gtz_shouldAnimateBadge = YES;
    // Avoids badge to be clipped when animating its scale
    self.clipsToBounds = NO;
}

#pragma mark - Utility methods

// Handle badge display when its properties have been changed (color, font, ...)
- (void)gtz_refreshBadge
{
    // Change new attributes
    self.gtz_badge.textColor        = self.gtz_badgeTextColor;
    self.gtz_badge.backgroundColor  = self.gtz_badgeBGColor;
    self.gtz_badge.font             = self.gtz_badgeFont;
}

- (CGSize) gtz_badgeExpectedSize
{
    // When the value changes the badge could need to get bigger
    // Calculate expected size to fit new value
    // Use an intermediate label to get expected size thanks to sizeToFit
    // We don't call sizeToFit on the true label to avoid bad display
    UILabel *frameLabel = [self gtz_duplicateLabel:self.gtz_badge];
    [frameLabel sizeToFit];
    
    CGSize expectedLabelSize = frameLabel.frame.size;
    return expectedLabelSize;
}

- (void)gtz_updateBadgeFrame
{
    
    CGSize expectedLabelSize = [self gtz_badgeExpectedSize];
    
    // Make sure that for small value, the badge will be big enough
    CGFloat minHeight = expectedLabelSize.height;
    
    // Using a const we make sure the badge respect the minimum size
    minHeight = (minHeight < self.gtz_badgeMinSize) ? self.gtz_badgeMinSize : expectedLabelSize.height;
    CGFloat minWidth = expectedLabelSize.width;
    CGFloat padding = self.gtz_badgePadding;
    
    // Using const we make sure the badge doesn't get too smal
    minWidth = (minWidth < minHeight) ? minHeight : expectedLabelSize.width;
    self.gtz_badge.frame = CGRectMake(self.gtz_badgeOriginX, self.gtz_badgeOriginY, minWidth + padding, minHeight + padding);
    self.gtz_badge.layer.cornerRadius = (minHeight + padding) / 2;
    self.gtz_badge.layer.masksToBounds = YES;
}

// Handle the badge changing value
- (void)gtz_updateBadgeValueAnimated:(BOOL)animated
{
    // Bounce animation on badge if value changed and if animation authorized
    if (animated && self.gtz_shouldAnimateBadge && ![self.gtz_badge.text isEqualToString:self.gtz_badgeValue]) {
        CABasicAnimation * animation = [CABasicAnimation animationWithKeyPath:@"transform.scale"];
        [animation setFromValue:[NSNumber numberWithFloat:1.5]];
        [animation setToValue:[NSNumber numberWithFloat:1]];
        [animation setDuration:0.2];
        [animation setTimingFunction:[CAMediaTimingFunction functionWithControlPoints:.4f :1.3f :1.f :1.f]];
        [self.gtz_badge.layer addAnimation:animation forKey:@"bounceAnimation"];
    }
    
    // Set the new value
    self.gtz_badge.text = self.gtz_badgeValue;
    
    // Animate the size modification if needed
    NSTimeInterval duration = animated ? 0.2 : 0;
    [UIView animateWithDuration:duration animations:^{
        [self gtz_updateBadgeFrame];
    }];
}

- (UILabel *)gtz_duplicateLabel:(UILabel *)labelToCopy
{
    UILabel *duplicateLabel = [[UILabel alloc] initWithFrame:labelToCopy.frame];
    duplicateLabel.text = labelToCopy.text;
    duplicateLabel.font = labelToCopy.font;
    
    return duplicateLabel;
}

- (void)gtz_removeBadge
{
    // Animate badge removal
    [UIView animateWithDuration:0.2 animations:^{
        self.gtz_badge.transform = CGAffineTransformMakeScale(0, 0);
    } completion:^(BOOL finished) {
        [self.gtz_badge removeFromSuperview];
        self.gtz_badge = nil;
    }];
}

#pragma mark - getters/setters
-(UILabel*)gtz_badge {
    return objc_getAssociatedObject(self, &gtz_UIButton_badgeKey);
}
-(void)setgtz_badge:(UILabel *)badgeLabel
{
    objc_setAssociatedObject(self, &gtz_UIButton_badgeKey, badgeLabel, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

// Badge value to be display
-(NSString *)gtz_badgeValue {
    return objc_getAssociatedObject(self, &gtz_UIButton_badgeValueKey);
}
-(void) setGtz_badgeValue:(NSString *)badgeValue
{
    objc_setAssociatedObject(self, &gtz_UIButton_badgeValueKey, badgeValue, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    // When changing the badge value check if we need to remove the badge
    if (!badgeValue || [badgeValue isEqualToString:@""] || ([badgeValue isEqualToString:@"0"] && self.gtz_shouldHideBadgeAtZero)) {
        [self gtz_removeBadge];
    } else if (!self.gtz_badge) {
        // Create a new badge because not existing
        self.gtz_badge                      = [[UILabel alloc] initWithFrame:CGRectMake(self.gtz_badgeOriginX, self.gtz_badgeOriginY, 20, 20)];
        self.gtz_badge.textColor            = self.gtz_badgeTextColor;
        self.gtz_badge.backgroundColor      = self.gtz_badgeBGColor;
        self.gtz_badge.font                 = self.gtz_badgeFont;
        self.gtz_badge.textAlignment        = NSTextAlignmentCenter;
        [self gtz_badgeInit];
        [self addSubview:self.gtz_badge];
        [self gtz_updateBadgeValueAnimated:NO];
    } else {
        [self gtz_updateBadgeValueAnimated:YES];
    }
}

// Badge background color
-(UIColor *)gtz_badgeBGColor {
    return objc_getAssociatedObject(self, &gtz_UIButton_badgeBGColorKey);
}
-(void)setGtz_badgeBGColor:(UIColor *)badgeBGColor
{
    objc_setAssociatedObject(self, &gtz_UIButton_badgeBGColorKey, badgeBGColor, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if (self.gtz_badge) {
        [self gtz_refreshBadge];
    }
}

// Badge text color
-(UIColor *)gtz_badgeTextColor {
    return objc_getAssociatedObject(self, &gtz_UIButton_badgeTextColorKey);
}
-(void)setGtz_badgeTextColor:(UIColor *)badgeTextColor
{
    objc_setAssociatedObject(self, &gtz_UIButton_badgeTextColorKey, badgeTextColor, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if (self.gtz_badge) {
        [self gtz_refreshBadge];
    }
}

// Badge font
-(UIFont *)gtz_badgeFont {
    return objc_getAssociatedObject(self, &gtz_UIButton_badgeFontKey);
}
-(void)setGtz_badgeFont:(UIFont *)badgeFont
{
    objc_setAssociatedObject(self, &gtz_UIButton_badgeFontKey, badgeFont, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if (self.gtz_badge) {
        [self gtz_refreshBadge];
    }
}

// Padding value for the badge
-(CGFloat) gtz_badgePadding {
    NSNumber *number = objc_getAssociatedObject(self, &gtz_UIButton_badgePaddingKey);
    return number.floatValue;
}
-(void) setGtz_badgePadding:(CGFloat)badgePadding
{
    NSNumber *number = [NSNumber numberWithDouble:badgePadding];
    objc_setAssociatedObject(self, &gtz_UIButton_badgePaddingKey, number, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if (self.gtz_badge) {
        [self gtz_updateBadgeFrame];
    }
}

// Minimum size badge to small
-(CGFloat) gtz_badgeMinSize {
    NSNumber *number = objc_getAssociatedObject(self, &gtz_UIButton_badgeMinSizeKey);
    return number.floatValue;
}
-(void) setGtz_badgeMinSize:(CGFloat)badgeMinSize
{
    NSNumber *number = [NSNumber numberWithDouble:badgeMinSize];
    objc_setAssociatedObject(self, &gtz_UIButton_badgeMinSizeKey, number, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if (self.gtz_badge) {
        [self gtz_updateBadgeFrame];
    }
}

// Values for offseting the badge over the BarButtonItem you picked
-(CGFloat) gtz_badgeOriginX {
    NSNumber *number = objc_getAssociatedObject(self, &gtz_UIButton_badgeOriginXKey);
    return number.floatValue;
}
-(void) setGtz_badgeOriginX:(CGFloat)badgeOriginX
{
    NSNumber *number = [NSNumber numberWithDouble:badgeOriginX];
    objc_setAssociatedObject(self, &gtz_UIButton_badgeOriginXKey, number, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if (self.gtz_badge) {
        [self gtz_updateBadgeFrame];
    }
}

-(CGFloat) gtz_badgeOriginY {
    NSNumber *number = objc_getAssociatedObject(self, &gtz_UIButton_badgeOriginYKey);
    return number.floatValue;
}
-(void) setGtz_badgeOriginY:(CGFloat)badgeOriginY
{
    NSNumber *number = [NSNumber numberWithDouble:badgeOriginY];
    objc_setAssociatedObject(self, &gtz_UIButton_badgeOriginYKey, number, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if (self.gtz_badge) {
        [self gtz_updateBadgeFrame];
    }
}

// In case of numbers, remove the badge when reaching zero
-(BOOL) gtz_shouldHideBadgeAtZero {
    NSNumber *number = objc_getAssociatedObject(self, &gtz_UIButton_shouldHideBadgeAtZeroKey);
    return number.boolValue;
}
- (void)setGtz_shouldHideBadgeAtZero:(BOOL)shouldHideBadgeAtZero
{
    NSNumber *number = [NSNumber numberWithBool:shouldHideBadgeAtZero];
    objc_setAssociatedObject(self, &gtz_UIButton_shouldHideBadgeAtZeroKey, number, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

// Badge has a bounce animation when value changes
-(BOOL) gtz_shouldAnimateBadge {
    NSNumber *number = objc_getAssociatedObject(self, &gtz_UIButton_shouldAnimateBadgeKey);
    return number.boolValue;
}
- (void)setGtz_shouldAnimateBadge:(BOOL)shouldAnimateBadge
{
    NSNumber *number = [NSNumber numberWithBool:shouldAnimateBadge];
    objc_setAssociatedObject(self, &gtz_UIButton_shouldAnimateBadgeKey, number, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end
