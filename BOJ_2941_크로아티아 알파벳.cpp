#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	int counter = 0;
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		counter++;
		if ((a[i] == 'c' && ((a[i + 1] == '=') || (a[i + 1] == '-'))) || ((a[i] == 'd') && (a[i + 1] == '-')) || ((a[i] == 'l') && (a[i + 1] == 'j')) || ((a[i] == 'n') && (a[i + 1] == 'j')) || ((a[i] == 's') && (a[i + 1] == '=')) || ((a[i] == 'z') && (a[i + 1] == '=')))
			i++;
		if (a[i] == 'd'&&a[i + 1] == 'z'&&a[i + 2] == '=')
			i += 2;
	}
	cout << counter << endl;
	return 0;
}