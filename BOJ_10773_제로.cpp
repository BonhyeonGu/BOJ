#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXSIZE 100000
using namespace std;

class CMyStack
{
private:
	int myStack[MAXSIZE];
	int index;
public:
	CMyStack();
	void Push(int value);
	int Pop();
	bool Empty();
};

CMyStack::CMyStack()
{
	index = 0;
}

void CMyStack::Push(int value)
{
	myStack[index++] = value;
}

int CMyStack::Pop()
{
	return myStack[--index];
}

bool CMyStack::Empty()
{
	if (index == 0)
		return true;
	else
		return false;
}

int main()
{
	int c, tmpValue, sum = 0;
	CMyStack *s;
	s = new(CMyStack);
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		scanf(" %d", &tmpValue);
		if (tmpValue == 0)
			s->Pop();
		else
			s->Push(tmpValue);
	}
	while(!s->Empty())
		sum += s->Pop();
	printf("%d\n", sum);
	return 0;
}