#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXSIZE 1000000
using namespace std;

class CMyQueue
{
private:
	int myQueue[MAXSIZE];
	int pushIndex;
	int popIndex;
public:
	CMyQueue();
	void Push(int value);
	int Pop();
	bool LastOne();
};

CMyQueue::CMyQueue()
{
	pushIndex = 0;
	popIndex = 0;
}

void CMyQueue::Push(int value)
{
	myQueue[pushIndex++] = value;
}

int CMyQueue::Pop()
{
	return myQueue[popIndex++];
}

bool CMyQueue::LastOne()
{
	if (popIndex + 1 == pushIndex)
		return true;
	else
		return false;
}

int main()
{
	int n;
	CMyQueue *q;
	q = new(CMyQueue);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		q->Push(i);
	while (true)
	{
		if (q->LastOne())
			break;
		q->Pop();
		if (q->LastOne())
			break;
		q->Push(q->Pop());
	}

	printf("%d\n", q->Pop());
	return 0;
}