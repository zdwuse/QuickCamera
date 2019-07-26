//
//  QuickCameraEditer.h
//  QuickCamera
//
//  Created by 智享城市iOS开发 on 2019/7/2.
//  Copyright © 2019年 智享城市iOS开发. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Photos/Photos.h>
#import "QuickCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface QuickCameraEditer : NSObject

// 视频预览回调的委托对象，可以获取视频的播放进度等
@property (weak, nonatomic) id<QuickCameraEditerListener> editDelegate;

/*
 初始化
 @param videoPath 视频地址
 @param videoAsset 两者可以并存，以videoPath为主，可传nil，
 */
- (id)initWithVideoPath:(NSString *__nullable)videoPath
			 videoAsset:(AVAsset *__nullable)videoAsset;

/*
 设置预览界面
 */
- (void)startPlayInPreview:(UIView *)preview;

@end

NS_ASSUME_NONNULL_END
