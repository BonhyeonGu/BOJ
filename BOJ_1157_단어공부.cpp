#include<iostream>
using namespace std;
int main()
{
	char word[1000002], a[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int counter[26], max = 0, same = 0;
	for (int i = 0; i < 1000002; i++)
	{
		word[i] = NULL;
		if (i < 26)	counter[i] = 0;
	}
	scanf("%s", word);
	for (int i = 0; word[i] != NULL; i++)
		for (int j = 0; j < 26; j++)
			if ((a[j] == word[i]) || ((a[j] + 32) == word[i])) counter[j]++;
	for (int i = 0; i < 26; i++)
	{
		if (max < counter[i])
			max = counter[i];
	}
	for (int i = 0; i < 26; i++)
		if (max == counter[i])same++;
	if (same >= 2)
	{
		printf("?");
		return 0;
	}
	for (int i = 0; i < 26; i++)
		if (max == counter[i]) printf("%c", a[i]);
	return 0;
}