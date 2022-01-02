#include <iostream>
#include <cstring>
#include <queue>
#include <functional>
#define MAX 999999999
using namespace std;

int dp[201][201][201];
priority_queue<int, vector<int>, greater<int>> tq;
void indp(int n1, int n2, int n3, int y)
{
	//if (a[n1][n2][n3] != 0) return;
	dp[n1][n2][n3] = y;
	dp[n1][n3][n2] = y;
	dp[n2][n1][n3] = y;
	dp[n2][n3][n1] = y;
	dp[n3][n1][n2] = y;
	dp[n3][n2][n1] = y;
	return;
}

int f(int w, int l, int h)
{
	if (dp[w][l][h] != 0) return dp[w][l][h];

	if (w == l && l == h) indp(w, l, h, 1);
	else if (w == 1 || l == 1 || h == 1) indp(w, l, h, w * l * h);
	else
	{
		int n1 = MAX, n2 = MAX, n3 = MAX, tmp;
		//w 1¿¡¼­ ³ª´©¸é w°¡ 1ÀÌ¶û w-1ÀÌ¶û 
		for (int i = 1; i <= w / 2; i++)
		{
			tmp = f(i, l, h) + f(w - i, l, h);
			if (tmp < n1) n1 = tmp;
		}
		for (int i = 1; i <= l / 2; i++)
		{
			tmp = f(w, i, h) + f(w, l - i, h);
			if (tmp < n2) n2 = tmp;
		}
		for (int i = 1; i <= h / 2; i++)
		{
			tmp = f(w, l, i) + f(w, l, h - i);
			if (tmp < n3) n3 = tmp;
		}
		tq.push(n1); tq.push(n2); tq.push(n3);
		indp(w, l, h, tq.top()); tq.pop(); tq.pop(); tq.pop();
	}
	return dp[w][l][h];
}


int main()
{
	dp[1][1][1] = 1;
	int caseSize, n1, n2, n3;
	cin >> caseSize;
	for (int i = 0; i < caseSize; i++)
	{
		cin >> n1 >> n2 >> n3;
		memset(dp, 0, sizeof(dp));
		cout << f(n1, n2, n3) << "\n";
	}
	return 0;
}