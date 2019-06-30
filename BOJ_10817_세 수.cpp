#include <stdio.h>
int main()
{
	int num[3], min = 101, max = 0, want = 0;
	scanf("%d %d %d", &num[0], &num[1], &num[2]);
	for (int i = 0; i < 3; i++)
	{
		if (num[i] < min) min = num[i];
		if (num[i] > max) max = num[i];
	}
	for (int i = 0; i < 3; i++)
		if (num[i] > min&&num[i] < max) want = num[i];
	if (want == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			int tmp = num[i], count = 0;
			for (int j = 0; j < 3; j++)
				if (tmp == num[j]) count++;
			if (count >= 2)
				want = num[i];
		}
	}
	printf("%d", want);
	return 0;
}