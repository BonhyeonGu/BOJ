#include<stdio.h>
int main()
{
	int a[100], b[100], size = 0, b_s = 0;
	while ((a[size++] = getchar()) != '\n');
	b[b_s++] = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] == '-')
		{
			b[b_s++] = a[++i];
			continue;
		}
	}
	for (int i = 0; i < b_s; i++)
		printf("%c", b[i]);
	printf("\n");
	return 0;
}
