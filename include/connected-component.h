#pragma once

#include <vector>
#include "graph.h"
#include <stack>

using namespace std;

namespace finalproject {

class ConnectedComponent {
    public:
        ConnectedComponent();
        vector<vector<int>> kosaraju(const Graph& g);
        vector<vector<int>> getComponents();
        void print();
        void printLargest();
        ~ConnectedComponent();

    private:
        vector<vector<int>>* components;
        vector<bool> visited;

        stack<int>* st;


        void visit(int node, const Graph& g);
        void assign(int node, const Graph& g, vector<int>& component);
};

}