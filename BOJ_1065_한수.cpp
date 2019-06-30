#include <stdio.h>
int main()
{
	int a, counter = 99;
	scanf("%d", &a);
	if (a < 100)
	{
		printf("%d", a);
		return 0;
	}
	for (int i = 100; i <= a; i++)
	{
		int i1 = i / 100, i2 = (i / 10) % 10, i3 = (i % 100) % 10;
		if ((i1 - i2) == (i2 - i3)) counter++;
	}
	printf("%d", counter);
	return 0;
}