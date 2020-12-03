#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

#define MAX_CUST (5) //upper limit on customers, from driver

struct node {
    int f; //flag: 0 for cust and 1 for plates
    int cust; //customer id
    float weight; //weight of the plate
    int num; //number of plates
};

//occurence is called by its own forked process to check of deadlock conditions
void occurrence (char *input) {
    //attempt to open the file
    FILE *fp;
    fp = fopen(input, "r");
    if (fp == NULL) {
        fprintf(stderr,"fopen() failed!\n");
        exit(1);
    }
    //create buffer variables, first line is number of weights
    char line[256];
    if (fgets(line, 256, fp) == NULL) {
        fprintf(stderr,"file is empty!\n");
        exit(1);
    }
    //pasre length info from first line
    int n = strtol(line, NULL, 0);
    printf("Lines: %d\n", n);
    struct node nodes[n + MAX_CUST];
    Graph g = makeGraph(n);
    //cycle through lines recording weights
    for(int i = 0; i < n; i++) {
        if(fgets(line, 256, fp) == NULL) {
            fprintf(stderr, "Less data than expected!\n");
            exit(1);
        }
        char *pch = strtok(line, ";");
        float weight = strtof(pch, NULL);
        pch = strtok(NULL, "\n");
        int num = strtol(pch, NULL, 0);
        nodes[i].weight = weight;
        nodes[i].num = num;
        nodes[i].f = 1;
    }
    int k = n;
    //MAIN LOOP
    /* pseudocode while sorting out implementation details
     * while(RUNNING) {
     * //UPDATE RESOURCE GRAPH
     *  if(NEW_CUSTOMER) {
     *      nodes[k].f = 0;
     *      nodes[k].cust = CUST_ID;
     *      newNode(g);
     *  }
     *  if(NEW_REQUEST) {
     *      insertEdge(g, REQUESTER, REQUESTEE);
     *  }
     *  if(RESOURCE_RESERVED) {
     *      insertEdge(g, RESOURCE, HOLDER);
     *  }
     *  if(RESOURCE_RELEASED) {
     *      removeEdge(g, RESOURCE, HOLDER);
     *  }
     *  //CHECK FOR DEADLOCK
     *  if(hasLoop(g)) {
     *      recovery();
     *  }
     * }
     */
}

void recovery() {
    //No pseudocode, too dependant on driver implementation
    //Function will identify where in the resource graph the deadlock occurred then
    //decide in favor of the customer with more reps
}

int main() {
    /*
    //Test of graph implementation
    //Graph A
    struct graph* a = makeGraph(3);
    insertEdge(a,0,1);
    insertEdge(a,1,2);
    insertEdge(a,2,0);

    //Graph B
    struct graph* b = makeGraph(5);
    insertEdge(b,0,1);
    insertEdge(b,0,3);
    insertEdge(b,1,2);
    insertEdge(b,1,4);
    insertEdge(b,2,0);
    insertEdge(b,2,3);
    insertEdge(b,3,1);
    insertEdge(b,3,4);
    insertEdge(b,4,0);
    insertEdge(b,4,2);

    //Graph C
    Graph c = makeGraph(4);
    insertEdge(c,0,2);
    insertEdge(c,0,3);
    insertEdge(c,1,2);
    insertEdge(c,3,2);
    //insertEdge(c, 1, 0);


    //Loop Test
    printf("\nLOOP CHECK:\n");
    printf("A: %d\n", hasLoop(a));
    printf("B: %d\n", hasLoop(b));
    printf("C: %d\n", hasLoop(c));
    */
    occurrence("weights.txt");
    return 0;
}

