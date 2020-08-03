#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int cycle(int num, int str, int des, int sub)
{
	if (num > 0)
	{
		cycle(num - 1, str, sub, des);
		printf("%d %d\n", str, des);
		cycle(num - 1, sub, des, str);
	}
	return 0;
}

int main()
{
	int in_size;
	scanf("%d", &in_size);
	printf("%d\n", (1 << in_size) - 1);
	cycle(in_size, 1, 3, 2);
	return 0;
}