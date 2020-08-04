#include<stdio.h>
int main()
{
	char a[11];
	unsigned int s = 0;
	while ((a[s++] = getchar()) != '\n');
	s--;
	for (unsigned int i = 0; i < s; i++)
	{
		char max = '/';
		unsigned int mi;
		for (unsigned int j = 0; j < s; j++)
		{
			if (max <= a[j] && a[j] != '+')
			{
				max = a[j];
				mi = j;
			}
		}
		printf("%c", max);
		a[mi] = '+';
	}
	printf("\n");
	return 0;
}