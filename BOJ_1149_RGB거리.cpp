#include <iostream>

#define R 0
#define G 1
#define B 2

using namespace std;

int dp[1001][3];

int min(int n1, int n2)
{
	if (n1 < n2)
		return n1;
	else
		return n2;
}

int main()
{
	int c, tmp[3];	

	scanf("%d", &c);
	scanf("%d %d %d", &dp[0][R], &dp[0][G], &dp[0][B]);
	for (int i = 1; i < c; i++)
	{
		scanf("%d %d %d", &tmp[R], &tmp[G], &tmp[B]);
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + tmp[R];
		dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + tmp[G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + tmp[B];
	}

	printf("%d\n", min(min(dp[c - 1][R], dp[c - 1][G]), dp[c - 1][B]));

	return 0;
}