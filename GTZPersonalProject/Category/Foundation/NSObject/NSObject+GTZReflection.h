//
//  NSDictionary+GTZReflection.h
//  GTZPersonalProject
//
//  Created by guangai on 2017/9/1.
//  Copyright © 2017年 GuoTZ. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (GTZReflection)
//类名
- (NSString *)gtz_className;
+ (NSString *)gtz_className;
//父类名称
- (NSString *)gtz_superClassName;
+ (NSString *)gtz_superClassName;

//实例属性字典
-(NSDictionary *)gtz_propertyDictionary;

//属性名称列表
- (NSArray*)gtz_propertyKeys;
+ (NSArray *)gtz_propertyKeys;

//属性详细信息列表
- (NSArray *)gtz_propertiesInfo;
+ (NSArray *)gtz_propertiesInfo;

//格式化后的属性列表
+ (NSArray *)gtz_propertiesWithCodeFormat;

//方法列表
-(NSArray*)gtz_methodList;
+(NSArray*)gtz_methodList;

-(NSArray*)gtz_methodListInfo;

//创建并返回一个指向所有已注册类的指针列表
+ (NSArray *)gtz_registedClassList;
//实例变量
+ (NSArray *)gtz_instanceVariable;

//协议列表
-(NSDictionary *)gtz_protocolList;
+ (NSDictionary *)gtz_protocolList;


- (BOOL)gtz_hasPropertyForKey:(NSString*)key;
- (BOOL)gtz_hasIvarForKey:(NSString*)key;

@end
