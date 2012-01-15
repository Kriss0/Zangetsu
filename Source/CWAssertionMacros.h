/*
//  CWAssertionMacros.h
//  Zangetsu
//
//  Created by Colin Wheeler on 1/14/12.
//  Copyright (c) 2012. All rights reserved.
//

Copyright (c) 2011 Colin Wheeler

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#import <SenTestingKit/SenTestingKit.h>

/**
 Throws an assertion when the objects are equal
 */
#define CWAssertNotEqualsObjects(o1, o2, description, ...) \
do { \
	id object1 = o1; \
	id object2 = o2; \
	if([object1 isEqualTo:object2] || \
		(object1 == object2)) { \
			STFail(description, ##__VA_ARGS__); \
	} \
}while(0)
		
#define CWAssertEqualsStrings(object, string) \
do { \
	NSString *_aString = (NSString *)object; \
	if(![_aString isEqualToString:string]) { \
		STFail(@"The Object %s is not equal to the string '%@'", #object , string); \
	} \
}while(0)
