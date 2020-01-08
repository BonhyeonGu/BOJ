#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int a[10], aIndex, tmp;
bool sameQ;

int main()
{	
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &tmp);
		tmp %= 42;
		sameQ = false;
		for (int j = 0; j < aIndex; j++)
		{
			if (tmp == a[j])
			{
				sameQ = true;
				break;
			}
		}
		if (!sameQ)
			a[aIndex++] = tmp;
	}
	printf("%d\n", aIndex);
}