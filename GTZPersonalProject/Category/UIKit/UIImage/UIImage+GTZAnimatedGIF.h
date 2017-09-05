//
//  UIImage+GTZAnimatedGIF.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (GTZAnimatedGIF)

/**
 UIImage *animation = [UIImage animatedImageWithAnimatedGIFData:theData];

 @param theData theData description
 @return return value description
 */
+ (UIImage *)gtz_AnimatedImageWithAnimatedGIFData:(NSData *)theData;

/**
 UIImage *image = [UIImage animatedImageWithAnimatedGIFURL:theURL];

 @param theURL theURL description
 @return return value description
 */
+ (UIImage *)gtz_AnimatedImageWithAnimatedGIFURL:(NSURL *)theURL;
@end
