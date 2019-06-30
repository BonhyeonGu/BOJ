#include<iostream>
using namespace std;
int main()
{
	int c, h, w, n;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int val;
		cin >> h >> w >> n;
		if (n%h == 0) val = h * 100 + (n / h);
		else  val = n%h * 100 + (n / h) + 1;
		cout << val << endl;
	}
	return 0;
}