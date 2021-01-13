#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct splitPoint
{
	splitPoint* front;
	splitPoint* left;
	splitPoint* right;
	int headIndex;
	int rearIndex;
};

int dataArray[1000001], tmpdataArray[1000001];

void Func(int size, splitPoint* frontSplitPoint, char flag)
{
	splitPoint* newSplitPoint = new splitPoint;
	newSplitPoint->left = NULL;
	newSplitPoint->right = NULL;
	//--------------------------------------------------------------------------------------------------------------------
	//쪼개기 시작
	//수가 하나만 왔음을 의미한다 재귀의 종료 조건이다.
	if (size == 1)
	{
		//size는 풀 사이즈이다.
		if (flag == 'S')
		{
			printf("!!!!!!!!!!오류!!!!!!!! 수가 하나만 왔습니다.\n");
		}

		//size는 반으로 나누어진 사이즈이다. 잊지말자, 여기까지 온 size는 반으로 정확히 떨어진 size이다.
		else if (flag == 'L')
		{
			frontSplitPoint->left = newSplitPoint;

			newSplitPoint->front = frontSplitPoint;
			newSplitPoint->headIndex = frontSplitPoint->headIndex;
			newSplitPoint->rearIndex = frontSplitPoint->headIndex;
		}
		else if (flag == 'R')
		{
			frontSplitPoint->right = newSplitPoint;

			newSplitPoint->front = frontSplitPoint;
			newSplitPoint->headIndex = frontSplitPoint->rearIndex;
			newSplitPoint->rearIndex = frontSplitPoint->rearIndex;
		}
		return;
	}
	//--------------------------------------------------------------------------------------------------------------------
	//size는 풀 사이즈이다.
	if (flag == 'S')
	{
		frontSplitPoint->left = newSplitPoint;

		newSplitPoint->front = NULL;
		newSplitPoint->headIndex = 0;
		newSplitPoint->rearIndex = size - 1;
	}

	//size는 반으로 나누어진 사이즈이다. 잊지말자, 여기까지 온 size는 반으로 정확히 떨어진 size이다.
	else if (flag == 'L')
	{
		frontSplitPoint->left = newSplitPoint;

		newSplitPoint->front = frontSplitPoint;
		newSplitPoint->headIndex = frontSplitPoint->headIndex;
		newSplitPoint->rearIndex = (frontSplitPoint->headIndex) + (size - 1);
	}
	else if (flag == 'R')
	{
		frontSplitPoint->right = newSplitPoint;

		newSplitPoint->front = frontSplitPoint;
		newSplitPoint->headIndex = (frontSplitPoint->rearIndex) - (size - 1);
		newSplitPoint->rearIndex = frontSplitPoint->rearIndex;
	}
	//쪼개기 종료
	//--------------------------------------------------------------------------------------------------------------------
	int sizeHalf, leftPopHead, rightPopHead;
	bool qleftEnd;

	int tmpdataIndex = 0, tmp;//전역변수 tmpdataArray참고
	//--------------------------------------------------------------------------------------------------------------------
	if (size % 2 == 0)//만약에 양 쪽으로 나누어 떨어진다면, 양 쪽으로 정확히 나누어 작은쪽을 POP한다.
	{
		sizeHalf = size / 2;
		Func(sizeHalf, newSplitPoint, 'L'); Func(sizeHalf, newSplitPoint, 'R');//재귀실행
		leftPopHead = newSplitPoint->left->headIndex;//빼낼때 쓰는 변수
		rightPopHead = newSplitPoint->right->headIndex;
		while (1)//왼쪽 오른쪽 둘중에 하나가 다 빠질때 까지 무한반복
		{
			if (leftPopHead == (newSplitPoint->left->rearIndex) + 1)//왼쪽이 다 빠지면 왼쪽이 끝났다고 알림
			{
				qleftEnd = true;
				break;
			}
			if (rightPopHead == (newSplitPoint->right->rearIndex) + 1)//오른쪽이 다 빠지면 오른쪽이 끝났다고 알림
			{
				qleftEnd = false;
				break;
			}
			if (dataArray[leftPopHead] < dataArray[rightPopHead])
				tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
			else
				tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
		}
		if(qleftEnd)//만약에 왼쪽을 마쳤다면 오른쪽을 순서대로 넣는다.
			while(rightPopHead != (newSplitPoint->right->rearIndex) + 1)
				tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
		else//만약에 오른쪽을 마쳤다면 왼쪽을 순서대로 넣는다.
			while (leftPopHead != (newSplitPoint->left->rearIndex) + 1)
				tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];

	}
	else//만약에 양 쪽으로 나누어 떨어지지 않는다면, 세 가지로 나누어 작은쪽을 POP한다.
	{
		tmp = dataArray[newSplitPoint->rearIndex];//하나는 따로 변수를 이용해 뺀다.
		bool qtmpEmpty = false;//따로 뺀 수가 사용 되었는지 알려준다. 현재는 사용되지 않았다.
		sizeHalf = (size - 1) / 2;


		(newSplitPoint->rearIndex)--; //rear와 size가 1 감소한다.맨 끝쪽은 따로 빼주었기 때문이다.
		Func(sizeHalf, newSplitPoint, 'L'); Func(sizeHalf, newSplitPoint, 'R');//재귀실행

		leftPopHead = newSplitPoint->left->headIndex;//빼낼때 쓰는 변수
		rightPopHead = newSplitPoint->right->headIndex;
		//--------------------------------------------------------------------------------------------------------------------
		while (1)//왼쪽 오른쪽 둘중에 하나가 다 빠질때 까지 무한반복
		{
			if (leftPopHead == (newSplitPoint->left->rearIndex) + 1)//왼쪽이 다 빠지면 왼쪽이 끝났다고 알림
			{
				qleftEnd = true;
				break;
			}
			if (rightPopHead == (newSplitPoint->right->rearIndex) + 1)//오른쪽이 다 빠지면 오른쪽이 끝났다고 알림
			{
				qleftEnd = false;
				break;
			}

			//만약에 따로 뺀 수(tmp)가 아직 남아있다면
			if (!qtmpEmpty)
			{
				if (dataArray[leftPopHead] < dataArray[rightPopHead])
				{
					if (dataArray[leftPopHead] < tmp)
						tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
					else
					{
						tmpdataArray[tmpdataIndex++] = tmp;
						qtmpEmpty = true;
					}
				}
				else
				{
					if (dataArray[rightPopHead] < tmp)
						tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
					else
					{
						tmpdataArray[tmpdataIndex++] = tmp;
						qtmpEmpty = true;
					}
				}
			}

			//따로 뺀 수가 남아있지 않다면
			else
			{
				if (dataArray[leftPopHead] < dataArray[rightPopHead])
					tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
				else
					tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
			}
		}
		//--------------------------------------------------------------------------------------------------------------------
		//이 다음은
		//1. tmp가 소비 되어 그대로 나머지 소비만 해주면 되는경우
		//2. tmp가 소비 되지 않아 계속 비교하며 tmp소비가 먼저 끝나 뒤늦게 나머지 소비만 해주는 경우
		//3. tmp가 소비 되지 않아 계속 비교하며 나머지 소비가 먼저 끝나 tmp를 마지막에 소비시켜 주는 경우
		//모두를 고려한다.
 		if (qleftEnd)//만약에 왼쪽을 마쳤다면 오른쪽을 순서대로 넣는다.
		{
			while (rightPopHead != (newSplitPoint->right->rearIndex) + 1)
			{
				//2번의 경우
				if (!qtmpEmpty)
				{
					if (dataArray[rightPopHead] < tmp)
						tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
					else
					{
						tmpdataArray[tmpdataIndex++] = tmp;
						qtmpEmpty = true;
					}
				}
				else
					tmpdataArray[tmpdataIndex++] = dataArray[rightPopHead++];
			}
		}
		else//만약에 오른쪽을 마쳤다면 왼쪽을 순서대로 넣는다.
		{
			while (leftPopHead != (newSplitPoint->left->rearIndex) + 1)
			{
				//2번의 경우
				if (!qtmpEmpty)
				{
					if (dataArray[leftPopHead] < tmp)
						tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
					else
					{
						tmpdataArray[tmpdataIndex++] = tmp;
						qtmpEmpty = true;
					}
				}
				else
					tmpdataArray[tmpdataIndex++] = dataArray[leftPopHead++];
			}
				
		}
		//3번의 경우
		if (!qtmpEmpty)
		{
			tmpdataArray[tmpdataIndex++] = tmp;
			qtmpEmpty = true;
		}
		//--------------------------------------------------------------------------------------------------------------------
		(newSplitPoint->rearIndex)++; //rear을 다시 증가시킨다. 두 갈래로 나눈 파트와 따로 빼둔 파트를 다시 합쳤기 때문이다.
	}

	//tmpdataArray를 채우는 작업이 끝났으면, tmpdataArray를 현재 범위에 참고하여 덮어씌운다.
	for (int i = 0; i < tmpdataIndex; i++)
		dataArray[(newSplitPoint->headIndex) + i] = tmpdataArray[i];

	delete newSplitPoint->left;//이제 둘은 필요없다.
	delete newSplitPoint->right;
	return;
}

int main()
{
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
		scanf(" %d", &dataArray[i]);
	if (size == 1)
	{
		printf("%d\n", dataArray[0]);
	}
	else
	{
		splitPoint* newSplitPoint = new splitPoint;
		Func(size, newSplitPoint, 'S');
		for (int i = 0; i < size; i++)
			printf("%d\n", dataArray[i]);
		delete newSplitPoint->left;
		delete newSplitPoint;
	}
	return 0;
}