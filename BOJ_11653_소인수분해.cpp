#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int input, value;
	scanf("%d", &input);
	while (input != 1)
	{
		value = 2;
		while (input % value != 0)
			value++;
		printf("%d\n", value);
		input /= value;
	}
	return 0;
}