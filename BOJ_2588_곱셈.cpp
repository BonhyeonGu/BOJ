#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	int n1, n2, n2a, n2b, n2c;
	scanf("%d\n%d", &n1, &n2);

	n2a = n2 / 100;
	n2b = n2 / 10 % 10;
	n2c = n2 % 10;
	
	printf("%d\n%d\n%d\n%d\n", n2c * n1, n2b * n1, n2a * n1, n2 * n1);

	return 0;
}