#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int c, last;
int F(int num1, int num2)
{
	if (c == 0)
	{
		last = num2;
		return 0;
	}
	else
	{
		c--;
		return F(num2, num1 + num2);
	}
}

int main()
{
	scanf("%d", &c);
	if (c == 0)
		printf("0");
	else if (c == 1)
		printf("1");
	else
	{
		c -= 1;
		F(0, 1);
		printf("%d", last);
	}
	printf("\n");
}