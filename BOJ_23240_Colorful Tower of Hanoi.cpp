#include <iostream>
#include <cstring>
#include <map>
#define R -1
#define B 1
#define G 0
using namespace std;

int rSize;
struct ring
{
	int color;
	int count;
};
ring r[26];
int val[26];

int f()
{
	if (rSize == 1)
	{
		if (r[1].color == R) return r[1].count;
		else if (r[1].color == B) return r[1].count * 2 - 1;
	}

	int ret;
	for (int i = 1; i <= rSize; i++)
		val[i] = val[i - 1] * 2 + r[i].count;

	ret = val[rSize];
	if (r[rSize].color == B && r[rSize].count != 1)
	{
		ret += r[rSize].count + val[rSize - 1];
		r[rSize - 1].color *= -1;
		r[rSize].color = R;
	}

	for (int i = rSize - 1; i >= 2; i--)
	{
		if (r[i].color == R && r[i].count != 1)
		{
			ret += r[i].count + val[i - 1];
			r[i - 1].color *= -1;
			r[i].color = B;
		}
	}

	if (r[1].color == R && r[1].count != 1)
	{
		ret += r[1].count - 1;
		r[1].color = B;
	}
	return ret;
}

int main()
{
	char tc;
	val[0] = 0;
	cin >> rSize;
	for (int j = 1; j <= rSize; j++)
	{
		ring& t = r[j];
		cin >> tc >> t.count;
		if (tc == 'R') t.color = R;
		else if (tc == 'G') t.color = G;
		else if (tc == 'B') t.color = B;
	}
	cout << f() << "\n";	
	return 0;
}