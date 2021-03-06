//
//  LCA-main.hpp
//  LCA-Sweng
//
//  Created by Andrew Donegan on 10/10/2017.
//  Copyright © 2017 Andrew Donegan. All rights reserved.
//

#ifndef LCA_main_hpp
#define LCA_main_hpp

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

// A Bianry Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * newNode(int k);

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(Node *root, std::vector<int> &path, int k);

// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(Node *root, int n1, int n2);

#endif /* LCA_main_hpp */
