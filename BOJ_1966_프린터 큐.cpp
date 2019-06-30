#include<stdio.h>
int start(int size, int index_query)
{
	int a[101], counter = 0;
	for (int i = 0; i < size; i++)
		scanf("%d", &a[i]);
	while (1)
	{
		int tmp = a[0], max = -1, max_index;
		bool same = true;
		for (int i = 0; i < size; i++)
		{
			if (a[i] != same)
				same = false;
			if (a[i] > max)
			{
				max = a[i];
				max_index = i;
			}
		}
		if (same)
			return counter + index_query + 1;
		if (max_index == index_query)
			return counter + 1;
		else
		{
			int b[101], b_index = 0;
			for (int i = max_index + 1; i < size; i++)
				b[b_index++] = a[i];
			for (int i = 0; i < max_index; i++)
				b[b_index++] = a[i];
			for (int i = 0; i < b_index; i++)
				a[i] = b[i];
			size--;
			if (max_index < index_query)
				index_query -= max_index + 1;
			else
				index_query += size - max_index;
			counter++;
		}		
	}
}

int main()
{
	int c;
	scanf("%d", &c);
	for (int cc = 0; cc < c; cc++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", start(a, b));
	}
	return 0;
}
