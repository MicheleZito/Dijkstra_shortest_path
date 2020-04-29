# Dijkstra_shortest_path
Implementation of the Dijkstra algorithm for shortest path problem

The code was firstly developed for Windows systems. This version is reviewed for Ubuntu 16.04 LTS, 'cause some functions or instructions weren't working.

To execute the program on a graph, you need to use a .txt file which describes the graph itsef. I will leave a .txt file for comparison. You must declare on the first line the number of nodes of the graph.
on the second line, after strating with a '#' you must declare the names of the nodes separated by other '#', ending the line with the same characters.

Then you must specify the adjacencies for each node
First you must declare the number of nodes adjacent, then on each line
The name of the adjacent node and the weight of the edge that bonds them separated by a ';'.
The name of the chosen node must be written as it was in the first line.

Obviously edges that connect two nodes, must have the same weight value in the adjacencies of the two nodes.

Example of file:

2
#One#Two#
1
Two;5
1
One;5
