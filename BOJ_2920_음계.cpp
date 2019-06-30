#include<iostream>
using namespace std;
int main()
{
	char a[8], asc[8] = { 1,2,3,4,5,6,7,8 }, des[8] = { 8,7,6,5,4,3,2,1 };
	int as = 0, de = 0;
	for (int i = 0; i < 8; i++)
	{
		scanf(" %d", &a[i]);
		if (a[i] == asc[i])as++;
		if (a[i] == des[i])de++;
	}
	if (as == 8) cout << "ascending" << endl;
	else if (de == 8) cout << "descending" << endl;
	else cout << "mixed" << endl;
	return 0;
}