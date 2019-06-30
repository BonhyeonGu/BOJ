#include <stdio.h>

#define JAN 31
#define FEB 28
#define MAR 31
#define APR 30
#define MAY 31
#define JUN 30
#define JUL 31
#define AUG 31
#define SEP 30
#define OCT 31
#define NOV 30
#define DEC 31

int main()
{
	int month[12]{ JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC };
	int a, b, day = 0;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a - 1; i++)
	{
		day += month[i];
	}
	switch ((day + b) % 7)
	{
	case 0: printf("SUN");
		break;
	case 1: printf("MON");
		break;
	case 2: printf("TUE");
		break;
	case 3: printf("WED");
		break;
	case 4: printf("THU");
		break;
	case 5: printf("FRI");
		break;
	case 6: printf("SAT");
		break;
	}
	return 0;
}