#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	freopen("sequence.inp", "r", stdin);
	freopen("sequence.out", "w", stdout);
	long long int A;
	long long int B;
	int cas = 0;
	long long int num;
	while (1)
	{
		int count = 0;
		scanf("%lld %lld", &A, &B);
		num = A;
		if (A == -1 && B == -1)
			break;
		else
		{
			while (1)
			{
				if (A == 1 || A>B)
				{
					if (A == 1)
						count++;
					cas++;
					printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", cas, num, B, count);
					break;
				}
				else
				{
					if (A % 2 == 0)
						A = A / 2;
					else
						A = A * 3 + 1;
					count++;
				}
			}
		}
	}
}
