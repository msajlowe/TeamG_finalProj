// sync.c

void deadlock (int a, bool b, bool c) {
	// if trainer does not see a client
	// will go play with phone
	if (a != 0) {
		b == true;
		c == false;
		printf("Trainer cannot find client.\n");
	}
	return 0;
}

void starvation (int a, bool b) {
	// trainer helping other clients with higher priority
	// client stays waiting indefinitely 
	if (a != 0) {
		b == false;
		// client is unknown
		printf("All trainers are busy.");
	}
	return 0;
}

void unfair(int a, bool b, bool c) {
	// trainer spots client come in and helps
	// without checking waiting room
	if (a != 0) {
		b == false;
		c == true;
		printf("The available trainer got sidetracked by another client");
	}
	
	return 0;
}

void avoidance () {
	// if deadlock is not detected
}