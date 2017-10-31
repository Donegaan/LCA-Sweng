//
//  dag.cpp
//  LCA-Sweng
//
//  Created by Andrew Donegan on 30/10/2017.
//  Copyright © 2017 Andrew Donegan. All rights reserved.
//

//------
// Code from: http://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
//------

#include "dag.hpp"

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int x, int y)
{
    AdjListNode node(y);
    adj[x].push_back(node); // Add w to v’s list.
}

bool Graph::isCyclic()
{
    list<AdjListNode>::iterator iter; // This is the stating node, this function goes through each node, it compares adjacent node keys
    
    for(int i=1;i<=V;i++){
        for(iter=adj[i].begin(); iter != adj[i].end(); ++iter){
            int temp=iter->getV();
            if(temp==0) // If the nodes key is the same as root (0) then there is a cycle.
                return true;
        }
    }
    return false;
}

stack<int> Graph:: path(int nodeKey,stack<int> &adjStack,int position){ // Gets node and pushes nodes in adjacency list onto the stack.
    //Stack is the route being search through.
    if(position<0||nodeKey<0){//cannot have negative nodes so an error is returned
        adjStack.push(-1);
        return adjStack;
    }
    if(position==nodeKey||position==V-1){//if node is found or tree has been searched return stack with found node
        adjStack.push(position);
        return adjStack;
    }
    stack<int> pathStack = adjStack;
    list<AdjListNode>::iterator iter;
    pathStack.push(position);
    //goes through all the nodes adjList which is a list of the nodes its connected to
    for(iter=adj[position].begin();iter!=adj[position].end();++iter){
        stack<int> temp=path(nodeKey, pathStack,iter->getV());
        if(temp.top()==nodeKey){//if the key is at the top of the stack return it
            return temp;
        }
    }
    return pathStack;
    
}

int Graph::LCA(int num1, int num2){
    
    if (!isCyclic()){
        for (int i=0;i<V;i++){
            stack<int>path1;// Paths for nodes passed in
            stack<int>path2;
            path1 = path(num1,path1,0);
            path2 = path(num2,path2,0);
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




//int main()
//{
//
//    // 0, 1, 2, 3, 4, 5 with following mappings:
//    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
//    Graph g(5);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 3);
//    g.addEdge(1, 2);
//    g.addEdge(2, 4);
//    g.addEdge(2, 5);
//
//    if(g.isCyclic())
//        cout << "Graph contains cycle";
//    else
//        cout << "Graph doesn't contain cycle ";
//    cout<<g.LCA(1, 2);
//
//    return 0;
//}

