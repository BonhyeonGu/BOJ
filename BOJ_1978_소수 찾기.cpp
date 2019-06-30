#include<iostream>
using namespace std;
int main()
{
	unsigned int size;
	cin >> size;
	int* a = new int[size];
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
		if (a[i] == 1 || a[i] == 0)
			continue;
		bool real = true;
		for (int j = 2; j < a[i]; j++)
		{
			if (a[i] % j == 0)
			{
				real = false;
				break;
			}
		}
		if (real == true) count++;
	}
	cout << count << endl;
	return 0;
}