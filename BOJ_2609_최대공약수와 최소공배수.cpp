#include<stdio.h>
int cgy(int n1, int n2)
{
	int nn = 1, val;
	while (!(n1 < nn&&n2 < nn))
	{
		if (n1%nn == 0 && n2%nn == 0)
			val = nn;
		nn++;
	}
	return val;
}
int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	int c = cgy(n1, n2);
	printf("%d\n%d\n", c, n1*n2 / c);
	return 0;
}	