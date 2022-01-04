#include <iostream>
#include <algorithm>
using namespace std;

int a[10001], aSize;

int minmin(int n1, int n2)
{
	int ret = n1 - n2;
	if (ret < 0)ret *= -1;
	return ret;
}

int f()
{
	int ret = -1, t1, t2;
	t1 = minmin(a[0], a[1]);
	t2 = minmin(a[0], a[2]);
	if (ret < t1) ret = t1;
	if (ret < t2) ret = t2;
	for (int i = 3; i < aSize; i++)
	{
		t1 = minmin(a[i], a[i - 2]);
		if (ret < t1) ret = t1;
	}
	t1 = minmin(a[aSize - 1], a[aSize - 2]);
	if (ret < t1) ret = t1;
	return ret;
}

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		cin >> aSize;
		for (int j = 0; j < aSize; j++)
			cin >> a[j];
		sort(a, a + aSize);
		cout << f() << "\n";
	}
	return 0;
}