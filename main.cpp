#include <iostream>
#include "include/graph.h"
#include <fstream>

using namespace finalproject;

int main() {
    Graph g(5105039);

    std::ifstream input_file("data/web-data.txt");
    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    g.print();
    return 0;
}
