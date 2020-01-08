#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	int max = 0, maxindex, tmp;
	for (int i = 0; i < 9; i++)
	{
		scanf(" %d", &tmp);
		if (tmp > max)
		{
			max = tmp;
			maxindex = i + 1;
		}
	}
	printf("%d\n%d", max, maxindex);
}