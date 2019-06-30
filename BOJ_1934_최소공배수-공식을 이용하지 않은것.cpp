#include<stdio.h>
int main()
{
	int c;
	scanf("%d", &c);
	for (int cc = 0; cc < c; cc++)
	{
		int n1, n2, nn = 1, a[45001] = { 0, }, a_index = 0, val = 1;
		scanf("%d %d", &n1, &n2);
		while (!(nn >= n1&&nn >= n2))
		{
			nn++;
			if (n1%nn == 0 && n2%nn == 0)
			{
				n1 /= nn;
				n2 /= nn;
				a[a_index++] = nn;
				nn--;
			}
		}
		if (a[0] == 0)
			val = n1*n2;
		else
		{
			for (int i = 0; i < a_index; i++)
				val *= a[i];
			val = val*n1*n2;
		}
		printf("%d\n", val);
	}
	return 0;
}