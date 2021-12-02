# Final Project Proposal

## Leading Question
* How can we find the shortest path between webpage nodes and also rank them on their popularity?
* Given any two specific web pages, what is the exact list of webpages in the shortest path between those two pages?
* What are the top ten webpages based on our pagerank algorithm?

## Dataset Acquisition and Processing
* For our dataset, we will be using the web-Google dataset from the Stanford Large Network Dataset Collection. 
    * This is an unweighted graph
    * Each Node represents a different website or endpoint on the web
    * Each edge is a connection between each endpoint on the internet
* We will download the dataset from the above webpage and store it as a file in our repo.
* We will parse the text file into an adjacency list that stores the nodes and edges.
* We will make a map where the first entry is a node, and the second entry is a vector of all the nodes that the first entry has a directed edge towards.
* Using an adjacency list should be more space-effective than a matrix of all the nodes.
* The dataset may have webpages that do not contain links to anywhere else, so these entries of our map will have empty vectors as their second entries.

## Graph Algorithms
* DFS for traversal
1. **Connected Components Algorithm**
    * We will be using Kosaraju's Algorithm
    * This algorithm will traverse through the given graph and then return the different groups of nodes that are grouped as connected components
    * The input would be an adjacency matrix
    * Effeciency would be **O(N + E)** where N is the number of Nodes and E is the number of edges
2. **Page Rank**
    * Given a graph, we will return a list of pages ranked based on popularity. Popularity refers to the number of edges connected to a node and the ranking of those    connected nodes. 
    * To use the Google page rank algorithm, we will need to construct a Markov matrix from our adjacency list to represent the probabilities of the nodes that a        given node could go to.
    * The input would be an adjacency matrix
    * Effeciency would be **O(N + E)** where N is the number of Nodes and E is the number of edges
  
## Timeline
* Week 1 - Research
* Week 2 - Research Start work on beginning project
* Week 3 - Try to do Connected components
* Week 4 - Try to do page ranking algorithm
* Week 5 - Finish up any code and work on final documents and presentation


