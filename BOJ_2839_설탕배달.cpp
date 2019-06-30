#include <stdio.h>
int main()
{
	int a, b = 0;
	scanf("%d", &a);
	while (a % 5 != 0)
	{
		a -= 3;
		b++;
	}
	if (a < 0)
	{
		printf("-1");
		return 0;
	}
	printf("%d", b + (a / 5));
	return 0;
}