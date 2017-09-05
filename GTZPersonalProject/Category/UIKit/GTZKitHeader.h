//
//  GTZKitHeader.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

//我要导入的东西哈哈哈哈哈😊😊😊😊😊😊😊😊😊😊😊😊😊
#ifdef __OBJC__
//basic frame 😅
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "UIWindow+Level.h"

#import "UIView+GTZAnimation.h"
#import "UIView+GTZVisuals.h"
#import "UIView+GTZToast.h"
#import "UIView+GTZLayerBorder.h"
#import "UIView+GTZBlockGesture.h"
#import "UIView+GTZNib.h"
#import "UIView+GTZViewController.h"
#import "UIView+GTZFrame.h"
#import "UIView+GTZScreenshot.h"

#import "UITextField+GTZBlock.h"
#import "UITextField+GTZSelect.h"
#import "UITextField+GTZInputLimit.h"

#import "UITableViewCell+GTZNIB.h"

#import "UIScreen+GTZFrame.h"
#import "UITextField+GTZFirstResponder.h"

#import "UINavigationItem+GTZMargin.h"
#import "UINavigationItem+GTZLoading.h"

#import "UINavigationBar+GTZAwesome.h"

#import "UIImageView+GTZReflect.h"
#import "UIImageView+GTZAddition.h"

#import "UIImage+GTZMerge.h"
#import "UIImage+GTZOrientation.h"
#import "UIImage+GTZFileName.h"
#import "UIImage+GTZColor.h"
#import "UIImage+GTZCapture.h"
#import "UIImage+GTZBlur.h"
#import "UIImage+GTZAnimatedGIF.h"
#import "UIImage+GTZAlpha.h"

#import "UIFont+GTZDynamicFontControl.h"

#import "UIDevice+GTZHardware.h"

#import "UIButton+GTZBackgroundColor.h"
#import "UIButton+GTZCountDown.h"
#import "UIButton+GTZImagePosition.h"
#import "UIButton+GTZBadge.h"


#import "UIControl+GTZActionBlocks.h"
#import "UIControl+GTZBlock.h"



#endif /* GTZKitHeader_h */

#ifdef DEBUG //处于开发阶段
#define NSLog(...) NSLog(@"%s %d\n %@\n\n", __func__, __LINE__, [NSString stringWithFormat:__VA_ARGS__])
#else //处于发布阶段
#define NSLog(...)
#endif
//获取最上层的window
#define GTZTopWindow [[UIApplication sharedApplication].windows lastObject]
//弱引用申明
#define WSELF __weak __typeof(self) weakSelf = self;

#define SFM(x) ([NSString stringWithFormat:@"%@", (x)])

#define AppDelegate_GTZ ((AppDelegate *) [[UIApplication sharedApplication] delegate])
#define UserDefaults_GTZ [NSUserDefaults standardUserDefaults]

//状态栏高度
#define GTZStatus_Bar_Height 20
//NavBar高度
#define GTZNavigation_Bar_Height 44
//状态栏 ＋ 导航栏 高度
#define GTZStatus_And_Navigation_Height ((WTStatus_Bar_Height) + (WTNavigation_Bar_Height))
//底部tab高度
#define GTZTab_Bar_Height 49
//通知中心
#define NotificationCenter_GTZ [NSNotificationCenter defaultCenter]

//随机色
#define RandomColor_GTZ [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1.0]

#define ScreenHeight_GTZ [UIScreen mainScreen].bounds.size.height
#define WTScreenWidth_GTZ [UIScreen mainScreen].bounds.size.width















