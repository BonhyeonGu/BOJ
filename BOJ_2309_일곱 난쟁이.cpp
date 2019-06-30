#include<stdio.h>
int main()
{
	unsigned int a[9], s[2];
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%u", &a[i]);
		sum += a[i];
	}
	sum -= 100;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == j)
				continue;
			if (a[i] + a[j] == sum)
			{
				s[0] = i;
				s[1] = j;
				break;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		int min = 101, mi;
		for (int j = 0; j < 9; j++)
		{
			if (j == s[0] || j == s[1])
				continue;
			if (min >= a[j])	
			{
				min = a[j];
				mi = j;
			}
		}
		printf("%d\n", min);
		a[mi] = 102;
	}
	return 0;
}