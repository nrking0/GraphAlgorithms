#include <iostream>
#include "include/graph.h"
#include "include/connected-component.h"
#include <fstream>
#include <vector>

using namespace finalproject;

int main() {
    Graph g(5105039);

    std::ifstream input_file("../data/web-data.txt");
    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }
    // g.print();

    ConnectedComponent c;
    std::vector<std::vector<int>> vec = c.kosaraju(g);
    std::cout << vec.size() << std::endl;
    return 0;
}
