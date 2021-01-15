#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int n1[10001], n2[10001], n3[10001];
int main()
{
	int* nMoreBig;
	int sizeMin, sizeMax, tmp, tmpCarry = 0;
	string s1, s2, s3 = "", s4 = "";
	cin >> s1 >> s2;

	if (s1.size() < s2.size())
	{
		sizeMin = s1.size();
		sizeMax = s2.size();
		nMoreBig = n2;
	}
	else
	{
		sizeMin = s2.size();
		sizeMax = s1.size();
		nMoreBig = n1;
	}
	//최소값 기준으로 묶어서 반복시키면 맞지 않는 자리수, 최대값 기준으로 묶어서 반복시키면 없는 자리 인덱싱 오류, 분할해서 반복한다.
	for (int i = s1.size() - 1; i >= 0; i--)
		n1[s1.size() - i - 1] = s1[i] - 48;
	for (int i = s2.size() - 1; i >= 0; i--)
		n2[s2.size() - i - 1] = s2[i] - 48;
	for (int i = 0; i < sizeMin; i++)
	{
		tmp = n1[i] + n2[i] + tmpCarry;
		if (tmp >= 10)
		{
			tmp -= 10;
			tmpCarry = 1;
		}
		else
			tmpCarry = 0;
		n3[i] = tmp;
	}
	for (int i = sizeMin; i < sizeMax; i++)
	{
		tmp = nMoreBig[i] + tmpCarry;
		if (tmp >= 10)
		{
			tmp -= 10;
			tmpCarry = 1;
		}
		else
			tmpCarry = 0;
		n3[i] = tmp;
	}
	if (tmpCarry == 1)
		n3[sizeMax++] = 1;
	for (int i = sizeMax - 1; i >= 0; i--)
		printf("%d", n3[i]);
	return 0;
}