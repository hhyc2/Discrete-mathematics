#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
int main()
{
	FILE* fp;
	FILE* fp1;
	fp = fopen("divisor.inp", "r");
	fp1 = fopen("divisor.out", "w");
	int Test;
	fscanf(fp, "%d", &Test);
	int min;
	int max;
	for (int i = 0; i < Test; i++)
	{
		int arr[2000] = { 0, };
		int value = 0;
		fscanf(fp, "%d %d", &min, &max);
		for (int j = min; j <= max; j++)
		{
			int cnt = 0;
			int A = sqrt(j);
			int flag = 0;
			if (A * A == j && j != 1)
				flag = 1;
			for (int k = 1; k <= A; k++)
			{
				if (j % k == 0)
					cnt++;
			}
			if (flag == 0)
			{
				if (j % (2 * cnt) == 0)
				{
					value++;
				}
			}
			else
			{
				if (j % (2 * (cnt-1)+1) == 0)
				{
					value++;
				}
			}
			
		}
		fprintf(fp1,"%d\n", value);
	}
}