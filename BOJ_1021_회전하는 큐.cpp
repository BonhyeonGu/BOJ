#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define MAXSIZE 55 


using namespace std;

int dqOK[MAXSIZE], dqSize, dqClearCount;
int want[MAXSIZE], wantSize;
int tmpCounter1, tmpCounter2, moveCounter, nowIndex, tmpIndex1, tmpIndex2;

bool findQ;

int main()
{

	//!!!!!!!!!!!인덱스를 1부터 약속함!!!!!!!!!!!!!!!!!

	scanf("%d %d", &dqSize, &wantSize);
	for (int i = 1; i <= wantSize; i++)
		scanf(" %d", &want[i]);
	for (int i = 1; i <= dqSize; i++)//1부터 size까지의 배열을 만든다.
		dqOK[i] = true;

	nowIndex = 1;//시직위치는 처음
	for (int i = 1; i <= wantSize; i++)
	{

		if (nowIndex == want[i])//지금의 포인터가 원하는 숫자인가?
		{
			dqOK[nowIndex] = false;
			
			nowIndex++;
			while (!dqOK[nowIndex] && nowIndex < dqSize) //숫자가 있을때까지, 마지막 숫자까지 오른쪽으로 가본다.
				nowIndex++;
			if (!dqOK[nowIndex])//그래도 존재하지 않았다면
			{
				nowIndex = 1; //가장 첫번째로 돌아온다.
				while (!dqOK[nowIndex])//처음부터 숫자가 나올때까지 찾는다.
					nowIndex++;
			}
			
		}

		else//첫번째가 아니라면 찾기 시작한다.
		{
			tmpCounter1 = 0, tmpCounter2 = 0;

			findQ = false;
			tmpIndex1 = nowIndex;
			while (!findQ && tmpIndex1 > 1)//현재저짐에서 왼쪽으로 갈수있다면 왼쪽을 알아보겠다.
			{
				tmpIndex1--;

				if (!dqOK[tmpIndex1])//숫자가 없는 칸이면 그다음 칸으로 가본다.
					continue;
				else
				{
					tmpCounter1++;
					if (tmpIndex1 == want[i])//찾았는가?
						findQ = true;
				}
			}	

			if (!findQ)//왼쪽 끝까지 갔지만 못 찾았다면 
			{
				tmpIndex1 = dqSize + 1;//오른쪽 포인터로 이동하고
				while (!findQ)//찾을때까지 왼쪽으로 이동한다.
				{					
					if (!dqOK[tmpIndex1])
					{
						tmpIndex1--;
						continue;
					}
					else
					{
						if (tmpIndex1 == want[i])//찾았는가?
							findQ = true;
						tmpIndex1--;
						tmpCounter1++;
					}
				}
			}

			findQ = false;
			tmpIndex2 = nowIndex;

			while (!findQ && tmpIndex2 < dqSize) //오른쪽으로 갈 수 있다면 오른쪽으로 가겠다.
			{
				tmpIndex2++;//방향은 점점 오른쪽으로 가고

				if (!dqOK[tmpIndex2])//숫자가 없으면 넘어간다.
					continue;

				else
				{				
					tmpCounter2++;//움직인 횟수는 증가한다.

					if (tmpCounter1 <= tmpCounter2)//만약에 왼쪽으로 갔던 값보다 같거나 커진다면 강제종료 시킨다.
					{
						findQ = true;
						break;
					}

					if (tmpIndex2 == want[i])//찾았는가?
						findQ = true;
				}
			}
			if (!findQ)//오른쪽 끝까지 갔지만 못 찾았다면 
			{
				tmpIndex2 = 1;//왼쪽 포인터로 이동하고
				while (!findQ)//찾을때까지 오른쪽으로 이동한다.
				{
					if (!dqOK[tmpIndex2])
					{
						tmpIndex2++;
						continue;
					}
					else
					{
						if (tmpCounter1 <= tmpCounter2)//만약에 왼쪽으로 갔던 값보다 같거나 커진다면 강제종료 시킨다.
						{
							findQ = true;
							break;
						}

						if (tmpIndex2 == want[i])//찾았는가?
							findQ = true;

						tmpCounter2++;
						tmpIndex2++;
					}
				}
			}

			dqOK[want[i]] = false;
			if (want[i] + 1 > dqSize)
				nowIndex = 1;
			else
				nowIndex = want[i] + 1;

			if (!dqOK[nowIndex] && i != wantSize)
			{
				while (!dqOK[nowIndex])
				{
					nowIndex++;
					if (nowIndex > dqSize)
						nowIndex = 1;
				}
			}

			if (tmpCounter1 < tmpCounter2)
				moveCounter += tmpCounter1;
			else
				moveCounter += tmpCounter2;
		}
	}
	printf("%d\n", moveCounter);

	return 0;
}