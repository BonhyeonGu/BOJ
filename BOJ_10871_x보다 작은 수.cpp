#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, c;
	scanf("%d %d\n", &a, &b);
	int* num = (int*)malloc(sizeof(int*)*a);
	for (int i = 0; i < a; i++)
		scanf(" %d", &num[i]);
	for (int i = 0; i < a; i++)
		if (num[i] < b)
			printf("%d ", num[i]);
	return 0;
}