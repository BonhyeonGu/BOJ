#include<iostream>
using namespace std;
int main()
{
	int a;
	scanf("%d\n", &a);
	char** word = new char*[a];
	int* gop = new int[a];
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &gop[i]);
		word[i] = new char[20];
		scanf(" %s", word[i]);
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; word[i][j] != '\0'; j++)
			for (int k = 0; k < gop[i]; k++)
				printf("%c", word[i][j]);
		printf("\n");
	}
	return 0;
}