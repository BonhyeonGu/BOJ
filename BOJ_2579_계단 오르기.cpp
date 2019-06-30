#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 301

#include <iostream>
using namespace std;

int arrayNum[MAXSIZE];
int dp[MAXSIZE];
int arraySize;

int Max(int n1, int n2)
{
	return n1 > n2 ? n1 : n2;
}

int main()
{
	scanf("%d", &arraySize);
	for (int i = 0; i < arraySize; i++)
		scanf(" %d", &arrayNum[i]);

	dp[1] = arrayNum[1] + arrayNum[0];
	dp[2] = Max(arrayNum[2] + arrayNum[1], arrayNum[2] + arrayNum[0]);
	for (int i = 3; i < arraySize; i++)
		dp[i] = Max(arrayNum[i] + arrayNum[i - 1] + dp[i - 3], arrayNum[i] + dp[i - 2]);
	
	printf("%d\n", dp[arraySize - 1]);
	return 0;
}	