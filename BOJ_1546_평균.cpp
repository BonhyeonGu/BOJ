#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, max = -1;
	float sum = 0;
	scanf("%d\n", &a);
	int* num = (int*)malloc(sizeof(int*)*a);
	for (int i = 0; i < a; i++)
	{
		scanf(" %d", &num[i]);
		if (max < num[i]) max = num[i];
	}
	for (int i = 0; i < a; i++)
		sum += (float)num[i] / max * 100.0;
	printf("%4.2f", (float)sum / a);
	return 0;
}