/////////////////////////////////////////////////////
/*
Author: Brady Prince, Amanda Lowe, Josh Minton
Email: prady.prince@okstate.edu,
Date: 12/2/2020
Program Description: 
*/
////////////////////////////////////////////////////

int detectDeadlock(sem_t semaphor, int trainerInWaitingRoom) 
{
	int numberInWaitingRoom; 
	sem_getValue(&semaphor, &numberInWaitingRoom);
	if(trainerInWaitingRoom == 1 && abs(numberInWaitingRoom) == 0)
	{
		printf("Deadlock Detected \n");
		return 1;
	}
	return 0;
}
void solveDeadlock()
{
	printf("Deadlock Solved \n");
	return;
}


int detectStarvation(sem_t semaphor, int trainerInWaitingRoom) 
{
	int numberInWaitingRoom; 
	sem_getValue(&semaphor, &numberInWaitingRoom);
	if(trainerInWaitingRoom == 1 && abs(numberInWaitingRoom) >= 0)
	{
		printf("Starvation Detected \n");
		return 1;
	}
	return 0;
}
void solveStarvation() 
{
	printf("Starvation Solved \n");
	return;
}


int detectUnfair(int m, int i, int* arrivalTimes, int* inWaitingRoom, int numOfCustomers) 
{
	int numberInWaitingRoom; 
	int j;
	for(j = 0; j < numOfCustomers; j++)
	{
		if(inWaitingRoom[j] == 1)
		{
			numberInWaitingRoom++;
		}
	}
	if(numberInWaitingRoom < m) return 0; 
	for(int j = 0; j < numOfCustomers; j++)
	{
		if(arrivalTimes[i] <= arrivalTime[j] && inWaitingRoom[j])
		{
			printf("Unfair Scedualling Detected \n");
			return 1;
		}
	}
	return 0;
}
void solveUnfair(int i, int* arrivalTimes, int* inWaitingRoom, int numOfCustomers) 
{
	int j;
	for(j = 0; j < numOfCustomers; j++)
	{
		if(arrivalTimes[i] < arrivalTime[j] && inWaitingRoom[j])
		{
			inWaitingRoom[i] = 1;
			inWaitingRoom[j] = 0;
			printf("Unfair Scedualling Solved \n");
			return;
		}
	}
}


