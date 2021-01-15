#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int inputArray[1000001];
int outputArray[1000001], outputIndex;
int dataArray[1000001], dataIndex;

int main()
{
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
		scanf(" %d", &inputArray[i]);

	dataArray[dataIndex++] = inputArray[size - 1];
	outputArray[outputIndex++] = -1;

	bool qfind;
	int nownum;
	for (int i = size - 2; i >= 0; i--)
	{
		qfind = false;
		nownum = inputArray[i];
		for (int j = dataIndex - 1; j >= 0; j--)
		{
			if (nownum < dataArray[j])
			{
				qfind = true;
				outputArray[outputIndex++] = dataArray[j];
				break;
			}
		}
		if(!qfind)
			outputArray[outputIndex++] = -1;

		while (dataIndex > 0 && nownum >= dataArray[dataIndex - 1])
			dataIndex--;
		dataArray[dataIndex++] = nownum;
	}
	for (int i = outputIndex - 1; i >= 0; i--)
		printf("%d ", outputArray[i]);
}