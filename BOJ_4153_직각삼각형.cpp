#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

bool tri90(int n1, int n2, int n3)
{
	n1 = n1 * n1;
	n2 = n2 * n2;
	n3 = n3 * n3;
	if (((n1 + n2) == n3) || ((n1 + n3) == n2) || ((n2 + n3) == n1))
		return true;
	return false;
}

int main()
{
	int n1, n2, n3;
	while (1)
	{
		scanf(" %d %d %d", &n1, &n2, &n3);
		if (n1 == 0 && n2 == 0 && n3 == 0)
			break;
		if (tri90(n1, n2, n3))
			printf("right\n");
		else
			printf("wrong\n");
	}
}