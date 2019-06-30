#include <iostream>
using namespace std;
int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		int* a = new int[in2]; 
		for (int j = 0; j < in2; j++)
			a[j] = j + 1;
		for (int j = 0; j < in1; j++)
		{
			int* b = new int[in2];
			for (int k = 0; k < in2; k++)
			{
				int sum = 0;
				for (int l = 0; l <= k; l++)
					sum += a[l];
				b[k] = sum;
			}
			for (int k = 0; k < in2; k++)
				a[k] = b[k];
			delete b;
		}
		cout << a[in2 - 1] << endl;
		delete a;
	}
	return 0;
}