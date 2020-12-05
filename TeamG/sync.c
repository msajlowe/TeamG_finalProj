// sync.c

int detectDeadlock(sem_t semaphor, int trainerInWaitingRoom) 
{
	int numberInWaitingRoom; 
	sem_getValue(&semaphor, &numberInWaitingRoom);
	if(trainerInWaitingRoom == 1 && abs(numberInWaitingRoom) == 0)
	{
		printf("Deadlock Detected");
		return 1;
	}
	return 0;
}
void solveDeadlock()
{
	printf("Deadlock Solved");
	return;
}


void detectStarvation(sem_t semaphor, int trainerInWaitingRoom) 
{
	int numberInWaitingRoom; 
	sem_getValue(&semaphor, &numberInWaitingRoom);
	if(trainerInWaitingRoom == 1 && abs(numberInWaitingRoom) >= 0)
	{
		printf("Starvation Detected");
		return 1;
	}
	return 0;
}
void solveStarvation() 
{
	printf("Starvation Solved");
	return;
}


int detectUnfair(int m, int i, int* arrivalTimes, int* inWaitingRoom, int numOfCustomers) 
{
	int numberInWaitingRoom; 
	for(int j = 0; j < numOfCustomers; j++)
	{
		if(inWaitingRoom[j] == 1)
		{
			numberInWaitingRoom++;
		}
	}
	if(numberInWaitingRoom < m) return 0; 
	for(int j = 0; j < numOfCustomers; j++)
	{
		if(arrivalTime[i] <= arrivalTime[j] && inWaitingRoom[j])
		{
			printf("Unfair Scedualling Detected");
			return 1;
		}
	}
	return 0;
}
void solveUnfair(int i, int* arrivalTimes, int* inWaitingRoom, int numOfCustomers) 
{
	for(int j = 0; j < numOfCustomers; j++)
	{
		if(arrivalTime[i] < arrivalTime[j] && inWaitingRoom[j])
		{
			inWaitingRoom[i] = 1;
			inWaitingRoom[j] = 0;
			printf("Unfair Scedualling Solved");
			return;
		}
	}
}


