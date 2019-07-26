//
//  QuickCameraRecordParts.h
//  QuickCamera
//
//  Created by 智享城市iOS开发 on 2019/7/4.
//  Copyright © 2019年 智享城市iOS开发. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QuickCameraDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface QuickCameraRecordParts : NSObject

@property (weak, nonatomic) id<QuickCameraJoinListener> joinDelegate;

/**
 *  获取当前录制视频片段的总时长  单位：s
 */
- (float)getDuration;

/**
 *  获取当前录制所有视频片段路径
 */
- (NSArray *)getVideoPathList;

/**
 *  删除当前录制视频最后一片段,默认删除本地视频文件
 */
- (void)deleteLastPart;

/**
 *  删除当前录制视频指定片段，默认删除本地视频文件
 */
- (void)deletePart:(int)index;

/**
 *  删除当前录制视频所有片段，默认删除本地视频文件
 */
- (void)deleteAllParts;

/**
 *  您可以添加当前录制视频之外的视频，调用合joinAllParts的时候，SDK会把所有的视频合成（这里添加的视频需要和录制视频的分辨率保持一致，否则会合成失败）
 *  videoPath 添加视频的文件路径
 *  index 添加视频的所在整个视频list的位置
 */
- (void)insertPart:(NSString *)videoPath
		   atIndex:(int)index;

/**
 *  合成当前录制视频所有片段（这里需要保证视频片段的分辨率一致，否则会合成失败, 每个片段的时长必须大于1s，否则视为无效s片段）
 *  videoPath 合成后视频文件存放地址
 *  result  0:成功  -1：失败
 */
- (void)joinAllParts:(NSString *)videoOutputPath
			complete:(void(^)(int))result;

@end

NS_ASSUME_NONNULL_END
