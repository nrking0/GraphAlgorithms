#include "../include/connected-component.h"
#include "../include/graph.h"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

namespace finalproject {

ConnectedComponent::ConnectedComponent() {
    components = new vector<vector<int>>();
    st = new stack<int>();
 }

 ConnectedComponent::~ConnectedComponent() {
     delete components;
     delete st;
 }



vector<vector<int>> ConnectedComponent::kosaraju(const Graph& g) {
    visited.clear();
    visited = vector<bool>(g.getNodes(), false);

    for (int i = 0; i < g.getNodes(); i++) {
        visit(i, g);
    }    

    visited.clear();
    visited = vector<bool>(g.getNodes(), false);
    Graph transpose = g.getTranspose();

    while(!st->empty()) {
        int n = st->top();
        st->pop();

        if (!visited[n]) {
            vector<int> component;
            assign(n, transpose, component);
            components->push_back(component);
        }

    }

    return *components; 
}

void ConnectedComponent::visit(int node, const Graph& g) {
    if (!visited[node]) {
        visited[node] = true;
        vector<int>& list = g.getList()[node];
        for (int i = 0; i < list.size(); i++) {
            visit(list[i], g);
        }
        st->push(node);
    }
}

void ConnectedComponent::assign(int node, const Graph& g, vector<int>& component) {
    if (!visited[node]) {
        visited[node] = true;
        component.push_back(node);
        for (int i : g.getList()[node]) {
            if (!visited[i]) {
                assign(i, g, component);
            }
        }
    }
}


vector<vector<int>> ConnectedComponent::getComponents() {
    return *components;
}

void ConnectedComponent::print() {
    for (vector<int> vec : *components) {
        if (vec.size() <= 1) continue;
        cout << "(";
        int i = 0;
        for (int a : vec) {
            if (i == vec.size() - 1) cout << a;
            else cout << a << ", ";
            i++;
        }
        cout << ")" << endl;
        cout << endl;
    }
}

void ConnectedComponent::printLargest() {
    int max = 0;
    int index = 0;
    int maxIndex = 0;
     for (vector<int> vec : *components) {
        if (vec.size() > max) {
            max = vec.size();
            maxIndex = index;
        }
        index++;
    }

    cout << "The largest component has a size of " << max << "nodes. The component contains the following nodes:";
    cout << "(";
        int i = 0;
        vector<int> vec = components->at(maxIndex);
        for (int a : vec) {
            if (i == vec.size() - 1) cout << a;
            else cout << a << ", ";
            i++;
        }
        cout << ")" << endl;
        cout << endl;
}

}