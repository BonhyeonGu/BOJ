#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum = 0, index;
	scanf("%d", &index);
	getchar();
	int *a = (int*)malloc(sizeof(int*)*index);
	int i = 0;
	while ((a[i] = getchar()) != '\n')
	{
		sum += (a[i]-48);
		i++;
	}
	printf("%d", sum);
}