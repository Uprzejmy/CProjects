#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void) 
{
	int i;
	int randomIndex;
	int visitationCounter = 0;
	int n = 20;
	int table[n];
	bool visitedIndexes[n];
	
	printf("Proszę podać 20 liczb\n");

	for(i=0; i<n; i++)
	{
		scanf("%d", &table[i]);
	}

	printf("\n od tyłu\n");

	for(i=n-1; i>=0; i--)
	{
		printf("%d ", table[i]);
	}

	for(i=n-1; i>=0; i--)
	{
		visitedIndexes[i] = false;
	}

	printf("\n losowo\n");

	while(visitationCounter < 20)
	{
		randomIndex = (rand() % (19 - 0 + 1) + 0);//rand() % (max - min + 1) + min
		if(!visitedIndexes[randomIndex])
		{
			visitedIndexes[randomIndex] = true;
			visitationCounter++;
			printf("%d ", table[randomIndex]);
		}

	}
	

	return 0;
}
