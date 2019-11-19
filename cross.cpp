#include<stdio.h>
#pragma warning(disable:4996)
int arr[10001];
int check[10001];
int main()
{
	freopen("cross.inp", "r", stdin);
	freopen("cross.out", "w", stdout);
	int Test;
	int count = 0;
	int num;
	int value;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		count = 0;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%d ", &value);
			arr[value] = j;
		}
		for (int j = 0; j < num; j++)
		{
			scanf("%d ", &value);
			check[value] = j;
		}
		for (int k = 0; k < num; k++)
		{
			for (int l = k + 1; l <= num; l++)
			{
				if (arr[k]<arr[l] && check[k]>check[l])
					count++;
				else if (arr[k] > arr[l] && check[k] < check[l])
					count++;
			}
		}
		printf("Case %d: %d\n", i + 1, count);
	}
}