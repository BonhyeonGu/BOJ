#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int size;
	cin >> size;
	int* num = new int[size];
	for (int i = 0; i < size; i++)
	{
		int a, b;
		cin >> a >> b;
		num[i] = b - a;
	}
	for (int i = 0; i < size; i++)
	{
		int mid = sqrt(num[i]);
		int count = mid * 2 - 1;
		if (num[i] > mid*mid)
			count++;
		if (num[i] > mid*mid + mid)
			count++;
		cout << count << endl;
	}
    return 0;
}