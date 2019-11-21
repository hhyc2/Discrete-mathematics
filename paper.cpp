#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	freopen("paper.inp", "r", stdin);
	freopen("paper.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	int N;
	int M;
	for (int i = 0; i < Test; i++)
	{
		int flag = 0;
		int width[51][51] = { 0, };
		int col[51][51] = { 0, };
		scanf("%d %d", &N, &M);
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M - 1; k++)
				scanf("%d", &width[j][k]);
		}
		for (int j = 0; j < N-1; j++)
		{
			for (int k = 0; k < M; k++)
				scanf("%d", &col[j][k]);
		}
		for (int j = 0; j < N-1; j++)
		{
			for (int k = 0; k < M-1; k++)
			{
				int sum = width[j][k] + width[j + 1][k] + col[j][k] + col[j][k + 1];
				if (sum % 2 == 0 && flag==0)
				{
					printf("0 ");
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
			printf("1 ");
		
	}
}