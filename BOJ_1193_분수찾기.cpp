#include<iostream>
using namespace std;
int main()
{
	unsigned int input;
	int maxline = 3, tmp = 1, down, ans[2], sum = 3;
	cin >> input;
	if (input == 1)
	{
		cout << "1/1" << endl;
		return 0;
	}
	bool sw = false;
	for (int i = 1; i < input; i++)
	{
		if (sw == false)
		{
			if (i < maxline)
			{
				ans[0] = tmp;
				ans[1] = maxline - i;
				tmp++;
			}
			else
			{
				tmp = 1;
				maxline += sum;
				sum++;
				i--;
				sw = true;
			}
		}
		else
		{
			if (i < maxline)
			{
				ans[1] = tmp;
				ans[0] = maxline - i;
				tmp++;
			}
			else
			{
				tmp = 1;
				maxline += sum;
				sum++;
				i--;
				sw = false;
			}
		}

	}
	cout << ans[0] << "/" << ans[1] << endl;
	return 0;
}