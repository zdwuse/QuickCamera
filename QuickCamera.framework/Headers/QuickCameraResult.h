//
//  QuickCameraResult.h
//  CameraEditor
//
//  Created by 智享城市iOS开发 on 2019/6/27.
//  Copyright © 2019年 智享城市iOS开发. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CameraResult_Type){
	CameraResult_Type_Record_Success, // 录制成功
	CameraResult_Type_Record_OutTime, // 录制超时
	CameraResult_Type_Record_Faile,   // 录制失败
	CameraResult_Type_Join_Success,   // 合成成功
	CameraResult_Type_Join_Fail,      // 合成失败
};

NS_ASSUME_NONNULL_BEGIN

@interface QuickCameraResult : NSObject

@property (assign, nonatomic) CameraResult_Type  type;
@property (copy, nonatomic)   NSString *errorMsg;

@end

NS_ASSUME_NONNULL_END
