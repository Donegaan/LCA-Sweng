//
//  dag.hpp
//  LCA-Sweng
//
//  Created by Andrew Donegan on 30/10/2017.
//  Copyright © 2017 Andrew Donegan. All rights reserved.
//

//-------
// Code from: http://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
//-------

#include<iostream>
#include <list>
#include <stack>
#include <limits.h>
#include <stdio.h>
#define INF INT_MAX
using namespace std;

// Graph is represented using adjacency list. Every node of adjacency list
// contains vertex number of the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

// Class to represent a graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices'
    
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
    
    // A function used by shortestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
    
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
    
    // Finds shortest paths from given source vertex
    void shortestPath(int s);
};

