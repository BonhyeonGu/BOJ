#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string output[6600];
int cycle(int midLine, int value)
{
	if (value == 3)
	{
		output[midLine - 1] += "***";
		output[midLine] += "* *";
		output[midLine + 1] += "***";
	}
	else
	{
		for (int i = 0; i < 3; i++)
			cycle(midLine - value / 3, value / 3);
		cycle(midLine, value / 3);
		for (int i = midLine - value / 3 / 2; i <= midLine + value / 3 / 2; i++)
			for (int j = 0; j < value / 3; j++)
				output[i] += " ";
		cycle(midLine, value / 3);
		
		for (int i = 0; i < 3; i++)
			cycle(midLine + value / 3, value / 3);
	}
	return 0;
}

int main()
{
	int in_size;
	scanf("%d", &in_size);
	cycle(in_size / 2, in_size);
	for (int i = 0; i < in_size; i++)
		cout << output[i] << endl;
	return 0;
}