#include <iostream>
#include "include/graph.h"
#include <fstream>

using namespace finalproject;

int main() {
    Graph g(5105039);
    // g.addEdge(0,1);
    // g.addEdge(1,1);
    // g.addEdge(2,1);
    // g.addEdge(3,1);
    // g.addEdge(4,1);

    std::ifstream input_file("data/web-data.txt");
    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    g.print();
    return 0;
}
