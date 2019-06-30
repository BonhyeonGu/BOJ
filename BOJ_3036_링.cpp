#include<stdio.h>
int cgy(int n1, int n2)
{
	int nn = 1, val;
	while (n1 >= nn&&n2 >= nn)
	{
		if (n1%nn == 0 && n2%nn == 0)
			val = nn;
		nn++;
	}
	return val;
}

int main()
{
	unsigned int c, ring[101];
	scanf("%u", &c);
	for (int cc = 0; cc < c; cc++)
		scanf("%u", &ring[cc]);
	for (int i = 1; i < c; i++)
	{
		int gy = cgy(ring[0], ring[i]);
		printf("%u/%u\n", ring[0] / gy, ring[i] / gy);
	}
	return 0;
}