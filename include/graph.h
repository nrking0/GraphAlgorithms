#pragma once

#include <vector>
#include <iostream>

using namespace std;

namespace finalproject {

class Graph {
    public:
        Graph(int nodes);
        ~Graph();
        void addEdge(int a, int b);
        Graph getTranspose();
        friend istream& operator>>(istream& is, Graph& g);
        void print();
        bool isNode(int a, int b) const;
        vector<int>* getList() const;
        int getNodes() const;
        void BFS(int source);
        void printShortestPath(int dest);

    private:
        vector<int>* adjacency_list;  
        int nodes;  
        // Define a source node for the graph. This is changed when BFS is called.
        int source;
        // Contains predecessor of every node. Only is populated after BFS is called with an arbitrary source node.
        vector<int> predecessor;
        // Contains distance from arbitrary source to any node. Only is populated after BFS is called with an arbitrary source node.
        vector<int> distance;
};

}
