#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	string c = to_string(a);
	string d = to_string(b);
	string rc, rd;
	for (int i = 0; i < c.size(); i++)
		rc += c[c.size() - i - 1];
	for (int i = 0; i < d.size(); i++)
		rd += d[d.size() - i - 1];
	a = atoi(rc.c_str());
	b = atoi(rd.c_str());
	if (a > b) cout << a << endl;
	else cout << b << endl;
}