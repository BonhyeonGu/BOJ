#include <stdio.h>
int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		bool itis = false;
		for (int j = 1; j < i; j++)
		{
			if (i == ((j/1000%10)+(j/100%10)+((j/10)%10)+(j % 10) + j))
			{
				itis = true;
				break;
			}
		}
		if (itis == false) printf("%d\n", i);
	}
}