#define _CRT_SECURE_NO_WARNINGS
#define SIZEMAX 10000
#include <iostream>
using namespace std;

unsigned int want, s, a[SIZEMAX];

unsigned int sumsum(int s, int e)
{
	unsigned int re = 0;
	for (int i = s; i <= e; i++) re += a[i];
	return re;
}

int main()
{
	int s = 0, e = 0, c = 0, size;
	unsigned int tmp;
	scanf("%u %u", &size, &want);
	for (int i = 0; i < size; i++) scanf(" %u", &a[i]);
	while (1)
	{
		tmp = sumsum(s, e);
		if (tmp < want) e++;
		else
		{
			s++;
			if (tmp == want) c++;
		}
		if (e < s) e = s;
		if (e >= size) break;
	}
	printf("%d\n", c);
	return 0;
}