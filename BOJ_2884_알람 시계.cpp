#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	int h, m;
	scanf("%d %d", &h, &m);
	if (m - 45 < 0)
	{
		m = 60 + (m - 45);
		h--;
		if (h < 0)
			h = 23;
	}
	else
		m -= 45;

	printf("%d %d\n", h, m);
}