//
// Copyright (c) 2023 Tencent. All rights reserved.
//
//
// ===============================================================
// ====================== TIMPush 高级用法 ========================
// ===============================================================
// 【一、基础说明】
// 如果您想尽可能简单地接入 TIMPush 组件，您需要使用 [TUILogin](https://github.com/TencentCloud/TIMSDK/blob/master/iOS/TUIKit/TUICore/TUILogin.h) login/logout 接口登录/登出
// 此时 TIMPush 组件会自动感知登录/登出事件，按照 TIMPushDelegate.h 中的 TIMPush接入指南即可满足要求。
// 如果您不想使用 TUILogin 提供的接口，可参见下面的 的 【二、手动注册推送服务】
// 如果您想统计 TIMPush 的推送抵达率，可以参考 【三、统计推送抵达率】
// 如果 TIMPush 依然满足不了您的需求，欢迎点击【 https://zhiliao.qq.com/s/c5GY7HIM62CK/c35MJIIM62CB 】 反馈。
//
// 【二、手动注册推送服务】
// 如果您未接入TUICore组件，不需要使用 TUILogin 的登录/登出，但依然想实现离线推送，您只需：
// - 调用 [TIMPush disableAutoRegisterPush];
// - 在您的 APP/IM 登录完成后，主动调用 registerPush 方法注册推送
// - 退出登录时，主动调用 unRegisterPush 方法 反注册推送
//
// 【三、统计推送抵达率】
// 如果您需要统计推送的抵达和点击数据
// 您需要在 AppDelegate.m 文件中实现 `- applicationGroupID` 方法，返回 App Group ID。
// 并在 Notification Service Extension 的 '- didReceiveNotificationRequest:withContentHandler:' 方法中调用
// 推送抵达率统计函数:'+ (void)onReceiveNotificationRequest:inAppGroupID:callback:'
//
// 【四、关于合规】
// - TIMPush 在您未主动调用 registerPush 之前，不会有其他任何操作，符合相关规定
// - 如果您使用了 TUILogin 的登录登出，TIMPush 会在内部自动调用 registerPush / unRegisterPush。
// ================================================================
// ================================================================
// ================================================================


#ifndef TIMPush_h
#define TIMPush_h

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#if __has_include(<TIMPush/TIMPushDelegate.h>)
#import <TIMPush/TIMPushDelegate.h>
#else
#import "TIMPushDelegate.h"
#endif

NS_ASSUME_NONNULL_BEGIN

typedef void(^TIMPushNotificationExtensionCallback)(UNNotificationContent *content) API_AVAILABLE(macos(10.14), ios(10.0), watchos(3.0), tvos(10.0));

@interface TIMPush : NSObject

/**
 * 1. 设置插件是否在登录后自动注册推送服务，需要在注册推送服务之前调用
 *
 * @note
 *  - 插件默认自动注册推送Service
 *  - 如果您使用了 [TUILogin](https://github.com/TencentCloud/TIMSDK/blob/master/iOS/TUIKit/TUICore/TUILogin.h) 提供的 login/logout，无需再调用该接口
 */
+ (void)disableAutoRegisterPush NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");

/**
 * 2. 注册服务
 *
 * @note
 * - 在登录完成之后调用
 * - 如果您使用了 [TUILogin](https://github.com/TencentCloud/TIMSDK/blob/master/iOS/TUIKit/TUICore/TUILogin.h) 提供的 login/logout，无需再调用该接口
 */
+ (void)registerPush NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");

/**
 * 3. 取消注册
 *
 * @note
 * - 在退出登录时调用
 * - 如果您使用了 [TUILogin](https://github.com/TencentCloud/TIMSDK/blob/master/iOS/TUIKit/TUICore/TUILogin.h) 提供的 login/logout，无需再调用该接口
 */
+ (void)unRegisterPush NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");

/**
 * 4. 统计 TIMPush 的推送抵达率
 *
 * @note 请注意：
 * - 仅支持在 Notification Service Extension 的 '- didReceiveNotificationRequest:withContentHandler:' 方法中调用；
 * - appGroup 标识当前主 APP 和 Extension 之间共享的 APP Group，需要在主 APP 的 Capability 中配置 App Groups 能力。
 */
+ (void)onReceiveNotificationRequest:(UNNotificationRequest *)request inAppGroupID:(NSString *)appGroupID callback:(TIMPushNotificationExtensionCallback)callback NS_SWIFT_NAME(onReceiveNotificationRequest(request:inAppGroupID:callback:));

@end

NS_ASSUME_NONNULL_END

#endif /* TIMPush_h */
