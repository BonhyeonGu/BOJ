#include <stdio.h>
int main()
{
	int a, mem, counter = 0;
	scanf("%d", &a);
	if (a / 10 == 0) a *= 10;
    mem = a;
	while (1)
	{
		a = ((a % 10) * 10) + ((a / 10) + (a % 10)) % 10;
		counter++;
		if (mem == a) break;
	}
	printf("%d", counter);
}