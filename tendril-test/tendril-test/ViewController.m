//
//  ViewController.m
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

#import "ViewController.h"

@implementation ViewController

#pragma mark - View lifecycle
- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.tendrilConnect = [[BKTendrilConnect alloc] init];
    [self.tendrilConnect setDelegate:self];
    [self.tendrilConnect authorize];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

#pragma mark - Test button actions
-(IBAction)getConsumptionInLastDay:(id)sender
{
    NSDate *date = [NSDate date];
    NSTimeInterval now = [date timeIntervalSince1970];
    NSTimeInterval twoDaysAgo = now-(3600*24*2);
    NSTimeInterval oneDayAgo = now-(3600*24);
    [self.tendrilConnect getConsumptionDataFrom:twoDaysAgo to:oneDayAgo];
}

-(IBAction)getCurrentMeterReading:(id)sender
{
    NSDate *date = [NSDate date];
    NSTimeInterval now = [date timeIntervalSince1970];
    [self.tendrilConnect getMeterReadingFrom:(now-3600) to:now];
}

-(IBAction)getUserInformation:(id)sender
{
    [self.tendrilConnect getUserInformation];
}

-(IBAction)checkAccessToken:(id)sender
{
    [self.tendrilConnect printAccessToken];
}

#pragma mark - BKTendrilConnect delegate methods
-(void)tendrilConnectDidReturnData:(NSDictionary*)jsonDict forConnectionType:(NSInteger)connectionType
{
    // consume your data here...
    // connectionType (referenced in SharedConstants) can be used to determine what kind of data should be expected
    
    [self.output setText:[jsonDict description]];
}


@end
