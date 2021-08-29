#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num = 666, count = 1, wantCount;
	string tmp;
	scanf("%d", &wantCount);
	while (count < wantCount)
	{
		num++;
		tmp = to_string(num);
		for (int i = 0; i < tmp.length(); i++)
		{
			if (tmp[i] == '6' && i + 1 < tmp.length() && tmp[i + 1] == '6' && i + 2 < tmp.length() && tmp[i + 2] == '6')
			{
				count++;
				break;
			}
		}
	}
	printf("%d\n", num);
	return 0;
}