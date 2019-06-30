#include <stdio.h>
#include <math.h>
int main()
{
	int input = 1;
	while (1)
	{
		scanf("%d", &input);
		if (input == 0) break;
		unsigned int count = 0, inputgop = input * 2;
		int* sosu = new int[inputgop + 1];
		for (int i = 0; i <= inputgop; i++)
			sosu[i] = 0;
		sosu[0] = -1; sosu[1] = -1;
		for (int i = 2; i <= inputgop; i++)
		{
			if (sosu[i] == 0)
			{
				sosu[i] = 1;
				int besu = i;
				while (1)
				{
					besu += i;
					if (inputgop < besu)
						break;
					sosu[besu] = -1;
				}
			}
		}
		for (int i = input + 1; i <= inputgop; i++)
			if (sosu[i] == 1)
				count++;
		printf("%d\n", count);
		delete[]sosu;
	}
	return 0;
}