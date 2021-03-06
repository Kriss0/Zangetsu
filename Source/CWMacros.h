/*
 *  CWMacros.h
 *  Gitty
 *
 *  Created by Colin Wheeler on 5/17/09.
 *  Copyright 2009. All rights reserved.
 *
 
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

//MARK: General Functions

#define NSDICT(...) [NSDictionary dictionaryWithObjectsAndKeys: __VA_ARGS__, nil]
#define NSARRAY(...) [NSArray arrayWithObjects: __VA_ARGS__, nil]
#define NSBOOL(_X_) [NSNumber numberWithBool:(_X_)]
#define NSSET(...) [NSSet setWithObjects: __VA_ARGS__, nil]

#define NSCOLOR(r,g,b,a) [NSColor colorWithCalibratedRed:r green:g blue:b alpha:a]
#define NSDEVICECOLOR(r,g,b,a) [NSColor colorWithDeviceRed:r green:g blue:b alpha:a]

//MARK: -
//MARK: Log Functions

#ifdef DEBUG
#	define CWPrintClassAndMethod() NSLog(@"%s%i:\n",__PRETTY_FUNCTION__,__LINE__)
#	define CWDebugLog(args...) NSLog(@"%s%i: %@",__PRETTY_FUNCTION__,__LINE__,[NSString stringWithFormat:args])
#else
#	define CWPrintClassAndMethod() /**/
#	define CWDebugLog(args...) /**/
#endif

#define CWLog(args...) NSLog(@"%s%i: %@",__PRETTY_FUNCTION__,__LINE__,[NSString stringWithFormat:args])

#define CWDebugLocationString() [NSString stringWithFormat:@"%s[%i]",__PRETTY_FUNCTION__,__LINE__]

//MARK: -
//MARK: NSAssert Functions

#ifdef DEBUG
#	define CWAssert(cond,desc) NSAssert(cond,desc)
#	define CWAssert1(cond,desc,a1) NSAssert1(cond,desc,a1)
#	define CWAssert2(cond,desc,a1,a2) NSAssert2(cond,desc,a1,a2)
#	define CWAssert3(cond,desc,a1,a2,a3) NSAssert3(cond,desc,a1,a2,a3)
#	define CWAssert4(cond,desc,a1,a2,a3,a4) NSAssert4(cond,desc,a1,a2,a3,a4)
#	define CWAssert5(cond,desc,a1,a2,a3,a4,a5) NSAssert5(cond,desc,a1,a2,a3,a4,a5)
#else
#	define CWAssert(...) /**/
#	define CWAssert1(...) /**/
#	define CWAssert2(...) /**/
#	define CWAssert3(...) /**/
#	define CWAssert4(...) /**/
#	define CWAssert5(...) /**/
#endif

#define CWAssertV(cond, ...) \
do { \
	if(!cond) { \
		[[NSAssertionHandler currentHandler] handleFailureInFunction:[NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding] \
																file:[NSString stringWithCString:__FILE__ encoding:NSUTF8StringEncoding] \
														  lineNumber:__LINE__ \
														 description:__VA_ARGS__]; \
	} \
} while(0);

/* Basis of this is from Stack Overflow
 http://stackoverflow.com/questions/2283987/xcode-call-stack-trace-on-assert
 Basically a simple assertion that spits the exact expression that failed out to log and
 also spits out the stack trace without the assertion handling frames
 */
#define CWAssertST(x,desc) \
do { \
	if (!(x)) { \
		[[NSAssertionHandler currentHandler] handleFailureInFunction:[NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding] \
																file:[NSString stringWithCString:__FILE__ encoding:NSUTF8StringEncoding] \
														  lineNumber:__LINE__ \
														 description:[NSString stringWithFormat:@"%s:%s failed assertion\nMessage:%@\n%@",__PRETTY_FUNCTION__, #x, desc, [NSThread callStackSymbols]]]; \
	} \
} while(0);

#define CWIBOutletAssert(_x_) \
do { \
	if(_x_ == nil) { \
		NSLog(@"IBOutlet Assertion: %s is nil and appears to not be hooked up!",#_x_); \
	} \
} while(0);

#define CWZeroLengthAssert(_x_) \
do { \
	if([_x_ length] == 0) { \
		[[NSAssertionHandler currentHandler] handleFailureInFunction:[NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding] \
																file:[NSString stringWithCString:__FILE__ encoding:NSUTF8StringEncoding] \
														  lineNumber:__LINE__ \
														 description:[NSString stringWithFormat:@"%s length is 0 (needs to be > 0)",#_x_]]; \
	} \
} while(0);

//MARK: -
//MARK: GCD Macros

#define CWGCDQueueLow() dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW,0)
#define CWGCDQueueNormal() dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT,0)
#define CWGCDQueueHigh() dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0)
#define CWGCDQueueBackground() dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND,0)
