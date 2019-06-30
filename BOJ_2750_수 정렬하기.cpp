#include<iostream>
using namespace std;
int main()
{
	int input, min = 0;
	cin >> input;
	int* a = new int[input];
	int* b = new int[input];
	for (int i = 0; i < input; i++)
		cin >> a[i];
	for (int i = 0; i < input; i++)
	{
		int maxindex, max = 1001;
		for (int j = 0; j < input; j++)
		{
			if (max > a[j])
			{
				max = a[j];
				maxindex = j;
			}
		}
		b[i] = a[maxindex];
		a[maxindex] = 1001;
	}
	for (int i = 0; i < input; i++)
		cout << b[i] << endl;
	return 0;
}