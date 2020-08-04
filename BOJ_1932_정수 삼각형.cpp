#include <iostream>

using namespace std;

int bt[501][501];

int main()
{
	int floor, size = 0, left, right;

	scanf("%d", &floor);

	for (int i = 0; i < floor; i++)
		for (int j = 0; j < i + 1; j++)
			scanf("%d", &bt[i][j]);

	for (int i = floor - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
		{
			left = bt[i + 1][j];
			right = bt[i + 1][j + 1];
			
			if (left > right)
				bt[i][j] += left;
			else
				bt[i][j] += right;
		}

	printf("%d\n", bt[0][0]);

	return 0;
}