//File: graph.c
//By: Joshua Minton
//Description: An implementation of graphs using adjacency lists. Nodes are
//indexed with integers from 0. A function to find loops in the graph is also
//provided. Implements header graph.h.
#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

//graph structure, with a substructure for the adjacency lists
struct graph {
    int v; //number of vertices
    int e; //number of edges
    //substruct for the adjacency lists
    struct lists {
        int n; //number of neighbors
        int size; //size of array
        int list[]; //list data
    } *alist[];
};

//creates a graph with size vertices and no edges
Graph makeGraph(int size) {
    //initialize memory for the graph
    Graph graph;
    graph = malloc(sizeof(struct graph) + sizeof(struct lists *) * size);
    if(!graph) {
        fprintf(stderr, "malloc() failed!");
        exit(-1);
    }
    //initialize struct variables
    graph->v = size;
    graph->e = 0;

    //initialize each adjacency list to zero
    for(int i = 0; i < size; i++) {
        graph->alist[i] = malloc(sizeof(struct lists)); //reserve memory for each list struct
        if(!(graph->alist[i])) {
            fprintf(stderr, "malloc() failed!");
            exit(-1);
        }
        graph->alist[i]->size = 0;
        graph->alist[i]->n = 0;
    }

    return graph;

}

//destroy a graph in memory
void freeGraph(Graph graph) {
    //iteratively free each adjacency list
    for(int i = 0; i < graph->v; i++) {
        //free(graph->alist[i]->list);
        free(graph->alist[i]);
    }

    //finally, free the struct
    free(graph);
}
//defines comparison for sorting
static int intcmp(const void *a, const void *b) {
    return *((const int *) a) - *((const int *) b);
}
//creates an edge from vertex a to vertex b in given graph. returns 0 if succeeds
int insertEdge(Graph graph, int a, int b) {
    //check if request is valid
    if((a < 0) ||
       (b < 0) ||
       (a >= graph->v) ||
       (b >= graph->v)) {
        return -1; //fail if invalid
    }

    //check if the current list is large enough for the insertion. if not, expand the list.
    while(graph->alist[a]->size <= graph->alist[a]->n) {
        //double the size of the list and reallocate the required memory
        graph->alist[a]->size *= 2;
        graph->alist[a]->size++; //inc incase was 0
        graph->alist[a] = realloc(graph->alist[a], sizeof(struct lists) + sizeof(int) * graph->alist[a]->size);
    }

    //add the edge
    graph->alist[a]->list[graph->alist[a]->n++] = b;
    //increment the list size and the total edge count
    //graph->alist[a]->n++;
    graph->e++;
    //sorts the list to simplify searching
    //qsort(graph->alist[a]->list, graph->alist[a]->n, sizeof(int), intcmp);
    return 0;
}

void printGraph(Graph graph, char *name) {
    if(name != NULL) {
        printf("GRAPH %s:\n", name);
    }
    for(int i = 0; i < graph->v; i++) {
        printf("%d: ", i);
        if(graph->alist[i]->n != 0) {
            for (int j = 0; j < graph->alist[i]->n - 1; j++) {
                printf("%d, ", graph->alist[i]->list[j]);
            }
            printf("%d\n", graph->alist[i]->n - 1);
        }
        else {
            printf("\n");
        }
    }
}
//returns 1 if an edge exists from a to b, 0 otherwise
int hasEdge(Graph graph, int a, int b) {
    //check if request is valid
    if((a < 0) ||
       (b < 0) ||
       (a > graph->v) ||
       (b > graph->v)) {
        return -1; //fail if invalid
    }

    //search through the adjacency list to see if the edge exists
    //linear search could be unruly for large graphs
    for(int i = 0; i < graph->alist[a]->n; i++) {
        if(graph->alist[a]->list[i] == b) {
            return 1;
        }
    }
    return 0;
}

//returns the number of incoming edges of the node a; returns -1 if node does not exist
//used for hasLoop()
int* indegrees(Graph graph) {
    //creates an array of length v
    int* degrees = malloc(sizeof(int)*graph->v);
    //initializes this array to 0
    for(int i = 0; i < graph->v; i ++) {
        degrees[i] = 0;
    }
    //goes through every adjacency list in the graph
    for(int i = 0; i < graph->v; i++) {
        //goes through the adjacency list
        for(int j = 0; j < graph->alist[i]->n; j++) {
            //for each number in the list, increment the degree at that index
            degrees[graph->alist[i]->list[j]]++;
            //printf("DEBUG:\n\tindex = %d\n\ti = %d, j = %d\n", graph->alist[i]->list[j], i, j);
        }
    }

    return degrees;
}

int getV(Graph graph) {
    return graph->v;
}

int getE(Graph graph) {
    return graph->e;
}
//QUEUE IMPLEMENTATION FOR BFS, NOT IN HEADER
struct Queue {
    int *arr;
    int front;
    int back;
    int size;
    int max;
};

struct Queue* create(int cap) {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->arr = malloc(cap * sizeof(int));
    queue->front = 0;
    queue->back = cap - 1;
    queue->size = 0;
    queue->max = cap;
    return queue;
}

void enq(struct Queue* queue, int x) {
    if(queue->size == queue->max) return;
    queue->back = (queue->back + 1) % queue->max;
    queue->arr[queue->back] = x;
    queue->size++;
}

int deq(struct Queue* queue) {
    if(queue->size == 0) return -1;
    int x = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->max;
    queue->size--;
    return x;
}

//uses a modified breadth first search to find loops in the graph
int hasLoop(Graph graph) {
    int *indeg = indegrees(graph);
    struct Queue *q = create(graph->v);
    for(int i = 0; i < graph->v; i++) {
        if(indeg[i] == 0) {
            enq(q, i);
        }
    }
    int seen = 0;
    while(q->size > 0) {
        int n = deq(q);
        seen++;
        for(int i = 0; i < graph->alist[n]->n; i++) {
            indeg[graph->alist[n]->list[i]]--;
            if(indeg[graph->alist[n]->list[i]] == 0) {
                enq(q, graph->alist[n]->list[i]);
            }
        }
    }
    if(seen != graph->v) {
        return 1;
    }
    return 0;
}