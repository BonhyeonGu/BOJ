#include <iostream>
#include <string>
using namespace std;
int stack[10000], s = 0;
int push(int val)
{
	stack[s] = val;
	s++;
	return 0;
}

int pop()
{
	if (stack[s - 1] == NULL)
		return -1;
	s--;
	int tmp = stack[s];
	stack[s] = NULL;
	return(tmp);
}

int size()
{
	return s;
}

int empty()
{
	if (stack[s - 1] == NULL)
		return 1;
	return 0;
}

int top()
{
	if (stack[s - 1] == NULL)
		return -1;
	return stack[s - 1];
}

int main()
{
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		string command;
		cin >> command;
		if (command.compare("push") == 0)
		{
			int b;
			cin >> b;
			push(b);
		}
		else if (command.compare("pop") == 0)
			cout << pop() << endl;
		else if (command.compare("size") == 0)
			cout << size() << endl;
		else if (command.compare("empty") == 0)
			cout << empty() << endl;
		else if (command.compare("top") == 0)
			cout << top() << endl;
		else cout << "?" << endl;
	}

	return 0;
}