#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int counterArray[100001];

int main()
{
	int size, input;
	scanf("%d\n", &size);
	for (int i = 0; i < size; i++)
	{
		scanf(" %d", &input);
		counterArray[input]++;
	}
	for (int i = 0; i < 100001; i++)
	{
		if (counterArray[i] == 0)
			continue;
		for (int j = 0; j < counterArray[i]; j++)
			printf("%d\n", i);
	}
	return 0;
}