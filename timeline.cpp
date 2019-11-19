//문한규 바보
#include<stdio.h>
#pragma warning(disable:4996)
int arr[1000000];
int cnt = 0;
int max = -1;
void find(int n)
{
	for (int k = 0; k <= n; k++)
	{
		cnt = cnt + arr[k];
		if (max < cnt)
			max = cnt;
		arr[k] = 0;
	}
}
int main()
{
	freopen("timeline.inp", "r", stdin);
	freopen("timeline.out", "w", stdout);
	int Test;
	int line;
	int first_y;
	int first_m;
	int first_d;
	int second_y;
	int second_m;
	int second_d;
	int value;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d", &line);
		
		for (int j = 0; j < line; j++)
		{
			scanf("%d.%d.%d %d.%d.%d", &first_y, &first_m, &first_d, &second_y, &second_m, &second_d);
			value = first_y * 12*31 + first_m * 31 + first_d;
			arr[value]++;
			value = second_y * 12*31 + second_m * 31 + second_d;
			arr[value]--;
		}
		cnt = 0;
		max = -1;
		find(1000000);
		printf("%d\n", max);
	}
}