#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MOD 1000000000
using namespace std;

unsigned int m[102][10];

unsigned int dp(unsigned int size, unsigned int num)
{
	if (m[size][num] != 0) return m[size][num];

	unsigned int c = 0;
	size--;
	if (size > 0)
	{
		if (num != 0 && num != 9)
			c = (c + 1) % MOD;
		if (num != 0)
			c = (c + dp(size, num - 1)) % MOD;
		if (num != 9)
			c = (c + dp(size, num + 1)) % MOD;
	}

	m[size + 1][num] = c;
	return c;
}

int main()
{
	unsigned int size, c = 0;
	scanf("%d", &size);
	for (int i = 1; i <= 9; i++)
		c = (c + dp(size, i)) % MOD;
	printf("%d\n", c + 9);
	return 0;
} 