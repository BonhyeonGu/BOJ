#include <iostream>
#include <fstream>
using namespace std;

int a[2][100001], aSize;

int maxmax(int n1, int n2)
{
	if (n1 < n2) return n2;
	else return n1;
}

int f()
{
	a[0][1] += a[1][0];
	a[1][1] += a[0][0];
	for (int i = 2; i < aSize; i++)
	{
		a[0][i] += maxmax(a[1][i - 2], a[1][i - 1]);
		a[1][i] += maxmax(a[0][i - 2], a[0][i - 1]);
	}
	return maxmax(a[0][aSize - 1], a[1][aSize - 1]);
}

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		cin >> aSize;
		for (int j = 0; j < aSize; j++)
			cin >> a[0][j];
		for (int j = 0; j < aSize; j++)
			cin >> a[1][j];
		if (aSize == 1) cout << maxmax(a[0][0], a[1][0]) << "\n";
		else cout << f() << "\n";
	}
	return 0;
}