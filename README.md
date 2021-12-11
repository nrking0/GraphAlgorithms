# CS225 Final Project
Final project for **jhuan35, nrking2, ep7, and av13**. For this project we created algorithms to analyze web graphs from the [**Stanford Large Network Dataset Collection**](http://snap.stanford.edu/data/). Our data set is in a text file that can be viewed in the directory labeled *"/data"*. Additionally our main project code can be found in three main directories. The header files are in the "*/include*" directory. Our source files are in the "*/src*" directory. Finally, our test files are in the "*/test*" directory. There is additionally, our "*main.cpp*" file on the top-level of the project. All output of this projects puts results directly into the console.

# Running the Project
This project uses cmake to create a makefile and install catch2. Use the following commands to build and run the project:
1. `cd build`
2. `cmake ..`
3. `make` (additionally, you may use `make test` or `make main` to make either executable individually)
4. `./main`

Please make sure to run any commands related to running the project within the build folder. Additionally, make sure to uncomment the correct lines from main in regards to file path when reading in the graph data.

Currently main will ingest the web graph from and run our algorithms on them. There are commented out lines to print more in-depth information that you can uncomment if you would like to print out the nodes of the graph or all of the connected components of the graph. 


## Commands to run main if you do not have cmake:
1. `g++ src/graph.cc src/connected-component.cc ./main.cpp -o main -std=c++11`
2. `./main`

*Note: Unfortunately, you will not be able to run the testing suite without cmake as cmake is used to install the catch2 dependency.*


# Running the Test Suite
To run the testing suite, follow the same instructions as above to build the make files, then simply run:

1. `cd build`
2. `make test`
3. `./test` 

Results of tests should directly be shown in the console.
