#include <iostream>
using namespace std;

int stairs[300];

int dp[300][1];
int cycle(int size, int train)
{
	int value = stairs[size];
	int a, b;
	if (size >= 2 && train < 1)
	{
		if (dp[size - 1][train + 1] != 0)
			a = dp[size - 1][train + 1];
		else
			a = dp[size - 1][train + 1] = cycle(size - 1, train + 1);
		if (dp[size - 2][0] != 0)
			b = dp[size - 2][0];
		else
			b = dp[size - 2][0] = cycle(size - 2, 0);
		if (a > b)
			value += a;
		else
			value += b;
	}
	else if (size >= 2)
	{
		if (dp[size - 2][0] != 0)
			a = dp[size - 2][0];
		else
			a = dp[size - 2][0] = cycle(size - 2, 0);
		value += a;
	}
	else if (size == 1 && train < 1)
	{
		if (dp[size - 1][train + 1])
			a = dp[size - 1][train + 1];
		else
			a = dp[size - 1][train + 1] = cycle(size - 1, train + 1);
		value += a;
	}
	return value;
}

int main()
{
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
		scanf(" %d", &stairs[i]);
	printf("%d\n", cycle(size - 1, 0));
	return 0;
}