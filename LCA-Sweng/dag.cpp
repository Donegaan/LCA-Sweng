//
//  dag.cpp
//  LCA-Sweng
//
//  Created by Andrew Donegan on 30/10/2017.
//  Copyright © 2017 Andrew Donegan. All rights reserved.
//

//------
// Code from: http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
//------

#include "dag.hpp"

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int x, int y, int w)
{
    AdjListNode node(y,w);
    adj[x].push_back(node); // Add w to v’s list.
}

bool Graph::isCyclic()
{
    list<AdjListNode>::iterator iter; // This is the stating node, this function goes through each node, it compares adjacent node keys
    
    for(int i=1;i<=V;i++){
        for(iter=adj[i].begin(); iter != adj[i].end(); ++iter){
            int tmp=iter->getV();
            if(tmp==0) // If the nodes key is the same as root (0) then there is a cycle.
                return true;
        }
    }
    return false;
}

stack<int> Graph:: path(int nodeKey,stack<int> &Stack,int position){ // Gets node and pushes the value onto the stack.
    //Stack is the route being search through.
    list<AdjListNode>:: iterator iter; // Reference to first node
    stack<int> pathStack = Stack;
    
    // Iterate through all nodes and their array of vertices
    for(iter=adj[position].begin();iter!=adj[position].end();++iter){
        int tempKey=iter->getV(); // Key of current node
        if(nodeKey==tempKey){ // Found the nodeKey we are looking for
            pathStack.push(tempKey);
            return pathStack;
        }else{
            pathStack.push(tempKey);
            return path(nodeKey, pathStack, tempKey);
        }
    }
    return Stack;
}

int Graph::LCA(int num1, int num2){
    
    if (!isCyclic()){
        for (int i=0;i<V;i++){
            stack<int>path1 = path(num1,path1,0);// Paths for nodes passed in
            stack<int>path2 = path(num2,path2,0);
            while (!path1.empty()) {
                int topP1=path1.top(); // Gets top of the first path
                while (!path2.empty()) {
                    if(topP1==path2.top()){
                        return topP1;   // This returns lowest common ancestor
                    }
                    path2.pop(); // take top off of stack
                }
                path1.pop();
            }
        }
    }
    return -1;
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.addEdge(5, 6, 3);
    
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
