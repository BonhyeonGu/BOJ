#include <iostream>
using namespace std;

struct numValue
{
	int zero;
	int one;
} numValue[41];

bool numEx[41];

int zeroTmp, oneTmp;

int fibo(int n)
{
	if (numEx[n])
	{
		zeroTmp += numValue[n].zero;
		oneTmp += numValue[n].one;
		return -1;
	}

	else if (n == 0)
	{
		zeroTmp++;
		return 0;
	}
	else if (n == 1)
	{
		oneTmp++;
		return 1;
	}
	else
	{
		fibo(n - 1);
		fibo(n - 2);
		numEx[n] = true;
		numValue[n].zero = zeroTmp;
		numValue[n].one = oneTmp;
		return -1;
	}
}

int main()
{
	numValue[0].zero = 1;
	numValue[1].one = 1;
	int cas, n;

	scanf("%d", &cas);

	for (int i = 0; i < cas; i++)
	{
		zeroTmp = 0, oneTmp = 0;
		scanf("%d", &n);
		if (n != 0 && n != 1)
			fibo(n);
		printf("%d %d\n", numValue[n].zero, numValue[n].one);
	}

	return 0;
}