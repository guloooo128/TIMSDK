/**
 * Copyright (c) 2022 Tencent. All rights reserved.
 */
#import "TUIRoomEngine.h"

@class TRTCCloud;
@class TXDeviceManager;
@class TXAudioEffectManager;
@class TXBeautyManager;

NS_ASSUME_NONNULL_BEGIN
@interface TUIRoomEngine (deprecated)

/////////////////////////////////////////////////////////////////////////////////
//
//                    弃用接口（建议使用对应的新接口）
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 开始推送本地音频
 *
 * @deprecated v1.5.0 版本开始不推荐使用,建议使用{@link unmuteLocalAudio}代替。
 */
- (void)startPushLocalAudio NS_SWIFT_NAME(startPushLocalAudio())__attribute__((deprecated("use muteLocalAudio instead")));

/**
 * 停止推送本地音频
 *
 * @deprecated v1.5.0 版本开始不推荐使用,建议使用{@link muteLocalAudio}代替。
 */
- (void)stopPushLocalAudio NS_SWIFT_NAME(stopPushLocalAudio())__attribute__((deprecated("use muteLocalAudio instead")));

/**
 * 获得TRTC实例对象
 *
 * @deprecated v1.5.0 版本开始不推荐使用
 */
- (TRTCCloud *)getTRTCCloud NS_SWIFT_NAME(getTRTCCloud()) __attribute__((deprecated("Deprecated from v1.5.0")));

/**
 * 获得设备管理对象
 *
 * @deprecated v1.5.0 版本开始不推荐使用
 */
- (TXDeviceManager *)getDeviceManager NS_SWIFT_NAME(getDeviceManager()) __attribute__((deprecated("Deprecated from v1.5.0")));

/**
 * 获得音效管理对象
 *
 * @deprecated v1.5.0 版本开始不推荐使用
 */
- (TXAudioEffectManager *)getAudioEffectManager NS_SWIFT_NAME(getAudioEffectManager()) __attribute__((deprecated("Deprecated from v1.5.0")));

/**
 * 获得美颜管理对象
 *
 * @deprecated v1.5.0 版本开始不推荐使用
 */
- (TXBeautyManager *)getBeautyManager NS_SWIFT_NAME(getBeautyManager()) __attribute__((deprecated("Deprecated from v1.5.0")));

/**
 * 设置本地用户视频渲染的视图控件
 *
 * @deprecated v1.6.1 版本开始不推荐使用
 */
- (void)setLocalVideoView:(TUIVideoStreamType)streamType view:(TUIVideoView *__nullable)view NS_SWIFT_NAME(setLocalVideoView(streamType:view:)) __attribute__((deprecated("Deprecated from v1.6.1")));

/**
 * 设置房间麦控模式（只有管理员或房主能够调用）
 *
 * @deprecated v2.0 版本开始，该功能已废弃，建议使用isSeatEnabled代替
 * 房间麦控模式更新后，SDK会通过 {@link $TUIRoomObserver$} 中的 {@link onRoomSpeechModeChanged} 回调通知房间内用户
 * @param mode TUISpeechModeFreeToSpeak: 自由发言模式, 用户可以自由开启麦克风和扬声器;
 *             TUISpeechModeApplyToSpeak: 申请发言模式，用户requestOpenLocalMicrophone 或 requestOpenLocalCamera 向房主或管理员申请后，方可打开麦克风和摄像头开始发言
 *             TUISpeechModeApplySpeakAfterTakingSeat: 上麦发言模式，KConference房间内，所有人在发言前，必须takeSeat，才能进行麦克风和摄像头操作。
 * @param onSuccess 成功回调
 * @param onError 错误回调
 */
- (void)updateRoomSpeechModeByAdmin:(TUISpeechMode)mode onSuccess:(TUISuccessBlock)onSuccess onError:(TUIErrorBlock)onError NS_SWIFT_NAME(updateRoomSpeechModeByAdmin(_:onSuccess:onError:)) __attribute__((deprecated("Deprecated from v2.0")));

#if TARGET_OS_IPHONE

/**
 * 切换前置或后置摄像头（仅适用于移动端）
 *
 * @deprecated v2.0 版本开始不推荐使用,建议使用{$TUIRoomDeviceManager$}中的{@link switchCamera}代替。
 * @return 0：操作成功；负数：操作失败
 */
- (NSInteger)switchCamera:(BOOL)frontCamera NS_SWIFT_NAME(switchCamera(frontCamera:)) __attribute__((deprecated("Deprecated from v2.0")));

#endif

#if !TARGET_OS_IPHONE && TARGET_OS_MAC

/**
 * 获取设备列表（仅适用于桌面端）
 *
 * @deprecated v2.0 版本开始不推荐使用,建议使用{$TUIRoomDeviceManager$}中的{@link getDevicesList}代替。
 * @param type  设备类型，指定需要获取哪种设备的列表。详见 TXMediaDeviceType 定义。
 * @note
 * - 使用完毕后请调用 release 方法释放资源，这样可以让 SDK 维护 ITXDeviceCollection 对象的生命周期。
 *   - 不要使用 delete 释放返回的 Collection 对象，delete ITXDeviceCollection* 指针会导致异常崩溃。
 *   - type 只支持 TXMediaDeviceTypeMic、TXMediaDeviceTypeSpeaker、TXMediaDeviceTypeCamera。
 *   - 此接口只支持 Mac 和 Windows 平台。
 */
- (NSArray<TXMediaDeviceInfo *> *_Nullable)getDevicesList:(TUIMediaDeviceType)type NS_SWIFT_NAME(getDevicesList(type:)) __attribute__((deprecated("Deprecated from v2.0")));

/**
 * 设置当前要使用的设备（仅适用于桌面端）
 *
 * @deprecated v2.0 版本开始不推荐使用,建议使用{$TUIRoomDeviceManager$}中的{@link setCurrentDevice}代替。
 * 设置当前要使用的设备后,SDK会通过 {@link $TUIRoomObserver$} 中的 {@link onDeviceChanged} 通知您
 * @param type 设备类型，详见 TXMediaDeviceType 定义。
 * @param deviceId 设备ID，您可以通过接口 {@link getDevicesList} 获得设备 ID。
 * @return 0：操作成功；负数：操作失败。
 */
- (NSInteger)setCurrentDevice:(TUIMediaDeviceType)type deviceId:(NSString *)deviceId NS_SWIFT_NAME(setCurrentDevice(type:deviceId:)) __attribute__((deprecated("Deprecated from v2.0")));

#endif

NS_ASSUME_NONNULL_END
@end
