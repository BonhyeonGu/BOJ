#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	int size, max = -1000000, min = 1000000, tmp;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf(" %d", &tmp);
		if (tmp > max)
			max = tmp;
		if (tmp < min)
			min = tmp;
	}
	printf("%d %d", min, max);
}