#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;
	scanf("%d\n", &a);
	int** num = (int**)malloc(sizeof(int*)*a);
	for (int i = 0; i < a; i++)
	{
		b = 1;
		for (int j = 0; j < b; j++)
		{
			int tmp;
			if (j == 0)
			{
				scanf(" %d", &tmp);
				b = tmp + 1;
				num[i] = (int*)malloc(sizeof(int)*b);
				num[i][j] = tmp;
				j++;
			}
			scanf(" %d", &num[i][j]);
		}
	}
	for (int i = 0; i < a; i++)
	{
		int sum = 0, counter = 0;
		for (int j = 1; j <= num[i][0]; j++)
			sum += num[i][j];
		for (int j = 1; j <= num[i][0]; j++)
			if (num[i][j] > (sum / num[i][0])) counter++;
		printf("%.3f%%\n", ((float)counter / num[i][0]) * 100);
	}
	for (int i = 0; i < a; i++)
		free(num[i]);
	free(num);
	return 0;
}