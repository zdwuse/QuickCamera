//
//  QuickCameraDefine.h
//  QuickCamera
//
//  Created by 智享城市iOS开发 on 2019/7/2.
//  Copyright © 2019年 智享城市iOS开发. All rights reserved.
//

#ifndef QuickCameraDefine_h
#define QuickCameraDefine_h

#import <AVFoundation/AVFoundation.h>
#import "QuickCameraResult.h"

#define isPad ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
//判断iPhoneX
#define SC_iPhone_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPHoneXr //目前有两种
#define SC_iPhoneXr1 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1624), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
#define SC_iPhoneXr2 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhoneXs
#define SC_iPhoneXs ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhoneXs Max
#define SC_iPhoneXsMax ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//是否是iPhoneX系列     //可以用于快速适配所有机型，包括iPhoneX
#define iPhoneX (SC_iPhone_X + SC_iPhoneXr1 + SC_iPhoneXr2 + SC_iPhoneXs + SC_iPhoneXsMax)
//导航高度
#define SafeAreaNavHeight (iPhoneX ? 88 : 64)
#define SafeAreaStateHeight (iPhoneX ? 44 : 20)
//UITabBar高度由49pt变成了83pt,增加了34
#define SafeAreaTabbarHeight (iPhoneX ? 83 : 49)
//iPhone X底部高度
#define SafeAreaBarIncreaseHeight (iPhoneX ? 34 : 0)
// 录制
#define RecordCachesDirctory [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"RecordParts"]
#define CachesDirectory [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"RecordWritePart"]

#define RecordPipleParh [[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"] stringByAppendingPathComponent:@"RecordParts"]
#define RecordFileName(url) [url stringByAppendingString:@".mp4"]
// 录制视频分片路径
#define RecordPipAllPath(url) [RecordPipleParh stringByAppendingPathComponent:RecordFileName(url)]
// 录制视频输出路径
#define RecordOutPutPath [CachesDirectory stringByAppendingPathComponent:@"OutPutParh.mp4"]

//
#define FilterImagePath(path) [[[NSBundle mainBundle] pathForResource:@"QMXFilterResource" ofType:@"bundle"] stringByAppendingPathComponent:path]

// 视频录制
@protocol QuickCameraRecorderListener <NSObject>

/**
 * 短视频录制进度
 * @param second 以秒为单位
 */
@optional
- (void)onRecordProgress:(NSInteger)second;

/**
 * 短视频录制完成
 * @param result 返回码及错误原因
 * @see TXUGCRecordResult
 */
@optional
- (void)onRecordComplete:(QuickCameraResult *)result;

@end

@protocol QuickCameraJoinListener <NSObject>

@optional
/**
 * 短视频合成完成
 * @param progress  合成视频进度百分比
 */
- (void)onJoinProgress:(float)progress;

/**
 * 短视频合成完成
 * @param result 合成结果
 * @see TXJoinerResult
 */
- (void)onJoinComplete:(QuickCameraResult *)result;

@end

// 视频编辑
@protocol QuickCameraEditerListener <NSObject>

/**
 * 短视频预览进度
 * time 视频预览的当前时间 (s)
 */
@optional
- (void)onPreviewProgress:(CGFloat)time;

/**
 * 短视频预览结束回调
 */
@optional
- (void)onPreviewFinished;

@end

typedef NS_ENUM(NSInteger, MXQFilterType) {
	MXQFilterType_None     = 0 ,   //清除滤镜
	MXQFilterType_normal		,   //标准滤镜
	MXQFilterType_yinghong		,   //樱红滤镜
	MXQFilterType_yunshang		,   //云裳滤镜
	MXQFilterType_chunzhen		,   //纯真滤镜
	MXQFilterType_bailan       ,   //白兰滤镜
	MXQFilterType_yuanqi       ,   //元气滤镜
	MXQFilterType_chaotuo      ,   //超脱滤镜
	MXQFilterType_xiangfen     ,   //香氛滤镜
	MXQFilterType_white        ,   //美白滤镜
	MXQFilterType_langman      ,   //浪漫滤镜
	MXQFilterType_qingxin      ,   //清新滤镜
	MXQFilterType_weimei       ,   //唯美滤镜
	MXQFilterType_fennen       ,   //粉嫩滤镜
	MXQFilterType_huaijiu      ,   //怀旧滤镜
	MXQFilterType_landiao      ,   //蓝调滤镜
	MXQFilterType_qingliang    ,   //清凉滤镜
	MXQFilterType_rixi         ,   //日系滤镜
};

