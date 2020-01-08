#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int F(int num)
{
	if (num > 1)
		return num * F(num - 1);
	else
		return 1;
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d\n", F(num));
}