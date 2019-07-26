//
//  QuickCameraConfig.h
//  CameraEditor
//
//  Created by 智享城市iOS开发 on 2019/6/27.
//  Copyright © 2019年 智享城市iOS开发. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QuickCameraConfig : NSObject
/*
 拍摄画面预定
 */
@property (copy, nonatomic) NSString *sessionPreset;

/*
 预拍摄方向
 */
@property (assign, nonatomic) AVCaptureDevicePosition cameraPosition;

/*
 视频最小时长
 */
@property (assign, nonatomic) CGFloat MinDuration;

/*
 视频最大时长
 */
@property (assign, nonatomic) CGFloat MaxDuration;


@end

NS_ASSUME_NONNULL_END
