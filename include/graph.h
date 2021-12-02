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

        private:
            vector<int>* adjacency_list;  
            int nodes;  
    };

}
