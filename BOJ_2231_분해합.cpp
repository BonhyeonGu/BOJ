#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Start(int num)
{
	int sumValue, oneValue, pos;
	for (int i = 1; i < num; i++)
	{
		pos = 1;
		sumValue = i;
		while (1)
		{
			oneValue = i / pos % 10;
			if (oneValue <= 0) break;
			sumValue += oneValue;
			pos *= 10;
		}
		if (sumValue == num)
			return i;
	}
	return 0;
}

int main()
{
	int input;
	scanf("%d", &input);
	printf("%d\n", Start(input));
	return 0;
}