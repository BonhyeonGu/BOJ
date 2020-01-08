#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int D(int x1, int x2, int y1, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	int c, x1, y1, r1, x2, y2, r2, d;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		scanf(" %d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		d = D(x1, x2, y1, y2);

		if (r1 == r2 && x1 == x2 && y1 == y2)
			printf("-1");
		else if (d > ((r1 + r2) * (r1 + r2)))
			printf("0");
		else if (d == ((r1 + r2) * (r1 + r2)))
			printf("1");
		else if (d < ((r1 + r2) * (r1 + r2)))
		{
			if (d > ((r2 - r1) * (r2 - r1)))
				printf("2");
			else if (d == ((r2 - r1) * (r2 - r1)))
				printf("1");
			else if (d < ((r2 - r1) * (r2 - r1)))
				printf("0");
		}
		printf("\n");
	}
}