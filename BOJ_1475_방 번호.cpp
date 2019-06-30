#include <iostream>
#include <string>
using namespace std;

int buy(char *box,int &boxs)
{
	boxs += 11;
	realloc(box, boxs);
	char in = '0';
	for (int i = boxs - 11; i < boxs; i++)
		box[i] = in++;
	box[boxs - 1] = '6';
	return 0;
}

int main()
{
	string n;
	cin >> n;
	for (int i = 0; i < n.size(); i++)
		if (n[i] == '9')
			n[i] = '6';
	int buyc = 0, boxs = 0;
	char* box = (char*)malloc(sizeof(char) * boxs);
	for (int i = 0; i < n.size(); i++)
	{
		bool gotit = false;
		for (int j = 0; j <= boxs; j++)
		{
			if (n[i] == box[j])
			{
				box[j] = '\0';
				gotit = true;
				break;
			}
		}
		if (gotit == false)
		{
			buyc++;
			buy(box, boxs);
			i--;
		}
	}
	cout << buyc << endl;
	return 0;
}