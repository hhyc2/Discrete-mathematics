#include<stdio.h>
#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct soccer
{
	int win = 0; // ½ÂÁ¡
	int score = 0; // °ñ µæ½Ç
	int goal = 0; // away¿¡¼­ ³ÖÀº °ñ¼ö
	int index = 0;
	int grade = 0;
};
bool compare(const soccer &a, const soccer &b)
{
	if (a.win == b.win)
	{
		if (a.score == b.score)
		{
			if (a.goal == b.goal)
				return a.index < b.index;
			else
				return a.goal < b.goal;
		}
		else
			return a.score < b.score;
	}
	return a.win < b.win;
}
bool compare2(const soccer& a, const soccer& b)
{
	return a.index < b.index;
}
int main()
{
	freopen("soccer.inp", "r", stdin);
	freopen("soccer.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		soccer arr[42];
		int n;
		int k;
		int first, second;
		char c;
		int f_s, s_s;
		scanf("%d %d", &n, &k);
		for (int l = 0; l < 2 * k * (n - 1); l++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				scanf("%d-%d %d %d%c", &first, &second, &f_s, &s_s, &c);
				if (f_s > s_s)
				{
					arr[first].win += 3; // ½ÂÁ¡
					arr[first].goal += f_s; // away °ñ ¼ö
					arr[first].score = arr[first].score + f_s - s_s; // µæ½Ç
					arr[second].score = arr[second].score + s_s - f_s;
				}
				else if (f_s == s_s)
				{
					arr[first].win += 1;
					arr[second].win += 1;
					arr[first].goal += f_s;
				}
				else
				{
					arr[second].win += 3;
					arr[second].score = arr[second].score + s_s - f_s;
					arr[first].score = arr[first].score + f_s - s_s;
					arr[first].goal += f_s;
				}
			}
		}
			for (int j = 1; j <= n; j++)
				arr[j].index = j;
			sort(arr + 1, arr + n + 1, compare);
			printf("Test Case #%d: ", i + 1);
			int count = 0;
			int value = 0;
			for (int j = n ; j > 0; j--)
			{
				if (arr[j].win == arr[j + 1].win&& arr[j].goal == arr[j + 1].goal&& arr[j].score == arr[j + 1].score)
				{
					arr[j].grade = count;
					value++;
				}
				else
				{
					count=count+1+value;
					arr[j].grade = count;
					value = 0;
				}
			}
			sort(arr + 1, arr + n + 1, compare2);
			for (int j = 1; j <= n; j++)
				printf("%d ", arr[j].grade);
			printf("\n");
		}
}

