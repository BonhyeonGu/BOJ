#include <stdio.h>
int gcd(int m, int n)
{
	unsigned int min, gcdd;
	if (m >= n) min = n;
	else min = m;
	for (int i = 1; i <= min; i++)
	{
		if (m%i == 0 && n%i == 0)
			gcdd = i;
	}
	return gcdd;
}

int main()
{
	int cc, m, n, x, y;
	scanf("%d", &cc);
	for (int i = 0; i < cc; i++)
	{
		unsigned int c = 1;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		int gcdd = gcd(m, n);
		int ming = m*n / gcdd;
		int month = 1, day = 1, big, small;
		int mmn = x - y;
		if (x > y) {
			big = x;
			small = y;
		}
		else {
			big = y;
			small = x;
		}
		if ((big - small) % gcdd != 0)
		{
			printf("-1\n");
			continue;
		}
		while (!(month == x&&day == y))
		{
			int xmy = month - day;
			if (mmn != xmy)
			{
				if (m - month + 1 < n - day + 1)
				{
					
					day += m - month + 1;
					c += m - month + 1;
					month = 1;
				}
				else
				{
					
					month += n - day + 1;
					c += n - day + 1;
					day = 1;
				}
			}
			else
			{
				month++;
				day++;
				c++;
				if (day > n)
					day = 1;
				if (month > m)
					month = 1;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}