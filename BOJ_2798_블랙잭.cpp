#include <iostream>
using namespace std;

int num[1000000], numSize;
int jack;
int tmpValue;
int tmpChi = 300000;

int main()
{
	scanf("%d %d", &numSize, &jack);
	for (int i = 0; i < numSize; i++)
		scanf(" %d", &num[i]);
	for (int i = 0; i < numSize; i++)
		for (int j = 1; j < numSize; j++)
			for (int k = 2; k < numSize; k++)
			{
				if (i == j || j == k || i == k)
					continue;
				int t = num[i] + num[j] + num[k];
				if (t <= jack && jack - t < tmpChi)
				{
					tmpChi = jack - t;
					tmpValue = t;
				}
			}
	printf("%d\n", tmpValue);
	return 0;
}