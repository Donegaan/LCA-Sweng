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



//Test case for Null values

TEST_CASE("Testing null values for all functions","null"){
    struct Node* testNode = (struct Node*) malloc(sizeof(struct Node));
    
    SECTION("Find path of Null"){
        std::vector<int> testPath;
        //To see if it will run with a null value passed as the int value.
        //
        //REQUIRE((findPath(testNode, testPath, NULL))==false);
        //
        // To see if it will run with a null value passed as the Node
        REQUIRE((findPath(NULL, testPath, 1))==false);
    }
    
    SECTION("Testing the LCA with a null value"){
        // NULL node
        REQUIRE((findLCA(NULL, 6, 2))==-1);
    }
    
    SECTION("Testing to make sure you cannot access or create a null node"){
        REQUIRE((testNode->key)==NULL);
        //REQUIRE((newNode(NULL))==NULL);
    }
}

