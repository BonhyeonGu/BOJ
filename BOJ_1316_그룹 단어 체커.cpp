#include <iostream>
#include<string.h>
using namespace std;
int main()
{
	int s, allcounter = 0;
	cin >> s;
	char** word = new char*[s];
	for (int i = 0; i < s; i++)
	{
		word[i] = new char[101];
		cin >> word[i];
	}
	for (int i = 0; i < s; i++)
	{
		int counter = 0, as = 0, tmps = 0;
		char a[26];
		int bs = strlen(word[i]);
		for (int j = 0; word[i][j] != '\0'; j++)
		{
			bool ss = false;
			for (int k = 0; k < as; k++)
				if (a[k] == word[i][j])
				{
					ss = true;
					break;
				}
			if (ss == true) continue;
			a[as] = word[i][j];
			as++;
			for (int k = j; k < bs; k++)
			{
				if (word[i][j] != word[i][k + 1]) break;
				else
					j++;
			}
			int same = 0;
			for (int k = j; k < bs; k++)
				if (word[i][j] == word[i][k]) same++;
			if (same < 2)
				counter++;
			tmps++;
		}
		if ((counter - tmps) == 0)allcounter++;
	}
	cout << allcounter << endl;
	return 0;
}