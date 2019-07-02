#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int Start(int num)
{
	int tmp = 0;
	for (int i = 1; i <= num; i++)
	{
		if (i >= 1000000)
		{
			int n1, n2, n3, n4, n5, n6, n7;
			n1 = i / 1000000;
			n2 = i / 100000 % 10;
			n3 = i / 10000 % 10;
			n4 = i / 1000 % 10;
			n5 = i / 100 % 10;
			n6 = i / 10 % 10;
			n7 = i % 10;
			tmp = n1 + n2 + n3 + n4 + n5 + n6 + n7 + i;
		}
		else if (i >= 100000)
		{
			int n1, n2, n3, n4, n5, n6;
			n1 = i / 100000;
			n2 = i / 10000 % 10;
			n3 = i / 1000 % 10;
			n4 = i / 100 % 10;
			n5 = i / 10 % 10;
			n6 = i % 10;
			tmp = n1 + n2 + n3 + n4 + n5 + n6 + i;
		}
		else if (i >= 10000)
		{
			int n1, n2, n3, n4, n5;
			n1 = i / 10000;
			n2 = i / 1000 % 10;
			n3 = i / 100 % 10;
			n4 = i / 10 % 10;
			n5 = i % 10;
			tmp = n1 + n2 + n3 + n4 + n5 + i;
		}
		else if (i >= 1000)
		{
			int n1, n2, n3, n4;
			n1 = i / 1000;
			n2 = i / 100 % 10;
			n3 = i / 10 % 10;
			n4 = i % 10;
			tmp = n1 + n2 + n3 + n4 + i;
		}
		else if (i >= 100)
		{
			int n1, n2, n3;
			n1 = i / 100;
			n2 = i / 10 % 10;
			n3 = i % 10;
			tmp = n1 + n2 + n3 + i;
		}
		else if (i >= 10)
		{
			int n1, n2;
			n1 = i / 10;
			n2 = i % 10;
			tmp = n1 + n2 + i;
		}
		
		if (tmp == num)
			return i;
	}
	return 0;
}

int main()
{
	int input;
	scanf("%d", &input);
	printf("%d\n", Start(input));
	return 0;
}