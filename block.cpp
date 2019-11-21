#include<stdio.h>
#pragma warning(disable:4996)
int block[1001][1001];
int search(int floor)
{
	int count = 0;
	for (int i = 0; i < floor-1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if ( block[i][j] == -1 )
			{
				if (block[i + 1][j] != -1 && block[i + 1][j + 1] != -1)
				{
					block[i][j] = (block[i + 1][j] + block[i + 1][j + 1]) % 100;
					count++;
				}
			}
			else
			{
				if (block[i + 1][j] != -1 && block[i + 1][j + 1] == -1)
				{
					block[i + 1][j + 1] = (block[i][j] + 100 - block[i + 1][j]) % 100;
					count++;
				}
				else if (block[i + 1][j] == -1 && block[i + 1][j + 1] != -1)
				{
					block[i + 1][j] = (block[i][j] + 100 - block[i + 1][j + 1]) % 100;
					count++;
				}
			}
		}
	}
	return count;
}
int main()
{
	freopen("block.inp", "r", stdin);
	freopen("block.out", "w", stdout);
	int Test;
	int floor;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d", &floor);
		for (int j = 0; j < floor; j++)
		{
			for (int k = 0; k < j+1; k++)
				scanf("%d", &block[j][k]);
		}
		while (1)
		{
			int count = search(floor);
			if (count == 0)
				break;
		}
		for (int j = 0; j < floor; j++)
		{
			for (int k = 0; k < j + 1; k++)
			{
				printf("%d ", block[j][k]);
			}
			printf("\n");
		}
	}
}