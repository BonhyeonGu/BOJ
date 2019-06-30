#include <stdio.h>
#include <stdlib.h>

int main()
{
	char word[100];
	scanf("%s", word);
	for (int i = 0; word[i] != NULL; i++)
	{
		if ((i % 10 == 0) && (i / 10 != 0)) printf("\n");
		printf("%c", word[i]);
	}
}