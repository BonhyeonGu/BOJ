#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int diff3(int n1, int n2, int n3)
{
	if (n1 == n2)
		return n3;
	if (n1 == n3)
		return n2;
	if (n2 == n3)
		return n1;
}

int main()
{
	int x1, y1, x2, y2, x3, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3,&y3);
	printf("%d %d\n", diff3(x1, x2, x3), diff3(y1, y2, y3));
}