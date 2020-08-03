#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXSIZE 100
using namespace std;

class CMyStack
{
private:
	int myStack[MAXSIZE];
	int index;
public:
	CMyStack();
	void Push(char value);
	char Pop();
	bool Empty();
	char Last();
};

CMyStack::CMyStack()
{
	index = 0;
}

void CMyStack::Push(char value)
{
	myStack[index++] = value;
}

char CMyStack::Pop()
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

char CMyStack::Last()
{
	return myStack[index - 1];
}

int main()
{
	while (true)
	{
		CMyStack s;
		int stringSize = 0;
		char c;
		bool ok = true;
		
		while ((c = getchar()) != '.')
		{
			if (ok)
			{
				if (c == '(' || c == '[')
					s.Push(c);
				else if (c == ')')
				{
					if (s.Last() == '(')
						s.Pop();
					else
						ok = false;
				}
				else if (c == ']')
				{
					if (s.Last() == '[')
						s.Pop();
					else
						ok = false;
				}
			}
			stringSize++;
		}
		getchar();
		if (stringSize == 0)
			break;
		if (s.Empty() && ok)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}