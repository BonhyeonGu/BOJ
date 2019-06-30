#include<iostream>
using namespace std;
int main()
{
	char a[101], b[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	scanf("%s", a);
	for (int i = 0; i < 26; i++)
	{
		int space = 0;
		bool find = false;
		for (int j = 0; a[j] != '\0'; j++)
		{
			if (b[i] == a[j])
			{
				find = true;
				break;
			}
			space++;
		}
		if (find == true) printf("%d ", space);
		else printf("-1 ");
	}
}