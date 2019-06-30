#include<iostream>
using namespace std;
int main()
{
	int a[5], sum = 0;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	for (int i = 0; i < 5; i++)
	{
		if (a[i] < 40) a[i] = 40;
		sum += a[i];
	}
	cout << sum / 5 << endl;
	return 0;
}