#include<stdio.h>
#pragma warning(disable:4996)
int gcd(int a, int b)
{
	int big = b;
	int small = a;
	while (1)
	{
		int mok = big / small;
		int mod = big - (mok * small);
		if (mod == 0)
		{
			return small;
			break;
		}
		else
		{
			big = small;
			small = mod;
		}
	}
}
int main()
{
	freopen("fraction.inp", "r", stdin);
	freopen("fraction.out", "w", stdout);
	int k;
	while (1)
	{
		int count = 0;
		scanf("%d", &k);
		if (k == 0)
			break;
		else
		{
			for (int i = k+1; i <= 2 * k; i++)
			{
				int lcm = k*i/gcd(k, i);
				if(lcm%(lcm/k - lcm/i)==0)
					count++;
			}
			printf("%d\n", count);
		}
	}
}