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
        Graph getTranspose() const;
        friend istream& operator>>(istream& is, Graph& g);
        void print();
        bool isNode(int a, int b) const;
        vector<int>* getList() const;
        int getNodes() const;

    private:
        vector<int>* adjacency_list;  
        int nodes;  
};

}
