#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/mman.h>
	
#include "sync.c"	
int main() 
{
	
	printf("Use Solution For Starvation [Y/N]: ");
	char SFlag;
	scanf("%c", &SFlag);
	
	printf("Use Solution For Deadlock [Y/N]: ");
	char DFlag;
	scanf("%c", &DFlag);
	
	printf("Use Solution For Unfair Schedualing [Y/N]: ");
	char UFlag;
	scanf("%c", &UFlag);
	
	
	
	printf("ENTER N: ");
	int n;
	scanf("%d", &n);
	printf("ENTER M: ");
	int m;
	scanf("%d", &m);
	printf("ENTER File Name: ");
	char* name;
	scanf("%s", &name);
	
	
	FILE* stream = fopen(name, "r");
	char line[100];
	if(stream == NULL)
	{
		fclose(stream);
		printf("Could Not open File!");
		return 1;
	}
	int numOfCustomers = -1;
	while(fgets(line, 100, stream) != NULL)
	{
		numOfCustomers++;
	}
	fclose(stream);
	
	
	sem_t semaphore;
	
	int trainerInWaitingRoom = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	trainerInWaitingRoom = 0;
	int pshared = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	pshared = 1;
	pid_t* processIDs = mmap(NULL, numOfCustomers * sizeof(pid_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int* arrivalTimes = mmap(NULL, numOfCustomers * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int* inWaitingRoom = mmap(NULL, numOfCustomers * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	
	sem_init(&semaphore, pshared, n);
	
	
	int isParent = 0;
	stream = fopen(name, "r");
	if(stream == NULL)
	{
		fclose(stream);
		printf("Could Not open File!");
		return 1;
	}
	fgets(line, 100, stream);
	int i;
	for(i = 0; i < numOfCustomers; i++)
	{
		fgets(line, 100, stream);
		char* end;
		char data[100];
		int j = 0;
		while(line[j] != ',' && line[j] != '\n')
		{
			data[j] = line[j];
			j++;
		}
		arrivalTime[i] = strtol(data, &end, 10);
		if (end == str) {
			printf("could not read bt");
			fclose(stream);
			return 1;
		}
		pid_t pid = fork();
		if(pid == 0) {
			isParent = 0;
			break;
		}
		else {
			processIDs[i] = pid;
			isParent = 1;
		}
	}
	if(isParent)
	{
			for(int j = 0; j < numOfCustomers; j++)
			{
				wait(NULL);
			}
			sem_close(&semaphore);
	}
	else
	{
		// i is the customer number
//>>>>>>>>>>>>>// put calls to other functions here 
		inWaitingRoom[i] = 0;
		sleep(arivalTime[i]);
		
		detectUnfair(m, i, arrivalTimes, inWaitingRoom, numOfCustomers);
		solveUnfair(i, arrivalTimes, inWaitingRoom, numOfCustomers);
		detectDeadlock(semaphor, trainerInWaitingRoom);
		solveDeadlock();
		detectStarvation(semaphor, trainerInWaitingRoom);
		solveStarvation();
		
		inWaitingRoom[i] = 1;
		sem_wait(&semaphore);
		if(inWaitingRoom[i] != 1)
		{
			sem_post(&semaphore);
			return 1;
		}
		inWaitingRoom[i] = 0;





		sem_post(&semaphore);
		trainerInWaitingRoom = 1;
		sleep(10);
		trainerInWaitingRoom = 0;
	}
	fclose(stream);
	return 1;
}