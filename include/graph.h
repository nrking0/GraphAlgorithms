#pragma once

#include <vector>

using namespace std;

class Graph {
    public:
        Graph(int nodes);
        ~Graph();
        void addEdge(int a, int b);
        Graph getTranspose();

        void print();

    private:
        vector<int>* adjacency_list;  
        int nodes;  
};