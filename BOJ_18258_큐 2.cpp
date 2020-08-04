#include <iostream>
#include <string>
#define MAXSIZE 2000001
using namespace std;

int myQueue[MAXSIZE];

class CMyQueue
{
private:

	int pushIndex;
	int popIndex;
public:
	CMyQueue();
	void Push(int value);
	void Pop();
	void Size();
	bool Empty();
	void Front();
	void Back();
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

void CMyQueue::Pop()
{
	if (Empty())
		cout << "-1\n";
	else
		cout << myQueue[popIndex++] << "\n";
}

void CMyQueue::Size()
{
	cout << pushIndex - popIndex << "\n";
}

bool CMyQueue::Empty()
{
	if (popIndex == pushIndex)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CMyQueue::Front()
{
	if (Empty())
		cout << "-1\n";
	else
		cout << myQueue[popIndex] << "\n";
}

void CMyQueue::Back()
{
	if (Empty())
		cout << "-1\n";
	else
		cout << myQueue[pushIndex - 1] << "\n";
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int c, tmp_value;
	string comm;
	CMyQueue q;
	
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> comm;
		if (comm.compare("push") == 0)
		{
			cin >> tmp_value;
			q.Push(tmp_value);
		}
		else if (comm.compare("pop") == 0)
			q.Pop();
		else if (comm.compare("size") == 0)
			q.Size();
		else if (comm.compare("empty") == 0)
		{
			if (q.Empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (comm.compare("front") == 0)
			q.Front();
		else if (comm.compare("back") == 0)
			q.Back();
		else
			cout << "?\n";
	}
}