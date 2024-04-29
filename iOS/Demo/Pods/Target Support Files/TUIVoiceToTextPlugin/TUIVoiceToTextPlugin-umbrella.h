#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "TUIVoiceToTextConfig.h"
#import "TUIVoiceToTextDataProvider.h"
#import "TUIVoiceToTextExtensionObserver.h"
#import "TUIVoiceToTextView.h"

FOUNDATION_EXPORT double TUIVoiceToTextPluginVersionNumber;
FOUNDATION_EXPORT const unsigned char TUIVoiceToTextPluginVersionString[];

