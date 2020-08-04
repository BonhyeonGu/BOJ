#include<iostream>

using namespace std;

int input[1002][1002];

int main()
{
	char inc;
	int n, m, max = 0;
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%c", &inc);
			if (inc == '1')
				input[i][j] = 1;
			else
				input[i][j] = 0;
		}
		getchar();
	}

	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= m + 1; j++)
			if (input[i][j] != 0)
			{
				int min = (input[i - 1][j - 1] < input[i - 1][j] ? input[i - 1][j - 1] : input[i - 1][j]);
				min = (min < input[i][j - 1] ? min : input[i][j - 1]);
				input[i][j] = min + 1;
				if (max < input[i][j])
					max = input[i][j];
			}

	printf("%d\n", max*max);
	return 0;
}