#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	unsigned int k, a, b, value;
	scanf("%u %u %u", &k, &a, &b);

	if (a < b)
		printf("%d\n", (k / (b - a)) + 1);
	else
		printf("-1\n");

	
	return 0;
}