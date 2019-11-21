#include<stdio.h>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
char arr[20];
void change(int n)
{
	int num = n;
	int i = 0;
	int mok;
	int mod = 0;
	while (1)
	{
		if (num == 0)
			break;
		mok = num / 26;
		mod = num % 26;
		num = num / 26;
		if (mod == 0)
		{
			arr[i] = 'Z';
			num--;
		}
		else
			arr[i] = 'A' + mod - 1;
		i++;
	}
	for (int j = i-1; j>=0; j--)
		printf("%c", arr[j]);
}
void change2(int n)
{
	int index = n;
	int num;
	int value=0;
	for (int i = 0; i <= index; i++)
	{
		num = arr[i] - 'A' + 1;
		value = value * 26 + num;
	}
	printf("%d\n", value);
}
int main()
{
	freopen("spreadsheet.inp", "r", stdin);
	freopen("spreadsheet.out", "w", stdout);
	int Test;
	string word;
	int type;
	int value = 0;
	int num = 0;
	int index = 0;
	int first;
	int second;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		cin >> word;
		value = 0;
		num = 0;
		if (word[0] == 'R' && word[1] >= '1' && word[1] <= '9')
		{
			for (int j = 1; j < word.size(); j++)
			{
				if (word[j] >= '0' && word[j] <= '9')
				{
					num = word[j]-'0';
					value = value * 10 + num;
				}
				else if (word[j] == 'C')
				{
					first = value;
					value = 0;
				}
			}
			second = value;
			change(second);
			printf("%d\n", first);
		}
		else
		{
			for (int j = 0; j < word.size(); j++)
			{
				if (word[j] >= '0' && word[j] <= '9')
				{
					num = word[j] - '0';
					value = value * 10 + num;
				}
				else
				{
					arr[j] = word[j];
					index = j;
				}
			}
			printf("R%dC", value);
			change2(index);
		}
	}
}