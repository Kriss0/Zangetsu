//
//  CWTreeTests.m
//  Zangetsu
//
//  Created by Colin Wheeler on 7/15/11.
//  Copyright 2011. All rights reserved.
//

#import "CWTreeTests.h"
#import "CWTree.h"

@implementation CWTreeTests

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
}

-(void)testCWTreeRootNode {
    
    NSString *aString = [[NSString alloc] initWithString:@"Hello World!"];
    
    CWTree *tree1 = [[CWTree alloc] init];
    CWTreeNode *node1 = [[CWTreeNode alloc] initWithValue:aString];
    [tree1 setRootNode:node1];
    
    CWTree *tree2 = [[CWTree alloc] initWithRootNodeValue:aString];
    
    STAssertTrue([[tree1 rootNode] isNodeValueEqualTo:[tree2 rootNode]], @"Nodes should be equal");
    
    STAssertFalse([[tree1 rootNode] isEqualTo:[tree2 rootNode]], @"The Root nodes should not be equal because they are in different trees");
}

-(void)testTreeEquality {
    
    NSString *aStringVal = [[NSString alloc] initWithString:@"Hynotoad"];
    
    CWTree *tree1 = [[CWTree alloc] initWithRootNodeValue:aStringVal];
    CWTree *tree2 = [[CWTree alloc] initWithRootNodeValue:aStringVal];
    
    STAssertTrue([tree1 isEqualTo:tree2], @"Trees should be equal");
    
    CWTreeNode *node2 = [[CWTreeNode alloc] initWithValue:@"Cheez it!"];
    [[tree1 rootNode] addChild:node2];
    
    STAssertFalse([tree1 isEqualTo:tree2], @"Trees should not be equal now");
}

- (void)tearDown
{
    // Tear-down code here.
    
    [super tearDown];
}

@end
