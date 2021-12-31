#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string inp1, inp2;
int inpUp[5004], inpDown[5004], upSize, downSize;
int dp[5004][5004];
int logCounterUp[30][5004], logCounterDown[30][5004];

int minmin(int n1, int n2)
{
	if (n1 < n2)return n1;
	else return n2;
}

void f()
{
	//Ǯ�� �ݺ�������
	for (int i = 0; i < upSize + 1; i++)
	{
		for (int j = 0; j < downSize + 1; j++)
		{
			int tmp, a, b;
			//dp�迭 �Ʒ�!!!!�� ������!!!!!�� ������ �����ǵ�
			//���� ó�� ���� ���ĺ�(���� 1�� ���)��� �̰��� �����Ѵ�.
			//���� ���� �α׿� �� �α��� ������ ���ĺ��� ���ٸ� ���Ѵ�
			//�ε�����~~~~~~���� ������~~~~~~~~ �Ѻ�κ�`
			a = b = 0;
			if (logCounterUp[inpUp[i]][i + 1] + logCounterDown[inpUp[i]][j] == 1)
				b = i + 1 + j;
			if (logCounterUp[inpUp[i]][i + 1] + logCounterDown[inpUp[i]][j] == logCounterUp[inpUp[i]][upSize] + logCounterDown[inpUp[i]][downSize])
				a = i + 1 + j;
			tmp = a - b;
			dp[i + 1][j] = minmin(dp[i][j] + tmp, dp[i + 1][j]);

			a = b = 0;
			if (logCounterUp[inpDown[j]][i] + logCounterDown[inpDown[j]][j + 1] == 1)
				b = i + 1 + j;
			if (logCounterUp[inpDown[j]][i] + logCounterDown[inpDown[j]][j + 1] == logCounterUp[inpDown[j]][upSize] + logCounterDown[inpDown[j]][downSize])
				a = i + 1 + j;
			tmp = a - b;
			dp[i][j + 1] = minmin(dp[i][j] + tmp, dp[i][j + 1]);
		}
	}
}

//���ĺ� ������ ��ȭ�� ���Ұ��̴�. ���̷��� ó���� ����� ���߿� �� ��츦 ����ϱ����� �ڷᱸ���� �����ʿ��ϴ�
//idx1 = ���ĺ�
//idx2 = Ƚ��
void makeLog()
{
	for (int i = 1; i < upSize + 1; i++)
	{
		for (int j = 0; j < 30; j++)
			logCounterUp[j][i] = logCounterUp[j][i - 1];
		logCounterUp[inpUp[i - 1]][i] += 1;
	}
	for (int i = 1; i < downSize + 1; i++)
	{
		for (int j = 0; j < 30; j++)
			logCounterDown[j][i] = logCounterDown[j][i - 1];
		logCounterDown[inpDown[i - 1]][i] += 1;
	}
}

void encodeencode()
{
	upSize = inp1.length();
	downSize = inp2.length();
	for (int i = 0; i < upSize; i++)
		inpUp[i] = inp1[i] - 'A';
	for (int i = 0; i < downSize; i++)
		inpDown[i] = inp2[i] - 'A';
}


int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		cin >> inp1;
		cin >> inp2;//���� �Ǽ��ؼ� �ε��� �ϳ��� �ѳ�~~
		fill(&logCounterUp[0][0], &logCounterUp[29][upSize + 1], 0);
		fill(&logCounterDown[0][0], &logCounterDown[29][downSize + 1], 0);
		encodeencode();
		makeLog();
		fill(&dp[0][0], &dp[5003][5004], 999999999);
		dp[0][0] = 0;
		f();
		cout << dp[upSize][downSize] << '\n';
	}
	return 0;
}