//
//  CWURLUtilitiesTests.m
//  Zangetsu
//
//  Created by Colin Wheeler on 12/3/11.
//  Copyright (c) 2011. All rights reserved.
//

#import "CWURLUtilitiesTests.h"
#import <Zangetsu/Zangetsu.h>

@implementation CWURLUtilitiesTests

-(void)testBasicBase64AuthHeader {
	NSString *authorizationHeaderString = CWURLAuthorizationHeaderString(@"TestAccount", @"TestPassword");
	NSString *const goodResultString = @"Basic VGVzdEFjY291bnQ6VGVzdFBhc3N3b3Jk";
	
	STAssertEqualObjects(authorizationHeaderString, goodResultString, @"Strings Should match given the input");
}

-(void)testBase64AuthHeaderWithNilData {
	STAssertNil(CWURLAuthorizationHeaderString(nil, @"TestPassword"), @"Returned String should be nil");
	STAssertNil(CWURLAuthorizationHeaderString(@"Test Account", nil), @"Returned String should be nil");
}

@end
