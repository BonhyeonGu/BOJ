#include <stdio.h>
int main()
{
	unsigned int input, tmp1 = 0, tmp2 = 1;
	scanf("%d", &input);
	if (input == 0)
	{
		printf("%d\n", tmp1);
		return 0;
	}
	if (input == 1)
	{
		printf("%d\n", tmp2);
		return 0;
	}
	for (int i = 0; i < input - 1; i++)
	{
		int tmp = tmp2;
		tmp2 += tmp1;
		tmp1 = tmp;
	}
	printf("%d\n", tmp2);
	return 0;
}