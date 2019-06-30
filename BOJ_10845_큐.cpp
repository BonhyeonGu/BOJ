#include<iostream>
#include<string>
#define MAXSIZE 10001
using namespace std;
int queue[MAXSIZE], front = 0, rear = 0;
int push(int val)
{
	queue[rear] = val;
	rear = ++rear%MAXSIZE;
	return 0;
}

int pop()
{
	if (front == rear)
		return -1;
	int val = queue[front];
	front = ++front%MAXSIZE;
	return val;
}

int size()
{
	int val = rear - front;
	return val;
}

int ffront()
{
	if (front == rear)
		return -1;
	return queue[front];
}

int back()
{
	if (front == rear)
		return -1;
	return queue[rear - 1];
}

int main()
{
	int c;
	string comm;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		cin >> comm;
		if (comm.compare("push") == 0)
		{
			int val;
			cin >> val;
			push(val);
		}

		else if (comm.compare("pop") == 0)
			printf("%d\n", pop());

		else if (comm.compare("size") == 0)
			printf("%d\n", size());

		else if (comm.compare("empty") == 0)
			printf("%d\n", size() == 0);

		else if (comm.compare("front") == 0)
			printf("%d\n", ffront());

		else if (comm.compare("back") == 0)
			printf("%d\n", back());

	}
	return 0;
}