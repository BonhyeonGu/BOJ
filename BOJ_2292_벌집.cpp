#include<iostream>
using namespace std;
int main()
{
	unsigned int input, count = 1, same = 1, gop = 6, gopca = 1;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		if (i == same)
		{
			count++;
			same += (gop*gopca);
			gopca++;
		}
	}
	cout << count << endl;
	return 0;
}