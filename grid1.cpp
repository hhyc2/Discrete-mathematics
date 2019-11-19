#include <stdio.h>
#pragma warning(disable:4996)
int main(void)
{
	int Test;
	int N;
	int M;
	int type;
	int start;
	int k;
	int num = 1;
	int flag = 0;
	int count = 0;
	int value;
	freopen("grid1.inp", "r", stdin);
	freopen("grid1.out", "w", stdout);
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d %d %d %d %d", &N, &M, &type, &start, &k);
		if (type == 1)
		{
			if (start == 1)
			{
				value = (k-1) / M;
				if (value % 2 == 0)
				{
					num = value * M + (k-1) % M + 1;
					printf("%d\n", num);
				}
				else
				{
					num = (value+1) * M - (k-1) % M;
					printf("%d\n", num);
				}
			}
			else if (start == 2)
			{
				value = (k-1) / M;
				if (value % 2 == 0)
				{
					num = (value+1) * M - (k-1) % M;
					printf("%d\n", num);
				}
				else
				{
					num = value * M + (k-1) % M +1 ;
					printf("%d\n", num);
				}
			}
			else if (start == 3)
			{
				value = (k-1) / M;
				if (value % 2 == 0)
				{
					num = (N - value) * M - (k-1) % M;
					printf("%d\n", num);
				}
				else
				{
					num = (N - value - 1) * M + (k-1) % M +1;
					printf("%d\n", num);
				}
			}
			else if (start == 4)
			{
				value = (k-1) / M;
				if (value % 2 == 0)
				{
					num = (N - value - 1) * M  + (k-1) % M +1;
					printf("%d\n", num);
				}
				else
				{
					num = (N - value) * M - (k-1) % M;
					printf("%d\n", num);
				}
			}
		}
		else if (type == 2)
		{
			if (start == 1)
			{
				value = (k - 1) / N;
				if (value % 2 == 0)
				{
					num = value + 1 +  M *((k - 1) % N);
					printf("%d\n", num);
				}
				else
				{
					num = value+1 + M*(N-1) - M*((k-1)%N);
					printf("%d\n", num);
				}
			}
			else if (start == 2)
			{
				value = (k - 1) / N;
				if (value % 2 == 0)
				{
					num = M - value + M * ((k - 1) % N);
					printf("%d\n", num);
				}
				else
				{
					num = M*N - value - M * ((k - 1) % N);
					printf("%d\n", num);
				}
				
			}
			else if (start == 3)
			{
				value = (k - 1) / N;
				if (value % 2 == 0)
				{
					num = M * N - value - M * ((k - 1) % N);
					printf("%d\n", num);
				}
				else
				{
					num = M - value + M * ((k - 1) % N);
					printf("%d\n", num);
				}

			}
			else if (start == 4)
			{
				value = (k - 1) / N;
				if (value % 2 == 0)
				{
					num = value +1 + M * (N - 1) - M * ((k - 1) % N);
					printf("%d\n", num);
				}
				else
				{
					num = value + 1 + M * ((k - 1) % N);
					printf("%d\n", num);
				}
			}
		}
	}
}