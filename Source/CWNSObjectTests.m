//
//  CWNSObjectTests.m
//  Zangetsu
//
//  Created by Colin Wheeler on 12/18/10.
//  Copyright 2010. All rights reserved.
//

#import "CWNSObjectTests.h"
#import "NSObjectAdditions.h"


@implementation CWNSObjectTests

/**
 Testing the strong associated reference to make sure it works
 */
-(void)testStrongReferenceObjcAssociation
{
	NSString *key1 = @"key1";
	
	NSObject *object = [[NSObject alloc] init];
	
	[object cw_associateValue:@"All Hail the Hypnotoad" withKey:key1];
	
	STAssertTrue([[object cw_valueAssociatedWithKey:key1] isEqualToString:@"All Hail the Hypnotoad"],
				 @"ObjC Associated Objects should be equal but are not!");
}

-(void)testWeakObjcAssociation
{
	NSString *key3 = @"key3";
	
	NSObject *object = [[NSObject alloc] init];
	
	[object cw_associateWeakValue:@"Hypnotoad Season 3"
						  withKey:key3];
	
	STAssertTrue([[object cw_valueAssociatedWithKey:key3] isEqualToString:@"Hypnotoad Season 3"],
				 @"Objc Associated Objects should be equal but are not!");
}

@end
