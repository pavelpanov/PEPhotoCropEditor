//
//  PECropViewController.h
//  PhotoCropEditor
//
//  Created by kishikawa katsumi on 2013/05/19.
//  Copyright (c) 2013 kishikawa katsumi. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PECropViewControllerDelegate;

@interface PECropViewController : UIViewController

@property (nonatomic, strong) IBOutlet UIButton *cancelButton;
@property (nonatomic, strong) IBOutlet UIButton *doneButton;
@property (nonatomic, strong) IBOutlet UIButton *resetButton;
@property (nonatomic, strong) IBOutlet UIButton *squareButton;

@property (nonatomic, weak) id<PECropViewControllerDelegate> delegate;
@property (nonatomic) UIImage *image;

@property (nonatomic) BOOL keepingCropAspectRatio;
@property (nonatomic) CGFloat cropAspectRatio;

@property (nonatomic) CGRect cropRect;
@property (nonatomic) CGRect imageCropRect;

@property (nonatomic) BOOL toolbarHidden;

@property (nonatomic, assign, getter = isRotationEnabled) BOOL rotationEnabled;

@property (nonatomic, readonly) CGAffineTransform rotationTransform;

@property (nonatomic, readonly) CGRect zoomedCropRect;

@property (nonatomic) CGRect cropViewRect;
@property (nonatomic) UIColor *cropViewOverlayColor;


- (void)resetCropRect;
- (void)resetCropRectAnimated:(BOOL)animated;

- (IBAction)cancel:(id)sender;
- (IBAction)done:(id)sender;
- (IBAction)original:(id)sender;
- (IBAction)square:(id)sender;

@end

@protocol PECropViewControllerDelegate <NSObject>
@optional
- (void)cropViewController:(PECropViewController *)controller didFinishCroppingImage:(UIImage *)croppedImage;
- (void)cropViewController:(PECropViewController *)controller didFinishCroppingImage:(UIImage *)croppedImage transform:(CGAffineTransform)transform cropRect:(CGRect)cropRect;
- (void)cropViewControllerDidCancel:(PECropViewController *)controller;
- (void)cropViewControllerDidChangeCropArea:(PECropViewController*)controller;
@end
