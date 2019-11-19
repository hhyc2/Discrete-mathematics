#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	freopen("grid2.inp", "r", stdin);
	freopen("grid2.out", "w", stdout);
	int Test;
	int type;
	int k;
	int s;
	int N;
	int M;
	int start;

	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d %d %d %d %d", &N, &M, &type, &s, &k);
		int row = N;
		int col = M;
		if (type == 3)
		{
			if (s == 1)
			{
				start = 0;
				N--;
			}
			else if (s == 2)
			{
				start = 0;
				M--;
			}
			else if (s == 3)
			{
				start = N * M +1;
				N--;
			}
			else if (s == 4)
			{
				start = N * M + 1;
				M--;
			}
			while (k > 0)
			{
				if (s > 4)
					s = 1;
				if (s == 1)
				{
					if (k - M > 0)
						start = start + M;
					else
					{
						start = start + k;
						break;
					}
					s++;
					k = k - M;
					M--;
				}
				else if (s == 2)
				{
					if (k - N > 0)
						start = start + N * col;
					else
					{
						start = start + k * col;
						break;
					}
					s++;
					k = k - N;
					N--;
				}
				else if (s == 3)
				{
					if (k - M > 0)
						start = start - M;
					else
					{
						start = start - k;
						break;
					}
					s++;
					k = k - M;
					M--;
				}
				else if (s == 4)
				{
					if (k - N > 0)
						start = start - N * col;
					else
					{
						start = start - k * col;
						break;
					}
					s++;
					k = k - N;
					N--;
				}
			}
		}
		else if (type == 4)
		{
			if (s == 1)
			{
				start = 1-M;
				M--;
			}
			else if (s == 2)
			{
				start = M + 1;
				N--;
			}
			else if (s == 3)
			{
				start = N * M+M;
				M--;
			}
			else if (s == 4)
			{
				start = N * M-M;
				N--;
			}
			while (k > 0)
			{
				if (s==0)
					s = 4;
				if (s == 1)
				{
					if (k - N > 0)
						start = start + N * col;
					else
					{
						start = start + k * col;
						break;
					}
					s--;
					k = k - N;
					N--;
				}
				else if (s == 2)
				{
					if (k - M > 0)
						start = start - M;
					else
					{
						start = start - k;
						break;
					}
					s--;
					k = k - M;
					M--;
				}
				else if (s == 3)
				{
					
					if (k - N > 0)
						start = start - N * col;
					else
					{
						start = start - k * col;
						break;
					}
					s--;
					k = k - N;
					N--;
				}
				else if (s == 4)
				{
					if (k - M > 0)
						start = start + M;
					else
					{
						start = start + k;
						break;
					}
					s--;
					k = k - M;
					M--;
				}
			}
		} 
		printf("%d\n", start);
	}
	
}