#include<iostream>
using namespace std;
int main()
{
	unsigned int m, n, sum = 0, min = 10001;
	cin >> m >> n;
	for (; m <= n; m++)
	{
		if (m == 1)
			continue;
		bool sosu = true;
		for (int i = 2; i < m; i++)
		{
			if (m%i == 0)
			{
				sosu = false;
				break;
			}
		}
		if (sosu == true)
		{
			sum += m;
			if (min > m)
				min = m;
		}
	}
	if (sum == 0)
		cout << "-1" << endl;
	else
		cout << sum << "\n" << min << endl;
	return 0;
}