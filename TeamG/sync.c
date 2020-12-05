// sync.c

void detectDeadlock(int i, int* arrivalTimes, int* inWaitingRoom, int numOfCustomers) 
{
	
}
void solveDeadlock()
{
	
}


void starvation() 
{

}
void solveStarvation() 
{

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
			printf("Unfair Scedualling detected");
			return 1;
		}
	}
	return 0;
}
void SolveUnfair(int i, int* arrivalTimes, int* inWaitingRoom, int numOfCustomers) 
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


void avoidance() 
{

}
void SolveAvoidance() 
{

}