#include<iostream>
using namespace std;
int main()
{
	int a;
	scanf("%d", &a);
	int** star = new int*[a];
	for (int i = 0; i < a; i++)
	{
		star[i] = new int[(a*2)-1];
		for (int j = 0; j < ((a * 2) - 1); j++)
			star[i][j] = 0;
	}
	star[0][((a * 2) - 1) / 2] = 1;
	for (int i = 1; i < a; i++)
	{
		for (int j = 0; j < (a * 2) - 1; j++)
		{
			switch ((i+1)%3)
			{
			case 1:
				if ((star[i - 1][j - 1]) + (star[i - 1][j]) + (star[i - 1][j + 1]) == 1)star[i][j] = 1;
				break;
			case 2:
				if ((star[i - 1][j + 1] == 1) || (star[i - 1][j - 1] == 1)) star[i][j] = 1;
				break;
			case 0:
				if ((star[i - 1][j + 1] == 1) || (star[i - 1][j - 1] == 1) || (star[i - 1][j] == 1)) star[i][j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < (a * 2) - 1; j++)
		{
			if (star[i][j] == 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}