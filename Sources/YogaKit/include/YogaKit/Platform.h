//
//  Platform.h
//  FlexLayout
//
//  Created by shiqiren on 2026/4/9.
//

#pragma once

#if TARGET_OS_OSX
#import <AppKit/AppKit.h>

#define UIView NSView
#define UIColor NSColor
#define UIFont NSFont
#define UIEdgeInsets NSEdgeInsets
#define UITextView NSTextView
#define UITextField NSTextField
#define UIScreen NSScreen

/// MARK: - UIScreen
@interface NSScreen (Compat)
@property (nonatomic, readonly) CGFloat scale;
@end

@implementation NSScreen (Compat)
- (CGFloat)scale {
    return self.backingScaleFactor;
}
@end


/// MARK: - UIView
@interface NSView (Compat)
- (CGSize)sizeThatFits:(CGSize)size;
@end

@implementation NSView (Compat)

- (CGSize)sizeThatFits:(CGSize)size {
    // 默认使用 intrinsicContentSize
    CGSize intrinsic = self.intrinsicContentSize;

    // 如果传入 size 有约束，可以进行最小/最大限制
    CGFloat width = size.width > 0 ? MIN(size.width, intrinsic.width) : intrinsic.width;
    CGFloat height = size.height > 0 ? MIN(size.height, intrinsic.height) : intrinsic.height;

    return CGSizeMake(width, height);
}

@end


#else
#import <UIKit/UIKit.h>
#endif
