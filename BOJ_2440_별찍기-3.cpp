#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		for (int j = a; j-i > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
}