#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int sosu1[10001] = { -1,-1,0, };
	vector<int> sosu2;
	for (int i = 2; i <= 10000; i++)
	{
		if (sosu1[i] == 0)
		{
			sosu2.push_back(i);
			sosu1[i] = 1;
			int besu = i;
			while (1)
			{
				besu += i;
				if (besu > 10000)
					break;
				sosu1[besu] = -1;
			}
		}
	}
	int c;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		int input, a, b, min = 100000;
		bool fine = false;
		scanf("%d", &input);
		for (int j = 0; j < sosu2.size(); j++)
		{
			int inm = input - sosu2.at(j);
			int s = sosu2.at(j) - inm;
			if (s < 0) s *= -1;
			if ((sosu1[inm] == 1) && (s < min))
			{
				a = sosu2.at(j);
				b = inm;
				min = s;
			}
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}