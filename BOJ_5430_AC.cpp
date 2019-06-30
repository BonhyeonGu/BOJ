#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#define MAXFUNC 100001//십 만
#define MAXARRAY 100001

using namespace std;

int funcSize, arraySize;
string tmpString;
string input;

char func[MAXFUNC];
int numArray[MAXARRAY];
int front, rear;

int MakeFunc_StringToChar()
{
	funcSize = tmpString.length();
	for (int i = 0; i < funcSize; i++)
		func[i] = tmpString[i];

	return 0;
}

int MakeArray_StringToInt()
{
	int stringPoint = 1;
	char ch = tmpString[stringPoint];

	bool tf1, tf2, tf3;
	int num1, num2, num3;

	tf1 = tf2 = tf3 = false;
	while (arraySize != 0)
	{
		if (ch == ']')
		{
			if (tf2)
			{
				if (tf3)
				{
					numArray[rear++] = (num1 * 100) + (num2 * 10) + num3;
				}

				else
				{
					numArray[rear++] = num1 * 10 + num2;
				}

			}

			else
			{
				numArray[rear++] = num1;
			}

			break;
		}
		
		else if (ch == ',')
		{
			if (tf2)
			{
				if (tf3)
				{
					numArray[rear++] = (num1 * 100) + (num2 * 10) + num3;
				}

				else
				{
					numArray[rear++] = num1 * 10 + num2;
				}

			}

			else
			{
				numArray[rear++] = num1;
			}

			tf1 = tf2 = tf3 = false;
		}

		else//tf1 tf2 tf3
		{
			if (tf1)
			{
				if (tf2)
				{
					tf3 = true;
					num3 = (int)ch - 48;
				}

				else
				{
					tf2 = true;
					num2 = (int)ch - 48;
				}
			}

			else
			{
				tf1 = true;
				num1 = (int)ch - 48;
			}
		}

		ch = tmpString[++stringPoint];
	}
		
	return 0;
}

int Drop(bool frontRear)
{
	if (frontRear)
		front++;
	else
		rear--;

	return 0;
}

int Start()
{
	bool frontRear = true;
	bool errorerror = false;
	bool escesc = false;

	for (int i = 0; i < funcSize; i++)
	{
		if (func[i] == 'R')
		{
			if (frontRear)
				frontRear = false;
			else
				frontRear = true;
		}

		else if (func[i] == 'D')
			Drop(frontRear);

		else
		{
			errorerror = true;
			break;
		}
	}

	//출력
	// arraySize == 0 ||
	if (errorerror || front > rear)
	{
		escesc = true;
		printf("error\n");
	}
	else
	{
		printf("[");

		if (frontRear)
		{
			for (int i = front; i < rear; i++)
			{
				if (i == rear - 1)
				{
					printf("%d]\n", numArray[i]);
					escesc = true;
				}
				else
					printf("%d,", numArray[i]);
				
			}
			//printf("%d]\n", numArray[rear - 1]);
		}

		else
		{
			for (int i = rear - 1; i >= front; i--)
			{
				if (i == front)
				{
					printf("%d]\n", numArray[i]);
					escesc = true;
				}
				else
					printf("%d,", numArray[i]);
			}
		}

	}

	if (!escesc)
		printf("]\n");

	return 0;
}

int main()
{
	int c;

	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		cin >> tmpString;
		MakeFunc_StringToChar();
		scanf("%d", &arraySize);
		cin >> tmpString;
		MakeArray_StringToInt();

		Start();
		front = rear = 0;
		
	}

	return 0;
}