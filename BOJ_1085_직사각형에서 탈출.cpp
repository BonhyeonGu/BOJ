#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int min4(int n1, int n2, int n3, int n4)
{
	int tmp1, tmp2;

	if (n1 < n2)
		tmp1 = n1;
	else
		tmp1 = n2;
	if (n3 < n4)
		tmp2 = n3;
	else
		tmp2 = n4;
	if (tmp1 < tmp2)
		return tmp1;
	else
		return tmp2;
}

int main()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d\n", min4(x, y, w - x, h - y));
}