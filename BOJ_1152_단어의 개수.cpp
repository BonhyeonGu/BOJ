#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	int counter = 0;
	getline(cin, a);
	a += ' ';
	for (int i = 0; a[i] != '\0'; i++)
		if ((a[i] != ' ') && (a[i + 1] == ' '))
			counter++;
	cout << counter << endl;
	return 0;
}