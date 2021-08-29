#include <iostream>
using namespace std;

char pan[50][50];

int cheack(char c, int x, int y, int minCount)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (pan[y + i][j + x] != c) count++;
			if (count >= minCount) return minCount;
			c = (c == 'W') ? 'B' : 'W';
		}
		c = (c == 'W') ? 'B' : 'W';
	}
	return count;
}

int main()
{
	int y, x, minCount = 25000, tmp;
	
	cin >> y >> x;
	for (int i = 0; i < y; i++)
		cin >> pan[i];
	for (int i = 0; i <= y - 8; i++)
	{
		for (int j = 0; j <= x - 8; j++)
		{
			minCount = cheack('W', j, i, minCount);
			minCount = cheack('B', j, i, minCount);
		}
	}
	printf("%d\n", minCount);
	return 0;
}