#include<stdio.h>
int main()
{
	int c;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
	char input[51];
        int index = 1;
		scanf("%s", input);
		for (int i = 0; input[i] != '\0'; i++)
		{
			if (input[i] == '(')
				index++;
			else if (input[i] == ')')
			{
				index--;
				if (index == 0)
					break;				
			}
		}
		if (index == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}