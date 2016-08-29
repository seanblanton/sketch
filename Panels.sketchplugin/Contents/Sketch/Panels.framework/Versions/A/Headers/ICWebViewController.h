//
//  SamplesViewController.h
//  Panels
//
//  Created by Tomas Hanacek on 06/01/16.
//  Copyright © 2016 Tomas Hanacek. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ICPanel.h"
#import "ICPanelViewControllerProtocol.h"
#import "ICPanelView.h"

@class ICSketchApi;
@class ICWebViewController;

@protocol ICWebViewControllerDelegate <NSObject>

@required
- (void)command:(id)command forIdentifier:(NSString *)identifier withArguments:(NSDictionary *)arguments;
- (void)setGlobalSettingsValue:(id)value forKey:(NSString *)key;
- (id)globalSettingsValueForKey:(NSString *)key;
- (void)resizePanel:(CGSize)newSize;
- (void)togglePanel:(NSString *)identifier;
- (void)showFullscreen;
- (void)hideFullscreen;

@end

@interface ICWebViewController : NSViewController <ICPanelViewControllerProtocol>

@property (nonatomic, weak) id<ICWebViewControllerDelegate> delegate;
@property (nonatomic, weak) ICSketchApi *sketchApi;
@property (nonatomic, retain) ICPanelView *panelView;
- (id)initWithPanel:(ICPanel *)panel;
- (void)callback:(NSString *)data;
- (void)callAction:(NSString *)identifier;
- (void)callAction:(NSString *)identifier data:(NSString *)data;
- (void)setCommandIdentifier:(NSString *)identifier;
- (void)callCommand:(NSString *)identifier withArguments:(NSDictionary *)arguments;
- (ICPanel *)panel;

@end
