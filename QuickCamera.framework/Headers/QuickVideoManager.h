//
//  QuickVideoManager.h
//  CameraEditor
//
//  Created by 智享城市iOS开发 on 2019/6/27.
//  Copyright © 2019年 智享城市iOS开发. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QuickCameraConfig.h"
#import "QuickCameraRecorder.h"
#import "QuickCameraEditer.h"
#import "QuickCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface QuickVideoManager : NSObject

@property (strong, nonatomic) QuickCameraConfig *config;
@property (strong, nonatomic) QuickCameraRecorder *cameraRecorder;
@property (strong, nonatomic) QuickCameraEditer *cameraEditer;

/*
 初始化
 */
+ (instancetype)instace;


@end

NS_ASSUME_NONNULL_END
