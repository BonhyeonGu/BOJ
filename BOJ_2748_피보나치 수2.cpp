#include <stdio.h>
int main()
{
	unsigned long long input, tmp1 = 0, tmp2 = 1;
	scanf("%llu", &input);
	if (input == 0)
	{
		printf("%llu\n", tmp1);
		return 0;
	}
	if (input == 1)
	{
		printf("%llu\n", tmp2);
		return 0;
	}
	for (int i = 0; i < input - 1; i++)
	{
		unsigned long long tmp = tmp2;
		tmp2 += tmp1;
		tmp1 = tmp;
	}
	printf("%llu\n", tmp2);
	return 0;
}