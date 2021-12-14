# Week 1
For this week we started off by creating the team contract and deciding on the basic logistics of our group during this project. Additionally, we created the initial draft of our proposal. We spent the rest of the week looking into the best way for us to create a graph class and ingest our data set from its text file. Finally, we continued to do research on our chosen algorithms to plan on future implementation.

# Week 2
During week two, we recieved feedback on our proposal and realized that our dataset being unweighted made Dijkstra's Algorithm not sensible as a choice for one of our algorithms. We spent time discussing how we would want to move forward. We ended up deciding to stick with the current data set and picking a new algorithm that could work with an unweighted dataset. We discussed did research into the other listed algorithms that were suggested so we could plan out a new propsal to work on. 

# Week 3
For week 3 we finalized our new ideas for the adapted project proposal. We decided the an algorithm that identifies strongly connected components in a graph would be a great replacement for Dijkstra's Algorithm. We started research on this new algorithm and how it could be implemented for our projects. Additionally, we began implementing the graph class in the project. The graph was represented with an adjacency list. Additionally, we overloaded the insertion operator so that a graph could easily be converted from a text file into the graph class. 

# Week 4
For week 4 we started working on implementing algorithms. We started development of the connected components algorithm. More specifically we used Kosaraju's algorithm that uses two DFS traversals of the graph to identify all of the different connected components in the graph. Additionally, we created a shortest path algorithm utilizing a BFS traversal of the graph. This will return the shortest path between any two nodes of the graph. Finally, we also started work on building out some tests for the different algorithms that we were implementing.

# Week 5
We completed a lot of tasks in the final week. We implmented the PageRank algorithm by using the Eigen library. We wrote a page-rank class that performs this algorithm by representing our adjacency list as a sparse matrix, transforming it into a transition matrix that represents probabilities of going to nodes, and then running power iteration with the transition matrix to find the steady-state vector. We also wrote a lot more tests for BFS, getShortestPath, Kosaraju's, and Page Rank. We added many comments for the graph class. We completed a Google Presentation for our project and then met together as a group to record our video. 
