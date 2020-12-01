#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>






int main()
{
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
	//char* line = (char*)malloc(100 * sizeof(char));
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
	
	
	pid_t* pid = mmap(NULL, numOfCustomers * sizeof(pid_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int* bt = mmap(NULL, numOfCustomers * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int* wt = mmap(NULL, numOfCustomers * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int* at = mmap(NULL, numOfCustomers * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int* tat = mmap(NULL, numOfCustomers * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	
	
	
	
	stream = fopen("a.txt", "r");
	if(stream == NULL)
	{
		fclose(stream);
		printf("Could Not open File!");
		return 1;
	}
	fgets(line, 100, stream);
	for(int i = 0; i < numOfCustomers; i++)
	{
		fgets(line, 100, stream);
		char* end;
		char data0[100];
		int j = 0;
		int k = 0;
		while(line[j] != ',' && line[j] != '\n')
		{
			data0[k] = line[j];
			j++;
			k++;
		}
		bt[i] = int(strtol(data0, &end, 10));
		if(end == str)
		{
			printf("could not read bt");
			return 1;
		}
		char data1[100];
		k = 0;
		while(line[j] != ',' && line[j] != '\n')
		{
			data1[k] = line[j];
			j++;
			k++;
		}
		wt[i] = int(strtol(data1, &end, 10));
		if(end == str)
		{
			printf("could not read wt");
			return 1;
		}
		char data2[100];
		k = 0;
		while(line[j] != ',' && line[j] != '\n')
		{
			data2[k] = line[j];
			j++;
			k++;
		}
		at[i] = int(strtol(data2, &end, 10));
		if(end == str)
		{
			printf("could not read at");
			return 1;
		}
		char data3[100];
		k = 0;
		while(line[j] != ',' && line[j] != '\n')
		{
			data3[k] = line[j];
			j++;
			k++;
		}
		tat[i] = int(strtol(data3, &end, 10));
		if(end == str)
		{
			printf("could not read tat");
			return 1;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		if((pid[i] = fork()) == 0)
			break;
		
			
		
	}
	
	//free(line);
	fclose(stream);
	return 1;
}