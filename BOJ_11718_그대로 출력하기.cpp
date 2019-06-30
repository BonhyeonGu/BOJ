#include <iostream>
using namespace std;
int main()
{
	char a[101];
	int i = 0;
	while ((a[i] = getchar()) != EOF)
	{
		putchar(a[i]);
		i++;
	}
	return 0;
}