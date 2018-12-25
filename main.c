#include <stdio.h>
#include <stdlib.h>

#define SEED 0
#define MAX 1
#define NUM 2

unsigned int getRand(unsigned int seed)
{
	return (unsigned int)(48271 * seed % 2147483647);
}

int main(int argc, char *argv[])
{
	char str[12];
	int input[3];

	int i = 0;
	while (fgets(str, sizeof(str), stdin))
	{
		int number = atoi(str);
		input[i++] = number;
	}

	unsigned int rand;
	unsigned int dev = (unsigned int)(0x7FFFFFFF + input[MAX] - 1) / input[MAX];
	for (rand = getRand(input[SEED]), i = 0; i < input[NUM]; rand = getRand(rand), i++)
	{
		printf("%d\n", rand / dev + 1);
	}

	return 0;
}