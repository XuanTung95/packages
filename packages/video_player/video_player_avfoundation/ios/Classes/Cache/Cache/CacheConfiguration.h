// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import <Foundation/Foundation.h>
#import "ContentInfo.h"

@interface CacheConfiguration : NSObject <NSCopying>

+ (NSString *)configurationFilePathForFilePath:(NSString *)filePath;

+ (instancetype)configurationWithFilePath:(NSString *)filePath error:(NSError **)error;

@property(nonatomic, copy, readonly) NSString *filePath;
@property(nonatomic, strong) ContentInfo *contentInfo;
@property(nonatomic, strong) NSURL *url;

- (NSArray<NSValue *> *)cacheFragments;

@property(nonatomic, readonly) float progress;

#pragma mark - update API

- (void)save;
- (void)addCacheFragment:(NSRange)fragment;
- (void)addDownloadedBytes:(long long)bytes spent:(NSTimeInterval)time;

@end

@interface CacheConfiguration (Convenient)

+ (BOOL)createAndSaveDownloadedConfigurationForURL:(NSURL *)url error:(NSError **)error;

@end