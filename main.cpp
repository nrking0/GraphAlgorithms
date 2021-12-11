#include <iostream>
#include "include/graph.h"
#include "include/connected-component.h"
#include <fstream>
#include <vector>

using namespace finalproject;

int main() {
    Graph g(281903);

    std::ifstream input_file("data/web-stanford.txt");
    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    // g.print();

    ConnectedComponent c;
    std::vector<std::vector<int>> vec = c.kosaraju(g);
    // c.print();
    std::cout << "Number of Connected Components: " << vec.size() << std::endl;
    
    return 0;
}
