#include<iostream>
using namespace std;
int main()
{
	int a;
	scanf("%d\n", &a);
	char** ans = new char*[a];
	for (int i = 0; i < a; i++)
	{
		ans[i] = new char[80];
	}
	for (int i = 0; i < a; i++)
	{
		int j = 0;
		while ((ans[i][j] = getchar()) != '\n')
			j++;
	}
	for (int i = 0; i < a; i++)
	{
		int score = 0, plus = 1;
		for (int j = 0; j < ans[i][j] != NULL; j++)
		{
			switch (ans[i][j])
			{
			case 'O':
				score += plus;
				plus++;
				break;
			case 'X':
				plus = 1;
			}
		}
		printf("%d\n", score);
		delete [] ans[i];
	}
	delete [] ans;
}