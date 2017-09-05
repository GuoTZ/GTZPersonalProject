//
//  NSDate+GTZUtilities.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <Foundation/Foundation.h>
#define gtz_D_MINUTE	60
#define gtz_D_HOUR	3600
#define gtz_D_DAY	86400
#define gtz_D_WEEK	604800
#define gtz_D_YEAR	31556926
@interface NSDate (GTZUtilities)
+ (NSCalendar *)gtz_currentCalendar; // avoid bottlenecks
#pragma mark ---- Decomposing dates 分解的日期
@property (readonly) NSInteger gtz_nearestHour;
@property (readonly) NSInteger gtz_hour;
@property (readonly) NSInteger gtz_minute;
@property (readonly) NSInteger gtz_seconds;
@property (readonly) NSInteger gtz_day;
@property (readonly) NSInteger gtz_month;
@property (readonly) NSInteger gtz_week;
@property (readonly) NSInteger gtz_weekday;
@property (readonly) NSInteger gtz_nthWeekday; // e.g. 2nd Tuesday of the month == 2
@property (readonly) NSInteger gtz_year;

#pragma mark ----short time 格式化的时间
@property (nonatomic, readonly) NSString *gtz_shortString;
@property (nonatomic, readonly) NSString *gtz_shortDateString;
@property (nonatomic, readonly) NSString *gtz_shortTimeString;
@property (nonatomic, readonly) NSString *gtz_mediumString;
@property (nonatomic, readonly) NSString *gtz_mediumDateString;
@property (nonatomic, readonly) NSString *gtz_mediumTimeString;
@property (nonatomic, readonly) NSString *gtz_longString;
@property (nonatomic, readonly) NSString *gtz_longDateString;
@property (nonatomic, readonly) NSString *gtz_longTimeString;

///使用dateStyle timeStyle格式化时间
- (NSString *)gtz_stringWithDateStyle:(NSDateFormatterStyle)dateStyle timeStyle:(NSDateFormatterStyle)timeStyle;
///给定format格式化时间
- (NSString *)gtz_stringWithFormat:(NSString *)format;

#pragma mark ---- 从当前日期相对日期时间
///明天
+ (NSDate *)gtz_dateTomorrow;
///昨天
+ (NSDate *)gtz_dateYesterday;
///今天后几天
+ (NSDate *)gtz_dateWithDaysFromNow:(NSInteger)days;
///今天前几天
+ (NSDate *)gtz_dateWithDaysBeforeNow:(NSInteger)days;
///当前小时后dHours个小时
+ (NSDate *)gtz_dateWithHoursFromNow:(NSInteger)dHours;
///当前小时前dHours个小时
+ (NSDate *)gtz_dateWithHoursBeforeNow:(NSInteger)dHours;
///当前分钟后dMinutes个分钟
+ (NSDate *)gtz_dateWithMinutesFromNow:(NSInteger)dMinutes;
///当前分钟前dMinutes个分钟
+ (NSDate *)gtz_dateWithMinutesBeforeNow:(NSInteger)dMinutes;


#pragma mark ---- Comparing dates 比较时间
///比较年月日是否相等
- (BOOL)gtz_isEqualToDateIgnoringTime:(NSDate *)aDate;
///是否是今天
- (BOOL)gtz_isToday;
///是否是明天
- (BOOL)gtz_isTomorrow;
///是否是昨天
- (BOOL)gtz_isYesterday;

///是否是同一周
- (BOOL)gtz_isSameWeekAsDate:(NSDate *)aDate;
///是否是本周
- (BOOL)gtz_isThisWeek;
///是否是本周的下周
- (BOOL)gtz_isNextWeek;
///是否是本周的上周
- (BOOL)gtz_isLastWeek;

///是否是同一月
- (BOOL)gtz_isSameMonthAsDate:(NSDate *)aDate;
///是否是本月
- (BOOL)gtz_isThisMonth;
///是否是本月的下月
- (BOOL)gtz_isNextMonth;
///是否是本月的上月
- (BOOL)gtz_isLastMonth;

///是否是同一年
- (BOOL)gtz_isSameYearAsDate:(NSDate *)aDate;
///是否是今年
- (BOOL)gtz_isThisYear;
///是否是今年的下一年
- (BOOL)gtz_isNextYear;
///是否是今年的上一年
- (BOOL)gtz_isLastYear;

///是否提前aDate
- (BOOL)gtz_isEarlierThanDate:(NSDate *)aDate;
///是否晚于aDate
- (BOOL)gtz_isLaterThanDate:(NSDate *)aDate;
///是否晚是未来
- (BOOL)gtz_isInFuture;
///是否晚是过去
- (BOOL)gtz_isInPast;


///是否是工作日
- (BOOL)gtz_isTypicallyWorkday;
///是否是周末
- (BOOL)gtz_isTypicallyWeekend;

#pragma mark ---- Adjusting dates 调节时间
///增加dYears年
- (NSDate *)gtz_dateByAddingYears:(NSInteger)dYears;
///减少dYears年
- (NSDate *)gtz_dateBySubtractingYears:(NSInteger)dYears;
///增加dMonths月
- (NSDate *)gtz_dateByAddingMonths:(NSInteger)dMonths;
///减少dMonths月
- (NSDate *)gtz_dateBySubtractingMonths:(NSInteger)dMonths;
///增加dDays天
- (NSDate *)gtz_dateByAddingDays:(NSInteger)dDays;
///减少dDays天
- (NSDate *)gtz_dateBySubtractingDays:(NSInteger)dDays;
///增加dHours小时
- (NSDate *)gtz_dateByAddingHours:(NSInteger)dHours;
///减少dHours小时
- (NSDate *)gtz_dateBySubtractingHours:(NSInteger)dHours;
///增加dMinutes分钟
- (NSDate *)gtz_dateByAddingMinutes:(NSInteger)dMinutes;
///减少dMinutes分钟
- (NSDate *)gtz_dateBySubtractingMinutes:(NSInteger)dMinutes;


#pragma mark ---- 时间间隔
///比aDate晚多少分钟
- (NSInteger)gtz_minutesAfterDate:(NSDate *)aDate;
///比aDate早多少分钟
- (NSInteger)gtz_minutesBeforeDate:(NSDate *)aDate;
///比aDate晚多少小时
- (NSInteger)gtz_hoursAfterDate:(NSDate *)aDate;
///比aDate早多少小时
- (NSInteger)gtz_hoursBeforeDate:(NSDate *)aDate;
///比aDate晚多少天
- (NSInteger)gtz_daysAfterDate:(NSDate *)aDate;
///比aDate早多少天
- (NSInteger)gtz_daysBeforeDate:(NSDate *)aDate;

///与anotherDate间隔几天
- (NSInteger)gtz_distanceDaysToDate:(NSDate *)anotherDate;
///与anotherDate间隔几月
- (NSInteger)gtz_distanceMonthsToDate:(NSDate *)anotherDate;
///与anotherDate间隔几年
- (NSInteger)gtz_distanceYearsToDate:(NSDate *)anotherDate;

@end
