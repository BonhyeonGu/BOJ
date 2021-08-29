#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

unsigned long long int dp[101] = { 0,1,1,1,2,2, };

unsigned long long int f(int n)
{
	if (dp[n] == 0)
		dp[n] = f(n - 1) + f(n - 5);
	return dp[n];
}
int main()
{
	int c, input;
	scanf("%d", &c);

	for (int i = 0; i < c; i++)
	{
		scanf(" %d", &input);
		printf("%llu\n", f(input));
	}
	return 0;
}