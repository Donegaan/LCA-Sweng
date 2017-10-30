//
//  dag.hpp
//  LCA-Sweng
//
//  Created by Andrew Donegan on 30/10/2017.
//  Copyright © 2017 Andrew Donegan. All rights reserved.
//

//------
// Code from: http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
//------


// A C++ Program to detect cycle in a graph
#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};
