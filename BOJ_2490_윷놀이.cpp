#include<stdio.h>
int main()
{
	for (int i = 0; i < 3; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		switch (a + b + c + d)
		{
		case 4:
			printf("E\n");
			break;
		case 3:
			printf("A\n");
			break;
		case 2:
			printf("B\n");
			break;
		case 1:
			printf("C\n");
			break;
		case 0:
			printf("D\n");
			break;
		}
	}
	return 0;
}