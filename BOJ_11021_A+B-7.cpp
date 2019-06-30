#include<iostream>
using namespace std;
int main()
{
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout <<"Case #"<<i+1<< ": "<< a + b << endl;
	}
	return 0;
}