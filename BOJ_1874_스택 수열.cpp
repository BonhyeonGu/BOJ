#include<stdio.h>
int push(int *&stack, int &index, int &input)
{
	stack[++index] = ++input;
	return 0;
}

int pop(int *&stack, int &index)
{
	index--;
	return 0;
}

int main()
{
	int c, n, input = 0, index = 0, valc = 0;
	scanf("%d", &c);
	int *stack = new int[c];
	char val[200000];
	stack[0] = 0;
	for (int i = 0; i < c; i++)
	{
		scanf("%d", &n);
		if (stack[index] > n)
		{
			printf("NO\n");
			return 1;
		}
		while (input < n)
		{
			push(stack, index, input);
			val[valc++] = '+';
		}
		pop(stack, index);
		val[valc++] = '-';
	}
	delete[] stack;
	for (int i = 0; i < valc; i++)
		printf("%c\n", val[i]);
	return 0;
}