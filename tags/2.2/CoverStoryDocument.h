//
//  CoverStoryDocument.h
//  CoverStory
//
//  Created by dmaclach on 12/20/06.
//  Copyright 2006-2007 Google Inc.
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not
//  use this file except in compliance with the License.  You may obtain a copy
//  of the License at
// 
//  http://www.apache.org/licenses/LICENSE-2.0
// 
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
//  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
//  License for the specific language governing permissions and limitations under
//  the License.
//


#import <Cocoa/Cocoa.h>
#import "CoverStoryCodeViewTableView.h"

@class CoverStoryCoverageSet;

@interface CoverStoryDocument : NSDocument<CoverStoryCodeViewTableViewDelegateProtocol> {
 @private
  IBOutlet CoverStoryCodeViewTableView *codeTableView_;  // the code table
  IBOutlet NSArrayController *sourceFilesController_;
  IBOutlet NSProgressIndicator *spinner_;
  NSString *filterString_;
  volatile BOOL openingInThread_;  // Are we opening our files in a thread
  CoverStoryCoverageSet *dataSet_;
}

// Opens up the source code file in Xcode.
- (void)openSelectedSource;
- (NSString *)filterString;
- (void)setFilterString:(NSString *)string;
- (IBAction)setUseWildcardPattern:(id)sender;
- (IBAction)setUseRegularExpression:(id)sender;
@end