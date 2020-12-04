#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/mman.h>
	
int main() {
	char* str;
	printf("ENTER N: ");
	int n;
	scanf("%d", &n);
	printf("ENTER M: ");
	int m;
	scanf("%d", &m);
	printf("ENTER File Name: ");
	char* name;
	scanf("%s", &name);
	
	
	FILE* stream = fopen("a.txt", "r");
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
	
	
	pid_t* processIDs = mmap(NULL, numOfCustomers * sizeof(pid_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int* arrivalTime = mmap(NULL, numOfCustomers * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	
	
	int isParent = 0;
	stream = fopen("a.txt", "r");
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
	}
	else
	{
		// i is the customer number
//>>>>>>>>>>>>>// put calls to other functions here 



	}
	fclose(stream);
	return 1;
}