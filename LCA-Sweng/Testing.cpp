//
//  Testing.cpp
//  LCA-Sweng
//
//  Created by Andrew Donegan on 10/10/2017.
//  Copyright © 2017 Andrew Donegan. All rights reserved.
//

#include "Testing.hpp"
#include "LCA-main.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>



//Null test case

TEST_CASE("Testing null values for all functions","null"){
    struct Node* testNode = (struct Node*) malloc(sizeof(struct Node));
    
    SECTION("Find path of Null"){
        std::vector<int> testPath;
        //To see if it will run with a null value passed as the int value.
        REQUIRE((findPath(testNode, testPath, NULL))==false);
        // To see if it will run with a null value passed as the Node
        REQUIRE((findPath(NULL, testPath, 1))==false);
    }
}
