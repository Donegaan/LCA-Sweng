//
//  Testing.cpp
//  LCA-Sweng
//
//  Created by Andrew Donegan on 10/10/2017.
//  Copyright © 2017 Andrew Donegan. All rights reserved.
//

#include "LCA-main.hpp"
#include "dag.hpp"
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
        REQUIRE((findPath(testNode, testPath, NULL))==false);
        // To see if it will run with a null value passed as the Node
        REQUIRE((findPath(NULL, testPath, 1))==false);
    }

    SECTION("Testing the LCA with a null value"){
        // NULL node
        REQUIRE((findLCA(NULL, 6, 2))==-1);
    }

    SECTION("Testing to make sure you cannot access or create a null node"){
        REQUIRE((testNode->key)==NULL); // No key given so it should be NULL.
        REQUIRE((newNode(NULL))==NULL); // Key given is NULL so it shouldn't create a new node.
    }
}

TEST_CASE("Testing successful cases"){
    struct Node* testNode = (struct Node*) malloc(sizeof(struct Node));
    testNode = newNode(1);
    testNode->left = newNode(2);
    testNode->right = newNode(3);
    testNode->left->left = newNode(4);

    SECTION("Testing LCA"){
        //Test LCA of 2 and 3, should be 1
        REQUIRE((findLCA(testNode, 2, 3))==1);
        //Testing LCA of 2 and 4, should be 2
        REQUIRE((findLCA(testNode, 2, 4))==2);
    }

    SECTION("Testing finding a path"){
        std::vector<int> testPath;
        // Test when a key is the root's key
        REQUIRE((findPath(testNode, testPath, 1))==true);
        // Test if a key is in the right subtree
        REQUIRE((findPath(testNode, testPath, 3))==true);
        // Test is a key is in the left subtree
        REQUIRE((findPath(testNode, testPath, 4))==true);
    }
}

//Test case for unsuccessful things that are not null
TEST_CASE("Testing unsuccessful cases that are not null"){
    struct Node* testNode = (struct Node*) malloc(sizeof(struct Node));
    testNode = newNode(1);

    SECTION("Testing LCA"){
        //Test LCA of 2 and 3, should be -1
        REQUIRE((findLCA(testNode, 2, 3))==-1);
        //Testing LCA of 2 and 4, should be -1
        REQUIRE((findLCA(testNode, 2, 4))==-1);
    }

    SECTION("Testing finding a path"){
        std::vector<int> testPath;
        // Test when a key is less than the root's key
        REQUIRE((findPath(testNode, testPath, 0))==false);
        // Test if a nonexistent key is in the right subtree with no subtree
        REQUIRE((findPath(testNode, testPath, 3))==false);
        // Test is a nonexistent key is in the left subtree with no subtree
        REQUIRE((findPath(testNode, testPath, 4))==false);
        testNode->left = newNode(2);
        testNode->right = newNode(3);
        //Testing if a nonexistent key is in a right subtree with a right subtree
        REQUIRE((findPath(testNode, testPath, 4))==false);
        //Testing if a nonexistent key is in a left subtree with a left subtree
        REQUIRE((findPath(testNode, testPath, 5))==false);

    }

}

//-----------
//DAG tests
//-----------

TEST_CASE("Testing if graph is cyclic"){

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    SECTION("Checking for cycle"){
        REQUIRE(g.isCyclic()==false); // Shows thats the graph does not have a cycle
    }

    
    g.addEdge(2, 0); // To create a cycle
    SECTION("Checking for existing cycle"){
        REQUIRE(g.isCyclic());
    }
}


TEST_CASE("Test path"){
    
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    
    SECTION("Path of existing Nodes"){
        stack<int>stack;
        stack = g.path(0, stack, 0);
        REQUIRE(stack.top()==0);
        stack = g.path(2, stack, 0);
        REQUIRE(stack.top()==2);
    }
}

TEST_CASE("Testting LCA"){
    
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    
    SECTION("Checking LCA of nodes"){
        REQUIRE(g.LCA(0, 2)==0);
        REQUIRE(g.LCA(1, 2)==1);
        REQUIRE(g.LCA(2, 5)==2);
        REQUIRE(g.LCA(5, 2)==-1);
        REQUIRE(g.LCA(10, 11)==-1); // Doesn't exist
    }
}





