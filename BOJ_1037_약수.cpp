#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int size, num[50], min = 10000001, max = 1, tmp;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf(" %d", &tmp);
		if (tmp < min)
			min = tmp;
		if (tmp > max)
			max = tmp;
	}
	printf("%d\n", min * max);
	return 0;
}