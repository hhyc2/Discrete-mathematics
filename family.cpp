#include<stdio.h>
#pragma warning(disable:4996)
int visit[500001]; // 출발점 도착점 표시
int height[500001]; // 높이 표시
int max = 0;
int find_height(int num)
{
	int hei = 0;
	while (1)
	{
		hei++;
		if (visit[num] == 0)
			return hei;
		else
		{
			if (height[visit[num]] != 0 && visit[num] != 0) // 저장한 값이 있을때 
				return height[visit[num]] + hei;
			else // 0일때
				num = visit[num];
		}
	}
}
void find(int num)
{
	for (int i = 1; i <= num; i++)
	{
		if (visit[i] == 0)  // 루트일 때 체크 표시
			continue;
		else
		{
			int value = find_height(i);
			height[i] = value; // 값 넣어주기
			if (max < value)
				max = value;
		}
	}
}
int main()
{
	freopen("family.inp", "r", stdin);
	freopen("family.out", "w", stdout);
	int Test;
	int num;
	int first;
	int second;
	int value;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d", &num);
		for (int j = 0; j < num - 1; j++)
		{
			scanf("%d %d", &first, &second);
			visit[second] = first; // 0이면 루트 
		}
		find(num);
		printf("%d\n", max);
		max = 0;
		for (int i = 1; i <= num; i++)
		{
			visit[i] = 0;
			height[i] = 0;
		}

	}
}