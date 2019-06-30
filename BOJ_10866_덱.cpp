#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#define MAXSIZE 200000

using namespace std;

int DequeValue[MAXSIZE], DequeFront = 0, DequeRear = 0;
bool DequeOK[MAXSIZE];

int show()
{
	printf("front [%d] back [%d]\n", DequeFront, DequeRear);
	for (int i = 0; i < 10; i++)
	{
		printf("(%d) ", DequeValue[i]);
	}
	printf("\n");
	return 0;
}

int push_front(int value)
{
	if (DequeOK[DequeFront])
	{
		for (int i = DequeRear; i >= DequeFront; i--)
			DequeValue[i + 1] = DequeValue[i];
		DequeOK[DequeRear] = true;
	}

	DequeValue[DequeFront] = value;
	DequeOK[DequeFront] = true;
	DequeRear = ++DequeRear % MAXSIZE;
	return value;
}

int push_back(int value)
{
	DequeValue[DequeRear] = value;
	DequeOK[DequeRear] = true;
	DequeRear = ++DequeRear % MAXSIZE;
	return value;
}

int pop_front()
{
	int value;
	if ((DequeRear - DequeFront) == 0 && !DequeOK[DequeFront])
		value = -1;
	else
	{
		value = DequeValue[DequeFront];
		DequeOK[DequeFront++] = false;
	}
	printf("%d\n", value);
	return value;
}

int pop_back()
{
	int value;
	if ((DequeRear - DequeFront) == 0 && !DequeOK[DequeRear - 1])
		value = -1;
	else
	{
		value = DequeValue[DequeRear - 1];
		DequeOK[--DequeRear] = false;
	}
	printf("%d\n", value);
	return value;
}

int size()
{
	int value = (DequeRear - DequeFront);
	printf("%d\n", value);
	return value;
}

int empty()
{
	int value;
	if ((DequeRear - DequeFront) == 0)
		value = 1;
	else
		value = 0;
	printf("%d\n", value);
	return value;
}

int front()
{
	int value;
	if (!DequeOK[DequeFront])
		value = -1;
	else
		value = DequeValue[DequeFront];
	printf("%d\n", value);
	return value;
}

int back()
{
	int value;
	if (!DequeOK[DequeRear - 1])
		value = -1;
	else
		value = DequeValue[DequeRear - 1];
	printf("%d\n", value);
	return value;
}

int main()
{
	int n, value;
	string comm;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> comm;

		if (comm.compare("push_front") == 0)
		{
			cin >> value;
			push_front(value);
		}
		else if (comm.compare("push_back") == 0)
		{
			cin >> value;
			push_back(value);
		}
		else if (comm.compare("pop_front") == 0)
		{
			pop_front();
		}
		else if (comm.compare("pop_back") == 0)
		{
			pop_back();
		}
		else if (comm.compare("show") == 0)
		{
			show();
		}
		else if (comm.compare("size") == 0)
		{
			size();
		}
		else if (comm.compare("empty") == 0)
		{
			empty();
		}
		else if (comm.compare("front") == 0)
		{
			front();
		}
		else if (comm.compare("back") == 0)
		{
			back();
		}
	}

	return 0;
}