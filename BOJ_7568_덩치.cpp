#include <iostream>
using namespace std;

struct studentValue
{
	int weight;
	int tall;
};

int main()
{
	int sSize;
	studentValue s[50];
	scanf("%d", &sSize);
	for (int i = 0; i < sSize; i++)
		scanf(" %d %d", &s[i].weight, &s[i].tall);
	for (int i = 0; i < sSize; i++)
	{
		int c = 0;
		for (int j = 0; j < sSize; j++)
		{
			if (i == j)
				continue;
			if (s[i].weight < s[j].weight && s[i].tall < s[j].tall)
				c++;
		}
		printf("%d ", c + 1);
	}
	return 0;
}