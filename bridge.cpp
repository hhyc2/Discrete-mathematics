#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int S[20];
int W[20];
int N[20];
int E[20];
int find(char pattern, char num)
{
	int value;
	if (pattern == 'C')
		value = 100;
	else if (pattern == 'D')
		value = 200;
	else if (pattern == 'S')
		value = 300;
	else
		value = 400;
	if (num >= '0' && num <= '9')
		value = value + num-'0';
	else
	{
		if (num == 'T')
			value = value + 10;
		else if (num == 'J')
			value = value + 11;
		else if (num == 'Q')
			value = value + 12;
		else if (num == 'K')
			value = value + 13;
		else if (num == 'A')
			value = value + 14;
	}
	return value;
}
void change(int value)
{
	char pattern;
	char num;
	int val = value / 100;
	if (val == 1)
		pattern = 'C';
	else if (val == 2)
		pattern = 'D';
	else if (val == 3)
		pattern = 'S';
	else if (val == 4)
		pattern = 'H';
	printf("%c", pattern);
	val = value % 100;
	if (val >= 10)
	{
		if (val == 10)
			num = 'T';
		else if (val == 11)
			num = 'J';
		else if (val == 12)
			num = 'Q';
		else if (val == 13)
			num = 'K';
		else if (val == 14)
			num = 'A';
		printf("%c ", num);
	}
	else
	{
		printf("%d ", val);
	}
}
int main()
{
	freopen("bridge.inp", "r", stdin);
	freopen("bridge.out", "w", stdout);
	char person;
	while (1)
	{
		int flag = 0;
		scanf("%c\n", &person);
		if (person == '#')
			break;
		else
		{
			if (person == 'N')
				flag = 1;
			else if (person == 'E')
				flag = 2;
			else if (person == 'S')
				flag = 3;
			else if (person == 'W')
				flag = 4;
			int i = 0;
			int j = 0;
			int k = 0;
			int l = 0;
			for(int m=0;m<52; m++, flag++)
			{
				char num;
				char pattern;
				if (m == 25||m==51)
					scanf("%c%c\n", &pattern, &num);
				else
					scanf("%c%c", &pattern, &num);
				int value = find(pattern, num);
				if (flag > 4)
					flag = 1;
				if (flag == 1)
				{
					E[i] = value;
					i++;
				}
				else if (flag == 2)
				{
					S[j] = value;
					j++;
				}
				else if (flag == 3)
				{
					W[k] = value;
					k++;
				}
				else if (flag == 4)
				{
					N[l] = value;
					l++;
				}
				
			}
			sort(N, N + 13);
			sort(E, E + 13);
			sort(W, W + 13);
			sort(S, S + 13);
			printf("S: ");
			for (int n = 0; n < 13; n++)
				change(S[n]);
			printf("\n");
			printf("W: ");
			for (int n = 0; n < 13; n++)
				change(W[n]);
			printf("\n");
			printf("N: ");
			for (int n = 0; n < 13; n++)
				change(N[n]);
			printf("\n");
			printf("E: ");
			for (int n = 0; n < 13; n++)
				change(E[n]);
			printf("\n");
		}
	}
}