#define VideoFilterArr (@[@"原图",@"标准",@"樱红",@"云裳",@"纯真",@"白兰",@"元气",@"超脱",@"香氛",@"美白",@"浪漫",@"清新",@"唯美",@"粉嫩",@"怀旧",@"蓝调",@"清亮",@"日系"])

#define VideoFilterDic (@{@(MXQFilterType_None)        :@(0),@(MXQFilterType_normal)     :@(5),@(MXQFilterType_yinghong)   :@(8),@(MXQFilterType_yunshang)   :@(8),@(MXQFilterType_chunzhen)   :@(7),@(MXQFilterType_bailan)     :@(10),@(MXQFilterType_yuanqi)     :@(8),@(MXQFilterType_chaotuo)    :@(10),@(MXQFilterType_xiangfen)   :@(5),@(MXQFilterType_white)      :@(3),@(MXQFilterType_langman)    :@(3),@(MXQFilterType_qingxin)    :@(3),@(MXQFilterType_weimei)     :@(3),@(MXQFilterType_fennen)     :@(3),@(MXQFilterType_huaijiu)    :@(3),@(MXQFilterType_landiao)    :@(3),@(MXQFilterType_qingliang)  :@(3),@(MXQFilterType_rixi)       :@(3)})

#define VideoFilterImageDic (@{@(MXQFilterType_None)        :@"normal",@(MXQFilterType_normal)     :@"normal",@(MXQFilterType_yinghong)   :@"yinghong",@(MXQFilterType_yunshang)   :@"yunshang",@(MXQFilterType_chunzhen)   :@"chunzhen",@(MXQFilterType_bailan)     :@"bailan",@(MXQFilterType_yuanqi)     :@"yuanqi",@(MXQFilterType_chaotuo)    :@"chaotuo",@(MXQFilterType_xiangfen)   :@"xiangfen",@(MXQFilterType_white)      :@"white",@(MXQFilterType_langman)    :@"langman",@(MXQFilterType_qingxin)    :@"qingxin",@(MXQFilterType_weimei)     :@"weimei",@(MXQFilterType_fennen)     :@"fennen",@(MXQFilterType_huaijiu)    :@"huaijiu",@(MXQFilterType_landiao)    :@"landiao",@(MXQFilterType_qingliang)  :@"qingliang",@(MXQFilterType_rixi)       :@"rixi"})

/**
 * CameraRecord 录制视频比例类型定义
 */
typedef NS_ENUM(NSInteger, QuickCameraRecorderAspectRatio) {
	// 3:4
	QuickCameraRecorder_ASPECT_RATIO_3_4,
	// 9:16
	QuickCameraRecorder_ASPECT_RATIO_9_16,
	// 1:1
	QuickCameraRecorder_ASPECT_RATIO_1_1
};

/**
 * CameraRecord 录制视频速率
 */
typedef NS_ENUM(NSInteger, QuickCameraRecorderSpeed) {
	//极慢速
	QuickCameraRecorder_SPEED_SLOWEST,
	//慢速
	QuickCameraRecorder_SPEED_SLOW,
	//正常速
	QuickCameraRecorder_SPEED_NOMAL,
	//快速
	QuickCameraRecorder_SPEED_FAST,
	//极快速
	QuickCameraRecorder_SPEED_FASTEST,
};

#endif /* QuickCameraDefine_h */
