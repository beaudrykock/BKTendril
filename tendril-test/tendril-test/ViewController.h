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

// NOTES...
// 1. see dev.tendrilinc.com for full API details
// 2. Full capabilities available at http://dev.tendrilinc.com/oauth/capabilities

// **FOR TESTING, DO NOT MODIFY**
#define PASSWORD @"password"
#define X_ROUTE @"sandbox"

// **MODIFY THESE**
//#warning Add your app key
#define CLIENT_ID @"3c7ed78d76c4f2a9b1b616764b7e968f" // app key

//#warning Add your app secret
#define CLIENT_SECRET @"e98c50845baf67ce9792996cb363bcbb" // app secret

// **MODIFY THESE WITH PREFERRED USER FROM http://dev.tendrilinc.com/docs/sample_users**
#define USERNAME @"kurt.cobain@tendril.com"
#define USER_ID 55
#define EXTERNAL_ACCOUNT_ID @"aid_kc"

// Use short_lived for 3 second access token, to test refresh code
// other options: user_information, location, consumption, pricing, device, user_profile, comparisons, greenbutton, offline_access
#define SCOPE @"short_lived"
#define GRANT_TYPE @"password"

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
