#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
int prince[2];
int princess[3];
int card[54];
using namespace std;
int main()
{
	freopen("jollo.inp", "r", stdin);
	freopen("jollo.out", "w", stdout);
	while (1)
	{
		for (int i = 0; i < 54; i++)
			card[i] = 0;
		scanf("%d %d %d %d %d", &princess[0], &princess[1], &princess[2], &prince[0], &prince[1]);
		card[princess[0]]++;
		card[princess[1]]++;
		card[princess[2]]++;
		card[prince[0]]++;
		card[prince[1]]++;
		int flag = 1;
		if (princess[0] == 0)
			return 0;
		else
		{
			sort(prince, prince + 2);
			sort(princess, princess + 3);
			int s_max = princess[2];
			int s_mid = princess[1];
			int s_min = princess[0];
			int c_max = prince[1];
			int c_min = prince[0];
			//printf("%d %d %d %d %d\n", s_min,s_mid,s_max,c_min,c_max);
			if (c_max>s_max)
			{
				if (c_min>s_mid && c_min<s_max)
				{
					int num = s_mid;
					for (int k = num; k <= 52; k++)
						{
							if (card[k] == 0)
							{
								printf("%d\n", k);
								flag = 0;
								break;
							}
						}
						if (flag == 1)
							printf("-1\n");
				}
				else if(c_min>s_mid&&c_min>s_max)
				{
					int num = 1;
					for (int k = num; k <= 52; k++)
					{
						if (card[k] == 0)
						{
							printf("%d\n", k);
							flag = 0;
							break;
						}
					}
					if (flag == 1)
						printf("-1\n");
				}
				else if (c_min < s_mid)
				{
					int num = s_max;
					for (int k = num; k <= 52; k++)
					{
						if (card[k] == 0)
						{
							printf("%d\n", k);
							flag = 0;
							break;
						}
					}
					if (flag == 1)
						printf("-1\n");
				}
			}
			else
			{
				if (c_min < s_min)
					printf("-1\n");
				else 
				{
					if(c_min<s_mid)
						printf("-1\n");
					else
					{
						int num = s_mid;
						for (int k = num; k <= 52; k++)
						{
							if (card[k] == 0)
							{
								printf("%d\n", k);
								flag = 0;
								break;
							}
						}
						if (flag == 1)
							printf("-1\n");
					}
				}
			}


		}
	}
}