//
//  ViewController.h
//  tendril-test
//
//  Created by Beaudry Kock on 7/31/12.
//  Copyright (c) 2012 Beaudry Kock / Better World Coding. All rights reserved.
//
//  Permission is given to use this source code file, free of charge, in any
//  project, commercial or otherwise, entirely at your risk, with the condition
//  that any redistribution (in part or whole) of source code must retain
//  this copyright and permission notice. Attribution in compiled projects is
//  appreciated but not required.

#import <UIKit/UIKit.h>
#import "SharedConstants.h"
#import "BKTendrilConnect.h"



@interface ViewController : UIViewController <BKTendrilConnectDelegateProtocol, UIActionSheetDelegate>
{
    BKTendrilConnect *tendrilConnect;
    UITextView *output;
}

@property (nonatomic, weak) IBOutlet UITextView *output;
@property (nonatomic, strong) BKTendrilConnect *tendrilConnect;

-(IBAction)getConsumptionInLastDay:(id)sender;
-(IBAction)getUserInformation:(id)sender;
-(IBAction)checkAccessToken:(id)sender;

@end
