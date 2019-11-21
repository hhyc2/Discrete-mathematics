#include<stdio.h>
#pragma warning(disable:4996)
int arr[10000];
void check(int num, int strike, int ball,int count)
{
	int first = num / 1000;
	int second = (num / 100) % 10;
	int third = (num % 100) / 10;
	int last = num % 10;
	for (int i = 1234; i <= 9876; i++)
	{
		if (arr[i] != count)
			continue;
		else
		{
			int fir = i / 1000;
			int sec = (i / 100) % 10;
			int th = (i % 100) / 10;
			int lst = i % 10;
			int str = 0;
			int ba = 0;
			if (first == fir)str++;
			if (second == sec)str++;
			if (third == th)str++;
			if (last == lst)str++;
			if (fir == second || fir == third || fir == last) ba++;
			if (sec == first || sec == third || sec == last)ba++;
			if (th == first || th == second || th == last)ba++;
			if (lst == first || lst == second || lst == third)ba++;
			if (ba == ball && str == strike)
				arr[i] = count + 1;
		}
	}
}
void del()
{
	for (int i = 1234; i <= 9876; i++)
	{
		arr[i] = 0;
		int first = i / 1000;
		int second = (i / 100) % 10;
		int third = (i % 100) / 10;
		int last = i % 10;
		if (first == second || first == third || first == last || second == third || second == last || third == last || first == 0 || second == 0 || third == 0 || last == 0)
			continue;
		else
			arr[i]++;
	}
}
int count_num(int num)
{
	int count = 0;
	for (int i = 1234; i <= 9876; i++)
	{
		if (arr[i] == num + 1)
			count++;
	}
	return count;
}
void print_num(int num,int value)
{
	int ar[3];
	int flag = 0;
	int j = 0;
	if (value > 6)
		flag = 1;
	int count = 0;
	for (int i = 1234; i <= 9876; i++)
	{
		if (count == value)
			return;
		if (count == 3 && flag == 1)
			break;
		if (arr[i] == num + 1)
		{
			count++;
			printf("%d\n", i);
		}
	}
	for (int i = 9876; i >= 1234; i--)
	{
		if (count == 6 && flag == 1)
		{
			j = 2;
			for (int k = j; j >= 0; j--)
				printf("%d\n", ar[j]);
			return;
		}	
		if (arr[i] == num + 1)
		{
			count++;
			ar[j] = i;
			j++;
		}
	}
}
int main()
{
	freopen("numgame.inp", "r", stdin);
	freopen("numgame.out", "w", stdout);
	int Test;
	int num;
	int n;
	int strike;
	int ball;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		del();
		int value = 0;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%d %d %d", &n, &strike, &ball);
			check(n, strike, ball,j+1);
		}
		value=count_num(num);
		printf("%d\n", value);
		print_num(num,value);
	}
}