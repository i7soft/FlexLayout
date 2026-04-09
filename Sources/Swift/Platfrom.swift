//
//  macOS.swift
//  FlexLayout
//
//  Created by shiqiren on 2026/4/9.
//

#if os(macOS)

import AppKit

public typealias UIView = NSView
public typealias UIColor = NSColor
public typealias UIFont = NSFont
public typealias UIEdgeInsets = NSEdgeInsets
public typealias UIScreen = NSScreen
public typealias UITextView = NSTextView
public typealias UITextField = NSTextField
public typealias UIImageView = NSImageView

extension NSView {
    var boundsSize: CGSize {
        return bounds.size
    }
}

#endif
