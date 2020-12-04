// sync.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <driver.h>

#define MAX_CUST(5) // upper limit on customers, from driver

struct node {
	int f;
	int cust;
	float weight;
	int num;
}
// n = trainers 3 > n > 5
// m = couches 3 > m > 6
void deadlock (int n, int m) {
	// if trainer does not see a client
	// will go play with phone
	char str;
	if (n) {
		printf("Trainer cannot find client.\n");
	}

}

void starvation (int n, int m) {
	// trainer helping other clients with higher priority
	// client stays waiting indefinitely 
	if (!n) {
		// client is unknown
		printf("All trainers are busy.");
	}

}

void unfair(int n, int m) {
	// trainer spots client come in and helps
	// without checking waiting room
	if (!n && m) {
		printf("The available trainer got sidetracked by another client");
	}
	
}

void avoidance (int n, int m) {
	// if deadlock is not detected
	if (n && m) {
		printf("Resume as normal.");
		return(stream);
	}
}

