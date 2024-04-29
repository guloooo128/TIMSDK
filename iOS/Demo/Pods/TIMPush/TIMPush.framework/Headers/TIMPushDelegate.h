//
// Copyright (c) 2023 Tencent. All rights reserved.
//
// ===============================================================
// ====================== TIMPush 接入指南 ========================
// ===============================================================
// 【一、基础推送功能接入】
// 1. 在您的 AppDelegate 中遵守 TIMPushDelegate协议, `@interface AppDelegate () <TIMPushDelegate>`；
// 2. 在您的 AppDelegate.m 文件中，实现 '- offlinePushCertificateID' 方法，返回控制台证书 ID。
// 至此，您已经完成了基本推送功能的接入。
// 注意：
// - 当您登录后，在控制台上看到 APNs configuration success 日志打印时，即表示已成功接入；
// - 如果您的 APP 已经获取到了推送权限，此时退入后台或者杀死进程，即可收到远程推送通知。
//
// 【二、监听推送点击事件】
// 1. 如果您需要自定义解析收到的远程推送，您需要在 AppDelegate.m 文件中实现 `- onRemoteNotificationReceived` 方法;
// 2. 如果您想使用内置的 TUIChat 推送解析逻辑，并跳转到 TUIChat 的聊天页面，您可以实现 `- navigateToBuiltInChatViewController` 方法。
//
// 【三、统计推送抵达率】
// 1. 如果您需要统计推送的抵达和点击数据，您需要在 AppDelegate.m 文件中实现 `- applicationGroupID` 方法，返回 App Group ID。
// 2. 并参考 TIMPush.h 中的高级用法「统计推送抵达率」上报抵达事件。
//
// ================================================================
// ================================================================
// ================================================================

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_UI_ACTOR
@protocol TIMPushDelegate <UIApplicationDelegate>

@optional

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                      （一）基础 APNs 推送配置
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * 离线推送证书的 ID
 * 你需要在您的 AppDelegate 中实现该方法返回您在 IM 控制台上的证书 ID
 *
 * 特别注意的是，该证书ID使用时需要对应您的运行环境：
 * 使用开发环境的证书ID，可以直接在Xcode上运行测试（Debug 即可调试推送）。
 * 使用生产环境的证书ID，需要您 Archive 出 release 包后进行测试。
 */
- (int)offlinePushCertificateID;

/**
 * 收到远程推送（在线收到后触发、离线时点击通知栏通知触发）
 * 如果要自定义解析收到的远程推送通知，请在您的 AppDelegate 中实现该方法
 *
 * @note
 *  - 如果返回 YES， TIMPush 将不在执行内置的 TUIKit 离线推送解析逻辑，完全交由您自行处理；
 *  - 如果返回 NO，TIMPush 将继续执行内置的 TUIKit 离线推送解析逻辑，继续回调 - navigateToBuiltInChatViewController:groupID: 方法。
 */
- (BOOL)onRemoteNotificationReceived:(nullable NSString *)notice;

/**
 * 点击通知栏离线推送的通知后，跳转到自定义页面
 * 如果要实现跳转到聊天列表，请在您的 AppDelegate 中实现如下方法
 *
 * @note
 *  - TIMPush 默认已经从离线推送中解析出当前推送的 userID 和 groupID
 *  - 如果 groupID 不为空，说明当前点击的是群聊离线消息
 *  - 如果 groupID 为空且 userID 不为空，说明当前点击的是单聊离线消息
 */
- (void)navigateToBuiltInChatViewController:(nullable NSString *)userID
                                    groupID:(nullable NSString *)groupID NS_SWIFT_NAME(navigateToBuiltInChatViewController(userID:groupID:));

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                      （二）高级推送配置
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 主 APP 和 NSNotification Service Extension 所属的 App Group ID
 * AppGroupID 标识当前主 APP 和 Extension 之间共享的 APP Group，需要在主 APP 的 Capability 中配置 App Groups 能力。
 * 可以从苹果开发者官网获取。
 */
- (NSString *)applicationGroupID;

@end

NS_ASSUME_NONNULL_END
