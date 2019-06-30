#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int m, n;
	scanf("%d %d", &m, &n);
	for (; m <= n; m++)
	{
		if (m == 1)
			continue;
		bool sosu = true;
		for (int i = 2; i <= sqrt(m); i++)
		{
			if (m%i == 0)
			{
				sosu = false;
				break;
			}
		}
		if (sosu)
			printf("%d\n", m);
	}
	return 0;
}