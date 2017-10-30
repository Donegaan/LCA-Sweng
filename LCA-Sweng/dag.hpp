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
#include <stack>
#include <limits.h>

using namespace std;
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

class Graph
{
    int V;    // No. of vertices
    list<AdjListNode> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int x, int y, int w);   // to add an edge to graph, x = vertex number, y= value, w=weight
    bool isCyclic();    // returns true if there is a cycle in this graph
    stack<int> path(int nodeKey,stack<int> &Stack,int position); // Returns true if there is a path between two given nodes.
    int LCA(int num1, int num2); // Finds the lowest common ancestor of two given nodes in graph.
};

