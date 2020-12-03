//File: graph.h
//By: Joshua Minton
//Description: An implementation of graphs using adjacency lists. Nodes are
//indexed with integers from 0. A function to find loops in the graph is also
//provided. Header for graph.c.
#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

//typedef for the graph struct. struct contains number of vertices, edges, and
//the adjacency list
typedef struct graph *Graph;

//initializes a graph struct with size vertices and no connections
Graph makeGraph(int size);

//destroys a graph by freeing all memory associated with it
void freeGraph(Graph);

//creates an edge from vertex a to vertex b in given graph. returns 0 if it works
int insertEdge(Graph, int a, int b);

//TODO: Implement this!!!
//create a new node with zero edges in given graph
int insertNode(Graph);

//returns 1 if an edge exists from a to b, 0 otherwise
int hasEdge(Graph, int a, int b);

//returns an array containing the indegree of each node. used in hasLoops()
int* indegrees(Graph);

//returns 1 if a loop exists in the subgraph of the given graph containing
//vertex start, returns 0 if no loops are found
int hasLoop(Graph);

//getters for v and e
int getV(Graph);

int getE(Graph);

void printGraph(Graph graph, char *name);

#endif //GRAPHS_GRAPH_H
