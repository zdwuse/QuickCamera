//
//  QuickCameraRecorder.h
//  QuickCamera
//
//  Created by 智享城市iOS开发 on 2019/7/2.
//  Copyright © 2019年 智享城市iOS开发. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "QuickCameraConfig.h"
#import "QuickCameraDefine.h"
#import "QuickCameraRecordParts.h"

NS_ASSUME_NONNULL_BEGIN

@interface QuickCameraRecorder : NSObject

// 视频录制的委托对象，可以获取录制进度等
@property (weak, nonatomic) id<QuickCameraRecorderListener> recordDelegate;
// 视频片段管理
@property (strong, nonatomic) QuickCameraRecordParts *recordParts;

/*
 创建拍摄器
 */
- (instancetype)initWithConfig:(QuickCameraConfig *__nullable)config;

/*
 设置预览界面
 */
- (void)startPreview:(UIView *)preview;

/*
 开始录制
 */
- (void)startRecord;

/** 设置美颜 和 美白 效果级别
 @param beautyLevel     : 美颜级别取值范围 0 ~ 9； 0 表示关闭 1 ~ 9值越大 效果越明显。
 @param whitenessLevel  : 美白级别取值范围 0 ~ 9； 0 表示关闭 1 ~ 9值越大 效果越明显。
 @param ruddinessLevel  : 红润级别取值范围 0 ~ 9； 0 表示关闭 1 ~ 9值越大 效果越明显。
 */
- (void)setBeautyLevel:(float)beautyLevel
		whitenessLevel:(float)whitenessLevel
		ruddinessLevel:(float)ruddinessLevel;

/**
 设置指定素材滤镜特效
 @param filterImage 指定素材，即颜色查找表图片。注意：一定要用png格式！！！
 */
- (void)setImageFilter:(UIImage *)filterImage;

/**
 设置两个滤镜效果 [精简版不支持]
 @param   leftFilter       左滤镜图片(nil代表无左滤镜效果)
 @param   leftIntensity    左滤镜浓度
 @param   rightFilter      右滤镜图片(nil代表无右滤镜效果)
 @param   rightIntensity   右滤镜浓度
 @param   leftRatio        左滤镜所占比例
 */
- (void)setFilter:(UIImage *__nullable)leftFilter
	leftIntensity:(CGFloat)leftIntensity
	  rightFilter:(UIImage *__nullable)rightFilter
   rightIntensity:(CGFloat)rightIntensity
		leftRatio:(CGFloat)leftRatio;

/**
 * 设置视频录制比例
 * @warning 需要在startRecord 之前设置，录制过程中设置无效
 * @param videoRatio : 3：4  9：16  1：1
 */
- (void)setAspectRatio:(QuickCameraRecorderAspectRatio)videoRatio;

// 设置录制速率
- (void)setRecordSpeed:(QuickCameraRecorderSpeed)recordSpeed;

/**
 切换前后摄像头，startCamera 之后调用有效
 @param isFront  YES 切换到前置摄像头, NO 切换到后置摄像头
 @return  YES 切换成功, NO 切换失败。
 */
- (BOOL)switchCamera:(BOOL)isFront;

/** 打开闪关灯，startCamera 之后调用有效
 @param enable YES, 打开 NO, 关闭.
 @return YES 打开成功, NO 打开失败。
 */
- (BOOL)toggleTorch:(BOOL)enable;

// 结束画面预览
- (void)stopCameraPreview;

/*
 停止录制
 */
- (void)stopRecord;

/*
 * 截图/拍照
 */
- (void)snapshot:(void (^)(UIImage *))snapshotCompletionBlock;

@end

NS_ASSUME_NONNULL_END
