#include<stdio.h>
#pragma warning(disable:4996)
struct list
{
	int max = 1000000000;
	int min = 0;
	int k = 0; //출력해야할 k의 값
	int cnt = 0;
};
void check(struct list & List, int num, int line)
{
	 // 각 줄마다 k의 최대값 최소값을 결정한다.
	if (List.k != 0)
		return;
	int min;
	int max;
	int min_temp=0;
	int max_temp = 1000000000;
	if (line == 1)
	{
		min = 1;
		max = 0;
	}
	else
	{
		int sum = 1;
		for (int i = 0; i < line-1; i++)
			sum = sum + i;
		min = sum;
		sum = 1;
		for (int i = 0; i< line; i++)
			sum = sum + i;
		max = sum;
	}
	if ((num + 1 - max) % line!=0)
		min_temp = (num + 1 - max) / line + 1;
	else
		min_temp = (num + 1 - max) / line;
	if(line-1!=0)
	max_temp = (num - min) / (line-1);
	if (line == 1)
		min_temp = min_temp-1;
	min = min_temp;
	max = max_temp;
	//printf("%d %d수입니다\n", min, max);
	if (min > List.min)
		 List.min = min;
	if (max < List.max)
		 List.max = max;
	if (List.min == List.max)
		List.k = List.min;
	//printf("%d %d 확인 \n", List.min, List.max);
	List.cnt++;
}
int main()
{
	freopen("line.inp", "r", stdin);
	freopen("line.out", "w", stdout);
	int Test;
	int count;
	int num;
	int line;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		list List;
		scanf("%d", &count);
		for (int j = 0; j < count; j++)
		{
			scanf("%d %d", &num, &line);
			check(List, num, line);
		}
		if (List.k != 0)
			printf("%d %d\n", List.cnt, List.k);
		else
			printf("-1\n");
	}
}